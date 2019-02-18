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

bool Paren( const std::string & str ) {
	Stack<char> st;
	for ( auto val : str ) {
		switch ( val ) {
			case '(': case '[': case '{':
				st.push( val );
				break;
			case ')':
				if ( st.empty() or ( '(' != st.pop() ) ) return false;
				break;
			case ']':
				if ( st.empty() or ( '[' != st.pop() ) ) return false;
				break;
			case '}':
				if ( st.empty() or ( '{' != st.pop() ) ) return false;
				break;
			default:
				break;
		}
	}
	return st.empty();
}