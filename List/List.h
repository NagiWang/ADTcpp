#pragma once
#include "ListNode.h"

template<typename T>
class List {
private:
	Rank _size;       // List 规模
	Posi<T> header;   // 首哨兵节点
	Posi<T> trailer;  // 尾哨兵节点

protected:
	void init();
	Rank clear();
	void copyNodes( Posi<T> p, Rank index );

public:
	// 构造
	List() { init(); }
	List( const List<T> & L ) { copyNodes( L.first(), L._size ); }
	List( const List<T> & L, Rank index, Rank n ) { copyNodes( L[index], n ); }
	List( Posi<T> p, Rank n ) { copyNodes( p, n ); }
	// 析构
	~List() { clear(); delete header, trailer; }

	Rank size() const { return _size; }             // List 规模（ 不包含哨兵节点 ）
	bool empty() const { return _size <= 0; }       // 判空

	Posi<T> first() const { return header->succ; }  // 返回首节点
	Posi<T> last() const { return trailer->pred; }  // 返回尾节点

	T & operator[]( Rank index ) const;             // 寻秩访问（ 仅可读 ）

	Posi<T> find( const T & val, Posi<T> p, Rank n );
	Posi<T> find( const T & val );                  // 搜寻元素 val

	Posi<T> inserAsFirst( const T & val );          // 插入为首节点
	Posi<T> inserAsLast( const T & val );           // 插入为尾节点
	Posi<T> inserPred( Posi<T> p, const T & val );  // 插入为 p 的前驱
	Posi<T> inserSucc( Posi<T> p, const T & val );  // 插入为 p 的后继

	T remove( Posi<T> p );                          // 删除 p 节点
	Rank deduplicate();                             // 去重

	void traverse( void( *visit )( T & ) );

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
	while ( --n ) {
		if ( val == ( p = p->pred )->data )
			return p;
	}
	return nullptr;
}

template<typename T>
Posi<T> List<T>::find( const T & val ) {
	return find( val, trailer, _size );
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
T List<T>::remove( Posi<T> p ) {
	T val = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return val;
}

template<typename T>
Rank List<T>::deduplicate() {
	if ( _size < 2 )
		return 0;
	int oldSize = _size;
	Posi<T> p = header;
	Rank index = 0;
	while ( ( p = p.succ ) != trailer ) {
		Posi<T> q = find( p->data, r, p );
		q ? remove( q ) : ++index;
	}
	return oldSize - _size;
}
