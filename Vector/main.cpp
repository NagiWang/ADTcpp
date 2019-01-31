#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector<int> num( 9, 1 );
	for ( int i = 0; i < 9; i++ ) {
		cout << "array[" << i << "] = " << num[i] << endl;
	}
	return 0;
}