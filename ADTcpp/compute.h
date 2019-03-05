#pragma once
#include "Operator.h"
#include "../Stack/Stack_List.h"
#include "Calculation.h"
using namespace std;

template<typename T>
T compute( char * S, char *& RPN ) {
	Stack<T> opnd;
	Stack<char> optr;
	optr.push( '\0' );
	while ( !optr.empty() ) {
		if ( isdigit( *S ) ) {
			readNumber<T>( S, opnd );
			append<T>( RPN, opnd.top() );
		} else {
			switch ( orderBetween( optr.top(), ( *S ) ) {
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
							float Popnd = opnd.pop();
							opnd.push( calcu );
						}
					}
				default: exit( -1 );
			}
		}
	}
}

