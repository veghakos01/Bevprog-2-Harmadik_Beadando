#include "szamw.hpp"
#include "graphics.hpp"
#include "sstream"

using namespace genv;
using namespace std;

szamw::szamw(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int szam, int miin, int maax)
            : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), _szam(szam), _miin(miin), _maax(maax)
{
    _checked=false;
    //ctor
}



szamw::~szamw()
{
    //dtor
}

void szamw::draw()
{
    gout.load_font("LiberationSans-Regular.ttf",20);

    stringstream ss;
    ss << _szam;
    string num;
    ss >> num;

    gout << move_to(x-frame_size,y-frame_size) << color(200,200,200) << box(size_x+2*frame_size, size_y+2*frame_size);

    if(_checked)
        gout << move_to(x, y) << color(205,0,205) << box(size_x, size_y);
    else
        gout << move_to(x, y) << color(100,0,100) << box(size_x, size_y);

    gout << move_to(x+size_x/4, y+(size_y/4)) << color(200,200,200) << text(num);

    gout << move_to(x + size_x + 10, y) << color(200,200,200) << box(size_y/2, size_y/2)
         << color(0,0,0) << line(-size_y/2,0) << color(200,200,200) << move_to(x + size_x + 10, y + size_y/2) << box(size_y/2, size_y/2);

    for(int i = 0; i < size_y/4; i++)
    {
        gout << color(0,0,0) << move_to(x + size_x + size_y/4 + 10 - i, y + size_y/8 + i) << line(2 * i,0);
        gout << move_to(x + size_x + size_y/4 + 10 - i, y + size_y - size_y/8 - i) << line(2 * i, 0);
    }
}

void szamw::handle(event ev)
{
    if (ev.type == ev_mouse && ev.pos_x>x && ev.pos_x<x + size_x && ev.pos_y>y && ev.pos_y<y + size_y && ev.button==btn_left)
    {
        _checked = true;
    }
    else if (ev.type == ev_mouse && ev.button==btn_left)
    {
        _checked = false;
    }

    if(_checked)
    {
        if (ev.keycode == 75)
        {
        if(_szam + 10 > _maax)
            _szam = _maax;
        else if(_szam < _maax)
            _szam += 10;
        }
        if (ev.keycode == 78)
        {
        if(_szam - 10 < _miin)
            _szam = _miin;
        else if(_szam > _miin)
            _szam -= 10;
        }
        if (ev.keycode == 82)
        {
        if(_szam + 1 > _maax)
            _szam = _maax;
        else if(_szam < _maax)
            _szam += 1;
        }
        if (ev.keycode == 81)
        {
        if(_szam - 1 < _miin)
            _szam = _miin;
        else if(_szam > _miin)
            _szam -= 1;
        }


    }

    if(ev.button == btn_left)
        {
            if(ev.pos_x>x + size_x + 10 && ev.pos_x<x + size_x + 10 + size_y/2 && ev.pos_y>y && ev.pos_y<y + size_y/2)
            {
                if(_szam + 1 > _maax)
                    _szam = _maax;
                else if(_szam < _maax)
                    _szam += 1;
                _checked = true;
            }
            if(ev.pos_x>x + size_x + 10 && ev.pos_x<x + size_x + 10 + size_y/2 && ev.pos_y>y + size_y/2 && ev.pos_y<y + size_y)
            {
                if(_szam - 1 < _miin)
                    _szam = _miin;
                else if(_szam > _miin)
                    _szam -= 1;
                _checked = true;
            }

        }

}

bool szamw::is_checked()
{
    return _checked;
}










