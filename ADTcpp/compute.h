#pragma once

enum class Operator :int { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOP };
typedef Operator Op;


template<typename T>
class compute {
public:
	compute();
	~compute();
};

