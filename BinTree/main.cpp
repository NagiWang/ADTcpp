#include <iostream>
#include "BinNode.h"
using namespace std;


int main() {
	BinNode<int> root;
	BinNodePosi<int> p = &root;

	cout << IsRoot( root ) << endl;
	cout << IsLChild( root ) << endl;
	cout << HasBothChild( *( root.parent ) ) << endl;
	cout << sibling( p ) << endl;
	cout << uncle( p ) << endl;

	BinNodePosi<int> q = FromParentTo( root );
	cout << q << endl;
	cout << &( *p ) << endl;

	return 0;
}