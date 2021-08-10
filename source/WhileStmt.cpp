#include "WhileStmt.h"

ASTree::cptr WhileStmt::condition()const {
	return child(0);
}

ASTree::cptr WhileStmt::body()const {
	return child(1);
}

std::string WhileStmt::toString()const {
	return "(while" + condition()->toString() + " " + body()->toString() + ")";
}

Object::ptr WhileStmt::eval(Environment& env)const {
	Object::ptr ret;
	while (condition()->eval(env)->__bool())
		ret = body()->eval(env);
	if (ret)return ret;
	return nullptr;
}

