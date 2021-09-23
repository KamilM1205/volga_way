#include "gui/utils.h"

double translate(double x, double in_min, double in_max, double out_min, double out_max)
{
    double num = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    if (num < 0)
        num*=-1;
    return num;
}