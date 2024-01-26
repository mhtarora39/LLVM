#pragma once

#include <string>
#include <stdio.h>
#include <unordered_map>

#define SPACE ' '
#define COMMENT '#'
#define NEW_LINE '\n'
#define LF '\r'

enum class Token
{
  eEOF = -1,
  eDEF = -2,
  eEXTERN = -3,

  // primary
  eIDENTIFIER = -4,
  eNUMBER = -5,
  eUNKNOWN = -100000
};

std::unordered_map<std::string, Token> stringToTokenMap = {
    {"eof", Token::eEOF},
    {"def", Token::eDEF},
    {"extern", Token::eEXTERN},
    {"identifier", Token::eIDENTIFIER},
    {"number", Token::eNUMBER},
    {"unknown", Token::eUNKNOWN}};

std::unordered_map<Token, std::string> tokenToStringMap = {
    {Token::eEOF, "eof"},
    {Token::eDEF, "def"},
    {Token::eEXTERN, "extern"},
    {Token::eIDENTIFIER, "identifier"},
    {Token::eNUMBER, "number"},
    {Token::eUNKNOWN, "unknown"}};

struct Tokenizer
{
  /*
  Reds the next tokens from the standard inputs.
  */
  Token getNextToken()
  {
    // Read the input from stdin
    std::string token = "";
    char tok_chr = SPACE;
    while (tok_chr == SPACE)
    {
      tok_chr = getchar();
    }
    // ignore the comments till new line , EOF , '\r',
    if (tok_chr == COMMENT)
    {
      while (tok_chr != EOF && tok_chr != NEW_LINE && tok_chr != LF)
      {
        tok_chr = getchar();
        if (tok_chr == EOF)
        {
          return Token::eEOF;
        }
      }
      return getNextToken();
    }

    // check if it digit or string
    while (isdigit(tok_chr) || tok_chr == '.')
    {

      token += tok_chr;
      tok_chr = getchar();
    }
    // if digit return eNumber
    if (token != "")
    {
      num_val = std::stod(token);
      return Token::eNUMBER;
    }
    // else Check if word is any identifier return its value.
    token = "";
    while (isalpha(tok_chr))
    {
      token += tok_chr;
      tok_chr = getchar();
      if (stringToTokenMap.find(token) != stringToTokenMap.end())
      {
        identifier = token;
        return stringToTokenMap[token];
      }
    }
    std::cout << "token == " << token << std::endl;
    // check if last char was new EOF or NOT.
    if (tok_chr == EOF)
    {
      return Token::eEOF;
    }
    return Token::eUNKNOWN;

    // can one line have multiple Tokens ?
  }
  std::string identifier;
  double num_val;
};
