#include "ArrayRef.h"
#include "Array.h"
#include "Integer.h"
#include "Exception.h"

// �����±����
ASTree::cptr ArrayRef::index()const {
	return child(0);
}

// תΪ�ַ���
std::string ArrayRef::toString()const {
	return "[" + index()->toString() + "]";
}

// ��������
Object::ptr ArrayRef::eval(Environment& env, Object::ptr value)const {
	// ��ʾ����ת��Ϊ����Array����
	auto arr = std::dynamic_pointer_cast<Array>(value);
	if (arr) {
		// ���������±���ʽ
		auto id = std::dynamic_pointer_cast<Integer>(index()->eval(env));
		// ��������Ԫ�ض���
		if (id) return (*arr)[id->value()];
	}
	throw Exception("fail to access array :[" + location() + "]");
}

