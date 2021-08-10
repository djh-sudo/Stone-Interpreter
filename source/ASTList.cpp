#include "ASTList.h"
#include "Exception.h"

// ���캯��
ASTList::ASTList(const std::vector<ASTree::cptr>& list) :mChildren(list) {}

// ASTListΪ��Ҷ��㣬��˷���false
bool ASTList::isLeaf()const {
	return false;
}

// ��ȡ��������
int ASTList::numberChildren()const {
	return mChildren.size();
}

// ��Ҷ���û��token
Token::cptr ASTList::token()const {
	throw Exception("This AST node do not have token!");
}

// �����±귵�غ���
ASTree::cptr ASTList::child(rsize_t t)const {
	return mChildren.at(t);
}

// ��ȡ��Ӧλ�õĽ���ַ���
std::string ASTList::location()const {
	for (auto t : mChildren) {
		std::string s = t->location();
		if (s.size()) return s;
	}
	return "";
}

// תΪ�ַ�������
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

// �����﷨������Ҷ��㲻�����
Object::ptr ASTList::eval(Environment& env)const {
	throw Exception("can not eval " + toString());
}

// ���������
std::ostream& operator<<(std::ostream& os, const ASTree::cptr& ast) {
	os << ast->toString();
	return os;
}