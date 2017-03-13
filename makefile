OBJECT_FILES = Symbol.o Terminal.o Variable.o Start.o Number.o Expression.o \
               ExpressionTail.o Term.o TermTail.o Factor.o Context.o ExpressionParser.o \
               ParseTree.o Operator.o BinaryOperator.o AddOperator.o SubtractOperator.o MultiplyOperator.o \
               DivideOperator.o LeftParenthesis.o RightParenthesis.o main.o

C_FLAGS = --std=c++11 -g -c

calculator: $(OBJECT_FILES)
	g++ $(OBJECT_FILES) -o calculator

Symbol.o: Symbol.h Symbol.cpp
	g++ $(C_FLAGS) Symbol.cpp

Terminal.o: Symbol.o Terminal.h Terminal.cpp
	g++ $(C_FLAGS) Terminal.cpp

Variable.o: Symbol.o Variable.h Variable.cpp
	g++ $(C_FLAGS) Variable.cpp

Start.o: Variable.o Start.h Start.cpp
	g++ $(C_FLAGS) Start.cpp

Number.o: Terminal.o Number.h Number.cpp
	g++ $(C_FLAGS) Number.cpp

Expression.o: Symbol.o Expression.h Expression.cpp
	g++ $(C_FLAGS) Expression.cpp

ExpressionTail.o: Symbol.o ExpressionTail.h ExpressionTail.cpp
	g++ $(C_FLAGS) ExpressionTail.cpp

Term.o: Variable.o Term.h Term.cpp
	g++ $(C_FLAGS) Term.cpp

TermTail.o: Variable.o TermTail.h TermTail.cpp
	g++ $(C_FLAGS) TermTail.cpp

Factor.o: Variable.o Factor.h Factor.cpp
	g++ $(C_FLAGS) Factor.cpp

Context.o: Context.h Context.cpp
	g++ $(C_FLAGS) Context.cpp

ExpressionParser.o: ExpressionParser.h ExpressionParser.cpp
	g++ $(C_FLAGS) ExpressionParser.cpp

ParseTree.o: Symbol.o ParseTree.h ParseTree.cpp
	g++ $(C_FLAGS) ParseTree.cpp

Operator.o: Operator.h Operator.cpp
	g++ $(C_FLAGS) Operator.cpp

BinaryOperator.o: Operator.o BinaryOperator.h BinaryOperator.cpp
	g++ $(C_FLAGS) BinaryOperator.cpp

AddOperator.o: BinaryOperator.o AddOperator.h AddOperator.cpp
	g++ $(C_FLAGS) AddOperator.cpp

SubtractOperator.o: BinaryOperator.o SubtractOperator.h SubtractOperator.cpp
	g++ $(C_FLAGS) SubtractOperator.cpp

MultiplyOperator.o: BinaryOperator.o MultiplyOperator.h MultiplyOperator.cpp
	g++ $(C_FLAGS) MultiplyOperator.cpp

DivideOperator.o: BinaryOperator.o DivideOperator.h DivideOperator.cpp
	g++ $(C_FLAGS) DivideOperator.cpp

LeftParenthesis.o: Terminal.o LeftParenthesis.h LeftParenthesis.cpp
	g++ $(C_FLAGS) LeftParenthesis.cpp

RightParenthesis.o: Terminal.o RightParenthesis.h RightParenthesis.cpp
	g++ $(C_FLAGS) RightParenthesis.cpp

main.o: main.cpp
	g++ $(C_FLAGS) main.cpp

valgrind:
	make
	valgrind --leak-check=full -v --track-origins=yes --log-file=valgrind.txt ./calculator

clean:
	rm *.o calculator valgrind.txt
