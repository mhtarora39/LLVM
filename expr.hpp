#pragma once

#include <memory>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Visitor;

class ExprAST
{
public:
  virtual ~ExprAST() = default;
  virtual std::string getType()
  {
    return "GenericExpr";
  }
  virtual void accept(Visitor *visitor)
  {
  }
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

class Visitor
{

  virtual void visit(NumberExprAST &node) = 0;
  virtual void visit(VariableExprAST &node) = 0;
  virtual void visit(BinaryExprAST &node) = 0;
  virtual void visit(CallExprAST &node) = 0;
};

class ExprVisitor : public Visitor
{
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
}

class FunctionAST
{
  std::unique_ptr<PrototypeAST> Proto;
  std::unique_ptr<ExprAST> Body;

public:
  std::string getType() override
  {
    return "FunctionAST";
  }

  FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptr<ExprAST> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}
};
