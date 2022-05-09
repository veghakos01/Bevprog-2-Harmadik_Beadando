#include "application.hpp"
#include "scrolltext.hpp"
#include "szamw.hpp"
#include "kivalw.hpp"
#include "Elem.hpp"

using namespace std;


class App : public Application
{
private:
    //Scrolltext* s;
    szamw* z1;
    szamw* z2;
    kivalw* k1;
public:
    App(int w, int h) : Application(w,h)
    {
        //s = new Scrolltext(140,60,1000,400,5,this);
        z1 = new szamw(150,500,150,50,5,this,42,10,80);
        z2 = new szamw(150,700,100,50,5,this,80,-100,720);
        k1 = new kivalw(500,500,120,30,5,this,0);
        k1->add("A widget 1");
        k1->add("A  2");
        k1->add("A widget 3");
        k1->add("A negy");
    }
};


















int main()
{
    App* myapp = new App(1500,900);
    myapp->havak();
    myapp->event_loop();
    return 0;
}
