#pragma once
#include "Object.h"
#include "ASTree.h"
// String类

class String :public Object, public std::enable_shared_from_this<String> {
public:
	// 类型
	static const std::shared_ptr<const std::string>__type;

private:
	// 值
	std::string mValue;

public:
	// 默认构造函数和析构函数
	String() = default;
	~String() = default;
	String(const std::string& str);

	// 覆盖Object对应方法
	// 未被覆盖的运算表明 String不支持，抛出异常即可
	virtual bool __eq(Object::cptr obj)const override;
	virtual bool __ne(Object::cptr)const override;
	virtual bool __bool()const override;
	virtual Object::ptr __add(Object::cptr obj)const override;
	virtual std::string __str()const override;

	std::string value()const;
};