#include "graphics.hpp"
#include "iostream"
#include "math.h"
#include "vector"

using namespace std;
using namespace genv;

const int W = 2000, H = 1000;

struct Ur
{
    Ur()
    {
        x = rand() % W;
        y = rand() % H;
    }
    Ur(int x_, int y_) : x(x_), y(y_)
    {
    }
    void rajzol()
    {
        gout << move_to(x, y)
             << color(255, 255, 255)
             << dot;
    }
    void mozog(int dy)
    {
        y = (y + dy) % H;
    }
private:
    int x, y;
};
void rajzolcsill(vector<Ur> csillagok)
{
    gout << color(255, 255, 255);
    for (size_t i = 0; i < csillagok.size(); i++)
    {
        csillagok[i].rajzol();
    }
}



int main()
{


    gout.open(W,H);
    gout << color(0,0,0) << box_to(W,H);

    int csillag = 1000;
    vector<Ur> csillagok;
    for(size_t i = 0; i < csillag; i++)
    {
        Ur uj(rand() % W, rand() % H);
        csillagok.push_back(uj);
    }



    int w8 = 0;

//    for(int i = 0; i < 100; i++)
//    {
//        double y = x*(x/8);
//
//        //gout << color(200,200,200) << move(x,-y) << dot;
//        gout << color(200,200,200) << line(-x,y) << refresh;
//
//        x = x + 0.1;
//    }
//
//    gout << move_to(500,500);
//
//    x = 1;
//    y = 0;
//
//    for(int j = 0; j < 100; j++)
//    {
//        double y = x*(x/8);
//
//        //gout << color(200,200,200) << move(x,-y) << dot;
//        gout << color(200,200,200) << line(x,y);
//
//        x = x + 0.1;
//    }


//    gout << move_to(100,900);
//    double x = 10;
//    double y = 20;
    //int s = 1;

    event ev;
    while(gin >> ev)
    {

    if(ev.type == ev_timer)
    {
        gout << color(0,0,0) << move_to(0,0) << box(W,H);
        for (size_t i=0; i<csillagok.size(); i++)
        {
            csillagok[i].mozog(rand() % 15 - 2);
        }

        rajzolcsill(csillagok);
    }








//if(w8%10 == 0)
//{
//    //double y = x*(x/8);
////    y = sqrt(x)*2*(1/s);
////    gout << color(200,200,200) << line(x,-y) << refresh;
////    x = x + 0.1;
////    s++;
//
//    gout << color(200,200,200) << line(x,-y) << refresh;
//    y -= 0.3;
//
//}







    w8++;

    cout << w8 << endl;

    gout << refresh;
    }
    return 0;
}






