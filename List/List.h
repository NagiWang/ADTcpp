#pragma once
#include "ListNode.h"

template<typename T>
class List {
private:
	Rank _size;
	Posi<T> header;
	Posi<T> trailer;

protected:
	void init();

public:
	List() { init(); }
	~List() {}

};


template<typename T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = nullptr;
	header->succ = trailer;
	trailer->pred = header;
	trailer->succ = nullptr;
	_size = 0;
}

