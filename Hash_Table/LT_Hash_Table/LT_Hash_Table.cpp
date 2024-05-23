#include <iostream>
constexpr auto HASH_SIZE = 11;;

using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* hash_table[HASH_SIZE];

int hash_func(int data) {
    return data % 11;
}

void insert(int data) {
    int index = hash_func(data);
}

int main()
{
    
}
