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

	Posi<T> first() const { return header->succ; }
	Posi<T> last() const { return trailer->pred; }

	T & operator[]( Rank index ) const;

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

template<typename T>
T & List<T>::operator[]( Rank index ) const {
	Posi<T> p = first();
	while ( index-- > 0 )
		p = p->succ;
	return p->data;
}

