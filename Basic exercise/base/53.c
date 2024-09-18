#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct Point
{
    float x;
    float y;
    float z;
}Point;


float Distance(Point a,Point b){
    float x=a.x-b.x;
    float y=a.y-b.y;
    float z=a.z-b.z;
    float distance=sqrt(x*x+y*y+z*z);
    return distance;
}

int main() {
    
    return 0;
}