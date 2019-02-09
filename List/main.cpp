#include <iostream>
#include "ListNode.h"
#include "List.h"
using namespace std;


int main() {
	Posi<int> a = new ListNode<int>;
	a->data = 5;
	cout << a->data << endl;
	a->succ = new ListNode<int>( 6, a );
	auto b = a->succ;
	cout << b->insertAsPred( 7 )->data << endl;
	delete a, b;
	List<int> L;
	for ( int i = 0; i < 10; i++ ) {
		L.inserAsLast( i + 10 );
	}
	for ( int i = 0; i < 10; i++ ) {
		cout << L[i] << endl;
	}
	return 0;
}