#include <iostream>
using namespace std;
#include <vector>

//khong giong nhu array, chi mot so gia tri nhat dinh co the duoc luu tru duoi ten mot bien duy nhat
// vector giong mot dynamic array nhung co kha nang tu dong thay doi kich thuoc khi mot phan tu duoc chen hoac xoa
// cac pt vector duoc dat trong contigous storage (bo nho lien ke) de chung co the duoc truy cap va duyet bang iterator

/*
khai bao 1 vector
vector <kdl> ten_vector
vector <kdl> ten_vector(n) : vector co n phan tu co gtmd = 0
vector <kdl> ten_vector(n,v) : vector co n phan tu co gt  = v

push_back(vl) day phan tu vl vao cuoi
pop_back() xoa phan tu cuoi
size() tra ve so nguyen la kich thuoc cua vector
clear() xoa tat ca phan tu

duyet cac phan tu
duyet bang chi so
for (int i = 0; i < v.size(); i++) {}

duyet bang iterator
for (vector<int> :: iterator x = v.begin(); x != v.end(); x++) {v[i]}

duyet bang auto
for( auto x = v.begin(); x != v.end(); x++) {*x}

duyet bang foreach
for (int x : v) {x}

ham xoa vi tri bat ki
erase(iterator)
ham xoa mot doan
erase(ibegin, iend

ham dao nguoc vector
reverse(v.begin(), v.end())

max min trong vector
cout << "max: " << *max_element(v.begin(), v.end()) << endl;
cout << "min: " << *min_element(v.begin(), v.end()) << endl;

set giá trị cho tất cả các phần tử 
vector <int> v(n,0)
memset(n,0,sizeof(v))
*/ 
int main()
{
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

}
