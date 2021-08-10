#include "ASTList.h"
#include "Exception.h"

// 构造函数
ASTList::ASTList(const std::vector<ASTree::cptr>& list) :mChildren(list) {}

// ASTList为非叶结点，因此返回false
bool ASTList::isLeaf()const {
	return false;
}

// 获取孩子数量
int ASTList::numberChildren()const {
	return mChildren.size();
}

// 非叶结点没有token
Token::cptr ASTList::token()const {
	throw Exception("This AST node do not have token!");
}

// 根据下标返回孩子
ASTree::cptr ASTList::child(rsize_t t)const {
	return mChildren.at(t);
}

// 获取对应位置的结点字符串
std::string ASTList::location()const {
	for (auto t : mChildren) {
		std::string s = t->location();
		if (s.size()) return s;
	}
	return "";
}

// 转为字符串返回
std::string ASTList::toString()const {
	std::string b("(");
	std::string sep;
	for (auto t : mChildren) {
		b.append(sep);
		sep = " ";
		b.append(t->toString());
	}
	return b + ")";
}

// 解析语法树，非叶结点不予解析
Object::ptr ASTList::eval(Environment& env)const {
	throw Exception("can not eval " + toString());
}

// 重载输出流
std::ostream& operator<<(std::ostream& os, const ASTree::cptr& ast) {
	os << ast->toString();
	return os;
}