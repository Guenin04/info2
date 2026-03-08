#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    /*
    //notation pas utilisée car duplication

    struct {double x; double y;} p = {23,42};
    struct {double x; double y;} q = {3,-5};
    printf("%lf %lf\n",p.x,p.y);

    //pas utilisation car pas allegé

    struct point {double x; double y;};
    struct point r = {1,2};
    struct point s = {1,2};
    */

    typedef long double test;
    test p = 3.141592;

    /*
    typedef int number;
    number add (int a, int b) {return a+b;}
    */

    typedef struct point {double x; double y;} Point;

    Point point;

}