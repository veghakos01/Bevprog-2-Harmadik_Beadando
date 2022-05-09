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
    szamw* j1_ero;
    szamw* j1_szog;
    kivalw* j1_lovedek;

    szamw* j2_ero;
    szamw* j2_szog;
    kivalw* j2_lovedek;


public:
    App(int w, int h) : Application(w,h)
    {
        //s = new Scrolltext(140,60,1000,400,5,this);
        j1_ero = new szamw(50,50,100,50,5,this,50,0,100);
        j1_szog = new szamw(50,150,100,50,5,this,45,0,90);
        j1_lovedek = new kivalw(250,50,120,30,5,this,0);
        j1_lovedek->add("A widget 1");
        j1_lovedek->add("A  2");
        j1_lovedek->add("A widget 3");
        j1_lovedek->add("A negy");
        j1_lovedek->add("valami");

        j2_ero = new szamw(W-185,50,100,50,5,this,50,0,100);
        j2_szog = new szamw(W-185,150,100,50,5,this,45,0,90);
        j2_lovedek = new kivalw(W-355,50,120,30,5,this,0);
        j2_lovedek->add("A widget 1");
        j2_lovedek->add("A  2");
        j2_lovedek->add("A widget 3");
        j2_lovedek->add("A negy");
        j2_lovedek->add("megegy");
    }
};


















int main()
{
    App* myapp = new App(1500,900);
    myapp->havak();
    myapp->event_loop();
    return 0;
}
