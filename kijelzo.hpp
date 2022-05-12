#ifndef KIJELZO_HPP
#define KIJELZO_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include "application.hpp"

using namespace genv;
using namespace std;

class kijelzo : public Widget
{
    public:
        kijelzo(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int szam);
        virtual ~kijelzo();

        virtual void draw();

        virtual void handle(genv::event ev);

    protected:
        int _szam, kinn;

    private:
};

#endif // KIJELZO_HPP
