#include <iostream>
using namespace std;

// thu vien vector
#include <vector>

/*
Khong giong nhu Array, chi mot so gia tri nhat dinh co the duoc luu tru duoi ten mot bien duy nhat
Vector trong C++ giong nhu mot dynamic array nhung co kha nang tu dong thay doi kich thuoc khi mot phan tu duoc chen hoac xoa
cac phan tu vector duoc dat trong contigous storage (bo nho lien ke) de chung co the duoc truy cap va duyet qua bang cach su dung iterator

Cac ham su dung trong vector:
1. tao vector
- chua co phan tu
=> vector <KDL> ten_vector;
- co n phan tu co gia tri mac dinh = 0;
=> vector <KDL> ten_vector(n);
- co n phan tu co gia tri = x;
=> vector <KDL> ten_vector(n, x);

2. ham day phan tu vao cuoi vector
=> ten_vector.push_back(value);
*** value phai co cung kieu du lieu voi vector

3. ham lay kich thuoc cua vecotr
=> ten_vector.size();
*** ham tra ve int

4. truy suat
=> ten_vector[index] *** tra ve phan tu tai index
- iterator
=> ten_vector.begin(); *** la iterator tro vao phan tu dau
=> *ten_vector.begin(); *** tra ve phan tu dau
=> ten_vector.end(); *** la iterator tro vao phan tu cuoi
=> *ten_vector.end(); *** tra ve phan tu cuoi

5. Ham xoa
- xoa phan tu cuoi
=> ten_vector.pop_back();
- xoa het
=> ten_vector.clear();
- xoa vi tri bat ki (thong qua iterator)
=> ten_vector.erase(iterator);

6. ham lat nguoc vector 
=> reverse(v.begin(), v.end());

7. duyet vector
- duyet qua chi so
for(int i = 0; i < ten_vector.size(); i++) 
{
	v[i]
}
- duyet qua iterator
for (vector <KDL> ::iterator x = ten_vector.begin(); x != ten_vector.end(); x++) {
	*x
}
- duyet qua auto
for (auto x = ten_vector.begin(); x != ten_vector.end(); x++) 
{
	*x
}
- duyet qua for_each
for (KDL x : v) 
{
	x 
}
*/

int main()
{
	// tao mot vector
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	reverse(v.begin(), v.end());
	for (vector<int> ::iterator x = v.begin(); x != v.end(); x++) {
		cout << *x << " ";
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	for (auto x = v.begin(); x != v.end(); x++) {
		cout << *x << " ";
	}
	cout << endl;
	return 0;
}