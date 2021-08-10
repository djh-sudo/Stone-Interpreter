#include "ArrayLiteral.h"
#include "Array.h"

// �����ӽ������
int ArrayLiteral::size()const {
	return numberChildren();
}

// �����������µ����鲢��������
Object::ptr ArrayLiteral::eval(Environment& env)const {
	auto res = std::make_shared<Array>(mChildren.size());
	size_t i = 0;
	for (auto t : mChildren) {
		(*res)[i] = t->eval(env);
		i++;
	}
	return res;
}
