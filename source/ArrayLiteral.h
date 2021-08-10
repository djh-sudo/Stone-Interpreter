#pragma once
#include "ASTList.h"
class ArrayLiteral :public ASTList {
public:
	using ASTList::ASTList;
	int size()const;
	virtual Object::ptr eval(Environment& env)const override;
};
