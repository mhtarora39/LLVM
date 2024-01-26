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
    {"number", Token::eNUMBER}};

struct Tokeinizer
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
    // check if last char was new EOF or NOT.

    // check if it digit or string
    while (isdigit(tok_chr) || tok_chr == '.')
    {

      token += tok_chr;
      tok_chr = getchar();
    }

    if (token != "")
    {
      num_val = std::stod(token);
      return Token::eNUMBER;
    }
    // if digit return eNumber
    // else Check if word is any identifier return its value.
    token = "";
    while ((tok_chr = getchar()) != SPACE && isalpha(tok_chr))
    {
      token += tok_chr;
      if (stringToTokenMap.find(token) != stringToTokenMap.end())
      {
        identifier = token;
        return stringToTokenMap[token];
      }
    }

    if(tok_chr == EOF) {
      return Token::eEOF;
    }
    return Token::eUNKNOWN;
  
    // can one line have multiple Tokens ?
  }
  std::string identifier;
  double num_val;
};