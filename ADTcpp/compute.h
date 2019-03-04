#pragma once
#include "Operator.h"
#include "../Stack/Stack_List.h"
template<typename T> using Stack = Stack_List<T>;
// #include "../Stack/Stack_Vector.h"
// template<typename T> using Stack = Stack_Vector<T>;
#include <cstring>
#include <cstdio>
using namespace std;

template<typename T>
T compute( char * S, char *& RPN ) {
	Stack<T> opnd;
	Stack<char> optr;
	optr.push( '\0' );
	while ( !optr.empty() ) {
		if ( isdigit( *S ) ) {
			readNumber( s, opnd );
			append( RPN, opnd.top() );
		} else {
			switch ( ) {

				default: exit( -1 );
			}
		}
	}
}

template<typename T>
void readNumber( char *& p, Stack<T> & stk ) {
	stk.push( (T) ( *p - '\0' ) );
	while ( isdigit( *( ++p ) ) ) {
		stk.push( stk.pop() * 10 + ( *p - '\0' );
	}
	if ( *p != '.' )
		return;
	T fraction = 1;
	while ( isdigit( *( ++p ) ) ) {
		stk.push( stk.pop() + ( *p - '/0' ) * ( fraction /= 10 ) );
	}
}

template<typename T>
void append( char *& rpn, T opnd ) {
	int len = strlen( rpn );
	char buf[64];
	if ( T( (int) opnd ) != opnd )
		sprintf( buf, "%.2f\0", opnd );
	else
		sprintf( buf, "%d\0", (int) opnd );
	rpn = (char *) realloc( rpn, sizeof( char ) * ( len + strlen( buf ) + 1 );
	strcat( rpn, buf );
}

void append( char *& rpn, char optr ) {
	int len = strlen( rpn );
	rpn = (char *) realloc( rpn, sizeof( char ) * ( len + 3 ) );
	sprintf( rpn + len, "%c", optr );
	rpn[len + 2] = '\0';
}

Op optr2rank( char op ) {
	switch ( op ) {
		case '+':  return Op::ADD;
		case '-':  return Op::SUB;
		case '*':  return Op::MUL;
		case '/':  return Op::DIV;
		case '^':  return Op::POW;
		case '!':  return Op::FAC;
		case '(':  return Op::L_P;
		case ')':  return Op::R_P;
		case '\0': return Op::EOP;
		default:
			exit( -1 );
	}
}

// op1 与 op2 优先级比较
char orderBetween( char op1, char op2 ) {
	return Pri[optr2rank( op1 )][optr2rank( op2 )];
}
