#include "application.hpp"
#include "szamw.hpp"
#include "kivalw.hpp"
#include "Elem.hpp"
#include "kijelzo.hpp"
#include "Tank.hpp"

using namespace std;


class App : public Application
{
private:
    szamw* j1_ero;
    szamw* j1_szog;
    kivalw* j1_lovedek;

    szamw* j2_ero;
    szamw* j2_szog;
    kivalw* j2_lovedek;

    kijelzo* szel;
    kijelzo* jatekos;

    Tank* player1;
    Tank* player2;


public:
    App(int w, int h) : Application(w,h)
    {
        j1_ero = new szamw(50,50,100,50,5,this,50,0,100,1);
        j1_szog = new szamw(50,150,100,50,5,this,50,40,70,1);
        j1_lovedek = new kivalw(250,50,120,30,5,this,0);
        j1_lovedek->add("Regular");
        j1_lovedek->add("Pontos");
        j1_lovedek->add("Miazaszel");
        j1_lovedek->add("BigBoy/Fatman");
        j1_lovedek->add("valami");

        j2_ero = new szamw(W-185,50,100,50,5,this,50,0,100,2);
        j2_szog = new szamw(W-185,150,100,50,5,this,50,40,70,2);
        j2_lovedek = new kivalw(W-355,50,120,30,5,this,0);
        j2_lovedek->add("Regular");
        j2_lovedek->add("Pontos");
        j2_lovedek->add("Miazaszel");
        j2_lovedek->add("BigBoy/Fatman");
        j2_lovedek->add("megegy");

        szel = new kijelzo(W/2-25,50,50,50,1,this,1);
        jatekos = new kijelzo(W/2-75,150,150,50,1,this,2);

        player2 = new Tank(1200,800,200,200,0,this,j2_szog,j2_ero, j2_lovedek, 2);
        player1 = new Tank(100,800,200,200,0,this,j1_szog, j1_ero, j1_lovedek, 1);

        jatekosok(player1);
        jatekosok(player2);


    }
};


















int main()
{
    App* myapp = new App(1500,900);
    myapp->havak();
    myapp->event_loop();
    return 0;
}
