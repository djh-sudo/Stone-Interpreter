#include "ASTLeaf.h"
#include "Exception.h"
#include <ostream>


ASTLeaf::ASTLeaf(Token::cptr token) {
	this->mToken = token;
}

// Ҷ��㷵��true
bool ASTLeaf::isLeaf()const {
	return true;
}
// Ҷ���û�к���
int ASTLeaf::numberChildren()const {
	return 0;
}

Token::cptr ASTLeaf::token()const {
	return this->mToken;
}

// Ҷ���û�к��ӣ��׳��쳣 
ASTree::cptr ASTLeaf::child(rsize_t t)const {
	throw std::out_of_range("This node has no children!");
}

// ���ض������������
std::string ASTLeaf::location()const {
	return std::to_string(this->mToken->getLineNumber());
}

std::string ASTLeaf::toString()const {
	return mToken->getText();
}

// Ҷ��㲻�����
Object::ptr ASTLeaf::eval(Environment& env)const {
	throw Exception("can't eval the " + toString());
}
