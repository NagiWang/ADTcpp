#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector<int> array( 10 );
	for ( int i = array.size() - 1; i >= 0; i-- ) {
		array[9 - i] = i - 5;
		cout << "array[" << 9 - i << "] = " << array[9 - i] << endl;
	}
	cout << "the size of array: " << array.size() << endl << endl;
	cout << "the array is ordered: " << array.isordered() << endl << endl;
	//unsort( array );
	array.sort( 4 );
	for ( int i = 0; i < array.size(); i++ ) {
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
	array.sort( 4 );
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
	cout << "the array is ordered: " << array.isordered() << endl << endl;
	return 0;
}