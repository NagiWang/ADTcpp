#pragma once
#include <string>
//#include "../Stack/Stack_Vector.h"
//template<typename T> using Stack = Stack_Vector<T>;

#include "../Stack/Stack_List.h"
template<typename T> using Stack = Stack_List<T>;

bool pParen( const std::string & str );

// 括号匹配
