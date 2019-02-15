#pragma once
#include "../List/List.h"

template<typename T>
class Stack_List : public List<T> {
private:
	template<typename T> using L = List<T>;
public:
	void push( const T & val ){}
};
