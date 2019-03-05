#include "compute.h"
#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "Running...\n";
	while ( getline( cin, str ) ) {
		cout << Paren( str ) << "\n";
	}
	cout << "Done...\n";
	return 0;
}