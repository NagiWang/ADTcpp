#pragma once
#include <string>
//#include "../Stack/Stack_Vector.h"
//template<typename T> using Stack = Stack_Vector<T>;
#include "../Stack/Stack_List.h"
template<typename T> using Stack = Stack_List<T>;

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

// 括号匹配
