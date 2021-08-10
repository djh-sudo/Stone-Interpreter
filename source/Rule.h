#pragma once
#include "ASTree.h"
#include "Lexer.h"

/*
	RuleΪһ��������
	parser �� match�ɾ�������ʵ��

*/
/*
	Rule [Base]
	-> ListRule
	-> OrRule
*/

// �������
class Rule {
public:
	Rule() = default;
	virtual ~Rule() = default;
	virtual ASTree::cptr parser(Lexer& l) = 0;
	virtual bool match(Lexer& l) = 0;
};