#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "application.hpp"
#include "graphics.hpp"

class Widget
{
protected:
    int x;
    int y;
    int size_x;
    int size_y;
    int frame_size;
    Application* parent;
public:
    Widget(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_HPP
