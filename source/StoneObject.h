#pragma once
#include "Object.h"
#include "Environment.h"

class StoneObject :public Object{
protected:
	Environment* env;
	Environment* getEnv(const std::string& member);

public:
	static const std::shared_ptr<const std::string>__type;
	StoneObject() = default;
	~StoneObject();
	
	StoneObject(Environment* env);
	Object::ptr read(const std::string& member);
	void write(const std::string& member, Object::ptr value);

	std::string __str()const final;
};