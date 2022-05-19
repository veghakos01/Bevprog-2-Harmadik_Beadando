#ifndef TANK_HPP
#define TANK_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include "szamw.hpp"
#include "kivalw.hpp"

using namespace genv;
using namespace std;

class Tank : public Widget
{
    public:
        Tank(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, szamw* szog_, szamw* ero_, kivalw* bullet_, int jatekos_);
        virtual ~Tank();

        virtual void draw();

        virtual void handle(event ev);

        bool ifeletben() {return eletben;}
        void seteletben(bool a) {eletben = a;}

        bool hit(int,int);

        szamw* szog;
        szamw* ero;
        kivalw* bullet;

        int getx() {return x;}
        int gety() {return y;}

    protected:
        int jatekos;

        bool eletben;

    private:
};

#endif // TANK_HPP
