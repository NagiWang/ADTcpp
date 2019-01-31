#pragma once

typedef int Rank;
const int  DEFAULT_CAPACITY = 128;

template<typename T>
class Vector {
protected:
	Rank _size;
	T *  _elem;
	int  _capacity = 0;
	void copyFrom( T const * A, Rank lo, Rank hi );
	void expend();
	void shrink();

public:
	Vector();
	Vector( int s = 0, int v = 0 );  // 容量为 DEFAULT_CAPACITY (128)，规模为 s，初始元素为 v
	~Vector() { delete[] _elem; }    // 删除 _elem 数组，释放内存空间
	T & operator[]( Rank index ) const;
	T & operator=( Vector<T> const & vec );
	Rank size() const { return _size; }
	bool empty() const { return !_size; }
	Rank find( T const & e, Rank lo, Rank hi );
};

template<typename T>
inline void Vector<T>::copyFrom( T const * A, Rank lo, Rank hi ) {
	_elem = new T[_capacity = (lo + hi) << 1];
	_size = 0;
	while ( lo < hi ) {
		_elem[_size++] = A[lo++];
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
inline Vector<T>::Vector( int s, int v ) {
	_capacity = DEFAULT_CAPACITY;
	while ( s > _capacity ) {
		_capacity <<= 1;
	}
	_elem = new int[_capacity];
	for ( int i = 0; i < s; i++ ) {
		_elem[i] = v;
	}
	_size = s;
}

template<typename T>
inline T & Vector<T>::operator[]( Rank index ) const {
	return _elem[index];
}

template<typename T>
inline T & Vector<T>::operator=( Vector<T> const & vec ) {
	if ( _elem )
		delete[] _elem;
	copyFrom( vec._elem, 0, vec.size );
	return *this;
}

template<typename T>
inline Rank Vector<T>::find( T const & e, Rank lo, Rank hi ) {
	while ( (lo < hi--) and (e != _elem[lo]) );
	return hi;
}
