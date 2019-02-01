#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector<int> array( 10 );
	for ( int i = 0; i < array.size(); i++ ) {
		array[i] = i;
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << endl << endl;
	cout << "the array is ordered: " << array.isordered() << endl << endl;
	unsort( array );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << endl << endl;
	cout << "the array is ordered: " << array.isordered() << endl << endl;
	array.remove( 3, 6 );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << endl << endl;
	return 0;
}