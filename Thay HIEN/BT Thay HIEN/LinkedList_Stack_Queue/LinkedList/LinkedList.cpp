#include <iostream>
using namespace std;

// CTDL cua 1 node trong list don
struct NODE {
    int data;
    NODE* next;
};

// CTDL cua 1 list
typedef struct NODE* node;

// kt rong
bool isEmpty(node a) {
    return a == NULL;
}
 
// kich thuoc
int size(node a) {
    int dem = 0;
    while (a != NULL) {
        dem++;
        a = a->next;
    }
    return dem;
}

// tao node
node createNode(int x) {
    node p = new NODE;
    if (p == NULL) exit(-1);
    p->data = x;
    p->next = NULL;
    return p;
}

// chen vao truoc
void insertFirst(node& a, int x) {
    node tmp = createNode(x);
    if (a == NULL) {
        a = tmp;
    }
    else {
        tmp->next = a;
        a = tmp;
    }
}

// chen vao sau
void insertLast(node& a, int x) {
    node tmp = createNode(x);
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

// chen vao vi tri bat ki
void insertMid(node& a, int x, int pos) {
    node tmp = createNode(x);
    int n = size(a);
    if (pos < 1 || pos > n + 1) {
        return;
    }
    else if (pos == 1) {
        insertFirst(a, x);
    }
    else if (pos == n + 1) {
        insertLast(a, x);
    }
    else {
        node p = a;
        for (int i = 1; i < pos-1; i++) {
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
}

// xoa phan tu dau
void deleteFirst(node& a) {
    node p;
    if (a == NULL) {
        return;
    }
    p = a;
    a = a->next;
    delete p;
}

// xoa phan tu o cuoi
void deleteLast(node& a) {
    if (a == NULL) {
        return;
    }
    node truoc = NULL;
    node sau = a;
    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        sau = NULL;
    }
    else {
        truoc->next = NULL;
        delete sau;
    }
}

// xoa phan tu o vi tri bat ki
void deleteMid(node& a, int pos) {
    int n = size(a);
    if (pos < 1 || pos > n + 1) {
        return;
    }
    else if (pos == 1) {
        deleteFirst(a);
    }
    else if (pos == n) {
        deleteLast(a);
    }
    else {
        node truoc = NULL;
        node sau = a;
        for (int i = 1; i < pos; i++) {
            truoc = sau;
            sau = sau->next;
        }
        if (truoc == NULL) {
            sau == NULL;
        }
        else {
            truoc->next = sau->next;
            delete sau;
        }
    }
}

// duyet danh sach
void printList(node a) {
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

// tim kiem
node searchNode(node a, int x) {
    node p = a;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    return p;
}

// xoa toan bo
void clear(node& a) {
    while (a != NULL) {
        node p = a;
        a = a->next;
        delete p;
    }
}

// sap xep danh sach
void selectionSort(node& a) {
    for (node p = a; p->next != NULL; p = p->next) {
        node min = p;
        for (node q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        if (min != p) {
            swap(min->data, p->data);
        }
    }
}

int main()
{
    node list = NULL;
    insertFirst(list, 1);
    insertFirst(list, 5);
    insertFirst(list, 3);
    insertFirst(list, 4);
    insertLast(list, 6);
    insertLast(list, 2);
    insertLast(list, 8);
    insertLast(list, 7);
    printList(list);
    insertMid(list, 100, 3);
    printList(list);
    deleteMid(list, 5);
    printList(list);
    if (searchNode(list, -10)) {
        cout << "tim thay\n";
    }
    else {
        cout << "khon tim thay\n";
    }
    selectionSort(list);
    printList(list);
    clear(list);
    printList(list); cout << "a";
}

