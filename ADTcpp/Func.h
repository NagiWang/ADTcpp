#pragma once


template<typename T>
T facI( T b ) {
	if ( b < 1 )
		return 1;
	T res = 1;
	for ( int i = 1; i <= b; ++i ) {
		res *= i;
	}
	return res;
}