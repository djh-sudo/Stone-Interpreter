#include "ArrayParser.h"
#include "ArrayRef.h"
/*
	element: expr {"," expr}
	primary:("[" [element] "]" | "(" expr ")" | number | identifier | string | postfix)
	potfix: "(" [args] ")" | "[" expr "]"
*/
ArrayParser::ArrayParser(Lexer& l) :ClassParser(l) {
	
	element = mFactory.rule<ArrayLiteral>()->ast(expr)->repeat(mFactory.rule()->sep({ "," })->ast(expr));

	primaryOr->push_front({ mFactory.rule()->sep({"["})->maybe(element)->sep({"]"}) });

	postfix->push_back({ mFactory.rule<ArrayRef>()->sep({"["})->ast(expr)->sep({"]"}) });
}