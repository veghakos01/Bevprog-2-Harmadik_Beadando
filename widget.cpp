#include "widget.hpp"

Widget::Widget(int x_, int y_, int _size_x, int _size_y, int _frame_size, Application* parent_) :
    x(x_),y(y_),size_x(_size_x),size_y(_size_y), frame_size(_frame_size),parent(parent_)
{
    parent->feltolt(this);
}
