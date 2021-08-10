#pragma once
#include "ASTree.h"
#include "Object.h"
#include "Environment.h"
#include <vector>

// Ҷ���
/*
	ASTLeaf
	-> StringLiteral
	-> Name
	-> NumberLiteral
	
*/
class ASTLeaf :public ASTree {
protected:
	// token
	Token::cptr mToken;

public:
	// Ĭ�Ϲ��캯������������
	ASTLeaf() = default;
	~ASTLeaf() = default;
	// ���ع��캯��
	ASTLeaf(Token::cptr);

	bool isLeaf()const override final;								// Ҷ���
	int numberChildren()const override final;						// ��������
	Token::cptr token() const override final;						// token
	ASTree::cptr child(rsize_t t)const override final;				// �����±귵�ض�Ӧ���Ӷ���
	
	virtual std::string location()const override;					// λ�ö�Ӧ�������ַ���
	virtual std::string toString()const override;					// תΪ�ַ���
	virtual Object::ptr eval(Environment& env)const override;		// ����
};