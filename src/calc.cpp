#include <cmath>
#include <math.h>
int calc(int i, int j, float** a, int c)
{
    float x, y, R;
    //исследование на пересечение окружностей i и j
    x = abs(a[i][0] - a[j][0]);
    y = abs(a[i][1] - a[j][1]);
    R = a[i][2] + a[j][2];
    if ((x < R) && (y < R))
        c++;
    return c;
}
