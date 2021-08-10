#pragma once
#include "ASTList.h"

class WhileStmt :public ASTList {
public:
	using ASTList::ASTList;
	ASTree::cptr condition()const;
	ASTree::cptr body()const;
	std::string toString()const final;

	virtual Object::ptr eval(Environment& env)const override;

};