#pragma once
#include "ASTree.h"
#include <ostream>
#include <string>

// 继承AST 非叶结点
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
	// 孩子数组，这里不是二叉树，而是多叉树
	std::vector<ASTree::cptr>mChildren;

public:
	// 默认构造函数和析构函数
	ASTList() = default;
	~ASTList() = default;
	// 重载构造函数
	ASTList(const std::vector<ASTree::cptr>& list);
	// 判断是否为叶结点
	virtual bool isLeaf()const override;
	// 孩子数量
	virtual int numberChildren()const override;
	// token
	virtual Token::cptr token()const override;
	// 根据下标返回孩子对象
	virtual ASTree::cptr child(rsize_t t)const override;
	// 获取对应位置的结点字符串
	virtual std::string location()const override;
	// 转为字符串
	virtual std::string toString()const override;
	// 解析当前结点
	virtual Object::ptr eval(Environment& env)const override;
};
// 重载I/O流的输出流
std::ostream& operator<<(std::ostream& os, const ASTree::cptr& ast);
