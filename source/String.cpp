#include "String.h"
#include "Exception.h"
const std::shared_ptr<const std::string>String::__type = std::make_shared<const std::string>("String");

String::String(const std::string& str) :Object(__type) {
	this->mValue = str;
}

bool String::__eq(Object::cptr obj = false) const{
	if (obj->__name != __type) throw Exception("error type '==' [" + *(obj->__name) + "]");
	auto objTemp = std::dynamic_pointer_cast<const String>(obj);
	return mValue == objTemp->value();
}

bool String::__ne(Object::cptr obj)const {
	if (obj->__name != __type)
		throw Exception("error type for '!='[" + *(obj->__name) + "]");
	auto objTemp = std::dynamic_pointer_cast<const String>(obj);
	return mValue != objTemp->value();
}

bool String::__bool()const {
	return mValue.size();
}

std::string String::__str()const {
	return mValue;
}

std::string String::value()const {
	return mValue;
}

Object::ptr String::__add(Object::cptr obj)const {
	return std::make_shared<String>(mValue + obj->__str());
}