#ifndef TANK_HPP
#define TANK_HPP

#include "graphics.hpp"
#include "widget.hpp"

using namespace genv;
using namespace std;

class Tank : public Widget
{
    public:
        Tank(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int jatekos_);
        virtual ~Tank();

        virtual void draw();

        virtual void handle(event ev);

    protected:
        int jatekos;

    private:
};

#endif // TANK_HPP
