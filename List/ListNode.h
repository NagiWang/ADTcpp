#pragma once
#ifndef __ADT_LISTNODE__
#define __ADT_LISTNODE__

typedef int Rank;
template<typename T> struct ListNode;
template<typename T> using Posi = ListNode<T>*;


template<typename T> struct ListNode {
	T data;
	Posi<T> pred;
	Posi<T> succ;
	ListNode() {}
	ListNode( T val, Posi<T> p = nullptr, Posi<T> s = nullptr )
		: data( val ), pred( p ), succ( s ) {}
	Posi<T> insertAsPred( const T & val );
	Posi<T> insertAsSucc( const T & val );
};

template<typename T>
inline Posi<T> ListNode<T>::insertAsPred( const T & val ) {
	return Posi<T>();
}

template<typename T>
inline Posi<T> ListNode<T>::insertAsSucc( const T & val ) {
	return Posi<T>();
}



#endif // !__ADT_LISTNODE__