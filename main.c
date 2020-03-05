#include <clocale>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

typedef int c_characters[3];

int Count(string enter)
{
    int counter = 0;
    int temp = enter.find("circle(");
    while (temp >= 0) {
        counter++;
        int p = enter.find_first_of("(");
        enter.erase(0, p + 1);
        string c = "";
        c.append(enter.substr(0, 1));
        enter.erase(0, 1);

        int f = c.find_first_of(")");

        while (f < 0) {
            c.append(enter.substr(0, 1));
            enter.erase(0, 1);
            f = c.find_first_of(")");
        }
        int comma = c.find_first_of(",");

        c.erase(f);

        f = c.find_first_of(" ");
        temp = enter.find("circle(");
    }
    return counter;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    string enter;
    getline(cin, enter);
    int x, y, r, i = 0;
    c_characters* mas;
    int razmer = Count(enter);
    int temp = enter.find("circle(");
    mas = new c_characters[razmer];

    while (razmer - i > 0) {
        int p = enter.find_first_of("(");
        enter.erase(0, p + 1);
        string c = "";
        c.append(enter.substr(0, 1));
        enter.erase(0, 1);

        int f = c.find_first_of(")");

        while (f < 0) {
            c.append(enter.substr(0, 1));
            enter.erase(0, 1);
            f = c.find_first_of(")");
        }
        int comma = c.find_first_of(",");

        c.erase(f);

        f = c.find_first_of(" ");

        string xstr = "";
        string ystr = "";
        string rstr = "";
        rstr.append(c.substr(comma + 1));
        xstr.append(c.substr(0, f));
        ystr.append(c.substr(f + 1, comma));

        r = atoi(rstr.c_str());
        x = atoi(xstr.c_str());
        y = atoi(ystr.c_str());

        mas[i][0] = x;
        mas[i][1] = y;
        mas[i][2] = r;
        i++;

        temp = enter.find("circle(");
    }
    cout << endl;
    for (int u = 0; u < i; u++) {
        for (int h = 0; h < 3; h++) {
            cout << mas[u][h] << " ";
        }
        cout << endl;
        cout << endl;
    }

    for (int u = 0; u < i; u++) {
        double per, sq;
        per = 2 * mas[u][2] * 3.1415;
        sq = 3.1415 * mas[u][2] * mas[u][2];
        cout << u + 1 << " êðóã " << mas[u][0] << " " << mas[u][1] << endl;
        cout << "Ïåðèìåòð = " << per << endl;
        cout << "Ïëîùàäü = " << sq << endl;
        for (int g = 0; g < i; g++) {
            int rast, sumR;
            if (g == u)
                g++;
            if (g == i)
                break;
            rast
                    = sqrt(pow(mas[u][0] - mas[g][0], 2)
                           + pow(mas[u][1] - mas[g][1], 2));
            sumR = mas[u][2] + mas[g][2];
            if (rast <= sumR) {
                cout << "Ïåðåñåêàåòñÿ ñ " << g + 1 << " êðóãîì" << endl;
            } else {
                cout << "Íå ïåðåñåêàåòñÿ ñ " << g + 1 << " êðóãîì" << endl;
            }
        }
        cout << endl << endl;
    }
    return 0;
}
