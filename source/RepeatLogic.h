#pragma once
#include "Logic.h"
#include "Lexer.h"
#include "ASTree.h"
#include "Rule.h"

class RepeatLogic :public Logic {
private:
	Rule* mRules;
public:
	RepeatLogic(Rule* r) {
		this->mRules = r;
	}

	virtual void parser(Lexer& l, std::vector<ASTree::cptr>& list)override {
		while (match(l)) {
			auto ast = mRules->parser(l);
			if (ast)list.push_back(ast);
		}
	}

	virtual bool match(Lexer& l)override {
		return mRules -> match(l);
	}

	virtual bool ignore()const override {
		return true;
	}
};