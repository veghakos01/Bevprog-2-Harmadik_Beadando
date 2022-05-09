#ifndef HOPEHELY_HPP
#define HOPEHELY_HPP
#include "graphics.hpp"

using namespace genv;
using namespace std;

class Hopehely
{
    public:
        Hopehely(int x, int y);
        virtual ~Hopehely();
        void rajzol();
        void mozog(int dx, int dy);

    protected:
        int x_, y_;

    private:
};

#endif // HOPEHELY_HPP
