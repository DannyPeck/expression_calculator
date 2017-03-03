# expression_calculator
Expression Calculator not using Shunting Yard Algorithm

# Algorithm
Parse input by feeding it to ExpressionBuilder.
The ExpressionBuilder will build the final expression
by recursively reducing each operand for each operator
where the base case is a number.  This will call
build_expression passing in each side of the operator
and recursively build a Composite expression structure.

# Objects / Interfaces
- ExpressionBuilder
- Expr (Interface)
    - NumberExpr (Object)
    - OperatorExpr (Interface)
        - UnaryOperatorExpr (Abstract)
            - NegateOperatorExpr (Object)
        - BinaryOperatorExpr (Abstract)
            - AddOperatorExpr (Object)
            - SubOperatorExpr (Object)
            - MultiplyOperatorExpr (Object)
            - DivideOperatorExpr (Object)
                - DivideByZeroException (Object)

## ExpressionBuilder
### Properties
Expression * expr;

### Methods
#### Public
Expression * build_expression (String expr);

#### Private
Boolean base_case (String expr);