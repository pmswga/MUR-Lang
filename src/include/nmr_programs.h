#ifndef NMR_PROGRAMS_H_INCLUDED
#define NMR_PROGRAMS_H_INCLUDED

#include "nmr.h"

namespace NMR_PROGS {

int _min(int x, int y)
{
    int r[3] = {x, y, 0};
    NMR nmr(r, 3);

    int state = 1;
    while (state != 6)
    {
        switch (state)
        {
        case 1:
            {
                if (nmr.J(1, 3)) {
                    state = 6;
                } else {
                    state = 2;
                }
            } break;
        case 2:
            {
                if (nmr.J(2, 3)) {
                    state = 5;
                } else {
                    state = 3;
                }
            } break;
        case 3:
            {
                nmr.S(3);
                state = 4;
            } break;
        case 4:
            {
                if (nmr.J(1, 1)) {
                    state = 1;
                }
            } break;
        case 5:
            {
                nmr.T(2, 1);
                state = 6;
            } break;
        case 6:
            {
                return nmr.R(1);
            } break;
        }
    }

    return nmr.R(1);
}



}

#endif // NMR_PROGRAMS_H_INCLUDED
