#include "Tank.hpp"
#include "graphics.hpp"
#include "iostream"
#include "math.h"
#define PI 3.14159265

using namespace genv;
using namespace std;


Tank::Tank(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, szamw* szog_, int jatekos_)
            : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), szog(szog_), jatekos(jatekos_)
{
    //ctor
}

Tank::~Tank()
{
    //dtor
}

void Tank::draw()
{
    int e = 100;

    gout << move_to(x,y) << color(0,0,0);

    for(int i = 0; i < 20; i++)
    {
        gout << move_to(x+20-i,y-i) << line(100+2*i,0);
        gout << move_to(x+20-i,y-39+i) << line(100+2*i,0);
    }

    gout << move_to(x+50,y-40) << color(30,50,30) << box(40,-10);
    gout << move_to(x,y-50) << color(50,100,50) << box(140,-30) <<color(0,0,0) << box(-140,5);
    for(int i = 0; i < 20; i++)
    {
        gout << move_to(x+i,y-80-i) << color(50,100,50) << line(140-2*i,0);
    }


    if(jatekos == 1)
    {
        float agyu1 = szog->getszam();
        for(int i = 0; i < 20; i++)
        {
            gout << move_to(x+140-i,y-80-i) << color(100,100,200) << line(-20+i,0);
        }
        for(int i = 0; i < 10; i++)
        {
            gout << move_to(x+70,y-100-i) << color(0,0,0) << line(cos(agyu1*PI/180)*e,sin(agyu1*PI/180)*-e);
            gout << move_to(x+70,y-100+i) << color(0,0,0) << line(cos(agyu1*PI/180)*e,sin(agyu1*PI/180)*-e);
            gout << move_to(x+70+i,y-100) << color(0,0,0) << line(cos(agyu1*PI/180)*e,sin(agyu1*PI/180)*-e);
            gout << move_to(x+70-i,y-100) << color(0,0,0) << line(cos(agyu1*PI/180)*e,sin(agyu1*PI/180)*-e);
        }



    }
    else if(jatekos == 2)
    {
        float agyu2 = szog->getszam();
        for(int i = 0; i < 20; i++)
        {
            gout << move_to(x+i,y-80-i) << color(100,100,200) << line(20-i,0);
        }
        for(int i = 0; i < 10; i++)
        {
            gout << move_to(x+70,y-100-i) << color(0,0,0) << line(cos(agyu2*PI/180)*-e,sin(agyu2*PI/180)*-e);
            gout << move_to(x+70,y-100+i) << color(0,0,0) << line(cos(agyu2*PI/180)*-e,sin(agyu2*PI/180)*-e);
            gout << move_to(x+70+i,y-100) << color(0,0,0) << line(cos(agyu2*PI/180)*-e,sin(agyu2*PI/180)*-e);
            gout << move_to(x+70-i,y-100) << color(0,0,0) << line(cos(agyu2*PI/180)*-e,sin(agyu2*PI/180)*-e);
        }

    }


}

void Tank::loves()
{
    float agyu1 = szog->getszam();
    int e = 100;
    if(parent->getki() == 1 && jatekos == 1)
    {
        //gout << move_to(x+200,y-200) << color(200,0,0) << box(10,10);
        int ero = 50;
        //int szog = 60;
        gout << move_to(100,800);
        gout << move_to(x+70+cos(agyu1*PI/180)*e,y-100-sin(agyu1*PI/180)*e);
        double x = 1;
        double y = 1;

        for(int i = 0; i < 100; i++)
        {
            x = ero * i * cos(szog->getszam()*PI/180.0);
            y = ero * i * sin(szog->getszam()*PI/180.0) - 6*(i*i);
            //double b =;
            //y = x * tan(szog*PI/180.0) * ero - 100*i/(2*ero*ero*cos(szog*PI/180.0)*(x*x));



            //gout << color(200,100,100) << move_to(100+x,800-y) << dot;
            gout << color(200,0,0) << line(x,-y);

            //x = x + 0.1;
        }
    }

    if(parent->getki() == 2 && jatekos == 2)
    {
        gout << move_to(x-60,y-200) << color(200,0,0) << box(10,10);
    }


}

void Tank::handle(event ev)
{
    if(ev.keycode == key_enter)
    {
        loves();

    }




}














