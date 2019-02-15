#pragma once
#include "../Vector/Vector.h"

template<typename T>
class Stack_Vector : public Vector<T> {
public:
	void push( const T & val ) { ( *this ).insert( ( *this ).size(), val ); }
	const T pop() { return ( *this ).remove( ( *this ).size() - 1 ); }
	T & top() { return ( *this )[( *this ).size() - 1]; }
};

