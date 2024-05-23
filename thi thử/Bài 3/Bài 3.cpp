
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
	int key;
	TNode* left, * right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
	} 
	return root;
}

void Input(vector<int>& v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int height(TREE root) {
	if (root == NULL) {
		return -1;
	}
	else {
		int a = height(root->left);
		int b = height(root->right);
		return max(a,b) + 1;
	}
}

void Fun(TREE root) {
	if (root == NULL) {
		cout << "Empty Tree";
	}
	else if (height(root->left) > height(root->right)) {
		cout << -1;
	}
	else if (height(root->left) < height(root->right)) {
		cout << 1;
	}
	else if (height(root->left) == height(root->right)) {
		cout << 0;
	}
}

int main() {
	vector<int> duyetNLR;
	vector<int> duyetLNR;
	Input(duyetNLR);
	Input(duyetLNR);
	int Num = duyetNLR.size() - 1;
	TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
	Fun(root);
	return 0;
}

