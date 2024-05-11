#include <iostream>
using namespace std;

// CTDL Stack tao boi Single Linked List
struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;

// sử dụng SLL để mô phỏng lại các hàm trong thư viện stack

// empty()
bool empty(node top) {
    return top == NULL;
}

// size()
int size(node top) {
    int cnt = 0;
    while (top != NULL) {
        cnt++;
        top = top->next;
    }
    return cnt;
}

// tao not
node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
 
// push(int x)
void push(node& top, int x) {
    node tmp = makeNode(x);
    if (top == NULL) {
        top = tmp;
    }
    else {
        tmp->next = top;
        top = tmp;
    }
}

// pop()
void pop(node& top) {
    if (top == NULL) return;
    else {
        top = top->next;
    }
}

// top()
int getTop(node top) {
    return top->data;
}

// dùng stack giải bài toán đổi số thập phân -> nhị phân
void decToBin(node &stack, int n) {
    while (n) {
        push(stack, n % 2);
        n /= 2;
    }
    while (empty(stack) != 1) {
        cout << getTop(stack);
        pop(stack);
    }
}

int main()
{
    int n;
    cin >> n;
    node stackList = NULL;
    decToBin(stackList, n);
}
