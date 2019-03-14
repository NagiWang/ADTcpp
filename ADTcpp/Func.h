#pragma once

namespace func
{
	template<typename T>
	T facI( T b ) {
		if ( b < 1 )
			return 1;
		T res = 1;
		for ( int i = 1; i <= b; ++i ) {
			res *= i;
		}
		return res;
	};

	template<typename T>
	T powI( T a, T b ) {
		if ( a == 0 )
			return 0;
		else if ( b == 0 ) {
			return 1;
		} else {
			int res = 1;
			int base = a;
			while ( b ) {
				if ( b & 1 )
					res *= base;
				base *= base;
				b >>= 1;
			}
			return res;
		}
	}
}
