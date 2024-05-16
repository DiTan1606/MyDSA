#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode* left;
    TNode* right;
};

typedef TNode* Tree;

Tree CreateTNode(int x) {
    Tree newTree = new TNode();
    newTree->data = x;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

void insertTNode(Tree& t, int x) {
    Tree newTree = CreateTNode(x);
    if (t == NULL) {
        t = newTree;
    }
    else {
        if (x == t->data) {
            return;
        }
        else if (x < t->data) {
            insertTNode(t->left, x);
        }
        else if (x > t->data) {
            insertTNode(t->right, x);
        }
    }
}

void preorder_NLR(Tree t) {
    if (t != NULL) {
        cout << t->data << " ";
        preorder_NLR(t->left);
        preorder_NLR(t->right);
    }
}

void preorder_NRL(Tree t) {
    if (t != NULL) {
        cout << t->data << " ";
        preorder_NRL(t->right);
        preorder_NRL(t->left);
    }
}

void inorder_LNR(Tree t) {
    if (t != NULL) {
        inorder_LNR(t->left);
        cout << t->data << " ";
        inorder_LNR(t->right);
    }
}

void inorder_RNL(Tree t) {
    if (t != NULL) {
        inorder_RNL(t->right);
        cout << t->data << " ";
        inorder_RNL(t->left);
    }
}

void postorder_LRN(Tree t) {
    if (t != NULL) {
        postorder_LRN(t->left);
        postorder_LRN(t->right);
        cout << t->data << " ";
    }
}

void postorder_RLN(Tree t) {
    if (t != NULL) {
        postorder_RLN(t->right);
        postorder_RLN(t->left);
        cout << t->data << " ";
    }
}

Tree SearchTNodeX(Tree t, int x) {
    if (t == NULL) {
        return NULL;
    }
    else {
        if (x == t->data) {
            return t;
        }
        else if (x < t->data) {
            SearchTNodeX(t->left, x);
        }
        else if (x > t->data) {
            SearchTNodeX(t->right, x);
        }
    }
}
int CountTNode(Tree t) {
    if (t == NULL) {
        return 0;
    }
    else {
        int a = CountTNode(t->left);
        int b = CountTNode(t->right);
        return a + b + 1;
    }
}
int CountLeavesTNode(Tree t) {
    if (t == NULL) {
        return 0;
    }
    else if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    else {
        int a = CountLeavesTNode(t->left);
        int b = CountLeavesTNode(t->right);
        return a + b;
    }
}
int CountHaveOnlyOneChildTNode(Tree t) {
    if (t == NULL) {
        return 0;
    }
    int count = 0;
    if (t->left == NULL && t->right != NULL) {
        count = 1;
    }
    else if (t->left != NULL && t->right == NULL) {
        count = 1;
    }
    int a = CountHaveOnlyOneChildTNode(t->left);
    int b = CountHaveOnlyOneChildTNode(t->right);
    return count + a + b;
}
int CountHaveTwoChildTNode(Tree t) {
    if (t == NULL) {
        return 0;
    }
    int count = 0;
    if (t->left != NULL && t->right != NULL) {
        count = 1;
    }
    int a = CountHaveTwoChildTNode(t->left);
    int b = CountHaveTwoChildTNode(t->right);
    return count + a + b;
}
int CountTNodeChan(Tree t) {
    if (t == NULL) {
        return 0;
    }
    int count = 0;
    if (t->data %2 == 0) {
         count = 1;
    }
    int a = CountTNodeChan(t->left);
    int b = CountTNodeChan(t->right);
    return count + a + b;
}
int CountTNodeLaChan(Tree t) {
    if (t == NULL) {
        return 0;
    }
    else if (t->left == NULL && t->right == NULL && t->data % 2 == 0) {
        return 1;
    }
    else {
        int a = CountTNodeLaChan(t->left);
        int b = CountTNodeLaChan(t->right);
        return a + b;
    }
}


int Height(Tree t) {
    if (t == NULL) {
        return 0;
    }
    else {
        int a = Height(t->left);
        int b = Height(t->right);
        return (a > b ? a : b) + 1;
    }
}

bool KTSNT(int x) {
    if (x < 2) {
        return false;
    }
    else {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int tongCacTNodeTrongCay(Tree t) {
    int tong = 0;
    if (t == NULL) {
        return 0;
    }
    else {
        tong = t->data;
    }
    int a = tongCacTNodeTrongCay(t->left);
    int b = tongCacTNodeTrongCay(t->right);
    return tong + a + b;
}

int tongCacNodeCoDungMotCon(Tree t) {
    int tong = 0;
    if (t == NULL) {
        return 0;
    }
    else if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) {
        tong = t->data;
    }
    int a = tongCacNodeCoDungMotCon(t->left);
    int b = tongCacNodeCoDungMotCon(t->right);
    return tong + a + b;
}
int tongCacNodeCoDungMotConVaLaSoNT(Tree t) {
    int tong = 0;
    if (t == NULL) {
        return 0;
    }
    else if (((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) && KTSNT(t->data)) {
        tong = t->data;
    }
    int a = tongCacNodeCoDungMotConVaLaSoNT(t->left);
    int b = tongCacNodeCoDungMotConVaLaSoNT(t->right);
    return tong + a + b;
}

void TheMang(Tree& tmp, Tree& y) {
    if (y->left != NULL) {
        TheMang(tmp, y->left);
    }
    else {
        tmp->data = y->data;
        tmp = y;
        y = y->right;
    }
}
void DeleteTNodeX(Tree& t, int x) {
    if (t == NULL) {
        cout << "Khong co " << x << endl;
        return;
    }
    else {
        if (x < t->data) {
            DeleteTNodeX(t->left, x);
        }
        else if (x > t->data) {
            DeleteTNodeX(t->right, x);
        }
        else {
            Tree tmp = t;
            if (t->left == NULL) {
                t = t->right;
            }
            else if (t->right == NULL) {
                t = t->left;
            }
            else {
                Tree y = t->right;
                TheMang(tmp, y);
            }
            delete tmp;
        }
    }
}

bool KTHaiCayGiongNhau(Tree t1, Tree t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if (t1 == NULL && t2 != NULL) {
        return false;
    }
    if (t1 != NULL && t2 == NULL) {
        return false;
    }
    if (t1->data != t2->data) {
        return false;
    }
    return KTHaiCayGiongNhau(t1->left, t2->left) && KTHaiCayGiongNhau(t1->right, t2->right);
}

int main()
{
    Tree t = NULL;
    Tree t1 = NULL;

    int a[] = { 3,5,20,11,31,9,18,4,35,2,1 };

    for (int x : a) {
        insertTNode(t, x);
    }
    for (int x : a) {
        insertTNode(t1, x);
    }

    preorder_NLR(t); cout << endl;
    preorder_NRL(t); cout << endl;
    inorder_LNR(t); cout << endl;
    inorder_RNL(t); cout << endl;
    postorder_LRN(t); cout << endl;
    postorder_RLN(t); cout << endl;

    int x;
    cout << "Tim node co khoa bang x: ";
    cin >> x;
    if (SearchTNodeX(t, x)) {
        cout << x << " ton tai \n";
    }
    else {
        cout << x << " khong ton tai \n";
    }

    cout << "so TNode trong cay: " << CountTNode(t) << endl;
    cout << "so TNode la trong cay: " << CountLeavesTNode(t) << endl;
    cout << "so TNode chi co mot con trong cay: " << CountHaveOnlyOneChildTNode(t) << endl;
    cout << "so TNode co ca hai con trong cay: " << CountHaveTwoChildTNode(t) << endl;
    cout << "so TNode chan: " << CountTNodeChan(t) << endl;
    cout << "so TNode la chan: " << CountTNodeLaChan(t) << endl;
    cout << "tong cac node trong cay: " << tongCacTNodeTrongCay(t) << endl;
    cout << "tong cac node co dung mot con: " << tongCacNodeCoDungMotCon(t) << endl;
    cout << "tong cac node co dung mot con va la so nguyen to: " << tongCacNodeCoDungMotConVaLaSoNT(t) << endl;
    cout << "chieu cao cua cay: " << Height(t) << endl;
    int c;
    cout << "Xoa node co khoa bang c: "; cin >> c;
    DeleteTNodeX(t, c);
    preorder_NLR(t);
    cout << endl;
    if (KTHaiCayGiongNhau(t, t1)) {
        cout << "giong nhau";
    }
    else {
        cout << "khong giong nhau";
    }
}
