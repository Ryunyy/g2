#define CATCH_CONFIG_MAIN
#include "calc.h"
#include "ctest.h"
#include "math.h"
#include "per.h"
#include "square.h"

TEST_CASE("sq_pass", "test1")
{
    float** a;
    const double PI = 3.14;
    a = new float*[5];
    int i = 1, n = 0;
    a[i][2] = 4;
    if (PI * (pow(a[i][2], 2)) == square(i, PI, a))
        n = 1;
    REQUIRE(n == 1);
}

TEST_CASE("per_pass", "test1")
{
    float** a;
    const double PI = 3.14;
    a = new float*[5];
    int i = 1, n = 0;
    a[i][2] = 4;
    if (PI * (pow(a[i][2], 2)) == per(i, PI, a))
        n = 1;
    REQUIRE(n == 0);
}

TEST_CASE("per_pass", "test1")
{
    float** a;
    const double PI = 3.14;
    a = new float*[5];
    int i = 1, n = 0;
    a[i][2] = 4;
    if ((2 * PI * a[i][2]) == (per(i, PI, a)))
        n = 1;
    REQUIRE(n == 1);
}

TEST_CASE("calc_pass", "test1")
{
    float** a;
    a = new float*[5];
    int i = 1, j = 3, c = 0, n;
    a[i][0] = 0;
    a[i][1] = 0;
    a[j][0] = 0;
    a[j][1] = 0;
    a[i][2] = 3;
    a[j][2] = 5;
    n = calc(i, j, a, c);
    REQUIRE(n == 1);
}

TEST_CASE("calc_pass", "test2")
{
    float** a;
    a = new float*[5];
    int i = 1, j = 3, c = 0, n;
    a[i][0] = 0;
    a[i][1] = 0;
    a[j][0] = 10;
    a[j][1] = 10;
    a[i][2] = 3;
    a[j][2] = 5;
    n = calc(i, j, a, c);
    REQUIRE(n == 0);
}
