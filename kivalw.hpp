#ifndef KIVALW_HPP
#define KIVALW_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include "Elem.hpp"


using namespace genv;
using namespace std;


class kivalw : public Widget
{
    public:
        kivalw(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_, int db);
        virtual ~kivalw();

        virtual void draw();

        virtual void handle(genv::event ev);

        virtual bool is_checked();

        void add(string a);

        int geth();

        int getv();

    protected:
        int _db, kezd, veg;
        bool _checked, started;
        vector<Elem*> e;

    private:
};

#endif // KIVALW_HPP
