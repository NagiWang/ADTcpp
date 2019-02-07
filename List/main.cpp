#include <iostream>
#include "ListNode.h"
using namespace std;


int main() {
	Posi<int> a = new ListNode<int>;
	a->data = 5;
	cout << a->data << endl;
	a->succ = new ListNode<int>( 6, a );
	auto b = a->succ;
	cout << b->insertAsPred( 7 )->data << endl;
}