#pragma once
#include "../List/List.h"

template<typename T>
class Stack_List : public List<T> {
private:
	template<typename T> using L = List<T>;

public:
	void push( const T & val ) { L<T>::inserSucc( L<T>::last(), val ); }

	const T pop() {
		if ( !L<T>::empty() )
			return L<T>::remove( L<T>::last() );
		else
			return NULL;
	}

	T top() {
		if ( !L<T>::empty() )
			return L<T>::last()->data;
		else
			return NULL;
	}
};
