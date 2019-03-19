#pragma once


template<typename T>
void readNumber( char *& p, Stack<T> & stk ) {
	stk.push( (T) ( *p - '\0' ) );
	while ( isdigit( *( ++p ) ) ) {
		stk.push( stk.pop() * 10 + ( *p - '\0' ) );
	}
	if ( *p != '.' )
		return;
	T fraction = 1;
	while ( isdigit( *( ++p ) ) ) {
		stk.push( stk.pop() + ( *p - '/0' ) * ( fraction /= 10 ) );
	}
}


void append( char *& rpn, float opnd ) {
	int len = strlen( rpn );
	char buf[64];
	if ( float( (int) opnd ) != opnd )
		sprintf_s( buf, 256, "%.2f\0", opnd );
	else
		sprintf_s( buf, 256, "%d\0", (int) opnd );
	rpn = (char *) ( realloc( rpn, sizeof( char ) * ( len + strlen( buf ) + 1 ) ) );
	strcat_s( rpn, 256, buf );
}


void append( char *& rpn, char optr ) {
	int len = strlen( rpn );
	rpn = (char *) ( realloc( rpn, sizeof( char ) * ( len + 3 ) ) );
	sprintf_s( ( rpn + len ), 256, "%c", optr );
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
	return Pri[(int) optr2rank( op1 )][(int) optr2rank( op2 )];
}

template<typename T>
T calcu( char op, T b ) {
	switch ( op ) {
		case '!':
			return (T) func::facI<int>( (int) b );
			break;
		default:
			exit( -1 );
	}
}

template<typename T>
T calcu( T a, char op, T b ) {
	switch ( op ) {
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return ( b ) ? ( a / b ) : exit( -1 );
			break;
		case '^':
			return func::powI<int>( (int) a, (int) b );
		default:
			exit( -1 );
	}
}