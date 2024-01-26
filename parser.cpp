#include "expr.hpp"
#include "expr_handelers.hpp"

class ASTContainer
{

    ASTContainer(std::unordered_map<Token, ExprHandler> expr_handlers = EXPR_HANDLERS){

    };

    using AstExpr = std::vector<std::vector<std::unique_ptr<ExprAST>>>;
};

void
main_loop()
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

int main()
{
    main_loop();
}
