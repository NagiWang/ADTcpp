#pragma once
#include "Calculation.h"
using namespace std;

template<typename T>
T compute( char * S, char *& RPN ) {
	Stack<T> opnd;
	Stack<char> optr;
	optr.push( '\0' );
	while ( !optr.empty() ) {
		if ( isdigit( *S ) ) {
			readNumber<T>( S, opnd ); append( RPN, opnd.top() );
		} else
			switch ( orderBetween( optr.top(), ( *S ) ) ) {
				case '<':
					{
						optr.push( *S );
						S++;
						break;
					}
				case '=':
					{
						optr.pop();
						S++;
						break;
					}
				case '>':
					{
						char op = optr.pop();
						append( RPN, op );
						if ( op == '!' ) {
							T pOpnd = opnd.pop();
							opnd.push( calcu<T>( op, pOpnd ) );
						} else {
							T pOpnd2 = opnd.pop();
							T pOpnd1 = opnd.pop();
							opnd.push( calcu<T>( pOpnd1, op, pOpnd2 ) );
						}
						break;
					}
				default: exit( -1 );
			}
	}
	return opnd.pop();
}

