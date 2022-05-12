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
        Tank(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, szamw* szog_, szamw* ero_, kivalw* bullet_, int jatekos_, Tank* ellenfel_);
        virtual ~Tank();

        virtual void draw();

        virtual void handle(event ev);

        void loves();

        bool ifeletben() {return eletben;}
        void seteletben(bool a) {eletben = a;}

    protected:
        int jatekos;
        szamw* szog;
        szamw* ero;
        kivalw* bullet;
        bool eletben;
        Tank* ellenfel;

    private:
};

#endif // TANK_HPP
