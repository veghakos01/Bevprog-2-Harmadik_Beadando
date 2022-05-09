#include "kijelzo.hpp"
#include "graphics.hpp"
#include "sstream"


kijelzo::kijelzo(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int szam)
            : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), _szam(szam)
{
    //ctor
}

kijelzo::~kijelzo()
{
    //dtor
}

void kijelzo::draw()
{
    gout.load_font("LiberationSans-Regular.ttf",20);

    _szam = parent->getszel();

    stringstream ss;
    ss << _szam;
    string num;
    ss >> num;

    gout << move_to(x-frame_size,y-frame_size) << color(200,200,200) << box(size_x+2*frame_size, size_y+2*frame_size);
    gout << move_to(x, y) << color(100,100,100) << box(size_x, size_y);

    gout << move_to(x+size_x/4, y+(size_y/4)) << color(200,200,200) << text(num);
}

void kijelzo::handle(event ev)
{

}




