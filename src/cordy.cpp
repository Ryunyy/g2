#include <cmath>
int cordy(float** a, int i, int j)
{
    float z;
    z = std::abs(a[i][j]);
    if (z <= 50)
        return 1;
    else
        return 0;
}
