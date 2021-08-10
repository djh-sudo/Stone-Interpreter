#pragma once

#include <string>
#include <memory>
/*	Token [Base]
	-> IdToken
	-> NumberToken
	-> StrToken
*/
class Token {
public:
	// 两个智能指针
	typedef std::shared_ptr<Token>ptr;
	typedef std::shared_ptr<const Token>cptr;
	// 定义结束符
	static const Token::cptr END_OF_FILE;// 源文件解析完毕
	static const std::string END_OF_LINE;// 一行的结尾

public :
	// 默认构造函数 不允许隐式转换
	explicit Token() = default;
	explicit Token(int line);
	virtual ~Token() = default;

private:
	// 行号
	int lineNumber;
public:
	int getLineNumber() const;			//获取行号
	virtual bool isIdentifier()const;	//判断是否为标识符
	virtual bool isNumber()const;		//判断是否为数字
	virtual bool isString()const;		//判断是否为字符串
	virtual int getNumber()const;		//提取数字
	virtual std::string getText()const;	//以字符串形式提取Token
};
