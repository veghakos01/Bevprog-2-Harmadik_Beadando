#include "Tank.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;


Tank::Tank(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int jatekos_) : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), jatekos(jatekos_)
{
    //ctor
}

Tank::~Tank()
{
    //dtor
}

void Tank::draw()
{
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
        for(int i = 0; i < 20; i++)
        {
            gout << move_to(x+140-i,y-80-i) << color(100,100,200) << line(-20+i,0);
        }



    }
    else if(jatekos == 2)
    {
        for(int i = 0; i < 20; i++)
        {
            gout << move_to(x+i,y-80-i) << color(100,100,200) << line(20-i,0);
        }

    }


}

void Tank::handle(event ev)
{

}





