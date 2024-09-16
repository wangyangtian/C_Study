#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double Area(double a,double b,double c){
    double p=(a+b+c)/2;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}

int main() {
    printf("%.2f",Area(3,4,5));
    return 0;
}