#pragma once
#include "../List/List.h"


template<typename T>
class Queue : public List<T> {
public:
	void enqueue( const T & e ) { List<T>::inserAsLast( e ); }
	T dequeue() { return List<T>::remove( List<T>::first() ); }
	T & front() { return List<T>::first()->data; }
};

