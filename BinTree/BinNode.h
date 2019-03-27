#pragma once

template<typename T>
struct BinNode;                             // 二叉树结点类

template<typename T>
using BinNodePosi = BinNode<template> *;    // 二叉树结点指针

template<typename T>
constexpr auto stature( T p ) { return ( ( p ) ? ( p )->height : -1 ); } // 节点高度 ( 空树高度为-1 )

typedef enum { RB_RED, RB_BLACK } RBColor;  // 节点颜色

template<typename T>struct BinNode {
	T data;
	BinNodePosi<T> parent; // 父节点
	BinNodePosi<T> lc;     // 左节点
	BinNodePosi<T> rc;     // 右节点
	int height;
	int npl;
	RBColor color;
	BinNode() : parent( nullptr ), lc( nullptr ), rc( nullptr ),
		height( 0 ), npl( 1 ), color( RB_RED ) {}


};