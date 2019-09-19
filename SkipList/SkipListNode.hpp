#pragma once

template<typename T>
struct SkipListNode {
	SkipListNode() { }
	SkipListNode( T Key, SkipListNode ** Next = nullptr )
		:
		key( Key ),
		next( Next ) { }

	T key;
	SkipListNode ** next;
};
