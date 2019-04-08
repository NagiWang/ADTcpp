#include "BinNode.h"

template<typename T>
class BinTree {
protected:
	int _size;
	BinNodePosi<T> _root;
	virtual int updateHeight( BinNodePosi<T> x );
	void updateHeightAbove( BinNodePosi<T> x );
public:
	BinTree() : _size( 0 ), _root( nullptr ) {};
	~BinTree();
	int size() const { return _size; }
	int empty() const { return !_size; }

	BinNodePosi<T> root() const { return _root; }
	BinNodePosi<T> inserAsRoot( const T & e );
	BinNodePosi<T> inserAsLC( BinNodePosi<T> x, const T & e );
	BinNodePosi<T> inserAsRC( BinNodePosi<T> x, const T & e );
	BinNodePosi<T> arrachAsLC( BinNodePosi<T> x, BinTree<T> *& S );

};


template<typename T>
int BinTree<T>::updateHeight( BinNodePosi<T> x ) {
	return x->height = max( stature( x->lc ), stature( x->rc ) ) + 1;
}

template<typename T>
void BinTree<T>::updateHeightAbove( BinNodePosi<T> x ) {
	while ( x ) {
		int oldHeight = stature( x );
		updateHeight( x );
		if ( oldHeight != updateHeight( x ) )
			x = x->parent;
		else
			break;
	}
}

template<typename T>
inline BinTree<T>::~BinTree() {}

template<typename T>
BinNodePosi<T> BinTree<T>::inserAsRoot( const T & e ) {
	_size = 1;
	return _root = new BinNode<T>( e );
}

template<typename T>
BinNodePosi<T> BinTree<T>::inserAsLC( BinNodePosi<T> x, const T & e ) {
	++_size;
	x->inserAsLC( e );
	updateHeightAbove( x );
	return x->lc;
}

template<typename T>
BinNodePosi<T> BinTree<T>::inserAsRC( BinNodePosi<T> x, const T & e ) {
	++_size;
	x->inserAsRC( e );
	updateHeightAbove( x );
	return x->rc;
}

template<typename T>
BinNodePosi<T> BinTree<T>::arrachAsLC( BinNodePosi<T> x, BinTree<T> * &S ) {
	if ( x->lc = S->_root )
		x->lc->parent = x;
	_size += S->_size;
	updateHeightAbove( x );
	S->_root = nullptr;
	S->_size = 0;
	release( S );
	S = nullptr;
	return x;
}
