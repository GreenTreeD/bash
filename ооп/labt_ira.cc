#include <iostream>
#include <sys/select.h> // Для функции select
#include <termios.h>    // Для функции tcgetattr
#include <sstream>
#include <iomanip>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <thread>

// Infinity loop control code
static int done = 0;
using namespace std;
namespace con {
    int comax() {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_col);
    }

    int romax() {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return(w.ws_row);
    }

    ostream& ED(ostream& s) {
        return s << string("\033[2J");
    }

    ostream& EL(ostream& s) {
        return s << string("\033[K");
    }

    class estream {
    private:
        string escape; // Escape string
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
}

using con::CUP;
using con::ED;
using con::SGR;

void interruptor(int    signo) {
    done = signo;
    return;
}

int getchr( ) {
   struct termios oldt,
   newt;
   int ch;
   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   ch = getchar();
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   return ch;
}


int kbin() {
    char buf[512];
    int n = 0;
    int flags = fcntl(0, F_GETFL);
    usleep(1);
    fcntl(0, F_SETFL, flags | O_NONBLOCK);
    n = read (0, buf, 512);
    fcntl(0, F_SETFL, flags );
    return(n);
}



int main() {
    cout << con::CUP((con::romax()), 1);
    cout << con::ED << "^C or Enter to exit" << flush;

    struct termios t[2];
        tcgetattr(0, &t[0]);
        tcgetattr(0, &t[1]);
        t[0].c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSAFLUSH, &t[0]);
    signal(SIGINT, interruptor);
    int fon = 47;

        for (int i = 1; (i <= (con::comax())); i++) {
            for (int j = 1; j <= con::romax() - 1; j++) {
                cout << CUP(j, i);
                cout << "\033[" << fon << "m ";
            }
            fon -= 1;
            if (fon < 40) fon = 47;
            cin.clear();
            usleep(10000);
            cout << flush;
            if (i == (con::comax())) i = 1;

            if(kbin() > 0) break;

        }

    cout << con::SGR(0) << ED << con::EL;
    cout << "\033["<<con::romax()<<";1H" << flush;

   // cout << "Program terminated." << endl;
        tcsetattr(0, TCSAFLUSH, &t[1]);

    return 0;
}
