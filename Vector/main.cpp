#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector<int> num( 9, 3 );
	for ( int i = 0; i < 9; i++ ) {
		cout << "array[" << i << "] = " << num[i] << "\n";
	}
	return 0;
}