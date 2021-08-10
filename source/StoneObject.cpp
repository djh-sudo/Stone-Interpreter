#include "StoneObject.h"
#include <sstream>
#include "Exception.h"
const std::shared_ptr<const std::string>StoneObject::__type = std::make_shared<const std::string>("StoneObject");

StoneObject::StoneObject(Environment* env) :Object(__type) {
	this->env = env;
}

StoneObject::~StoneObject() {
	delete env;
}

Object::ptr StoneObject::read(const std::string& member) {
	return getEnv(member)->get(member);
}

std::string StoneObject::__str()const {
	std::stringstream ss;
	ss << "<StoneObject:" << this << ">";
	return ss.str();
}

//需要保证通过字段找到环境以后，此环境不是记录全局的环境
Environment* StoneObject::getEnv(const std::string& member) {
	auto en = env->where(member);
	if (en && en == env) return en;
	else throw Exception("fail to access the Object [" + member + "]");
}

void StoneObject::write(const std::string& member,Object::ptr value) {
	getEnv(member)->putNew(member, value);
}