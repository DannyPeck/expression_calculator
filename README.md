# expression_calculator
Expression Calculator using a Parsing Table and Grammar Objects

# Objects / Interfaces
- ExpressionParser
- Symbol (Interface)
    - Terminal (Interface)
        - Number (Object)
    - Variable (Interface)
        - Start (Object)
        - Expression (Object)
        - ExpressionTail (Object)
        - Term (Object)
        - TermTail (Object)
        - Factor (Object)
- Operator (Interface)
    - BinaryOperator (Interface)
        - AddOperator (Object)
        - SubOperator (Object)
        - MultiplyOperator (Object)
        - DivideOperator (Object)
- InvalidDerivationException (Object)
- DivideByZeroException (Object)