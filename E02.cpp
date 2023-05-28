#include <iostream>
#include <sstream>
#include <string>
#include <sys/ioctl.h>
#include <ctime>
#include <math.h>
#include <csignal>
#include <fcntl.h>

using namespace std;

int rezim = 0;

const int fps = 10; //смена целевого fps

namespace con {  // Escape Console io block
    // Cursor max col location
    int comax() {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_col);
    } // comax


    // Cursor max row location
    int romax() {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_row);
    } // romax


    //ClearDisplay
    ostream& CD(ostream& s) {
        return s << "\033c"s;
    } // ED


    // Eliminate Line
    // (Clear Line by spaces from cursor position)
    ostream& EL(ostream& s) {
        return s << string("\033[K");
    } // EL


    // Console class for escape-manipulators
    //  stream with parameter(s)
    class estream {
    private:
        string escape; // Escape string
    public:
        estream(string e) : escape(e) {};
        friend ostream& operator<<(ostream&, estream);
    }; // estream


    // friend overload << for escape output 
    ostream& operator<<(ostream& s, estream e) {
        s << e.escape << flush;
        return s;
    } // <<()


    // escape manipulator with 2 int parameters
    // to remove CUrsor in y row & x col Position 
    // (equal $ echo -ne "\033[y;xH")
    estream CUP(int y, int x) { // CUrsor Position
        ostringstream sout;         // output string stream
        sout << "\033[" << y << ";" << x << "H"; // gotoxy ESC  
        return estream(sout.str());       // return ESC object
    } // CUP

    // Set pseudo-Graphic Regime escape manipulator
    // (equal $echo -ne "\033[Rm")
    // with Regime int parameter: 

    // 0 default (black on white)
    // 1 Bold On
    // 4 Underscore
    // 5 Blink On
    // 7 Reverse video
    // 8 Cancelled On (invisible)
    // 3[0-7] foreground
    // 4[0-7] background
    // 2[1,4,5,7] cancel parameter in braces

    estream SGR(int r) {  // Set Graphic Regime
        ostringstream sout;   // output string stream
        sout << "\033[" << r << "m"; // specify GraphMode
        return estream(sout.str());  // Return ESC object
    } // SGR

    estream SGR255(int r) {  // Set Graphic Regime
        ostringstream sout;   // output string stream
        sout << "\033[48;5;" << r << "m"; // specify GraphMode
        return estream(sout.str());  // Return ESC object
    } // SGR

    string sSGR(int r) {  // Set Graphic Regime
        string out;   
        out = "\033[" + to_string(r) + "m"; // specify GraphMode
        return out;
    } // SGR

    string sSGR255(int r) {  // Set Graphic Regime
        string out;   
        out = "\033[48;5;" + to_string(r) + "m"; // specify GraphMode
        return out;  
    } // SGR

}

using namespace con;

class ColorPalette{
private:
    int color = 0;
    int height = 10;
    int width = 10;
    bool updateConsoleSize();
public: 
    ColorPalette() {};
    ColorPalette operator++(int);
    friend ostream& operator<<(ostream&, ColorPalette&);
    static void moveCursor(int x, int y) { cout << CUP(x, y); }
    static void clearScreen() { cout << CD; }
};


bool ColorPalette::updateConsoleSize(){
    bool changed = false;
    if (width != comax() or height != romax()) {
        changed = true;
    }
    width = comax();
    height = romax();
    return changed;
}

ColorPalette ColorPalette::operator++(int) {
    if (++color == 256)
        color = 0;
    return *this;
}

ostream& operator<<(ostream& out, ColorPalette& frame) {
    if (frame.updateConsoleSize()) {
        ColorPalette::clearScreen();
    }
    ColorPalette::moveCursor(0, 0);
    string line;

  
    //============быстрая реализация===========
    
    if(rezim == 0)
    {
    	    int color = frame.color;
	    for (int i = 0; i < frame.width; ++i){
		if (color > 255)
		    color = 0;
		line += sSGR255(color++) + " "s;
	    }
	    for (int i = 0; i < frame.height-3; ++i)
		out << line << sSGR(0) << endl;//строки выводятся быстрее чем символы
    
    }
    else if(rezim == 1)
    {
    
    //==========================================


    //медленная, но больше соответствует заданию
    for (int i = 0; i < frame.height - 3; ++i) {
        int color = frame.color;
        for (int i = 0; i < frame.width; ++i) {
            if (color > 255)
                color = 0;
            out << SGR255(color++) << " " << SGR(0);
        }
        out << endl;
    }
    //=============================================
    
    }

    out << endl << "height: "s << frame.height << ", width: " << frame.width;
    return out;
}

int kbin() {
    char buf[512];                  // read buffer
    int n = 0;                        // read bytes number
    int flags = fcntl(0, F_GETFL);  // stdin control flags
    usleep(1);                      // delay 1 ms for fcntl
    fcntl(0, F_SETFL, flags | O_NONBLOCK); // unblock input
    n = read(0, buf, 512);  // nonblock read input line
    fcntl(0, F_SETFL, flags /* & ~O_NONBLOCK */);  // block input
    return(n); // return input bytes number
} // kbin

long millis(){
    struct timespec _t;
    clock_gettime(CLOCK_REALTIME, &_t);
    return _t.tv_sec*1000 + lround(_t.tv_nsec/1e6);
}

bool cycle(){ 
    static long last = 0;
    if (millis()-last > 1000.0/fps){
    	last = millis();
    	return true;
    }
    return false;
}

int doCycle = 1;

void interruptor(int s){
    doCycle = 0;
}

int main(int argc, char * argv[])
{
    if(argc > 1)
    {
    	rezim = atoi(argv[1]);
    }
    signal(SIGINT, interruptor); //обработка ctrl+C
    ColorPalette frame;
    while (doCycle){
    	if (cycle()){ //каждые n миллисекунд вызывается отрисовка. Скорость отрисовки меняется параметром fps
	        frame++;
    	    cout << frame << endl;
    	}
        if (kbin() > 0) // обработка энтера
            break;
    }
    ColorPalette::clearScreen(); 
}

