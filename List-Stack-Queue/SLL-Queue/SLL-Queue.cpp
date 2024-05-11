#include <iostream>
using namespace std;

// CTDL Queue tao boi SLL
// back: phan tu dau
// front: phan tu cuoi
struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;

node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

int size(node back) {
    int cnt = 0;
    while (back != NULL) {
        cnt++;
        back = back->next;
    }
    return cnt;
}

bool empty(node back) {
    return back == NULL;
}
// back: cuoi hang doi = dau list
int getBack(node back) {
    return back->data;
}
// front: dau hang doi = cuoi list
int getFront(node back) {
    while (back->next != NULL) {
        back = back->next;
    }
    return back->data;
}
// push them mot phan tu vao cuoi hang doi = dau list
void push(node& back, int x) {
    node tmp = makeNode(x);
    tmp->next = back;
    back = tmp;
}
// xoa phan tu dau hang doi = cuoi list
void pop(node& back) {
    node truoc = NULL;
    node sau = back;
    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        back = NULL;
    }
    else {
        truoc->next = NULL;
    }
}

// duyet qua 
void print(node &back) {
    while (empty(back) != 1) {
        cout << getFront(back);
        pop(back);
    }
}

int main()
{
    node queue = NULL;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    print(queue);
}

