float per(int i, float** a, const float PI)
{
    //вычисление периметра
    a[i][4] = 2 * PI * a[i][2];
    return a[i][4];
}
