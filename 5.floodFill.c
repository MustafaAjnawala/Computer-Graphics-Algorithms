#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
// #include "bresen.cpp"

struct queue
{
    int x,y;
    struct queue *next;
};
typedef struct queue Node;
Node *p,*head=NULL,*end,*neww;

Node *create(int x, int y)
{
    Node *temp;
    temp = static_cast<Node *>(malloc(sizeof(Node)));
    if(temp==NULL){
        printf("Memory not allocated");
        exit(0);
    } else{
        temp->x = x;
        temp->y=y;
        temp->next=NULL;
    }
    return temp;
}

void addQ(int x, int y)
{
    neww = create(x,y);
   if(head==NULL)
   {
       head= neww;
   }
   else{
       p=head;
       while(p->next!=NULL)
           p=p->next;
       p->next = neww;
   }
}

Node *delQ()
{
    p=head;
    head = p->next;
    p->next=NULL;
    return(p);
}

int inQueue(int x, int y){
    p=head;
    while(p!=NULL){
        if(p->x==x && p->y==y){
            return(1);
        }
        p=p->next;
    }
    return(0);
}

int queueEmpty(){
    if(head== NULL)
        return 1;
    else
        return 0;
}

void Bfill_Recur(int x, int y)
{
    int col;

    col = getpixel(x,y); //so it will put 0 into col as (black=0)

    if(col==0)
    {
        putpixel(x,y,1);
        Bfill_Recur(x+1,y);
        Bfill_Recur(x-1,y);
        Bfill_Recur(x,y+1);
        Bfill_Recur(x,y-1);
    }
}

void Flood_fill(int xP,int yP,int putCol)
{
    int screenCol;
    Node *current_pixel;
    addQ(xP,yP);
    do {
        current_pixel = delQ();
        screenCol = getpixel(current_pixel->x,current_pixel->y);

        if(screenCol==0) {
            putpixel(current_pixel->x, current_pixel->y, putCol);
           //now checking the 4 connected pixels
            if (getpixel(current_pixel->x + 1, current_pixel->y) == 0 && inQueue(current_pixel->x + 1, current_pixel->y) == 0)
                //if right wala pixel BgCol && not already in queue
                addQ(current_pixel->x + 1,current_pixel->y);
            
            if (getpixel(current_pixel->x - 1, current_pixel->y) == 0 && inQueue(current_pixel->x - 1, current_pixel->y) == 0)
                addQ(current_pixel->x - 1,current_pixel-> y);
            
            if (getpixel(current_pixel->x, current_pixel->y + 1) == 0 && inQueue(current_pixel->x, current_pixel->y+1) == 0)
                addQ(current_pixel->x, current_pixel->y + 1);
            
            if (getpixel(current_pixel->x, current_pixel->y - 1) == 0 && inQueue(current_pixel->x,current_pixel->y-1) == 0)
                addQ(current_pixel->x, current_pixel->y - 1);
        }

    } while (queueEmpty()==0);//run till queue is not empty

}


int main() {
    initwindow(640,480);

    //drawing the square
    line(100, 100, 200, 100);
    line(200, 100, 200, 200);
    line(200, 200, 100, 200);
    line(100, 200, 100, 100);


    // Bfill_Recur(150,150);
    // cleardevice();
    Flood_fill(150,150,1);

    getch();
    closegraph();
    return 0;
}
