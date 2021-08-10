#include "StrToken.h"
StrToken::StrToken(int line, std::string str) :Token(line) {
	this->str = str;
}

bool StrToken::isString()const {
	return true;
}

std::string StrToken::getText()const {
	return this->str;
}