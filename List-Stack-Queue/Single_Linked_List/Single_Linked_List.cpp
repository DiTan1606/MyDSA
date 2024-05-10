#include <iostream>
using namespace std;

// Single Linked List (Danh sách liên kết đơn) là một tập hợp tuyến tính các phần tử dữ liệu, với thứ tự không được đưa ra bởi vị trí vật lí của chúng trong bộ nhớ.
// Thay vào đó, mỗi phần tử chỉ đến phần tử tiếp theo. 
// Nó là một cấu trúc dữ liệu bao gồm một tập hợp các nút.
// Ở dạng cơ bản nhất, mỗi nút chứa: dữ liệu và một tham chiếu (liên kết) tới nút tiếp theo trong dãy.
// Node = data + pnext 
// data chứa dữ liệu
// pnext chứa vị trí node tiếp theo
//
// ưu điểm: cho phép chèn, xoá bất kì phần tử ở vị trí bất kì một cách hiệu quả. Có thể mở rộng hay thu nhỏ nhờ cơ chế cấp phát động
// Nhược điểm: Thời gian truy cập phần tử là tuyến tính bởi vì k thể truy cập ngay một phần tử, phải đi từ phần tử đầu tiên 
// 
// Để quản lí một danh sách liên kết chỉ cần lưu thông tin của node đầu tiên trong danh sách
//

// Khai báo một node
struct Node {
    int data; // chứa dữ liệu
    Node* next; // liên kết đến node tiếp theo
};

typedef struct Node* node;  

// cấp phát động một node mới với data = x
node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL; //nullptr
    return tmp;
}

// kiểm tra rỗng
bool empty(node a) {
    return a == NULL;
}

// kich thuoc danh sach
int size(node a) {
    int cnt = 0;
    while (a != NULL) {
        ++cnt;
        a = a->next; 
        // gán địa chỉ của node tiếp theo cho node hiện tại
        // cho node hiện tại nhảy sang node tiếp theo
        // tương tự i++ 
    }
    return cnt;
}

// thêm một phần tử có data là x vào đầu danh sách
void insertFirst(node &a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    }
    else {
        tmp->next = a;
        a = tmp;
    }
}

// thêm một phần tử có data là x vào cuối danh sách 
void insertLast(node& a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    }
    else {
        node p = a; // phải tạo một biến thay thế a chứ k được dùng a để duyệt.
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

// thêm một phần tử có data là x vào một vị trí p bất kì
void insertMid(node& a, int x, int pos) {
    int n = size(a);
    // tính từ 1 đến n
    if (pos < 1 || pos > n + 1) {
        cout << "vi tri khong hop le\n";
    }
    else if (pos == 1) {
        insertFirst(a, x);
    }
    else if (pos == n + 1) {
        insertLast(a, x);
    }
    else {
        node p = a;
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        node tmp = makeNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

// Xóa phần tử đầu:
void deleteFirst(node &a) {
    if (a == NULL) return;
    else {
        a = a->next;
    }
}

// Xóa phần tử ở cuối
void deleteLast(node& a) {
    if (a == NULL) return;
    else {
        node truoc = NULL, sau = a;
        while (sau->next != NULL) {
            truoc = sau;
            sau = sau->next;
        }
        if (truoc == NULL) {
            a = NULL;
        }
        else {
            truoc->next = NULL;
        }
    }
}

// xóa một phần tử ở một vị trí p bất kì
void deleteMid(node& a, int pos) {
    int n = size(a);
    if (pos < 1 || pos > n + 1) {
        cout << "pos khong hop le\n";
    }
    else if (pos == 1) {
        deleteFirst(a);
    }
    else if (pos == n + 1) {
        deleteLast(a);
    }
    else {
        node truoc = NULL, sau = a;
        for (int i = 1; i < pos; i++) {
            truoc = sau;
            sau = sau->next;
        }
        truoc->next = sau->next;
    }
}

// Xóa toàn bộ danh sách
void clear(node& a) {
    while (a != NULL) {
        a = a->next;
    }
}

// Tìm kiếm phần tử có giá trị x trong danh sách
// tìm thấy trả về vị trí 
// không tìm thấy trả về -1
int find(node& a, int x) {
    node p = a;
    int n = size(a);
    for (int i = 1; i <= n; i++) {
        if (p->data == x) {
            return i;
        }
        p = p->next;
    }
}

// tim max min cua danh sach
int max(node a) {
    node p = a;
    int max = p->data;
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int min(node a) {
    node p = a;
    int min = p->data;
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

// Xuất danh sách
void print(node a) {
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

// sắp xếp
void sort(node& a) {
    for (node p = a; p->next != NULL; p = p->next) {
        node min = p;
        for (node q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        int tmp = p->data;
        p->data = min->data;
        min->data = tmp;
    }
}

int main()
{
    // cout << sizeof(Node) << endl; // 16
    // kich thuoc 1 con tro 64bit : 8byte
    node head = NULL;
    while (1) {
        cout << "\n-----------------------MENU----------------------\n";
        cout << "1 chen mot phan tu vao dau\n";
        cout << "2 chen mot phan tu vao cuoi\n";
        cout << "3 chen mot phan tu vao vi tri bat ky\n";
        cout << "4 xoa mot phan tu o dau\n";
        cout << "5 xoa mot phan tu o cuoi\n";
        cout << "6 xoa mot phan tu o vi tri bat ky\n";
        cout << "7 xoa toan bo danh sach\n";
        cout << "8 tim kiem\n";
        cout << "9 max\n";
        cout << "10 min\n";
        cout << "11 sap xep\n";
        cout << "12 xuat danh sach\n";
        cout << "13 kich thuoc danh sach\n";
        cout << "khac: thoat\n";
        cout << "------------------------------------------------ \n";
        cout << "danh sach: "; print(head);
        cout << "------------------------------------------------ \n";
        cout << "nhap lua chon: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "nhap gia tri can chen: "; cin >> x;
            system("cls");
            insertFirst(head, x);
        }
        else if (lc == 2) {
            int x; cout << "nhap gia tri can chen: "; cin >> x;
            system("cls");
            insertLast(head, x);
        }
        else if (lc == 3) {
            int x; cout << "nhap gia tri can chen: "; cin >> x;
            int pos; cout << "nhap vi tri can chen: "; cin >> pos;
            system("cls");
            insertMid(head,x,pos);
        }
        else if (lc == 4) {
            system("cls");
            deleteFirst(head);
        }
        else if (lc == 5) {
            system("cls");
            deleteLast(head);
        }
        else if (lc == 6) {
            int pos; cout << "nhap vi tri can xoa: "; cin >> pos;
            system("cls");
            deleteMid(head, pos);
        }
        else if (lc == 7) {
            system("cls");
            clear(head);
        }
        else if (lc == 8) {
            int x; cout << "nhap gia tri can tim: "; cin >> x;
            system("cls");
            cout << x << " o vi tri " << find(head, x) << endl;
        }
        else if (lc == 9) {
            system("cls");
            cout << "max: " << max(head) << endl;
        }
        else if (lc == 10) {
            system("cls");
            cout << "min: " << min(head) << endl;
        }
        else if (lc == 11) {
            system("cls");
            sort(head);
        }
        else if (lc == 12) {
            system("cls");
            print(head);
        }
        else if (lc == 13) {
            system("cls");
            cout << "kich thuoc danh sach: " << size(head);
        }
        else {
            system("cls");
            break;
        }
    }
    return 0;
}