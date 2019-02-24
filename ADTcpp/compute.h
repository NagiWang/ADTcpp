#pragma once
#include "Operator.h"
#include "../Stack/Stack_List.h"
template<typename T> using Stack = Stack_List<T>;
// #include "../Stack/Stack_Vector.h"
// template<typename T> using Stack = Stack_Vector<T>;

template<typename T>
T compute( char * str, char * & RPN ) {
	Stack<T> opnd;
	Stack<char> optr;
	optr.push( '\0' );
	while ( !optr.empty() ) {
		if ( isdigit( *str ) ) {

		}
	}
}

