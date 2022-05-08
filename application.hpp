#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>

class Widget;
class Widgets;

class Application
{
protected:
    int W;
    int H;
    std::vector<Widget*> widgets;
    std::vector<Widgets*> widgs;
public:
    Application(int W_, int H_);
    void event_loop();
    void feltolt(Widget* widget);
    void fel(Widgets* wid);
    void clearscreen();
};

#endif // APPLICATION_HPP
