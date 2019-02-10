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
	Rank clear();
	void copyNodes( Posi<T> p, Rank index );

public:
	List() { init(); }
	List( const List<T> & L ) { copyNodes( L.first(), L._size ); }
	List( const List<T> & L, Rank index, Rank n ) { copyNodes( L[index], n ); }
	List( Posi<T> p, Rank n ) { copyNodes( p, n ); }

	~List() {}

	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }

	Posi<T> first() const { return header->succ; }
	Posi<T> last() const { return trailer->pred; }

	T & operator[]( Rank index ) const;

	Posi<T> find( const T & val, Posi<T> p, Rank n );
	Posi<T> find( const T & val );

	Posi<T> inserAsFirst( const T & val );
	Posi<T> inserAsLast( const T & val );
	Posi<T> inserPred( Posi<T> p, const T & val );
	Posi<T> inserSucc( Posi<T> p, const T & val );

	const T remove( Posi<T> p );

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
Rank List<T>::clear() {
	Rank oldSize = _size;
	while ( _size )
		remove( header->succ );
	return oldSize;
}

template<typename T>
void List<T>::copyNodes( Posi<T> p, Rank index ) {
	init();
	while ( n-- ) {
		inserAsLast( p->data );
		p = p->succ;
	}
}

template<typename T>
T & List<T>::operator[]( Rank index ) const {
	Posi<T> p = first();
	while ( index-- )
		p = p->succ;
	return p->data;
}

template<typename T>
Posi<T> List<T>::find( const T & val, Posi<T> p, Rank n ) {
	while ( n-- ) {
		if ( val == ( p = p->pred )->data )
			return p;
	}
	return nullptr;
}

template<typename T>
Posi<T> List<T>::find( const T & val ) {
	return find( val, header, _size );
}

template<typename T>
Posi<T> List<T>::inserAsFirst( const T & val ) {
	_size++;
	return header->insertAsSucc( val );
}

template<typename T>
Posi<T> List<T>::inserAsLast( const T & val ) {
	_size++;
	return trailer->insertAsPred( val );
}

template<typename T>
Posi<T> List<T>::inserPred( Posi<T> p, const T & val ) {
	_size++;
	return p->insertAsPred( val );
}

template<typename T>
Posi<T> List<T>::inserSucc( Posi<T> p, const T & val ) {
	_size++;
	return p->insertAsSucc( val );
}

template<typename T>
const T List<T>::remove( Posi<T> p ) {
	T val = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return val;
}

