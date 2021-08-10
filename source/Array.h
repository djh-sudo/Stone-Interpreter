#pragma once
#include "Object.h"
#include <vector>

// 数组类型
class Array :public Object {
protected:
	// 值
	std::vector<Object::ptr>mArray;

public:
	// 静态成员变量，类型
	static const std::shared_ptr<const std::string>__type;

	~Array() = default;
	Array(size_t size);
	// 重载[]运算符
	Object::ptr& operator[](size_t n);
	std::string __str()const override;
};