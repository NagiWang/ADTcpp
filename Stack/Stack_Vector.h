#pragma once
#include "../Vector/Vector.h"

template<typename T>
class Stack_Vector : public Vector<T> {
private:
	template<typename T> using V = Vector<T>;
public:
	void push( const T & val ) { V<T>::insert( V<T>::size(), val ); }

	const T pop() {
		if ( !V<T>::empty() )
			return V<T>::remove( V<T>::size() - 1 );
		else
			return NULL;
	}

	T top() {
		if ( !V<T>::empty() )
			return ( *this )[V<T>::size() - 1];
		else
			return NULL;
	}
};

