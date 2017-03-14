OBJECT_FILES = Symbol.o Variable.o Start.o Number.o Expression.o \
               ExpressionTail.o Term.o TermTail.o Factor.o BinaryOperator.o \
               AddOperator.o SubtractOperator.o MultiplyOperator.o DivideOperator.o \
               LeftParenthesis.o RightParenthesis.o Context.o ExpressionParser.o ParseTree.o \
               StartProduction.o ExpressionProduction.o ExpressionTailAddProduction.o \
               ExpressionTailSubtractProduction.o EpsilonProduction.o TermProduction.o \
               TermTailMultiplyProduction.o TermTailDivideProduction.o FactorParenthesisProduction.o \
               FactorNumberProduction.o ProductionFlyweightFactory.o SymbolVisitor.o DerivationVisitor.o main.o

CFLAGS = --std=c++11 -g -c

calculator: $(OBJECT_FILES)
	g++ $(OBJECT_FILES) -o calculator

Symbol.o: Symbol.h Symbol.cpp
	g++ $(CFLAGS) Symbol.cpp

Variable.o: Symbol.o Variable.h Variable.cpp
	g++ $(CFLAGS) Variable.cpp

Start.o: Variable.o Start.h Start.cpp
	g++ $(CFLAGS) Start.cpp

Number.o: Terminal.h Number.h Number.cpp
	g++ $(CFLAGS) Number.cpp

Expression.o: Symbol.o Expression.h Expression.cpp
	g++ $(CFLAGS) Expression.cpp

ExpressionTail.o: Symbol.o ExpressionTail.h ExpressionTail.cpp
	g++ $(CFLAGS) ExpressionTail.cpp

Term.o: Variable.o Term.h Term.cpp
	g++ $(CFLAGS) Term.cpp

TermTail.o: Variable.o TermTail.h TermTail.cpp
	g++ $(CFLAGS) TermTail.cpp

Factor.o: Variable.o Factor.h Factor.cpp
	g++ $(CFLAGS) Factor.cpp

BinaryOperator.o: Terminal.h Operator.h BinaryOperator.h BinaryOperator.cpp
	g++ $(CFLAGS) BinaryOperator.cpp

AddOperator.o: BinaryOperator.o AddOperator.h AddOperator.cpp
	g++ $(CFLAGS) AddOperator.cpp

SubtractOperator.o: BinaryOperator.o SubtractOperator.h SubtractOperator.cpp
	g++ $(CFLAGS) SubtractOperator.cpp

MultiplyOperator.o: BinaryOperator.o MultiplyOperator.h MultiplyOperator.cpp
	g++ $(CFLAGS) MultiplyOperator.cpp

DivideOperator.o: BinaryOperator.o DivideOperator.h DivideOperator.cpp
	g++ $(CFLAGS) DivideOperator.cpp

LeftParenthesis.o: Terminal.h LeftParenthesis.h LeftParenthesis.cpp
	g++ $(CFLAGS) LeftParenthesis.cpp

RightParenthesis.o: Terminal.h RightParenthesis.h RightParenthesis.cpp
	g++ $(CFLAGS) RightParenthesis.cpp

Context.o: Context.h Context.cpp
	g++ $(CFLAGS) Context.cpp

ExpressionParser.o: ExpressionParser.h ExpressionParser.cpp
	g++ $(CFLAGS) ExpressionParser.cpp

ParseTree.o: Symbol.o ParseTree.h ParseTree.cpp
	g++ $(CFLAGS) ParseTree.cpp

StartProduction.o: Production.h StartProduction.h StartProduction.cpp
	g++ $(CFLAGS) StartProduction.cpp

ExpressionProduction.o: Production.h ExpressionProduction.h ExpressionProduction.cpp
	g++ $(CFLAGS) ExpressionProduction.cpp

ExpressionTailAddProduction.o: Production.h ExpressionTailAddProduction.h ExpressionTailAddProduction.cpp
	g++ $(CFLAGS) ExpressionTailAddProduction.cpp

ExpressionTailSubtractProduction.o: Production.h ExpressionTailSubtractProduction.h ExpressionTailSubtractProduction.cpp
	g++ $(CFLAGS) ExpressionTailSubtractProduction.cpp

EpsilonProduction.o: Production.h EpsilonProduction.h EpsilonProduction.cpp
	g++ $(CFLAGS) EpsilonProduction.cpp

TermProduction.o: Production.h TermProduction.h TermProduction.cpp
	g++ $(CFLAGS) TermProduction.cpp

TermTailMultiplyProduction.o: Production.h TermTailMultiplyProduction.h TermTailMultiplyProduction.cpp
	g++ $(CFLAGS) TermTailMultiplyProduction.cpp

TermTailDivideProduction.o: Production.h TermTailDivideProduction.h TermTailDivideProduction.cpp
	g++ $(CFLAGS) TermTailDivideProduction.cpp

FactorParenthesisProduction.o: Production.h FactorParenthesisProduction.h FactorParenthesisProduction.cpp
	g++ $(CFLAGS) FactorParenthesisProduction.cpp

FactorNumberProduction.o: Production.h FactorNumberProduction.h FactorNumberProduction.cpp
	g++ $(CFLAGS) FactorNumberProduction.cpp

ProductionFlyweightFactory.o: ProductionFactory.h ProductionFlyweightFactory.h ProductionFlyweightFactory.cpp
	g++ $(CFLAGS) ProductionFlyweightFactory.cpp

SymbolVisitor.o: SymbolVisitor.h SymbolVisitor.cpp
	g++ $(CFLAGS) SymbolVisitor.cpp

DerivationVisitor.o: SymbolVisitor.o DerivationVisitor.h DerivationVisitor.cpp
	g++ $(CFLAGS) DerivationVisitor.cpp

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

valgrind:
	make
	valgrind --leak-check=full -v --track-origins=yes --log-file=valgrind.txt ./calculator

clean:
	rm *.o calculator valgrind.txt
