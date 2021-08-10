#pragma once
#include "ASTLeaf.h"
#include "ParserException.h"
#include "Lexer.h"

template<typename T= ASTLeaf>
class StringLogic :public Logic{
public:
	StringLogic() {
		static_assert(std::is_base_of<ASTLeaf, T>::value, "StringLogic template must base of the ASTLeaf!");
	}

	virtual void parser(Lexer& l, std::vector<ASTLeaf::cptr>& list) override{
		if (!match(l)) throw ParserException(l.peek(0));
		list.push_back(std::make_shared<T>(l.readToken()));
	}
	virtual bool match(Lexer& l)override {
		return l.peek(0)->isString();
	}
};