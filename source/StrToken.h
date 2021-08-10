#pragma once
#include "Token.h"

// 字符串 token
class StrToken :public Token {
private:
	std::string str;

public:
	// 默认构造函数和析构函数
	StrToken() = default;
	~StrToken() = default;

	StrToken(int line, std::string str);
	// 是否为字符串
	bool isString()const override;
	std::string getText()const override;

};