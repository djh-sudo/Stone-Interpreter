#pragma once
#include "Postfix.h"

class ArrayRef :public Postfix {
public:
	using Postfix::Postfix;
	// ��ȡ�±����
	ASTree::cptr index()const;
	// תΪ�ַ���
	std::string toString()const final;
	// ��������
	virtual Object::ptr eval(Environment& env, Object::ptr value)const override;
};