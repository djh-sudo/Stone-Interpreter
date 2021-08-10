#pragma once
#include "Postfix.h"
// 实参序列

class Arguments :public Postfix, public std::enable_shared_from_this<Arguments> {
public:
	using Postfix::Postfix;
	// 实参数量
	int size()const;
	// 解析实参 覆盖父类方法
	Object::ptr eval(Environment& env, Object::ptr value)const override final;
};