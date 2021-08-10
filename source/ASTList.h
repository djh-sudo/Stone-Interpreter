#pragma once
#include "ASTree.h"
#include <ostream>
#include <string>

// �̳�AST ��Ҷ���
/*
	ASTList [Base]
	-> Postfix
	-> ArrayLiteral
	-> ParameterList
	-> BinaryExpr
	-> NegExpr
	-> PrimaryExpr
	-> BlockStmt
	-> ClassBody
	-> ClassStmt
	-> DefStmt
	-> IfStmt
	-> WhileStmt
	-> NullStmt
	-> ForStmt

*/
class ASTList :public ASTree {
protected:
	// �������飬���ﲻ�Ƕ����������Ƕ����
	std::vector<ASTree::cptr>mChildren;

public:
	// Ĭ�Ϲ��캯������������
	ASTList() = default;
	~ASTList() = default;
	// ���ع��캯��
	ASTList(const std::vector<ASTree::cptr>& list);
	// �ж��Ƿ�ΪҶ���
	virtual bool isLeaf()const override;
	// ��������
	virtual int numberChildren()const override;
	// token
	virtual Token::cptr token()const override;
	// �����±귵�غ��Ӷ���
	virtual ASTree::cptr child(rsize_t t)const override;
	// ��ȡ��Ӧλ�õĽ���ַ���
	virtual std::string location()const override;
	// תΪ�ַ���
	virtual std::string toString()const override;
	// ������ǰ���
	virtual Object::ptr eval(Environment& env)const override;
};
// ����I/O���������
std::ostream& operator<<(std::ostream& os, const ASTree::cptr& ast);
