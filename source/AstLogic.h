#pragma once
#include "Logic.h"
#include "Rule.h"
#include "Lexer.h"

// 抽象语法树逻辑
class AstLogic :public Logic {
protected:
	// 规则指针
	Rule* mRule;

public:
	// 构造函数
	AstLogic(Rule* r) {
		this->mRule = r;
	}

	// 语法分析
	virtual void parser(Lexer& l, std::vector<ASTree::cptr>& list)override {
		list.push_back(mRule->parser(l));
	}

	// 匹配token
	virtual bool match(Lexer&l)override {
		return mRule->match(l);
	}
};