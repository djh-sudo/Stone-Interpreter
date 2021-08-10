#pragma once
#include "Object.h"
#include <vector>

// ��������
class Array :public Object {
protected:
	// ֵ
	std::vector<Object::ptr>mArray;

public:
	// ��̬��Ա����������
	static const std::shared_ptr<const std::string>__type;

	~Array() = default;
	Array(size_t size);
	// ����[]�����
	Object::ptr& operator[](size_t n);
	std::string __str()const override;
};