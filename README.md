# Stone-Interpreter
### Two-week self-made scripting language 《两周自制脚本语言》

# Structure
```C
  * Object [对象类型]
		-> Integer
		-> String
		-> Boolean
		-> StoneObject
		-> Array
		-> Class
		-> Function
		-> NativeFunction
	* Token [token]
		-> IdToken
		-> NumberToken
		-> StrToken
	* ASTree [抽象语法树]
		-> * ASTList [非叶结点]
			-> * Postfix
				-> Dot
				-> Arguments
				-> ArrayRef
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
		-> * ASTLeaf [叶结点]
			-> StringLiteral
			-> Name
			-> NumberLiteral
	* Logic [逻辑]
		-> AstLogic
		-> ExprLogic
		-> IdLogic
		-> MaybeLogic
		-> NumberLogic
		-> OptionLogic
		-> OrLogic
		-> RepeatLogic
		-> SepLogic
	* Environment [解析环境]
		-> BasicEnvironment
		-> NestedEnvironment
	* BasicParser [语法分析]
		-> * FunctionParser
			-> * ClassParser
				-> ArrayParser
	* Rule [规则]
		-> ListRule
		-> OrRule
	* Exception [异常管理]
	* Lexer [词法分析]
	* ParserFactor
```

# Reference
1. almost source code is from [This person](https://github.com/hotsnow-sean/Stone-cpp)
2. The Book is called `Two-week self-made scripting language(Java version)`

# What did I do
1. Detailed notes
2. Some operators have been added
3. Added C-for loop structure
4. Fixed some bugs and Adjusted some structures

# What can you do
1. add more default naviveFunction like I/O
2. Generate intermediate code, This part you can read book
