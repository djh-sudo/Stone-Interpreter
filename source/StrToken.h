#pragma once
#include "Token.h"

// �ַ��� token
class StrToken :public Token {
private:
	std::string str;

public:
	// Ĭ�Ϲ��캯������������
	StrToken() = default;
	~StrToken() = default;

	StrToken(int line, std::string str);
	// �Ƿ�Ϊ�ַ���
	bool isString()const override;
	std::string getText()const override;

};