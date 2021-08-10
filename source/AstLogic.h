#pragma once
#include "Logic.h"
#include "Rule.h"
#include "Lexer.h"

// �����﷨���߼�
class AstLogic :public Logic {
protected:
	// ����ָ��
	Rule* mRule;

public:
	// ���캯��
	AstLogic(Rule* r) {
		this->mRule = r;
	}

	// �﷨����
	virtual void parser(Lexer& l, std::vector<ASTree::cptr>& list)override {
		list.push_back(mRule->parser(l));
	}

	// ƥ��token
	virtual bool match(Lexer&l)override {
		return mRule->match(l);
	}
};