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
	~BinTree() :;

};
