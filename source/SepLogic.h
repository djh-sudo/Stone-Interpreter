#pragma once
#include "ParserException.h"
#include "Lexer.h"
#include "Logic.h"
#include "ASTree.h"
#include <unordered_set>

class SepLogic :public Logic {
protected:
	std::unordered_set<std::string>mPat;
public:
	SepLogic(const std::unordered_set<std::string>& p) {
		this->mPat = p;
	}

	virtual void parser(Lexer& l, std::vector<ASTree::cptr>& list)override {
		if (!match(l)) throw ParserException(l.peek(0));
		l.readToken();
	}

	virtual bool match(Lexer& l)override {
		auto t = l.peek(0);
		if (!t->isIdentifier())return false;
		for (auto r : mPat) {
			if (t->getText() == r) return true;
		}
		return false;
	}
};