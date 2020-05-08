#include <clocale>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
const float PI = 3.14;
int main()
{
    setlocale(LC_ALL, "RUS");
    int n, i, j;
    float **a, x, y, R, c = 0;
    cout << "Введите количество окружностей: " << endl;
    cin >> n;
    a = new float*[n];
    for (i = 0; i < n; i++) {
        a[i] = new float[5];
        cout << endl << "Введите характеристики окружности №" << i + 1 << endl;
        cout << "Координата (x) окружности" << endl;
        cin >> a[i][1];
        cout << "Координата (y) окружности" << endl;
        cin >> a[i][2];
        cout << "Радиус окружности" << endl;
        cin >> a[i][3];
        a[i][4] = PI * (pow(a[i][3], 2));
        a[i][5] = 2 * PI * a[i][3];
    }
    cout << endl;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            x = abs(a[i][1] - a[j][1]);
            y = abs(a[i][2] - a[j][2]);
            R = a[i][3] + a[j][3];
            if ((x < R) && (y < R)) {
                c++;
                cout << "Окружности №" << i + 1 << " и №" << j + 1
                     << " пересекаются" << endl;
            }
        }
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << "Характерисики окружности №" << i + 1 << ":" << endl;
        cout << "Координаты центра: (" << a[i][1] << "," << a[i][2] << ")"
             << endl;
        cout << "Радиус: " << a[i][3] << endl;
        cout << "Площадь: " << a[i][4] << endl;
        cout << "Периметр: " << a[i][5] << endl;
        cout << endl;
    }
    if (c == 0)
        cout << "Пересекающихся окружностей не найдено" << endl;
}
