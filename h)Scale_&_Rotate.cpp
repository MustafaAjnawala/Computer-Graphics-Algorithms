//WAP to implememnt 2D scaling & Rotation of a Triangle
#include<cstdio>
#include <cstdlib>
#include<cmath>
#include "graphics.h"

int normx(int x){
    return ((getmaxx()/2)+(x*30));
}

int normy(int y){
    return ((getmaxy()/2)-(y*30));
}

void drawTriangle(double x1,double y1,double x2,double y2,double x3,double y3,int col){
    setcolor(col);
    x1=normx(x1);x2=normx(x2);x3=normx(x3);
    y1=normy(y1);y2=normy(y2);y3=normy(y3);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

void Scale(double *x1,double *y1,double *x2,double *y2,double *x3,double *y3,float sx,float sy){
    *x1 *= sx;*x2 *= sx;*x3 *= sx;
    *y1 *=sy;*y2 *=sy;*y3 *=sy;
}

void rotate(double *x1,double *y1,double *x2,double *y2,double *x3,double *y3,double angle){
    double tempx1,tempx2,tempx3,tempy1,tempy2,tempy3;
    angle = angle * M_PI / 180.0; //changing the degfrees to radians
    tempx1 = (*x1 * cos(angle)) - (*y1 * sin(angle));
    tempy1 = (*x1 * sin(angle)) + (*y1 * cos(angle));
    tempx2 = (*x2 * cos(angle)) - (*y2 * sin(angle));
    tempy2 = (*x2 * sin(angle)) + (*y2 * cos(angle));
    tempx3 = (*x3 * cos(angle)) - (*y3 * sin(angle));
    tempy3 = (*x3 * sin(angle)) + (*y3 * cos(angle));

    *x1 = tempx1;*x2 = tempx2;*x3 = tempx3;
    *y1 = tempy1;*y2 = tempy2;*y3 = tempy3;
}

int main(){
    double x1=0,y1=0,x2=4,y2=0,x3=2,y3=4;
    float sx,sy;
    int TriCol = 4;
    double angle;

    initwindow(640,480);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    printf("enter the coordinates for the vertices of the triangle(V1,V2,V3)\nAccording to the Cartesian plane");
    printf("Each unit equals 20px\n");
//    scanf();
    drawTriangle(x1,y1,x2,y2,x3,y3,TriCol);
    printf("Pls enter the scaling factors in X and Y axis:");
    scanf("%f %f",&sx,&sy);
    Scale(&x1,&y1,&x2,&y2,&x3,&y3,sx,sy);
    drawTriangle(x1,y1,x2,y2,x3,y3,5);

    printf("Now enter the angle of rotation:");
    scanf("%lf",&angle);
    rotate(&x1,&y1,&x2,&y2,&x3,&y3,angle);
    drawTriangle(x1,y1,x2,y2,x3,y3,6);


    getch();
    closegraph();
    return 0;
}
