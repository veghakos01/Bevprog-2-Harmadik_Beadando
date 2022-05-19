#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "Hopehely.hpp"
#include "Tank.hpp"
#include "iostream"
#include "time.h"
#include "math.h"

using namespace genv;
using namespace std;

Application::Application(int W_, int H_) : W(W_), H(H_)
{
    //gout.load_font("LiberationSans-Regular.ttf",20);
    gout.open(W_, H_);
    gout << refresh;
    szel = 10;
    ki = 1;
    jatek = true;

}

void Application::clearscreen()
{
    gout << color(60,80,150);
    gout << move_to(0,0);
    gout << box(W,800);
    gout << move_to(0,800) << color(100,50,0) << box(W,100);
    gout << move_to(0,800) << color(250,250,250) << box(W,10);
}

void Application::feltolt(Widget* widget)
{
    if(widget->getframe() != 0)
        widgets.push_back(widget);
}

void Application::jatekosok(Tank* jatekos)
{
    players.push_back(jatekos);
}

void Application::havak()
{
    for(size_t i = 0; i < 1000; i++)
    {
        Hopehely* uj;

        uj = new Hopehely(rand() % 1500,rand() % 900);
        //cout << uj->x << end;

        hav.push_back(uj);

        uj->rajzol();
    }
    cout << hav.size();
    gout << refresh;

}

void Application::event_loop()
{
    srand(time(NULL));

    gin.timer(50);

    event ev;
    while (gin >> ev && ev.keycode != key_escape)
    {
    clearscreen();
//////////////////////////////////////////////////////////
    if(ev.type == ev_timer)
    {
        for (size_t i=0; i<hav.size(); i++)
        {
            hav[i]->mozog(rand() % 7 - 3 + szel, rand() % 15 - 2);
        }
    }
    for (size_t i=0; i<hav.size(); i++)
    {
        hav[i]->rajzol();
    }

    if(!players[0]->ifeletben())
            jatek = false;
    else if(!players[1]->ifeletben())
            jatek = false;

    if(!jatek)
            endscreen();


/////////////////////////////////////////////////////////



    if(ev.keycode == key_space)
    {
        if(ki == 1)
            ki = 2;
        else if(ki == 2)
            ki =1;
        szel = rand() % 20 - 10;
        cout << ki << endl;
    }

    if(ev.keycode == key_backspace)
        players[ki-1]->loves();


    for (size_t i = 0; i < players.size(); i++)
            players[i]->handle(ev);

    for (size_t i = 0; i < players.size(); i++)
        players[i]->draw();




////////////////////////////////////////////////////////
        for (size_t i = 0; i < widgets.size(); i++)
            widgets[i]->handle(ev);

        for (size_t i = 0; i < widgets.size(); i++)
            widgets[i]->draw();
////////////////////////////////////////////////////////

        gout << refresh;



    }
}

void Application::endscreen()
{
    gout << color(0,0,0) << move_to(0,0) << box(W,H);

    if(players[0]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-50,H/2) << text("Egyes jatekos nyert");
    else if(players[1]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-50,H/2) << text("Kettes jatekos nyert");
    else if(!players[0]->ifeletben() && !players[1]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-75,H/2) << text("Senki se nyert");

    gout << color(200,200,200) << move_to(W/2-150,H/2+50) << text("GAME OVER - ESC a kilepeshez");
}















