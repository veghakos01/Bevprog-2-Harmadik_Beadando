#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>

using namespace std;

class Widget;
class Hopehely;
class Tank;

class Application
{
protected:
    int W;
    int H;
    vector<Widget*> widgets;
    vector<Hopehely*> hav;
    vector<Tank*> players;
    double szel;
    int ki;
    bool jatek;
    void endscreen();
public:
    Application(int W_, int H_);
    void event_loop();
    void feltolt(Widget* widget);
    void havak();
    void jatekosok(Tank* vki);
    void clearscreen();
    void setszel(int a) { szel = a; }
    int getszel() { return szel; }
    int getki() { return ki; }
    void setjatek(bool a) {jatek = a;}
    bool getjatek() {return jatek;}
};

#endif // APPLICATION_HPP
