#ifndef ELEM_HPP
#define ELEM_HPP

#include "widget.hpp"

using namespace genv;
using namespace std;

//class kivalw;

class Elem : public Widget
{
    public:
        Elem(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, string text);
        virtual ~Elem();

        virtual void draw();

        virtual void handle(genv::event ev);

        virtual bool is_checked();

        void seth(int h);

        void sets(int s);

        void sety(int ey);

        int gety(){return y;}

        int getl(){return size_y;}

        bool fol(int, int, int, int, int, int);

        void valt(bool);

    protected:
        int height, start;
        string _text;
        bool _checked, kinn;

    private:
};

#endif // ELEM_HPP
