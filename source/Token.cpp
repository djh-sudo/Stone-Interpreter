#include "Token.h"
#include "Exception.h"

// ��ʼ������������̬����
const Token::cptr Token::END_OF_FILE = std::make_shared<const Token>(-1);
const std::string Token::END_OF_LINE("\\n");

// ���캯��
Token::Token(int line) {
	lineNumber = line;
}
// ��ȡ�к�
int Token::getLineNumber()const {
	return lineNumber;
}

// �Ƿ�Ϊ��ʶ��
bool Token::isIdentifier()const {
	return false;
}

// �Ƿ�Ϊ����
bool Token::isNumber()const {
	return false;
}

// �Ƿ�Ϊ�ַ���
bool Token::isString() const {
	return false;
}

// ��ȡ����
int Token::getNumber() const {
	throw Exception("this is not number token");
}

// ����token��Ӧ�ַ�����ʽ
std::string Token::getText() const {
	return "";
}