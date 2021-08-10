#pragma once
#include "Postfix.h"

class ArrayRef :public Postfix {
public:
	using Postfix::Postfix;
	// 获取下标对象
	ASTree::cptr index()const;
	// 转为字符串
	std::string toString()const final;
	// 解析数组
	virtual Object::ptr eval(Environment& env, Object::ptr value)const override;
};