#include "SkipList.hpp"

int main() {
	std::default_random_engine e;
	e.seed( std::time( 0 ) );
	std::uniform_int_distribution<int> u( 0, 10000000 );
}