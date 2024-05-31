//20. Write a C Program to show that Reflection about a line Y=X is equivalent to reflection
//relative to X-axis followed by anticlockwise rotation of 90deg
#include<cstdio>
#include <cstdlib>
#include<cmath>
#include "graphics.h"

int reflect_X_Abt_YEqualsX(int x,int y){
    x=y;
    return x;
}
int reflect_Y_Abt_YEqualsX(int x,int y){
    y=x;
    return y;
}
int reflectYAbtX(int y){
    y=-y;
    return y;
}

void rotate(double *x,double *y, double angle){
    double tempx,tempy;
    angle= angle* (M_PI/180);
    tempx = (*x * cos(angle)) - (*y * sin(angle));
    tempy  = (*x * sin(angle)) + (*y * cos(angle));

    *x = tempx;
    *y = tempy;
}
int main(){
    initwindow(640,480);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    int x=1;
    int y=2;
    double angle = 90;
    int lhs_x = reflect_X_Abt_YEqualsX(x,y);
    int lhs_y = reflect_Y_Abt_YEqualsX(x,y);
    double rhs_x= x;
    double rhs_y = reflectYAbtX(y);
    rotate(&rhs_x,&rhs_y,angle);

    printf("result after first transformation(reflection abt Y=X) = %d %d\n",lhs_x,lhs_y);
    printf("result after reflecting abt X and then rotating 90deg = %lf %lf\n",rhs_x,rhs_y);
    printf("Hece Both results are SAME");

    getch();
    closegraph();
    return 0;
}
