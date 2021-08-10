#pragma once
#include "ASTree.h"
#include "Object.h"
#include "Environment.h"
#include <vector>

// 叶结点
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
	// 默认构造函数和析构函数
	ASTLeaf() = default;
	~ASTLeaf() = default;
	// 重载构造函数
	ASTLeaf(Token::cptr);

	bool isLeaf()const override final;								// 叶结点
	int numberChildren()const override final;						// 孩子数量
	Token::cptr token() const override final;						// token
	ASTree::cptr child(rsize_t t)const override final;				// 根据下标返回对应孩子对象
	
	virtual std::string location()const override;					// 位置对应结点对象字符串
	virtual std::string toString()const override;					// 转为字符串
	virtual Object::ptr eval(Environment& env)const override;		// 解析
};