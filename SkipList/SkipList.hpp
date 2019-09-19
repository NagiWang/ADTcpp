#pragma once
#include <random>
#include <ctime>
#include "SkipListNode.hpp"

const int MAXLEVEL = 4;

template<typename T>
class SkipList {
public:
	SkipList();
	bool isEmpty() const;
	void choosePowers();
	int chooseLevel();

private:
	typedef SkipListNode<T> * nodePtr;
	nodePtr root[MAXLEVEL];
	int powers[MAXLEVEL];
};

template<typename T>
SkipList<T>::SkipList() {
	for ( auto & var : root ) {
		var = nullptr;
	}
}

template<typename T>
inline bool SkipList<T>::isEmpty() const {
	return root[0];
}

template<typename T>
void SkipList<T>::choosePowers() {
	powers[MAXLEVEL - 1] = ( 2 << ( MAXLEVEL - 1 ) ) - 1;
	for ( int i = MAXLEVEL - 2, j = 0; i >= 0; --i, ++j ) {
		powers[i] = powers[i + 1] - ( 2 << j );
	}
}

template<typename T>
int SkipList<T>::chooseLevel() {
	int r = u( e ) % powers[MAXLEVEL - 1] + 1;
	for ( int i = 1; i < MAXLEVEL; i++ ) {
		if ( r < powers[i] )
			break;
	}
	return i - 1;
}
