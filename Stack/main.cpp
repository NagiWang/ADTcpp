﻿#include <iostream>
//#include "Stack_Vector.h"
//template<typename T> using Stack = Stack_Vector<T>;
#include "Stack_List.h"
template<typename T> using Stack = Stack_List<T>;
using namespace std;


int main() {
	Stack<int> st;
	for ( int i = 0; i < 10; i++ ) {
		st.push( i );
	}
	for ( int i = 0; i < 10; i++ ) {
		cout << st.top() << "\n";
		st.pop();
	}
	cout << "the stack is empty : " << st.empty() << endl;
	st.pop();
	return 0;
}