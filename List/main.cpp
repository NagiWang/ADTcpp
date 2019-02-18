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
	cout << b->insertAsPred( 7 )->data << "\n";
	delete a, b;
	List<int>  pL;
	for ( int i = 0; i < 10; i++ ) {
		pL.inserAsLast( 10 - i );
	}
	for ( int i = 0; i < 10; i++ ) {
		cout << pL[i] << "\n";
	}
	cout << endl;
	pL.sort();
	for ( int i = 0; i < 10; i++ ) {
		cout << pL[i] << "\n";
	}
	cout << endl;
	return 0;
}