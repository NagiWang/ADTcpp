#pragma once
#include "ListNode.h"

template<typename T>
class List {
private:
	Rank _size;       // List 规模
	Posi<T> header;   // 首哨兵节点
	Posi<T> trailer;  // 尾哨兵节点

protected:
	void init();      // 初始化 List
	Rank clear();     // 清除 List
	void copyNodes( Posi<T> p, Rank index );
	// 归并两个有序 List
	void merge( Posi<T> & p, Rank n, List<T> & L, Posi<T> q, Rank m );
	void mergeSort( Posi<T> & p, Rank n );    // 归并排序
	void insertionSort( Posi<T> p, Rank n );  // 插入排序

	Posi<T> selectMax( Posi<T> p, Rank n );   // 选择最大值所在的节点
	void selectionSort( Posi<T> p, Rank n );  // 选择排序

public:
	// 构造 List
	List() { init(); }
	List( const List<T> & L ) { copyNodes( L.first(), L._size ); }
	//List( List<T> & L, Rank index, Rank n ) { copyNodes( L[index], n ); }
	List( Posi<T> p, Rank n ) { copyNodes( p, n ); }
	// 析构 List
	~List() { clear(); delete header, trailer; }

	Rank size() const { return _size; }             // List 规模（ 不包含哨兵节点 ）
	bool empty() const { return _size <= 0; }       // 判空

	Posi<T> first() const { return header->succ; }  // 返回首节点
	Posi<T> last() const { return trailer->pred; }  // 返回尾节点

	T & operator[]( Rank index ) const;             // 寻秩访问（ 仅可读 ）

	Posi<T> find( const T & val, Posi<T> p, Rank n ) const;
	Posi<T> find( const T & val ) const;            // 无序 List 查找
	Posi<T> search( const T & val, Posi<T> p, Rank n ) const;
	Posi<T> search( const T & val ) const;          // 有序 List 查找


	Posi<T> inserAsFirst( const T & val );          // 插入为首节点
	Posi<T> inserAsLast( const T & val );           // 插入为尾节点
	Posi<T> inserPred( Posi<T> p, const T & val );  // 插入为 p 的前驱
	Posi<T> inserSucc( Posi<T> p, const T & val );  // 插入为 p 的后继

	T remove( Posi<T> p );                          // 删除 p 节点
	Rank deduplicate();                             // 无序 List 去重
	Rank uniquify();                                // 有序 List 去重
	bool disortered();                              // 升序判定
	// Sort Function( 1:MergeSort(default),
	//                2:InsertionSort,
	//                3:SelectionSort )
	void sort( Posi<T> p, Rank n, int sortType = 1 );
	void sort();
	// TODO: UnSort Function

	// 遍历
	void traverse( void( *visit )( T & ) );
	template<typename VST> void traverse( VST & visit );

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
	while ( index-- ) {
		inserAsLast( p->data );
		p = p->succ;
	}
}

template<typename T>
void List<T>::merge( Posi<T> & p, Rank n, List<T> & L, Posi<T> q, Rank m ) {
	Posi<T> pp = p->pred;
	while ( m > 0 ) {
		if ( ( n > 0 ) && ( p->data <= q->data ) ) {
			if ( q == ( p = p->succ ) ) { --n; break; }
		} else {
			inserPred( p, L.remove( ( q = q->succ )->pred ) );
			--m;
		}
	}
	p = pp->succ;
}

template<typename T>
void List<T>::mergeSort( Posi<T> & p, Rank n ) {
	if ( n < 2 )
		return;
	Rank m = n >> 1;
	Posi<T> q = p;
	for ( Rank i = 0; i < m; i++ ) { q = q->succ; }
	mergeSort( p, m ); mergeSort( q, n - m );
	merge( p, m, *this, q, n - m );
}

template<typename T>
void List<T>::insertionSort( Posi<T> p, Rank n ) {
	for ( Rank i = 0; i < n; i++ ) {
		inserSucc( search( p->data, p, n ), p->data );
		remove( ( p = p->succ )->pred );
	}
}

template<typename T>
Posi<T> List<T>::selectMax( Posi<T> p, Rank n ) {
	Posi<T> max_val = p;
	for ( Posi<T> cur = p; n > 1; n-- )
		if ( ( cur = cur->succ )->data >= max_val->data )
			max_val = cur;
	return max_val;
}

template<typename T>
void List<T>::selectionSort( Posi<T> p, Rank n ) {
	Posi<T> head = p->pred;
	Posi<T> tail = p;
	for ( Rank i = 0; i < n; i++ ) { tail = tail->succ; }
	while ( n > 1 ) {
		Posi<T> max_val = selectMax( head->succ, n-- );
		inserPred( tail, remove( max_val ) );
		tail = tail->pred;
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
Posi<T> List<T>::find( const T & val, Posi<T> p, Rank n ) const {
	while ( --n ) {
		if ( val == ( p = p->pred )->data )
			return p;
	}
	return nullptr;
}

template<typename T>
Posi<T> List<T>::find( const T & val ) const {
	return find( val, trailer, _size );
}

template<typename T>
Posi<T> List<T>::search( const T & val, Posi<T> p, Rank n ) const {
	while ( --n >= 0 ) {
		if ( ( ( p = p->pred )->data ) <= val )
			break;
	}
	return p;
}

template<typename T>
Posi<T> List<T>::search( const T & val ) const {
	search( val, trailer, _size );
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
	Rank oldSize = _size;
	Posi<T> p = header;
	Rank index = 0;
	while ( ( p = p->succ ) != trailer ) {
		Posi<T> q = find( p->data, p, index );
		q ? remove( q ) : ++index;
	}
	return oldSize - _size;
}

template<typename T>
Rank List<T>::uniquify() {
	if ( _size < 2 )
		return 0;
	Rank oldSize = _size;
	Posi<T> p = first(), q;
	while ( q = p->succ ) {
		if ( p->data != q->data )
			p = q;
		else
			remove( q );
	}
	return oldSize - _size;
}

template<typename T>
bool List<T>::disortered() {
	if ( _size < 2 )
		return true;
	Posi<T> p = header->succ;
	while ( p->succ != trailer ) {
		if ( p->data > ( p->succ )->data )
			return false;
	}
	return true;
}

template<typename T>
void List<T>::sort( Posi<T> p, Rank n, int sortType ) {
	switch ( sortType ) {
		case 1:  return mergeSort( p, n );
		case 2:  return insertionSort( p, n );
		case 3:  return selectionSort( p, n );
		default: return mergeSort( p, n );
	}
}

template<typename T>
void List<T>::sort() {
	sort( first(), _size, 1 );
}

template<typename T>
void List<T>::traverse( void( *visit )( T & ) ) {
	for ( Posi<T> p = header->succ; p != trailer; p = p->succ )
		visit( p->data );
}

template<typename T> template<typename VST>
void List<T>::traverse( VST & visit ) {
	for ( Posi<T> p = header->succ; p != trailer; p = p->succ )
		visit( p->data );
};
