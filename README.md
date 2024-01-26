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
