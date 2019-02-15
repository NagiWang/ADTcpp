#pragma once
#include "../Vector/Vector.h"

template<typename T>
class Stack_Vector : public Vector<T> {
public:
	void push( const T & val ) { Vector<T>::insert( Vector<T>::size(), val ); }

	const T pop() {
		if ( !Vector<T>::empty() )
			return Vector<T>::remove( Vector<T>::size() - 1 );
		else
			return NULL;
	}

	T top() {
		if ( !Vector<T>::empty() )
			return ( *this )[Vector<T>::size() - 1];
		else
			return NULL;
	}
};

