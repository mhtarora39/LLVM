#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include <iostream>

#include "expr.hpp"
#include "lexer.hpp"

using ExprHandler = std::function<std::unique_ptr<ExprAST>(const Token &)>;

auto place_holder_handler = [](const Token &tok) -> std::unique_ptr<ExprAST>
{
    std::cout << "Found Expression Type " << tokenToStringMap[tok] << std::endl;
    return std::make_unique<ExprAST>();
};

std::unordered_map<Token, ExprHandler> EXPR_HANDLERS = {
    {Token::eDEF, place_holder_handler},
    {Token::eEOF, place_holder_handler},
    {Token::eEXTERN, place_holder_handler},
    {Token::eIDENTIFIER, place_holder_handler},
    {Token::eNUMBER, place_holder_handler},
    {Token::eUNKNOWN, place_holder_handler},
};