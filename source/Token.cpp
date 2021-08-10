#include "Token.h"
#include "Exception.h"

// 初始化结束符，静态变量
const Token::cptr Token::END_OF_FILE = std::make_shared<const Token>(-1);
const std::string Token::END_OF_LINE("\\n");

// 构造函数
Token::Token(int line) {
	lineNumber = line;
}
// 获取行号
int Token::getLineNumber()const {
	return lineNumber;
}

// 是否为标识符
bool Token::isIdentifier()const {
	return false;
}

// 是否为数字
bool Token::isNumber()const {
	return false;
}

// 是否为字符串
bool Token::isString() const {
	return false;
}

// 获取数字
int Token::getNumber() const {
	throw Exception("this is not number token");
}

// 返回token对应字符串形式
std::string Token::getText() const {
	return "";
}