#pragma once
#include "ASTLeaf.h"

class StringLiteral :public ASTLeaf {
public:
	using ASTLeaf::ASTLeaf;
	std::string value()const;
	virtual Object::ptr eval(Environment& env)const;
};
