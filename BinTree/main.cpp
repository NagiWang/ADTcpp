#include <iostream>
#include "BinNode.h"
using namespace std;


int main() {
	BinNode<int> root;
	BinNodePosi<int> p = &root;

	cout << IsRoot( root ) << endl;
	cout << IsLChild( root ) << endl;
	cout << sibling( p ) << endl;
	cout << uncle( p ) << endl;
	cout << FromParentTo( root ) << endl;
	cout << &( *p ) << endl;

	return 0;
}