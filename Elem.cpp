#include "Elem.hpp"
#include "iostream"

Elem::Elem(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, string text) : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), _text(text)
{
    _checked=false;
    kinn = true;
    //ctor
}

Elem::~Elem()
{
    //dtor
}

void Elem::seth(int h)
{
    height = h;
}

void Elem::sets(int s)
{
    start = s;
}

void Elem::draw()
{
    gout.load_font("LiberationSans-Regular.ttf",14);

    if(_checked)
    {
        gout << move_to(x, y) << color(100,100,200) << box(size_x, size_y)
             << color(0,0,0) << box(-size_x,-5) << box(5,-(size_y-5))
             << move_to(x+5, y+(size_y/4 + size_y/2)) << color(0,0,0) << line(_text.size()*10,0);

    }

    else
        gout << move_to(x, y) << color(200,200,200) << box(size_x, size_y);

    gout << move_to(x+10, y+(size_y/4)) << color(0,0,0) << text(_text);
}

void Elem::handle(event ev)
{
    int kx = x;
    int ky = y-start;
    int ksx = size_x;
    int ksy = start + height;

    if(ev.button == btn_left && !fol(x, y, size_x, size_y, ev.pos_x, ev.pos_y)
       && fol(kx, ky, ksx, ksy, ev.pos_x, ev.pos_y))
    {
        _checked = false;
        //cout << "hamis" << endl;
    }
    if(ev.button == btn_left && fol(x, y, size_x, size_y, ev.pos_x, ev.pos_y) && kinn)
    {
        _checked = true;
        //cout << "igaz" << endl;
        //cout << kinn << endl;
    }

}

bool Elem::is_checked()
{
    return _checked;
}

void Elem::sety(int ey)
{
    y = y + ey;
}

bool Elem::fol(int ax, int ay, int bx, int by, int cx, int cy)
{
    if(cx >= ax && cx<=ax+bx && cy>=ay && cy<=ay+by)
        return true;
    else
        return false;
}

void Elem::valt(bool a)
{
    kinn = a;
}









