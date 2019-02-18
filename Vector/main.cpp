#include <iostream>
#include "Vector.h"
using namespace std;

template<typename T> void squart( T & a ) {
	a *= a;
};


int main() {
	Vector<int> array( 10 );
	for ( int i = array.size() - 1; i >= 0; i-- ) {
		array[9 - i] = std::rand() % 10 - 5;
		cout << "array[" << 9 - i << "] = " << array[9 - i] << endl;
	}
	cout << "the size of array: " << array.size() << "\n\n";
	cout << "the array is ordered: " << array.isordered() << "\n\n";
	//unsort( array );
	array.sort( 4 );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << "\n\n";
	cout << "the array is ordered: " << array.isordered() << "\n\n";
	array.unsort();
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << "\n\n";
	cout << "the array is ordered: " << array.isordered() << "\n\n";
	array.sort( 3 );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << "\n\n";
	cout << "the array is ordered: " << array.isordered() << "\n\n";
	array.remove( 3, 6 );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << "\n\n";
	cout << "the array is ordered: " << array.isordered() << "\n\n";
	cout << "the " << 3 << " is array[" << array.search( 3 ) << "] = "
		<< array[array.search( 3 )] << "\n\n";
  //void( *pk )( int & ) = squart;
	array.traverse( squart );
	for ( int i = 0; i < array.size(); i++ ) {
		cout << "array[" << i << "] = " << array[i] << "\n";
	}
	cout << "the size of array: " << array.size() << "\n\n";
	return 0;
}