#include "Stack_Vector.h"
#include <iostream>
using namespace std;


int main() {
	Stack_Vector<int> st;
	for ( int i = 0; i < 10; i++ ) {
		st.push( i );
	}
	for ( int i = 0; i < 10; i++ ) {
		cout << st.top() << endl;
		st.pop();
	}
	cout << "the stack is empty : " << st.empty() << endl;
	return 0;
}