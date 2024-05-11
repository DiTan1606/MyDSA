#include <iostream>
#include <stack>
using namespace std;

/*
Stack: ngan xep : nguyen tac LIFO(Last in Fist out)
push(value): day pt vao dau stack
size(): tra ve so luong pt
empty(): rong thi tra ve true
top() => tra ve gia tri phan tu tren cung cua ngan xep
pop() => lay pt o dau stack ra
truy suat:
	while (st.empty() == 0) {
		cout << st.top();
		st.pop();
	}
*/ 


int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.pop();
	cout << st.top();
}
