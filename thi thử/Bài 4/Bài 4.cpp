#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct HashTable {
    int size;
    double load_factor;
    int num_elements;
    vector<list<int>> table;

    HashTable(int size, double load_factor)
        : size(size), load_factor(load_factor), num_elements(0), table(size) {}

    int hash_function(int key) {
        return key % size;
    }

    bool insert(int key) {
        if (static_cast<double>(num_elements) / size > load_factor) {
            return false;
        }
        int index = hash_function(key);
        table[index].push_back(key);
        num_elements++;
        return true;
    }

    int find(int key) {
        int index = hash_function(key);
        int comparisons = 0;
        for (int k : table[index]) {
            comparisons++;
            if (k == key) {
                return comparisons;
            }
        }
        return -1; // KHONG
    }
};

int main() {
    int M, N, N_prime;
    double LOAD;
    cin >> M >> LOAD >> N;

    HashTable hash_table(M, LOAD);

    for (int i = 0; i < N; ++i) {
        int key;
        cin >> key;
        if (!hash_table.insert(key)) {
            cout << "KHONG THE THEM KHOA " << key << endl;
        }
    }

    cin >> N_prime;
    for (int i = 0; i < N_prime; ++i) {
        int key;
        cin >> key;
        int result = hash_table.find(key);
        if (result == -1) {
            cout << "KHONG" << endl;
        }
        else {
            cout << result << endl;
        }
    }

    return 0;
}
