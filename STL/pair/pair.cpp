#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
pair<int, int> p;
pait<pair<int, int>, int> p;
vector<pair<int,int>> v;
vector<pair<pair<int, int>, int>> v;
pair: luu 1 cap gia tri co kieu giong nhau hoac khac nhau
first va second
swap(pair)
manh khi dung voi vector
*/

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}
	for (pair<int,int> p : v) {
		cout << "(" << p.first << ";" << p.second << ")\n";
	}

	vector<pair<pair<int, int>, int>> w;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		w.push_back({{x,y},z});
	}
	for (pair<pair<int, int>, int> p : w) {
		cout << "(" << p.first.first << " " << p.first.second << " " << p.second << ")\n";
	}

}
