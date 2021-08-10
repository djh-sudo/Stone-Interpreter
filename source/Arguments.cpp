#pragma once
#include "Arguments.h"
#include "NativeFunction.h"
#include "Exception.h"
#include "Function.h"
#include "ParameterList.h"
#include <string>
#include <sstream>

// ʵ������
int Arguments::size()const {
	return numberChildren();
}

// ��������
Object::ptr Arguments::eval(Environment& env, Object::ptr value)const {
	// ��ʾ����ת��
	auto native = std::dynamic_pointer_cast<NativeFunction>(value);
	if (native) {//�����ж��Ƿ�Ϊԭ������
		int params = native->numberOfParameters();
		// �����������Ƿ�ƥ��
		if (params != -1 && size() != params) throw Exception("error in number of arguments " + this->location());
		int sum = numberChildren();
		// ����һ���������ڱ���������
		std::vector<Object::ptr>args(sum);
		for (int i = 0; i < sum; i++) {
			args[i] = child(i)->eval(env);
		}
		return native->invoke(args, this->shared_from_this());
	}
	// �Զ��庯������ʾ����ת��
	auto func = std::dynamic_pointer_cast<Function>(value);
	if (!func) throw Exception("error in function " + this->location());
	// ��ȡ��������
	auto params = std::dynamic_pointer_cast<const ParameterList>(func->parameters());
	if (!params) throw Exception("error in parameters " + this->location());
	// �����������Ƿ�ƥ��
	if (size() != params->size()) throw Exception("error in number of parameters "+ this->location());
	// Ϊ�������д���������
	Environment* e = func->makeEnvironment();
	int number = 0;
	// �Ƚ��������б��ٽ���������
	for (auto t : mChildren)
		params->eval(e,number++,t->eval(env));
	auto ret = func->body()->eval(*e);
	// �ͷ��ڴ�
	delete e;
	return ret;
}
