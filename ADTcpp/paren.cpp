#include "paren.h"

bool pParen( const std::string & str ) {
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
