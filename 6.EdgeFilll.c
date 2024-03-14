#include "cstdio"
#include <cstdlib>
#include <iostream>
#include <graphics.h>

struct points {
    int x, y;
    points* next;
};
typedef struct points Node;
Node* head1 = nullptr, *head2 = nullptr, *head3 = nullptr;

Node* createNode(int x, int y) {
    Node* neww = new Node;

    neww->x = x;
    neww->y = y;
    neww->next = nullptr;
    return neww;
}

void addNode(Node*& head, int x, int y) {
    if (head == nullptr) {
        head = createNode(x, y);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(x, y);
    }
}

void bresenham(int x1, int y1, int x2, int y2, int col, Node*& head) {
    int dx, dy, G;
    int sign_x = 1, sign_y = 1;

    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    G = (2 * dy) - dx;

    if (y2 < y1)
        sign_y = -1;

    if (dx > dy) {
        while (x1 <= x2) {
            putpixel(x1, y1, col);
            addNode(head, x1, y1);
            if (G >= 0) {
                y1 += sign_y;
                G = G + 2 * (dy - dx);
            } else {
                G = G + (2 * dy);
            }
            x1++;
        }
    } else {
        while (y1 != y2) {
            putpixel(x1, y1, col);
            addNode(head, x1, y1);
            if (G >= 0) {
                x1++;
                G = G + 2 * (dx - dy);
            } else {
                G = G + (2 * dx);
            }
            y1 += sign_y;
        }
    }
}

void rightFill(Node* head, int fillCol) {
    Node* current = head;
    while (current != nullptr) {
        int x = current->x;
        int y = current->y;

        for (int i = x; i <= 640; i++) {
            if (getpixel(i, y) == 0) {
                putpixel(i, y, fillCol);
            } else if (getpixel(i, y) == fillCol) {
                putpixel(i, y, 0);
            }
        }
        current = current->next;
    }
}

void freeMem(Node*& head) {
    Node* p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        p->next = nullptr;
        free(p);
    }
}

int main() {
    initwindow(640, 480);

    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 100;
    int x3 = 200, y3 = 300;

    bresenham(x1, y1, x2, y2, 1, head1);
    bresenham(x2 + 1, y2 - 1, x3, y3, 1, head2);
    bresenham(x3 - 1, y3 + 1, x1 - 1, y1 + 1, 1, head3);

    rightFill(head1, 2);
    rightFill(head2, 2);
    rightFill(head3, 2);

    freeMem(head1);
    freeMem(head2);
    freeMem(head3);

    getch();
    return 0;
}
