#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector<int> num( 10 );
	for ( int i = 0; i < num.size(); i++ ) {
		num[i] = i;
		cout << "array[" << i << "] = " << num[i] << "\n";
	}
	cout << endl << "the array is ordered: " << num.isordered() << endl;
	cout << endl;
	v_permute( num );
	for ( int i = 0; i < num.size(); i++ ) {
		cout << "array[" << i << "] = " << num[i] << "\n";
	}
	cout << endl << "the array is ordered: " << num.isordered() << endl;
	return 0;
}