#pragma once
#include "Postfix.h"
// ʵ������

class Arguments :public Postfix, public std::enable_shared_from_this<Arguments> {
public:
	using Postfix::Postfix;
	// ʵ������
	int size()const;
	// ����ʵ�� ���Ǹ��෽��
	Object::ptr eval(Environment& env, Object::ptr value)const override final;
};