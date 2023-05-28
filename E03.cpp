#include <iostream>
#include <sstream>
#include <string>
#include <sys/ioctl.h>
#include <ctime>
#include <math.h>
#include <csignal>
#include <fcntl.h>

using namespace std;

const int fps = 10; //смена целевого fps

namespace con {
    int comax() { // количество столбцов
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_col);
    } 

    int romax() { // количество строк
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_row);
    } 


    //ClearDisplay
    ostream& CD(ostream& s) {
        return s << "\033c"s;
    } 

    ostream& EL(ostream& s) { // стирание текущей строки
        return s << string("\033[K");
    }

    class estream {
    private:
        string escape; 
    public:
        estream(string e) : escape(e) {};
        friend ostream& operator<<(ostream&, estream);
    };

    ostream& operator<<(ostream& s, estream e) {
        s << e.escape << flush;
        return s;
    } 

    estream CUP(int y, int x) {
        ostringstream sout;
        sout << "\033[" << y << ";" << x << "H";
        return estream(sout.str());
    }

    estream SGR(int r) {
        ostringstream sout;
        sout << "\033[" << r << "m";
        return estream(sout.str());
    }

    estream SGR255(int r) {
        ostringstream sout;
        sout << "\033[48;5;" << r << "m";
        return estream(sout.str());
    }

    string sSGR(int r) {
        string out;
        out = "\033[" + to_string(r) + "m";
        return out;
    }

    string sSGR255(int r) {
        string out;
        out = "\033[48;5;" + to_string(r) + "m";
        return out;
    }

}

using namespace con;

class ColorPalette {
private:
    int color = 0;
    int height = 10;
    int width = 10;
    bool updateConsoleSize();
public:
    ColorPalette() {};
    ColorPalette operator--(int);
    friend ostream& operator<<(ostream&, ColorPalette&);
    static void moveCursor(int x, int y) { cout << CUP(x, y); }
    static void clearScreen() { cout << CD; }
};


bool ColorPalette::updateConsoleSize() {
    bool changed = false;
    if (width != comax() or height != romax()) {
        changed = true;
    }
    width = comax();
    height = romax();
    return changed;
}

ColorPalette ColorPalette::operator--(int) {
    if (--color < 0)
        color = 255;
    return *this;
}

ostream& operator<<(ostream& out, ColorPalette& frame) {
    if (frame.updateConsoleSize()) {
        ColorPalette::clearScreen();
    }
    ColorPalette::moveCursor(0, 0);
    string line;


    //============быстрая реализация===========
    //int color = frame.color;
    //for (int i = 0; i < frame.width; ++i){
    //    if (color < 0)
    //        color = 255;
    //    line += sSGR255(color--) + " "s;
    //}
    //for (int i = 0; i < frame.height-3; ++i)
    //    out << line << sSGR(0) << endl;//строки выводятся быстрее чем символы
    //
    //==========================================


    //медленная, но больше соответствует заданию
    for (int i = 0; i < frame.height - 3; ++i) {
        int color = frame.color;
        for (int i = 0; i < frame.width; ++i) {
            if (color < 0)
                color = 255;
            out << SGR255(color--) << " " << SGR(0);
        }
        out << endl;
    }
    //=========================================

    out << endl << "height: "s << frame.height << ", width: " << frame.width;
    return out;
}

int kbin() {
    char buf[512];
    int n = 0;                        // read bytes number
    int flags = fcntl(0, F_GETFL);
    usleep(1);                      // delay 1 ms for fcntl
    fcntl(0, F_SETFL, flags | O_NONBLOCK); // unblock input
    n = read(0, buf, 512);  // nonblock read input line
    fcntl(0, F_SETFL, flags /* & ~O_NONBLOCK */);  // block input
    return(n); // return input bytes number
}

long millis() {
    struct timespec _t;
    clock_gettime(CLOCK_REALTIME, &_t);
    return _t.tv_sec * 1000 + lround(_t.tv_nsec / 1e6);
}

bool cycle() {
    static long last = 0;
    if (millis() - last > 1000.0 / fps) {
        last = millis();
        return true;
    }
    return false;
}

int doCycle = 1;

void interruptor(int s) {
    doCycle = 0;
}

int main()
{
    signal(SIGINT, interruptor); //обработка ctrl+C
    ColorPalette frame;
    while (doCycle) {
        if (cycle()) { //каждые n миллисекунд вызывается отрисовка. Скорость отрисовки меняется параметром fps
            frame--;
            cout << frame << endl;
        }
        if (kbin() > 0) // обработка энтера
            break;
    }
    ColorPalette::clearScreen();
}

