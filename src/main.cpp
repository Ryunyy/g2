#include "calc.h"
#include "cordy.h"
#include "per.h"
#include "rad.h"
#include "square.h"
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
const float PI = 3.14;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n, i, j, c = 0;
    float **a, t, p;
    cout << "Введите количество окружностей: " << endl;
    cin >> n;
    a = new float*[n];
    for (i = 0; i < n; i++) {
        a[i] = new float[5];
        cout << endl << "Введите характеристики окружности №" << i + 1 << endl;
    q:
        cout << "Координата (x) окружности в диапазоне от -50 до 50" << endl;
        cin >> a[i][0];
        if (cordy(a, i, 0))
            continue;
        else {
            cout << "Введите координату корректно" << endl;
            goto q;
        }
    e:
        cout << "Координата (y) окружности в диапазоне от -50 до 50" << endl;
        cin >> a[i][1];
        if (cordy(a, i, 1))
            continue;
        else {
            cout << "Введите координату корректно" << endl;
            goto e;
        }
    m:
        cout << "Радиус окружности в диапазоне от 1 до 10" << endl;
        cin >> a[i][2];
        if (rad(a, i))
            continue;
        else {
            cout << "Введите радиус корректно" << endl;
            goto m;
        }
    }
    cout << endl;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            t = c;
            p = calc(i, j, a, c);
            if (p != t) {
                cout << "Окружности №" << i + 1 << " и №" << j + 1
                     << " пересекаются" << endl;
                c++;
            }
        }
    if (c == 0)
        cout << "Пересекающихся окружностей не найдено" << endl;
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << "Характерисики окружности №" << i + 1 << ":" << endl;
        cout << "Координаты центра: (" << a[i][0] << "," << a[i][1] << ")"
             << endl;
        cout << "Радиус: " << a[i][2] << endl;
        cout << "Площадь: " << square(i, PI, a) << endl;
        cout << "Периметр: " << per(i, a, PI) << endl;
        cout << endl;
    }
}
