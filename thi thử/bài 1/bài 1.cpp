#include <iostream>
#include <vector>
using namespace std;

struct Diem {
    double x, y, z;
    void nhap() {
        cin >> x >> y >> z;
    }
    bool operator<(const Diem& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }

    bool operator==(const Diem& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

int binary_search(const vector<Diem>& v, const Diem& target) {
    int left = 0, right = v.size() - 1;
    int steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (v[mid] == target) {
            return steps;
        }
        if (v[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // Không tìm thấy
}

int main()
{

    int n;
    cin >> n;
    vector <Diem> v(n);
    for (int i = 0; i < n; i++) {
        v[i].nhap();
    }

    int m;
    cin >> m;
    vector <Diem> w(m);
    for (int i = 0; i < m; i++) {
        w[i].nhap();
    }

    for (int i = 0; i < m; i++) {
        int steps = binary_search(v, w[i]);
        if (steps == -1) {
            cout << "KHONG" << endl;
        }
        else {
            cout << steps << endl;
        }
    }

    return 0;
}

