#include "ArrayRef.h"
#include "Array.h"
#include "Integer.h"
#include "Exception.h"

// 返回下标对象
ASTree::cptr ArrayRef::index()const {
	return child(0);
}

// 转为字符串
std::string ArrayRef::toString()const {
	return "[" + index()->toString() + "]";
}

// 解析数组
Object::ptr ArrayRef::eval(Environment& env, Object::ptr value)const {
	// 显示类型转换为数组Array类型
	auto arr = std::dynamic_pointer_cast<Array>(value);
	if (arr) {
		// 解析数组下标表达式
		auto id = std::dynamic_pointer_cast<Integer>(index()->eval(env));
		// 访问数组元素对象
		if (id) return (*arr)[id->value()];
	}
	throw Exception("fail to access array :[" + location() + "]");
}

