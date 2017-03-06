# Expression Calculator
Expression Calculator using a Parsing Table and Grammar Objects

## Input Constraints
- I have designed the calculator to only accept input where there is a space
between each token. e.g. ( 1 + 3 ) * ( 4 - 2 )
- To quit the program enter the input QUIT

## Supported Operators / Symbols
- Addition: +
- Subtraction: -
- Multiplication: *
- Division: /
- Left Parenthesis: (
- Right Parenthesis: )

## Algorithm
I have built essentially a Pushdown Automaton (a finite state machine with a stack)
that parses incoming symbols and performs a top down derivation of the language using a LL(1)
(Left Lookahead 1, only needs to look at one symbol at a time) grammar to build a Composite Parse Tree
made of Symbols which I can then evaluate to calculate the answer. This is possible because the grammar
that I have used integrates operator precedence into the grammar itself.  This can be viewed as
an implementation of the Interpreter pattern and the Composite Pattern.

### Grammar
#### Notes
- epsilon represents the empty string
- eof represents the end of the input
- Number, (, ), +, -, *, and / are terminal symbols
- Start, Expression, ExpressionTail, Term, TermTail, and Factor are Variables

#### Productions
- 1:  Start -> Expression
- 2:  Expression -> Term ExpressionTail
- 3:  ExpressionTail -> + Term ExpressionTail
- 4:  ExpressionTail -> - Term ExpressionTail
- 5:  ExpressionTail -> epsilon
- 6:  Term -> Factor TermTail
- 7:  TermTail -> * Factor TermTail
- 8:  TermTail -> / Factor TermTail
- 9:  TermTail -> epsilon
- 10: Factor -> ( Expression )
- 11: Factor -> Number

#### Parse Table
The Parse Table represents the derivation decisions and built into
each Variables derive method logic.

|   | ( | ) | + | - | * | / | Number | eof |
|---|---|---|---|---|---|---|--------|-----|
| S | 1 |   |   |   |   |   |   1    |     |
| E | 2 |   |   |   |   |   |   2    |     |
| ExpressionTail  |   | 5 | 3 | 4 |   |   |        |  5  |
| Term  | 6 |   |   |   |   |   |   6   |     |
| TermTail |   | 9 | 9 | 9 | 7 | 8 |        |  9  |
| Factor | 10 |   |   |   |   |   |   11   |     |


## Objects / Interfaces
- ExpressionParser
- Context (Object)
- Symbol (Interface)
    - Terminal (Interface)
        - Number (Object)
        - LeftParenthesis (Object)
        - RightParenthesis (Object)
        - Operator (Interface)
              - BinaryOperator (Abstract)
                  - AddOperator (Object)
                  - SubOperator (Object)
                  - MultiplyOperator (Object)
                  - DivideOperator (Object)
    - Variable (Interface)
        - Start (Object)
        - Expression (Object)
        - ExpressionTail (Object)
        - Term (Object)
        - TermTail (Object)
        - Factor (Object)

## Exceptions
- InvalidDerivationException (Object)
- DivideByZeroException (Object)