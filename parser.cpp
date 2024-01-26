#include "expr.hpp"
#include "expr_handelers.hpp"

void main_loop()
{

    auto tokenizer = Tokenizer();

    while (true)
    {
        auto token = tokenizer.getNextToken();
        EXPR_HANDLERS[token](token);
        if (token == Token::eEOF)
        {
            return;
        }
    }
}

int main() {
    main_loop();
}
