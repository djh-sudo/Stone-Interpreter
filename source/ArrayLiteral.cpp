#include "ArrayLiteral.h"
#include "Array.h"

// 返回子结点数量
int ArrayLiteral::size()const {
	return numberChildren();
}

// 解析作用域下的数组并返回数组
Object::ptr ArrayLiteral::eval(Environment& env)const {
	auto res = std::make_shared<Array>(mChildren.size());
	size_t i = 0;
	for (auto t : mChildren) {
		(*res)[i] = t->eval(env);
		i++;
	}
	return res;
}
