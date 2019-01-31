#pragma once

typedef int Rank;
static const int  DEFAULT_CAPACITY = 128;

template<typename T>
class Vector {
protected:
	Rank _size;
	T *  _elem;
	int  _capacity = 0;
	void copyFrom( const T * A, Rank lo, Rank hi );
	void expend();
	void shrink();

public:
	Vector();
	Vector( int length, int val );               // 规模为 length，初始元素为 val
	~Vector() { delete[] _elem; }                // 释放内存空间
	T & operator[]( Rank index ) const;          // Vector 寻秩访问
	T & operator=( const Vector<T> & vec );      // Vector clone
	Rank size() const { return _size; }          // 返回当前 Vector 所含元素数目
	bool empty() const { return !_size; }        // 判空
	Rank find( const T & e, Rank lo, Rank hi );  // 遍历查找元素 e
};

template<typename T>
inline void Vector<T>::copyFrom( const T * A, Rank lo, Rank hi ) {
	_elem = new T[_capacity = (lo + hi) << 1];
	_size = 0;
	for ( int i = lo; i < hi; i++ ) {
		_elem[_size++] = A[i];
	}
}

template<typename T>
inline void Vector<T>::expend() {
	if ( _size < _capacity )
		return;
	if ( _capacity < DEFAULT_CAPACITY )
		_capacity = DEFAULT_CAPACITY;
	T * oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for ( int i = 0; i < _size; i++ ) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
inline void Vector<T>::shrink() {
	if ( _capacity < DEFAULT_CAPACITY or (_size << 2) > _capacity )
		return;
	T * oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for ( int i = 0; i < _size; i++ ) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
inline Vector<T>::Vector() {
	_elem = new int[_capacity = DEFAULT_CAPACITY];
}

template<typename T>
inline Vector<T>::Vector( int length, int val ) {
	_capacity = DEFAULT_CAPACITY;
	while ( length > _capacity ) {
		_capacity <<= 1;
	}
	_elem = new int[_capacity];
	for ( int i = 0; i < length; i++ ) {
		_elem[i] = val;
	}
	_size = length;
}

template<typename T>
inline T & Vector<T>::operator[]( Rank index ) const {
	return _elem[index];
}

template<typename T>
inline T & Vector<T>::operator=( const Vector<T> & vec ) {
	if ( _elem )
		delete[] _elem;
	copyFrom( vec._elem, 0, vec.size );
	return *this;
}

template<typename T>
inline Rank Vector<T>::find( const T & e, Rank lo, Rank hi ) {
	for ( int i = lo; i < hi; i++ ) {
		if ( e == _elem[i] )
			return i;
	}
	return -1;
}
