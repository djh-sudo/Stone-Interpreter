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

# Demo
open you cmd,and input `gcc [filename] [-s]`,filename is path of source code you want to intepreter and -s is optional chose,which means step by step output 
```
stone.exe gcc ../t.st -s
```
# Source demo1 - Fibonacci
```C
def Foo(n){
	if(n == 0 || n == 1){
	1
	}else{
		Foo(n-1) + Foo(n-2)
	}
}

n = 20
while(n>=1){
	g = Foo(n)
	n = n - 1
	print("F(",n,")=>",g)
}
print("print over!")
```
# Source demo2 - Bubble-Sort
```C
a = [123,43,234,567,32,90,128,67,58,124,900]
n = 11
for(i=0;i<n-1;i=i+1){
	for(j=i;j<n;j=j+1){
		if(a[i]>a[j]){
			temp = a[i]
			a[i] = a[j]
			a[j] = temp
		}
	}
}
print("Bubble Sort:",a)

```

# Source demo3 - class
```C
class Position{
	x = 0
	y = 0
	array = [1,2,3,4]
	def move(nx,ny){
		x = nx
		y = ny
	}
}
p = Position.new
print("before:",p.x,p.y)
p.move(3,4)
print("after:",p.x,p.y)

class Position3D extends Position{
	z = 0
	def move(nx,ny,nz){
	x = nx;y=ny
	z = nz
}
}
p3d = Position3D.new
p3d.move(1,2,3)
print(p3d.x,p3d.y,p3d.z)
```

