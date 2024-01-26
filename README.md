# LLVM
LLVM code generation Tutorial


# Recursive Descent Parsing

Recursive Descent Parsing is a technique used in computer science to parse (analyze and understand) the structure of strings of symbols or expressions, usually in the context of programming languages. It's a top-down parsing technique where you start from the top (the highest level of abstraction) and work your way down, recursively breaking down the input into smaller parts until you reach the individual symbols or tokens.

## Example

Let's consider a simple arithmetic expression: `3 + 4 * 2`.

### Parsing Steps

1. **Expression**:
   - An expression can be a term followed by an optional operator and another expression.
   - `3 + 4 * 2` can be split into `3` (term) and `+ 4 * 2` (rest of the expression).
   - Recursively parse the rest of the expression.

2. **Term**:
   - A term can be a factor followed by an optional operator and another term.
   - `+ 4 * 2` can be split into `+` (operator) and `4 * 2` (term).
   - Recursively parse the term.

3. **Factor**:
   - A factor can be a number or a group of expressions enclosed in parentheses.
   - `4 * 2` can be split into `4` (factor) and `* 2` (rest of the term).
   - Recursively parse the rest of the term.

4. **Factor**:
   - `* 2` can be split into `*` (operator) and `2` (factor).
   - Recursively parse the factor.

5. **Number**:
   - `2` is a number, so we've reached the base case of our recursion.

We've successfully parsed the entire expression using recursive descent parsing.

Recursive descent parsing is a common technique used in building parsers for programming languages because it's relatively easy to understand and implement, especially for simple grammars like arithmetic expressions. However, it may not be the most efficient technique for parsing complex grammars due to potential issues like left recursion and ambiguity. In those cases, more advanced parsing


## Operator-Precedence Parsing

Operator-precedence parsing is a method used in computer science to parse mathematical expressions based on the precedence of operators. It's commonly used in the context of building parsers for programming languages or mathematical expressions. The main idea is to use the precedence and associativity of operators to guide the parsing process.

### How Operator-Precedence Parsing Works:

1. **Precedence Levels**: Operators are categorized into precedence levels, where operators with higher precedence bind more tightly than operators with lower precedence.

2. **Associativity**: Operators at the same precedence level may have different associativity, which determines the order in which they are evaluated when they appear consecutively without parentheses.

3. **Parsing Table**: A parsing table is constructed based on the precedence and associativity of operators. This table guides the parsing process and helps in making decisions on how to combine operands and operators.

4. **Parsing Algorithm**: The parsing algorithm iterates over the input expression, maintaining a stack of operators and operands. It compares the precedence of the current operator with the operator on the top of the stack to decide whether to reduce or shift.

5. **Reducing and Shifting**: If the precedence of the current operator is higher, it's pushed onto the stack. If the precedence is lower or equal, operations are performed on the top of the stack until the precedence of the current operator is higher.

6. **Handling Parentheses**: Parentheses can override the default precedence and associativity rules. When encountering an open parenthesis, the algorithm treats it as the start of a new subexpression.

### Example:

Let's consider a simple example of an operator-precedence parser for arithmetic expressions with the following operators:

- Operators: `+`, `-`, `*`, `/`
- Precedence (from highest to lowest): `*`, `/`, `+`, `-`
- Left associativity for `+` and `-`
- Left associativity for `*` and `/`

Given the expression: `2 * 3 + 4 / 2 - 1`

1. **Parsing Table**:
   - Operators: `+`, `-`, `*`, `/`
   - Precedence: `* > / > + > -`
   - Associativity: Left for all operators

2. **Parsing Algorithm**:

   - Start with an empty stack.
   - Iterate over each token in the input expression.

3. **Parsing Steps**:

   - Push `2` onto the stack.
   - Push `*` onto the stack.
   - Push `3` onto the stack.
   - Perform `*` operation (`2 * 3 = 6`) and push the result onto the stack.
   - Push `+` onto the stack.
   - Push `4` onto the stack.
   - Push `/` onto the stack.
   - Push `2` onto the stack.
   - Perform `/` operation (`4 / 2 = 2`) and push the result onto the stack.
   - Perform `+` operation (`6 + 2 = 8`) and push the result onto the stack.
   - Push `-` onto the stack.
   - Push `1` onto the stack.
   - Perform `-` operation (`8 - 1 = 7`) and push the result onto the stack.

4. **Result**: The final result on the stack is `7`, which is the result of evaluating the expression `2 * 3 + 4 / 2 - 1`.

This is a basic example of how operator-precedence parsing works. In more complex scenarios, the parsing table and algorithm may need to handle a wider range of operators and expressions, but the fundamental principles remain the same.
