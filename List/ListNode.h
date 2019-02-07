#pragma once

typedef int Rank;

template<typename T> struct ListNode;              // 列表节点模板类
template<typename T> using Posi = ListNode<T> *;   // 列表节点指针


template<typename T> struct ListNode {
	T data;        // 数据
	Posi<T> pred;  // 前驱
	Posi<T> succ;  // 后继
	ListNode() {};
	ListNode( T val, Posi<T> p = nullptr, Posi<T> s = nullptr );
	Posi<T> insertAsPred( const T & val );  // 当前节点前插入新节点
	Posi<T> insertAsSucc( const T & val );  // 当前节点后插入新节点
};

template<typename T>
inline ListNode<T>::ListNode( T val, Posi<T> p, Posi<T> s ) {
	data = val; pred = p; succ = s;
}

template<typename T>
inline Posi<T> ListNode<T>::insertAsPred( const T & val ) {
	Posi<T> x = new ListNode( val, pred, this );
	pred->succ = x;
	pred = x;
	return x;
}

template<typename T>
inline Posi<T> ListNode<T>::insertAsSucc( const T & val ) {
	Posi<T> x = new ListNode( val, this, succ );
	succ->pred = x;
	succ = x;
	return x;
}