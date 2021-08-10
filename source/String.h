#pragma once
#include "Object.h"
#include "ASTree.h"
// String��

class String :public Object, public std::enable_shared_from_this<String> {
public:
	// ����
	static const std::shared_ptr<const std::string>__type;

private:
	// ֵ
	std::string mValue;

public:
	// Ĭ�Ϲ��캯������������
	String() = default;
	~String() = default;
	String(const std::string& str);

	// ����Object��Ӧ����
	// δ�����ǵ�������� String��֧�֣��׳��쳣����
	virtual bool __eq(Object::cptr obj)const override;
	virtual bool __ne(Object::cptr)const override;
	virtual bool __bool()const override;
	virtual Object::ptr __add(Object::cptr obj)const override;
	virtual std::string __str()const override;

	std::string value()const;
};