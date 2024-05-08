#include <iostream>
#include <queue>
using namespace std;

/*
Queue: hang doi: FIFO (First in First out)
queue<int> p
push(value) day pt vao cuoi queue
empty()
size()
front(): tra ve gia tri dau queue
back(): tra ve gia tri cuoi queue
pop(): xoa hang tu dau queue
duyet:
    while (p.empty() == 0) {
        cout << p.top();
        p.pop();
    }
**** O(1) ****

priority_queue
priority_queve<int> pq
*/

int main()
{
    queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    pq.push(5);
    while (pq.empty() == 0) {
        cout << pq.front();
        pq.pop();
    }
}

