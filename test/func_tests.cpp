#define CATCH_CONFIG_MAIN
#include "calc.h"
#include "per.h"
#include "square.h"
#include <catch.hpp>
#include <math.h>

TEST_CASE("sq_pass", "test1")
{
    float **a, n;
    const float PI = 3.14;
    a = new float*[5];
    bool q;
    int i = 1;
    for (int w = 0; w < 5; w++)
        a[w] = new float[5];
    a[i][2] = 1;
    n = square(i, PI, a);
    if (n == 3.14)
        q = true;
    REQUIRE(q == false);
}

TEST_CASE("per_pass1", "test1")
{
    float **a, n;
    const float PI = 3.14;
    a = new float*[5];
    for (int w = 0; w < 5; w++)
        a[w] = new float[5];
    int i = 1;
    bool q;
    a[i][2] = 1;
    n = per(i, a, PI);
    if (n == 6.28)
        q = true;
    REQUIRE(q == false);
}

TEST_CASE("per_pass2", "test2")
{
    float **a, n;
    const float PI = 3.14;
    a = new float*[5];
    for (int w = 0; w < 5; w++)
        a[w] = new float[5];
    int i = 1;
    bool q;
    a[i][2] = 2;
    n = per(i, a, PI);
    if (n == 12.56)
        q = true;
    REQUIRE(q == false);
}

TEST_CASE("calc_pass1", "test1")
{
    float** a;
    a = new float*[5];
    for (int w = 0; w < 5; w++)
        a[w] = new float[5];
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

TEST_CASE("calc_pass2", "test2")
{
    float** a;
    a = new float*[5];
    for (int w = 0; w < 5; w++)
        a[w] = new float[5];
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
