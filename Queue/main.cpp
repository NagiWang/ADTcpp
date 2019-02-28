#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue<int> Q;
	for ( int i = 0; i < 10; i++ ) {
		Q.enqueue( 10 - i );
	}
	for ( int i = 0; i < 10; i++ ) {
		cout << Q.dequeue() << endl;
	}
	return 0;
}