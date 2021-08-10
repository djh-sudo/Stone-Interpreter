#include "Array.h"
#include "Exception.h"

const std::shared_ptr<const std::string>Array::__type = std::make_shared<const std::string>("Array");

// �����б��ʼ������Object
Array::Array(size_t size) :Object(__type),mArray(size) {}

// ����[]�����
Object::ptr& Array::operator[](size_t n) {
	if (n < mArray.size())
		return mArray.at(n);
	else throw Exception("index out of range!");
}

std::string Array::__str()const {
	std::string res;
	for (size_t i = 0; i < mArray.size(); i++) {
		res += mArray[i]->__str() + " ";
	}
	return res;
}