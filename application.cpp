#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "Hopehely.hpp"
#include "Tank.hpp"
#include "iostream"
#include "time.h"
#include "math.h"
#define PI 3.14159265

using namespace genv;
using namespace std;

Application::Application(int W_, int H_) : W(W_), H(H_)
{
    //gout.load_font("LiberationSans-Regular.ttf",20);
    gout.open(W_, H_);
    gout << refresh;
    szel = rand()%20-10;
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
    //cout << hav.size();
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
        if(szel==0)
            szel=1;
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
        //cout << ki << endl;
    }
//////////////////////////////////////////////////////////////////////////
    if(ev.keycode == key_backspace)
    {
        double lx = 1;
        double ly = 1;

        for(int i = 0; i < players[0]->bullet->e.size(); i++)
        {
            if(ki == 1 && players[0]->ifeletben())
            {
                if(players[0]->bullet->e[i]->is_checked())
                {
                    if(players[0]->bullet->e[i]->gettext() == "Regular" && szel != 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly)
                                <<  color(200,0,0) << box(10,10);
                            if(szel>0)
                                lx = players[0]->ero->getszam() * i * cos(players[0]->szog->getszam()*PI/180.0)  * szel/3 ;
                            else if(szel<0)
                                lx = players[0]->ero->getszam() * 2 * i * cos(players[0]->szog->getszam()*PI/180.0)  * -3/szel ;
                            ly = players[0]->ero->getszam() * i * sin(players[0]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[1]->hit(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly))
                                players[1]->seteletben(false);
                        }
                    }
                    if(players[0]->bullet->e[i]->gettext() == "Pontos" && szel != 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly)
                                <<  color(0,0,200) << box(10,10);
                            if(szel>0)
                                lx = players[0]->ero->getszam() * i * cos(players[0]->szog->getszam()*PI/180.0)  * szel/2 ;
                            else if(szel<0)
                                lx = players[0]->ero->getszam() * 2 * i * cos(players[0]->szog->getszam()*PI/180.0)  * -2/szel ;
                            ly = players[0]->ero->getszam() * i * sin(players[0]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[1]->hit(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly))
                                players[1]->seteletben(false);
                        }
                    }
                    if(players[0]->bullet->e[i]->gettext() == "Miazaszel" || szel == 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly)
                                <<  color(0,200,0) << box(10,10);
                            if(szel>0)
                                lx = players[0]->ero->getszam() * 2 * i * cos(players[0]->szog->getszam()*PI/180.0);
                            else if(szel<0)
                                lx = players[0]->ero->getszam() * 2 * i * cos(players[0]->szog->getszam()*PI/180.0);
                            ly = players[0]->ero->getszam() * i * sin(players[0]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[1]->hit(players[0]->getx()+70+cos(players[0]->szog->getszam()*PI/180)*100+lx,players[0]->gety()-100-sin(players[0]->szog->getszam()*PI/180)*100-ly))
                                players[1]->seteletben(false);
                        }
                    }
                    if(players[0]->bullet->e[i]->gettext() == "BigBoy/Fatman")
                    {
                        players[0]->seteletben(false);
                        players[1]->seteletben(false);
                        for(int i = 0; i < 100; i++)
                            gout << color(255-i,255-i,255-i) << move_to(0,0) << box(1500,900) << refresh;
                    }


                    ki = 2;
                    szel = rand() % 20 - 10;






                }

            }



            if(ki == 2 && players[1]->ifeletben())
            {
                if(players[1]->bullet->e[i]->is_checked())
                {
                    if(players[1]->bullet->e[i]->gettext() == "Regular" && szel != 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[1]->getx()+70-cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly)
                                <<  color(200,0,0) << box(10,10);
                            if(szel>0)
                                lx = players[1]->ero->getszam() * i * cos(players[1]->szog->getszam()*PI/180.0) * szel/3 ;
                            else if(szel<0)
                                lx = players[1]->ero->getszam() * 2 * i * cos(players[1]->szog->getszam()*PI/180.0) * -3/szel ;
                            ly = players[1]->ero->getszam() * i * sin(players[1]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[0]->hit(players[1]->getx()-70+cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly))
                                players[0]->seteletben(false);
                        }
                    }
                    if(players[1]->bullet->e[i]->gettext() == "Pontos" && szel != 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[1]->getx()+70-cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly)
                                <<  color(0,0,200) << box(10,10);
                            if(szel>0)
                                lx = players[1]->ero->getszam() * i * cos(players[1]->szog->getszam()*PI/180.0)  * szel/2 ;
                            else if(szel<0)
                                lx = players[1]->ero->getszam() * 2 * i * cos(players[1]->szog->getszam()*PI/180.0)  * -2/szel ;
                            ly = players[1]->ero->getszam() * i * sin(players[1]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[0]->hit(players[1]->getx()+70-cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly))
                                players[0]->seteletben(false);
                        }
                    }
                    if(players[1]->bullet->e[i]->gettext() == "Miazaszel" || szel == 0)
                    {
                        for(int i = 0; i < 20; i++)
                        {
                            gout << move_to(players[1]->getx()+70-cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly)
                                <<  color(0,200,0) << box(10,10);
                            if(szel>0)
                                lx = players[1]->ero->getszam() * 2 * i * cos(players[1]->szog->getszam()*PI/180.0);
                            else if(szel<0)
                                lx = players[1]->ero->getszam() * 2 * i * cos(players[1]->szog->getszam()*PI/180.0);
                            ly = players[1]->ero->getszam() * i * sin(players[1]->szog->getszam()*PI/180.0) - 6*(i*i);

                            if(players[0]->hit(players[1]->getx()+70-cos(players[1]->szog->getszam()*PI/180)*100-lx,players[1]->gety()-100-sin(players[1]->szog->getszam()*PI/180)*100-ly))
                                players[0]->seteletben(false);
                        }
                    }
                    if(players[1]->bullet->e[i]->gettext() == "BigBoy/Fatman")
                    {
                        players[0]->seteletben(false);
                        players[1]->seteletben(false);
                        for(int i = 0; i < 100; i++)
                            gout << color(255-i,255-i,255-i) << move_to(0,0) << box(1500,900) << refresh;
                    }

                    ki = 2;
                    szel = rand() % 20 - 10;


                }

            }



        }



    }

    ////////////////////////////////////////////////////////////////



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
    //gout << color(0,0,0) << move_to(0,0) << box(W,H);

    if(players[0]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-75,H/2) << text("Egyes jatekos nyert");
    else if(players[1]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-75,H/2) << text("Kettes jatekos nyert");
    else if(!players[0]->ifeletben() && !players[1]->ifeletben())
        gout << color(200,200,200) << move_to(W/2-50,H/2) << text("Senki se nyert");

    gout << color(200,200,200) << move_to(W/2-125,H/2+50) << text("GAME OVER - ESC a kilepeshez");
}















