#include <iostream>
using namespace std;

// nhap vao cay nhi phan cac so nguyen suat ra man hinh 
// khai bao cau truc 1 node
struct Node {
    int data;  // du lieu node luu tru
    Node* left; // cay con trai
    Node* right; // cay con phai
};

typedef struct Node* TREE;

// khoi tao cay
TREE makeTree(int x) {
    TREE tmp = new Node();
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
// them mot phan tu x vao cay 
void insert(TREE& t, int x) {
    if (t == NULL) {
        TREE p = makeTree(x);
        t = p;
    }
    else {
        if (x > t->data) {
            insert(t->right, x);
        }
        else if (x < t->data) {
            insert(t->left, x);
        }
    }
}
// duyet cay NLR
void duyet_NLR(TREE t) {
    if (t != NULL) {
        cout << t->data << " ";
        duyet_NLR(t->left);
        duyet_NLR(t->right);
    }
}
int main()
{
    TREE tree = NULL;
    string luachon;
    while (1) {
        system("cls");
        cout << "------------------------------------------------\n";
        cout << "1. them mot phan tu x vao cay\n";
        cout << "2. duyet cay NLR\n";
        cout << "3. thoat\n";
        cout << "khac: nhap lai\n";
        cout << "------------------------------------------------\n";
        cout << "nhap lua chon: ";
        cin >> luachon;

        if (luachon == "1") {
            int x;
            cout << "nhap x: ";
            cin >> x;
            insert(tree, x);
        }
        else if (luachon == "2") {
            duyet_NLR(tree);
            system("pause");
        }
        else if (luachon == "3") {
            break;
        }
        else {
            continue;
        }
    }

    return 0;
}