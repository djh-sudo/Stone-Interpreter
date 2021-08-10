#include "ASTLeaf.h"
#include "Exception.h"
#include <ostream>


ASTLeaf::ASTLeaf(Token::cptr token) {
	this->mToken = token;
}

// 叶结点返回true
bool ASTLeaf::isLeaf()const {
	return true;
}
// 叶结点没有孩子
int ASTLeaf::numberChildren()const {
	return 0;
}

Token::cptr ASTLeaf::token()const {
	return this->mToken;
}

// 叶结点没有孩子，抛出异常 
ASTree::cptr ASTLeaf::child(rsize_t t)const {
	throw std::out_of_range("This node has no children!");
}

// 返回对象的所在行数
std::string ASTLeaf::location()const {
	return std::to_string(this->mToken->getLineNumber());
}

std::string ASTLeaf::toString()const {
	return mToken->getText();
}

// 叶结点不予解析
Object::ptr ASTLeaf::eval(Environment& env)const {
	throw Exception("can't eval the " + toString());
}
