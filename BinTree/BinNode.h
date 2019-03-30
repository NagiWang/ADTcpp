#pragma once

template<typename T>
struct BinNode;                      // 二叉树结点类

template<typename T>
using BinNodePosi = BinNode<T> *;    // 二叉树结点指针

template<typename T>                 // 节点高度 ( 空树高度为-1 )
constexpr int stature( T p ) {
	return ( ( p ) ? ( p )->height : -1 );
}

typedef enum { RB_RED, RB_BLACK } RBColor;  // 节点颜色

template<typename T>struct BinNode {
	T data;
	BinNodePosi<T> parent; // 父节点
	BinNodePosi<T> lc;     // 左节点
	BinNodePosi<T> rc;     // 右节点
	int height;            // 树的高度
	int npl;               // Null Path Length ( 左氏堆 )
	RBColor color;
	BinNode() : data( 0 ), parent( nullptr ), lc( nullptr ), rc( nullptr ),
		height( 0 ), npl( 1 ), color( RB_RED ) {}
	BinNode( T e,
			 BinNodePosi<T> p = nullptr,
			 BinNodePosi<T> lc = nullptr,
			 BinNodePosi<T> rc = nullptr,
			 int h = 0, int l = 1,
			 RBColor c = RB_RED ) :
		data( e ), parent( p ), lc( lc ), rc( rc ),
		height( h ), npl( l ), color( c ) {}

};

template<typename T>
constexpr bool IsRoot( const T & x ) { return  !( &x ) or !( x.parent ); }

template<typename T>
constexpr bool IsLChild( const T & x ) {
	return ( !IsRoot( x ) and ( ( &x ) == ( x.parent->lc ) ) );
}

template<typename T>
constexpr bool IsRChild( const T & x ) {
	return ( !IsRoot( x ) and ( ( &x ) == ( x.parent->rc ) ) );
}

template<typename T>
constexpr bool HasParent( const T & x ) {
	return ( !IsRoot( x ) );
}

template<typename T>
constexpr bool HasLChild( const T & x ) { return x.lc; }

template<typename T>
constexpr bool HasRChild( const T & x ) { return x.rc; }

template<typename T>
constexpr bool HasChild( const T & x ) {
	return ( HasLChild( x ) or HasRChild( x ) );
}

template<typename T>
constexpr bool HasBothChild( const T & x ) {
	return ( HasLChild( x ) and HasRChild( x ) );
}

template<typename T>
constexpr bool IsLeaf( T  x ) {
	return !HasChild( x );
}

template<typename T>  // 返回兄弟节点
constexpr auto sibling( const T x ) {
	if ( !IsRoot( *x ) ) {
		return  IsLChild( *x )
			? ( x->parent->rc )
			: ( x->parent->lc );
	} else
		return x;
}

template<typename T>  // 返回叔叔节点
constexpr auto uncle( const T x ) {
	if ( !IsRoot( *( x->parent ) ) and !IsRoot( *( x->parent->parent ) ) ) {
		return  IsLChild( *( x->parent ) )
			? ( x->parent->parent->rc )
			: ( x->parent->parent->lc );
	} else {
		return x;
	}
}

template<typename T>  // 返回父节点
constexpr auto FromParentTo( const T & x ) {
	return IsRoot( x )
		? ( &x )
		: ( IsLChild( x )
			? ( x.parent->lc )
			: ( x.parent->rc ) );
}
