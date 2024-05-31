#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void move(int j, int h, int &x,int &y)
{
    if(j==1)
        y-=h;
    else
    if(j==2)
        x+=h;
    else if(j==3)
        y+=h;
    else if(j==4)
        x-=h;
    lineto(x,y);
}
void hilbert(int r,int d,int l ,int u,int i,int h,int &x,int &y)
{
    if(i>0)
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}

void koch(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60*M_PI/180;
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;

    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;

    int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

    if(it > 0)
    {
        koch(x1, y1, x3, y3, it-1);
        koch(x3, y3, x, y, it-1);
        koch(x, y, x4, y4, it-1);
        koch(x4, y4, x2, y2, it-1);
    }
    else
    {

        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main()
{
    int n,ch,ctr=0;
    int driver=DETECT,mode=0;
    int x0=50,y0=50,x,y,h=10,r=2,d=3,l=4,u=1;
    int x1 = 100, y1 = 100, x2 = 400, y2 = 400;
    do {
        printf("MENU :\n1.HILBERT Curve\n2.Triadic Koch Curve\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:

                cout << "enter the number of iterations=";
                cin >> n;
                x = x0;
                y = y0;

                initgraph(&driver, &mode, NULL);
                moveto(x, y);
                hilbert(r, d, l, u, n, h, x, y);
//delay(10000);

                break;
            case 2:
                initgraph(&driver, &mode, NULL);

                printf("Enter the number of iterations: ");
                scanf("%d", &n);
                koch(x1, y1, x2, y2, n - 1);

        }
        getch();
        printf("continue?(1/0)=");
        scanf("%d", &ctr);
        closegraph();
    }while(ctr==1);

    return 0;
}
