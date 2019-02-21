#include "paren.h"
#include <iostream>
using namespace std;

bool Paren( const std::string & str );

int main() {
	string str;
	cout << "Running...\n";
	while ( getline( cin, str ) ) {
		cout << Paren( str ) << "\n";
	}
	cout << "Done...\n";
	return 0;
}