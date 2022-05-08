#include "application.hpp"
#include "scrolltext.hpp"
#include "graphics.hpp"
#include "widgets.hpp"



using namespace genv;
using namespace std;

Application::Application(int W_, int H_) : W(W_), H(H_)
{
    gout.load_font("LiberationSans-Regular.ttf",20);
    gout.open(W_, H_);
    gout << refresh;
}

void Application::clearscreen()
{
    gout << color(0,0,0);
    gout << move_to(0,0);
    gout << box(W,H);
}

void Application::feltolt(Widget* widget)
{
    widgets.push_back(widget);
}

void Application::fel(Widgets* widg)
{
    widgs.push_back(widg);
}

void Application::event_loop()
{
    event ev;
    while (gin >> ev && ev.keycode != key_escape)
    {
        for (size_t i = 0; i < widgets.size(); i++)
            widgets[i]->handle(ev);
        clearscreen();
        for (size_t i = 0; i < widgets.size(); i++)
            widgets[i]->draw();





        for (size_t i = 0; i < widgs.size(); i++)
            widgs[i]->handle(ev);
        //clearscreen();
        for (size_t i = 0; i < widgs.size(); i++)
            widgs[i]->draw();


        gout << refresh;
    }
}
