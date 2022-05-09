#include "Hopehely.hpp"

Hopehely::Hopehely(int x, int y) : x_(x), y_(y)
{
    //ctor
}

Hopehely::~Hopehely()
{
    //dtor
}



void Hopehely::rajzol()
{
    gout << move_to(x_, y_) << color(255, 255, 255) << dot;
}

void Hopehely::mozog(int dx, int dy)
{
    x_ = (x_ + dx + 1500) % 1500;
    y_ = (y_ + dy) % 800;
}
