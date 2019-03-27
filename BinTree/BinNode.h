#pragma once

template<typename T> struct BinNode;                             // 二叉树结点类
template<typename T> using BinNodePosi = BinNode<template> *;    // 二叉树结点指针

template<typename T>
constexpr auto stature( T p ) { return ( ( p ) ? ( p )->height : -1 ); }

