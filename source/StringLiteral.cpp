#include "StringLiteral.h"
#include "String.h"

std::string StringLiteral::value()const {
	return token()->getText();
}

Object::ptr StringLiteral::eval(Environment& env)const {
	return std::make_shared<String>(value());
}
