#ifndef SZAMW_HPP
#define SZAMW_HPP

#include "graphics.hpp"
#include "widget.hpp"

using namespace genv;
using namespace std;

class szamw : public Widget
{
    public:
        szamw(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int szam, int miin, int maax, int jatekos_);
        virtual ~szamw();

        virtual void draw();

        virtual void handle(event ev);

        virtual bool is_checked() ;

        int getszam() { return _szam; };


    protected:
        int _szam, _miin, _maax, jatekos;
        bool _checked;

    private:
};

#endif // SZAMW_HPP
