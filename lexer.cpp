enum Token {
    eEOF = -1,
    eDEF = -2,
    eEXTERN = -3,

  // primary
  eIDENTIFIER = -4,
  eNUMBER = -5,
}; 

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number