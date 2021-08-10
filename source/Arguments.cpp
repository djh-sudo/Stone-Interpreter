#pragma once
#include "Arguments.h"
#include "NativeFunction.h"
#include "Exception.h"
#include "Function.h"
#include "ParameterList.h"
#include <string>
#include <sstream>

// 实参数量
int Arguments::size()const {
	return numberChildren();
}

// 解析规则
Object::ptr Arguments::eval(Environment& env, Object::ptr value)const {
	// 显示类型转换
	auto native = std::dynamic_pointer_cast<NativeFunction>(value);
	if (native) {//首先判断是否为原生函数
		int params = native->numberOfParameters();
		// 检查参数个数是否匹配
		if (params != -1 && size() != params) throw Exception("error in number of arguments " + this->location());
		int sum = numberChildren();
		// 创建一个数字用于保存解析结果
		std::vector<Object::ptr>args(sum);
		for (int i = 0; i < sum; i++) {
			args[i] = child(i)->eval(env);
		}
		return native->invoke(args, this->shared_from_this());
	}
	// 自定义函数，显示类型转化
	auto func = std::dynamic_pointer_cast<Function>(value);
	if (!func) throw Exception("error in function " + this->location());
	// 获取函数参数
	auto params = std::dynamic_pointer_cast<const ParameterList>(func->parameters());
	if (!params) throw Exception("error in parameters " + this->location());
	// 检查参数个数是否匹配
	if (size() != params->size()) throw Exception("error in number of parameters "+ this->location());
	// 为函数运行创建作用域
	Environment* e = func->makeEnvironment();
	int number = 0;
	// 先解析参数列表，再解析函数体
	for (auto t : mChildren)
		params->eval(e,number++,t->eval(env));
	auto ret = func->body()->eval(*e);
	// 释放内存
	delete e;
	return ret;
}
