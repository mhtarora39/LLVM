#pragma once

#include <memory>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

Tokenizer tokenizer;
class Visitor;

class ExprAST
{
public:
  virtual ~ExprAST() = default;
  virtual std::string getType()
  {
    return "GenericExpr";
  }
  virtual void accept(Visitor *visitor) = 0;
};

class NumberExprAST : public ExprAST
{
  double Val;

public:
  std::string getType() override
  {
    return "NumberExprAST";
  }
  virtual void accept(Visitor *visitor)
  {
    visitor->visit(*this);
  }

  NumberExprAST(double Val) : Val(Val) {}
};

class VariableExprAST : public ExprAST
{
  std::string Name;

public:
  std::string getType() override
  {
    return "VariableExprAST";
  }
  virtual void accept(Visitor *visitor)
  {
    visitor->visit(*this);
  }

  VariableExprAST(const std::string &Name) : Name(Name) {}
};

class BinaryExprAST : public ExprAST
{
  char Op;
  std::unique_ptr<ExprAST> LHS, RHS;

public:
  std::string getType() override
  {
    return "BinaryExprAST";
  }
  virtual void accept(Visitor *visitor)
  {
    visitor->visit(*this);
  }

  BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                std::unique_ptr<ExprAST> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

class CallExprAST : public ExprAST
{
  std::string Callee;
  std::vector<std::unique_ptr<ExprAST>> Args;

public:
  std::string getType() override
  {
    return "CallExprAST";
  }
  virtual void accept(Visitor *visitor)
  {
    visitor->visit(*this);
  }

  CallExprAST(const std::string &Callee,
              std::vector<std::unique_ptr<ExprAST>> Args)
      : Callee(Callee), Args(std::move(Args)) {}
};

class PrototypeAST
{
  std::string Name;
  std::vector<std::string> Args;

public:
  std::string getType() override
  {
    return "PrototypeAST";
  }
  PrototypeAST(const std::string &Name, std::vector<std::string> Args)
      : Name(Name), Args(std::move(Args)) {}

  const std::string &getName() const { return Name; }
};

/// FunctionAST - This class represents a function definition itself.
class FunctionAST
{
  std::unique_ptr<PrototypeAST> Proto;
  std::unique_ptr<ExprAST> Body;

public:
  virtual void accept(Visitor *visitor)
  {
    visitor->visit(*this);
  }
  FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptr<ExprAST> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}
};

class Visitor
{
public:
  virtual void visit(NumberExprAST &node) = 0;
  virtual void visit(VariableExprAST &node) = 0;
  virtual void visit(BinaryExprAST &node) = 0;
  virtual void visit(CallExprAST &node) = 0;
};

class ExprVisitor : public Visitor
{
public:
  virtual void visit(NumberExprAST &node)
  {
  }
  virtual void visit(VariableExprAST &node)
  {
  }
  virtual void visit(BinaryExprAST &node)
  {
  }
  virtual void visit(CallExprAST &node)
  {
  }
  virtual void visit(FunctionAST &node)
  {
  }

private:
  std::vector<std::unique_ptr<ExprAST>> ast_container;
};

// Parser class
class Parser
{
  std::unordered_map<char, int> BinopPrecedence;
  Tokenizer m_tokenizer;

public:
  Parser(Tokenizer &tokenizer) : m_tokenizer(tokenizer)
  {
    // Install standard binary operators.
    // 1 is lowest precedence.
    BinopPrecedence['<'] = 10;
    BinopPrecedence['+'] = 20;
    BinopPrecedence['-'] = 20;
    BinopPrecedence['*'] = 40; // highest.
  }

  std::unique_ptr<ExprAST> ParseExpression();
  std::unique_ptr<PrototypeAST> ParsePrototype();
  std::unique_ptr<FunctionAST> ParseDefinition();
  std::unique_ptr<FunctionAST> ParseTopLevelExpr();
  std::unique_ptr<PrototypeAST> ParseExtern();
  std::unique_ptr<NumberExprAST> ParseNumber();
  void MainLoop();
  int getNextToken();
};

std::unique_ptr<NumberExprAST> Parser::ParseNumber()
{
  // Placeholder for prototype parsing logic
  return std::make_unique<NumberExprAST>(tokenizer.num_val);
}

std::unique_ptr<ExprAST> Parser::ParseExpression()
{
  // Placeholder for expression parsing logic
  return nullptr;
}

std::unique_ptr<PrototypeAST> Parser::ParsePrototype()
{
  // Placeholder for prototype parsing logic
  return nullptr;
}

std::unique_ptr<FunctionAST> Parser::ParseDefinition()
{
  // Placeholder for function definition parsing logic
  tokenizer.getNextToken();
  auto proto = ParsePrototype();
  if(!proto) {
    return nullptr;
  }
  tokenizer.getNextToken();
  auto expr = ParseExpression();
  return std::make_unique<FunctionAST>(std::move(proto))
}

std::unique_ptr<FunctionAST> Parser::ParseTopLevelExpr()
{
  // Placeholder for top-level expression parsing logic
  return nullptr;
}

std::unique_ptr<PrototypeAST> Parser::ParseExtern()
{
  // Placeholder for external prototype parsing logic
  return nullptr;
}

void Parser::MainLoop()
{
  while (true)
  {
    auto token = m_tokenizer.getNextToken();
    switch (token)
    {
      case Token::eEOF:
        return;
      case Token::eUNKNOWN:
      {
        ParseExpression();
        break;
      }
      case Token::eDEF:
      {
        ParseDefinition();
        break;
      }
      case Token::eEXTERN:
      {
        ParseExtern();
        break;
      }
      default:
      {
        ParseTopLevelExpr();
      }
    }
  }
}

int main()
{
  ExprVisitor *visitor;
}