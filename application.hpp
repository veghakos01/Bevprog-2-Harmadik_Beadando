#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>

using namespace std;

class Widget;
class Hopehely;


class Application
{
protected:
    int W;
    int H;
    vector<Widget*> widgets;
    vector<Hopehely*> hav;
    int szel;
    int ki;
public:
    Application(int W_, int H_);
    void event_loop();
    void feltolt(Widget* widget);
    void havak();
    void clearscreen();
    void setszel(int a) { szel = a; }
    int getszel() { return szel; }
    int getki() { return ki; }
};

#endif // APPLICATION_HPP
