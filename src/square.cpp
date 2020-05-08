#include <cmath>
float square(int i, const float PI, float** a)
{
    //вычисление площади
    a[i][3] = PI * (pow(a[i][2], 2));
    return a[i][3];
}
