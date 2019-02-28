#pragma once
#include "../List/List.h"


template<typename T>
class Queue : public List<T> {
public:
	void enqueue( const T & e ) { *this->inserAsLast( e ); }
	T dequeue() { return remove( first() ); }
	T & front() { return first()->data; }
};