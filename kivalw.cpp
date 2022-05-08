#include "graphics.hpp"
#include "kivalw.hpp"
#include "iostream"

using namespace genv;
using namespace std;

kivalw::kivalw(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int db) : Widget(x_,y_,_size_x,_size_y,_frame_size,parent_), _db(db)
{
    started = false;
    _checked=false;
    kezd = 0;
    //ctor
}

kivalw::~kivalw()
{
    //dtor
}

void kivalw::draw()
{
    gout.load_font("LiberationSans-Regular.ttf",14);

    gout << color(200, 0, 0) << move_to(x-5, y-5) << box(size_x+10, geth()+10);


    if(_db != 0)
    {
        for(size_t i = 0; i < _db; i++)
            {
                e[i+kezd]->draw();
            }
        for(size_t i = 0; i < e.size(); i++)
        {
            if(i-kezd < _db)
                e[i]->valt(true);
            else
                e[i]->valt(false);
        }

    }
    else
    {
        for(size_t i = 0; i < e.size(); i++)
            {
                e[i]->draw();
            }
    }

}

void kivalw::handle(event ev)
{

    if(!started)
    {
        if(_db != 0)
        {
//            for(size_t i = 0; i < e.size(); i++)
//            {
//                e[i]->seth(geth()-i*30+kezd*30);
//                e[i]->sets(30*i-kezd*30);
//            }
        }
        else
        {
            for(size_t i = 0; i < e.size(); i++)
            {
                e[i]->seth(geth()-i*size_y);
                e[i]->sets(size_y*i);
            }
        }


        started = true;
    }
    if(_db != 0)
    {
        for(size_t i = 0; i < e.size(); i++)
        {
            //if(i >= kezd && i < kezd + _db)
            //{
                e[i]->seth(geth()-i*size_y+kezd*size_y);
                e[i]->sets(size_y*i-kezd*size_y);
            //}
//            else
//            {
//                e[i]->seth(0);
//                e[i]->sets(0);
//            }

        }


        //cout << e[4]-> << endl;

    //if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+geth())
    //{
        if(ev.button == btn_wheeldown)
        {

            if(kezd < veg-_db)
            {
                kezd++;
                for(size_t i = 0; i < e.size(); i++)
                {
                    e[i]->sety(-size_y);
                }
                //cout << kezd << endl;
            }

        }
        if(ev.button == btn_wheelup)
        {
            if(kezd > 0)
            {
                kezd--;
                for(size_t i = 0; i < e.size(); i++)
                {
                    e[i]->sety(+size_y);
                }
                //cout << kezd << endl;
            }

        }



    //}


        for(size_t i = 0; i < e.size(); i++)
        {

            e[i]->handle(ev);

        }
    }
    else
    {
        for(size_t i = 0; i < e.size(); i++)
        {
            e[i]->handle(ev);
        }
    }
}

bool kivalw::is_checked()
{
    return _checked;
}

void kivalw::add(string a)
{
    if(e.size() == 0)
        e.push_back(new Elem(x, y, size_x, size_y, 1, parent, a));

    else if(e.size() > 0)
        e.push_back(new Elem(x, y + e.size()*size_y, size_x, size_y, 1, parent, a));

    veg++;
    //cout << veg << endl;
}

int kivalw::getv()
{
    return e.size();
}


int kivalw::geth()
{
    if(_db != 0)
        return (_db)*size_y;
    else
        return e.size()*size_y;
}




