#pragma once
#include "../List/List.h"

template<typename T>
class Stack_List : public List<T> {
public:
	void push( const T & val ) { List<T>::inserSucc( List<T>::last(), val ); }

	const T pop() {
		if ( !List<T>::empty() )
			return List<T>::remove( List<T>::last() );
		else
			return NULL;
	}

	T top() {
		if ( !List<T>::empty() )
			return List<T>::last()->data;
		else
			return NULL;
	}
};
