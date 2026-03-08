#include <stdio.h>
#include <math.h>
typedef struct point {
    double x;
    double y;
} Point;

int main(int argc, char *argv[]) {
    Point p;
    p.x = 12;
    p.y = 15;
    printf("La distance entre les points est de : %lf",distance(p,q));
}

double distance(double p, double q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y; 
    
}