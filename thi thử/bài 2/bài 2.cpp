#include <iostream>
#include <cmath>

using namespace std;

struct Diem {
    double x, y, z;
    void nhap() {
        cin >> x >> y >> z;
    }
    bool sosanh(Diem d2) {
        return (x == d2.x && y == d2.y && z == d2.z);
    }
};

struct NODE {
    Diem data;
    NODE* next;
};

typedef NODE* node;

node createNode(Diem d) {
    node newNode = new NODE();
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void insertLast(node& a, Diem d) {
    node tmp = createNode(d);
    if (a == NULL) {
        a = tmp;
    }
    else {
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

int timkiem(node a, Diem d) {
    int index = 0;
    while (a != NULL) {
        if (a->data.sosanh(d)) {
            return index;
        }
        a = a->next;
        index++;
    }
    return -1; // Không tìm thấy
}

void run() {
    node list = NULL;
    node list2 = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Diem d;
        d.nhap();
        insertLast(list, d);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        Diem d2;
        d2.nhap();
        insertLast(list2, d2);
    }

    node p2 = list2;
    while (p2 != NULL) {
        int result = timkiem(list, p2->data);
        if (result == -1) {
            cout << "KHONG" << endl;
        }
        else {
            cout << result << endl;
        }
        p2 = p2->next;
    }
}

int main() {
    run();
    return 0;
}
