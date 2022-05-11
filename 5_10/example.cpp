# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string.h>
# include <vector> 
# include <string>
# include <math.h>

using namespace std;
int gLine = 1, gColumn = 0, gEOF = 1;
int gTokenListSize = 0;
bool gPeekChar = false;
bool gPeekToken = false;
bool gIsbool = false;
bool gTrueOrFalse = false;
bool gIsFloat = false;
bool gFirstTime = true;
string gFirstToken = "";
string gID = "", gOP = "", gNUM = "";

struct TOKEN {
  string token;
  string type;
  int line;
  int column;
};

struct IDENT {
  string ident;
  string type;
  double value;
};

vector<TOKEN> gTokenList;
vector<IDENT> gIdentList;

void SkipWhiteSpace( char & currentChar ) ;
void InputChar( char & currentChar ) ;
void SkipComment( char & currentChar ) ;
void GetIdent( string &currentToken, char &currentChar ) ;
void GetNum_digitFirst( string &currentToken, char &currentChar ) ;
void GetNum_dotFirst( string &currentToken, char &currentChar ) ;
bool IsIdent( string currentToken ) ;
bool IsIdent( string currentToken ) ;
bool IsInt( string currentToken ) ;
bool IsFloat( string currentToken ) ;
bool IsQuit( string currentToken ) ;
void GetType( string currentToken, string &currentTokenType ) ;
void GetToken( string &currentToken, char &currentChar, string &currentTokenType ) ;
void PrintAllType() ;
bool IDlessArithExpOrBexp( string &currentToken, char &currentChar, string &currentTokenType, string ident, 
                           double &factorValue ) ;
bool BooleanOperator( string &currentToken, char &currentChar, string &currentTokenType, string &OP ) ;
bool NOT_ID_StartArithExpOrBexp( string &currentToken, char &currentChar, string &currentTokenType, 
                                 double &factorValue ) ;
bool NOT_ID_StartArithExp( string &currentToken, char &currentChar, string &currentTokenType, 
                           double &factorValue ) ;
bool NOT_ID_StartTerm( string &currentToken, char &currentChar, string &currentTokenType, 
                       double &factorValue ) ;
bool NOT_ID_StartFactor( string &currentToken, char &currentChar, string &currentTokenType, 
                         double &factorValue ) ;
bool ArithExp( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) ;
bool Term( string &currentToken, char &currentChar, string &currentTokenType, double &factor1Value ) ;
bool Factor( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) ;
bool Command( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) ;
void Parser( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) ;
void SkipThisLine( string &currentToken, char &currentChar, string &currentTokenType ) ;
bool DefinedID( string currentToken ) ;
double FindIdentValue( string currentToken ) ;
string EXP( string error ) ;

void SkipWhiteSpace( char & currentChar ) {
  gEOF = scanf( "%c", &currentChar );
  if ( gEOF == -1 ) return;
  
  if ( currentChar == ' ' ) { // skip whitesapce
    gColumn ++;
    gEOF = scanf( "%c", &currentChar );
  } // if
  else if ( currentChar == '\t' ) {
    gColumn = gColumn + 2;
    gEOF = scanf( "%c", &currentChar );
  } // else if
  else if ( currentChar == '\n' ) {
    gColumn = 0;
    gLine++;
    gEOF = scanf( "%c", &currentChar );
  } // else if
  else { // not witespace
    gColumn++;
  } // else
  
} // SkipWhiteSpace()

void InputChar( char & currentChar ) {
  gEOF = scanf( "%c", &currentChar );
  
  if ( currentChar == ' ' ) { // skip whitesapce
    gColumn ++;
  } // if
  else if ( currentChar == '\t' ) {
    gColumn = gColumn + 2;
  } // else if
  else if ( currentChar == '\n' ) {
    gColumn = 0;
    gLine++;
  } // else if
  else { // not witespace
    gColumn++;
  } // else
  
} // InputChar()

void SkipComment( char & currentChar ) {
  gEOF = scanf( "%c", &currentChar );
  
  while ( currentChar != '\n' ) {
    gEOF = scanf( "%c", &currentChar );
  } // while
  
  gLine++;
  gColumn = 0;
  
} // SkipComment()

void GetIdent( string &currentToken, char &currentChar ) { 
  currentToken = currentChar;
  if ( !gPeekChar ) { // no gPeekChar, input next char
    InputChar( currentChar ); // input next char and calculate line and column
  } // if
  else {
    gPeekChar = false;
  } // else
  
  while ( ( currentChar >= 65 && currentChar <= 90 ) || 
          ( currentChar >= 97 && currentChar <= 122 ) || 
          ( currentChar >= 48 && currentChar <= 57 ) || currentChar == 95 ) {      
    currentToken = currentToken + currentChar;
    InputChar( currentChar );
  } // while
} // GetIdent()

void GetNum_digitFirst( string &currentToken, char &currentChar ) { // 35 or 35. or 35.8
  currentToken = currentChar;
  if ( !gPeekChar ) { // no gPeekChar , input next char
    InputChar( currentChar ); // input next char and calculate line and column
    
  } // if
  else {
    gPeekChar = false;
  } // else
  
  while ( currentChar >= '0' && currentChar <= '9' ) {
    currentToken = currentToken + currentChar;
    InputChar( currentChar );
  } // while
  
  if ( currentChar == '.' ) {
    currentToken = currentToken + currentChar;
    InputChar( currentChar );
  } // if
  
  while ( currentChar >= '0' && currentChar <= '9' ) {
    currentToken = currentToken + currentChar;
    InputChar( currentChar );
  } // while
  
} // GetNum_digitFirst()

void GetNum_dotFirst( string &currentToken, char &currentChar ) { // .35
  currentToken = currentChar;
  if ( !gPeekChar ) { // no gPeekChar , input next char
    InputChar( currentChar ); // input next char and calculate line and column
  } // if
  else {
    gPeekChar = false;
  } // else
  
  
  while ( currentChar >= '0' && currentChar <= '9' ) {
    currentToken = currentToken + currentChar;
    InputChar( currentChar );
  } // while
  
} // GetNum_dotFirst()

bool IsIdent( string currentToken ) { // check if this token is IDENT
  if ( currentToken[0] >= 65 && currentToken[0] <= 90 ) { // IDENT A-Z
    return true;
  } // if 
  else if ( currentToken[0] >= 97 && currentToken[0] <= 122 ) { // IDENT a-z
    return true;
  } // else if 
  
  return false;
  
} // IsIdent()

bool IsInt( string currentToken ) { // check if this token is INT
  for ( int i = 0 ; i < currentToken.size() ; i++ ) 
    if ( currentToken[i] < 48 || currentToken[i] > 57 ) 
      return false;
      
  return true;
} // IsInt()

bool IsFloat( string currentToken ) { // check if this token is FLOAT
  int dotnum = 1;
  for ( int i = 0 ; i < currentToken.size() ; i++ ) {
    if ( currentToken[i] < 48 || currentToken[i] > 57 ) {
      if ( currentToken[i] == '.' && dotnum == 1 ) { // first dot ( can only have one dot )
        dotnum --;
      } // if
      else {
        return false;
      } // else
    } // if
  } // for
  
  if ( dotnum == 0 && currentToken.size() > 1 )
    return true;
  
  return false;
} // IsFloat()

bool IsQuit( string currentToken ) { // check if this token is QUIT
  if ( currentToken == "quit" ) return true;
  
  return false;
} // IsQuit()

void GetType( string &currentToken, char &currentChar, string &currentTokenType ) {
  if ( gEOF == -1 ) return;
  TOKEN tempToken;
  tempToken.column = gColumn;
  tempToken.line = gLine;
  tempToken.token = currentToken;
  
  if ( currentToken == ";" ) tempToken.type = ";";
  else if ( currentToken == "=" ) tempToken.type = "=";
  else if ( currentToken == "+" ) tempToken.type = "+";
  else if ( currentToken == "-" ) tempToken.type = "-";
  else if ( currentToken == "*" ) tempToken.type = "*";
  else if ( currentToken == "/" ) tempToken.type = "/";
  else if ( currentToken == "(" ) tempToken.type = "("; 
  else if ( currentToken == ")" ) tempToken.type = ")";
  else if ( currentToken == ":=" ) tempToken.type = ":=";
  else if ( currentToken == "<>" ) tempToken.type = "<>";
  else if ( currentToken == ">" ) tempToken.type = ">";
  else if ( currentToken == "<" ) tempToken.type = "<";
  else if ( currentToken == ">=" ) tempToken.type = ">=";
  else if ( currentToken == "<=" ) tempToken.type = "<=";
  // else if ( IsQuit( currentToken ) ) tempToken.type = "QUIT";
  else if ( IsIdent( currentToken ) ) tempToken.type = "IDENT";
  else if ( IsInt( currentToken ) ) tempToken.type = "INT";
  else if ( IsFloat( currentToken ) ) tempToken.type = "FLOAT";
  else tempToken.type = "ERROR";
  
  if ( tempToken.type == "ERROR" ) {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unrecognized token" );
  } // if
  
  currentTokenType = tempToken.type;
  gTokenList.push_back( tempToken );
   
} // GetType()

void SkipThisLine( string &currentToken, char &currentChar, string &currentTokenType ) {
  if ( gEOF == -1 ) return;
  
  // gEOF = scanf( "%c", &currentChar );
  
  while ( currentChar != '\n' ) {
    gEOF = scanf( "%c", &currentChar );
  } // while
  
  gPeekToken = false;
  gLine++;
  gColumn = 0;

} // SkipThisLine() 

void GetToken( string &currentToken, char &currentChar, string &currentTokenType ) {
  if ( gPeekToken ) {
    gPeekToken = false;
    return; 
  } // if
  
  while ( gEOF != -1 ) { 
    if ( !gPeekChar ) { // no gPeekChar , input next char
      SkipWhiteSpace( currentChar ); // input next char and calculate line and column
      if ( gEOF == -1 ) return;
    } // if
    else {
      gPeekChar = false;
    } // else
    
    if ( currentChar == ';' || currentChar == '=' || currentChar == '+' || currentChar == '-' || 
         currentChar == '*' || currentChar == '(' || currentChar == ')' ) {
      currentToken = currentChar;   
      GetType( currentToken, currentChar, currentTokenType ); 
      return;
    } // if
    else if ( currentChar == ':' ) { // check this token is ':' or ':='
      currentToken = currentChar;
      InputChar( currentChar );
      if ( currentChar == '=' ) { // this token is ':='
        currentToken = currentToken + currentChar;
      } // if
      else { // this token is ':'
        gPeekChar = true; 
      } // else 

      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if
    else if ( currentChar == '<' ) { // check this token is '<' or '<=' or '<>'
      currentToken = currentChar;
      InputChar( currentChar );
      if ( currentChar == '=' ) { // this token is '<='
        currentToken = currentToken + currentChar;
      } // if
      else if ( currentChar == '>' ) { // this token is '<>'
        currentToken = currentToken + currentChar;
      } // else if
      else { // this token is '<'
        gPeekChar = true; 
      } // else
      
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if
    else if ( currentChar == '>' ) { // check this token is '>' or '>='
      currentToken = currentChar;
      InputChar( currentChar );
      if ( currentChar == '=' ) { // this token is '>='
        currentToken = currentToken + currentChar;
      } // if
      else { // this token is '>'
        gPeekChar = true; 
      } // else
      
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if
    else if ( currentChar == '/' ) { // check this token is '/' or '//'
      currentToken = currentChar;
      InputChar( currentChar );
      if ( currentChar == '/' ) { // this token is '//'
        currentToken = "";
        SkipComment( currentChar );
        SkipWhiteSpace( currentChar );
        gPeekChar = true;
      } // if
      else { // this token is '/'
        gPeekChar = true; 
        GetType( currentToken, currentChar, currentTokenType );
        return;
      } // else
    } // else if
    else if ( currentChar >= 'A' && currentChar <= 'Z' ) { // IDENT A-Z
      GetIdent( currentToken, currentChar );
      gPeekChar = true; 
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if 
    else if ( currentChar >= 'a' && currentChar <= 'z' ) { // IDENT a-z
      GetIdent( currentToken, currentChar );
      gPeekChar = true; 
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if 
    else if ( currentChar >= '0' && currentChar <= '9' ) { // NUM 35 or 35. or 35.8
      GetNum_digitFirst( currentToken, currentChar );
      gPeekChar = true;
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if
    else if ( currentChar == '.' ) { // NUM .8 or error
      GetNum_dotFirst( currentToken, currentChar );
      gPeekChar = true;
      GetType( currentToken, currentChar, currentTokenType );
      return;
    } // else if
    else if ( currentChar == ' ' || currentChar == '\n' || currentChar == '\t' ) {
      ; // donothing
    } // else if
    else {
      if ( gEOF != -1 ) {
        currentToken = currentChar;
        GetType( currentToken, currentChar, currentTokenType );
      } // if
      
      return;
    } // else
  } // while
} // GetToken()

void PrintAllType() {
  cout << gTokenList.size() << endl;
  for ( int i = 0 ; i < gTokenList.size() ; i++ ) {
    cout << "token: " << gTokenList[i].token << endl;
    cout << "type: " << gTokenList[i].type << endl;
    cout << "line: " << gTokenList[i].line << endl;
    cout << "column: " << gTokenList[i].column << endl << endl;
  } // for
} // PrintAllType()

string EXP( string error ) {
  return error;
} // EXP()

bool IDlessArithExpOrBexp( string &currentToken, char &currentChar, string &currentTokenType, string ident, 
                           double &factorValue ) {
                             
  bool firstTime = true;     
  double factor2Value;
  string operant;
  while ( currentTokenType == "+" || currentTokenType == "-" || currentTokenType == "*" || 
          currentTokenType == "/" ) {
    operant = currentTokenType;
    if ( !DefinedID( ident ) ) {  // for a+-*/? a undefined
      currentToken = ident;
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Undefined identifier" );
    } // if
    else {
      if ( firstTime ) {
        factorValue = FindIdentValue( ident );
        firstTime = false;
      } // if
    } // else
    
    gPeekToken = false;
    if ( currentTokenType == "+" ) {
      if ( Term( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        factorValue = factorValue + factor2Value; 
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // if
    else if ( currentTokenType == "-" ) {
      if ( Term( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        factorValue = factorValue - factor2Value; 
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // else if
    else if ( currentTokenType == "*" ) {
      if ( Factor( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        factorValue = factorValue * factor2Value; 
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // else if
    else if ( currentTokenType == "/" ) {
      gOP = currentTokenType ;
      if ( Factor( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        if ( gNUM != "" ) {  // for a/0
          if ( atof( gNUM.c_str() ) == 0 && gOP == "/" ) {
            currentToken = gNUM ;
            gNUM = "" ;
            gOP = "" ;
            SkipThisLine( currentToken, currentChar, currentTokenType );
            throw EXP( "ERROR" ) ;
          } // if
        } // if
        
        if ( gID != "" ) {  // for a/b  b = 0
          if ( factor2Value == 0 && gOP == "/" ) {
            currentToken = gID ;
            gID = "" ;
            gOP = "" ;
            SkipThisLine( currentToken, currentChar, currentTokenType );
            throw EXP( "ERROR" ) ;
          } // if
        } // if
        
        if ( fmod( factorValue, factor2Value ) != 0 ) gIsFloat = true;
        factorValue = factorValue / factor2Value; 
        
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // else if   
    
  } // while
  
  double factor1Value = factorValue;
  float tolerance = 0.0001;
  
  if ( BooleanOperator( currentToken, currentChar, currentTokenType, operant ) ) {
    
    if ( !DefinedID( ident ) ) { // for a > < >= <= = ? a undefined
      currentToken = ident;
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Undefined identifier" );
    } // if 
 
    if ( ArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
      if ( gID != "" ) { // for a > < >< >= <= = b   b undefined   a defined
        if ( !DefinedID( gID ) ) {
          currentToken = gID ;
          gID = "" ;
          SkipThisLine( currentToken, currentChar, currentTokenType );
          throw EXP( "Undefined identifier" );
        } // if
      } // if
      
      double larger;
      double smaller;
      if ( operant == "=" ) {
        if ( factor1Value > factorValue ) {
          larger = factor1Value;
          smaller = factorValue;
        } // if
        else {
          larger = factorValue;
          smaller = factor1Value;
        } // else
        
        if ( larger - smaller <= tolerance  ) {
          gTrueOrFalse = true;
        } // if
        else {
          gTrueOrFalse = false;
        } // else
      } // if
      else if ( operant == "<>" ) {
        if ( factor1Value > factorValue ) {
          larger = factor1Value;
          smaller = factorValue;
        } // if
        else {
          larger = factorValue;
          smaller = factor1Value;
        } // else
        
        if ( larger - smaller <= tolerance ) {
          gTrueOrFalse = false;
        } // if
        else {
          gTrueOrFalse = true;
        } // else
      } // else if
      else if ( operant == ">" ) {
        if ( factor1Value - tolerance > factorValue )
          gTrueOrFalse = true;
        else 
          gTrueOrFalse = false;
      } // else if
      else if ( operant == "<" ) {
        if ( factor1Value + tolerance < factorValue )
          gTrueOrFalse = true;
        else 
          gTrueOrFalse = false;
      } // else if
      else if ( operant == ">=" ) {
        if ( factor1Value - tolerance > factorValue ) {
          gTrueOrFalse = true;
        } // if
        else { // check if =         
          if ( factor1Value > factorValue ) {
            larger = factor1Value;
            smaller = factorValue;
          } // if
          else {
            larger = factorValue;
            smaller = factor1Value;
          } // else
          
          if ( larger - smaller <= tolerance ) {
            gTrueOrFalse = true;
          } // if
          else {
            gTrueOrFalse = false;
          } // else
        } // else
      } // else if
      else if ( operant == "<=" ) {
        if ( factor1Value + tolerance < factorValue ) {
          gTrueOrFalse = true;
        } // if
        else { // check if =         
          if ( factor1Value > factorValue ) {
            larger = factor1Value;
            smaller = factorValue;
          } // if
          else {
            larger = factorValue;
            smaller = factor1Value;
          } // else
          
          if ( larger - smaller <= tolerance ) {
            gTrueOrFalse = true;
          } // if
          else {
            gTrueOrFalse = false;
          } // else
        } // else
      } // else if
      else {
        cout << "non of above operant error" << endl; 
      } // else
      
      return true;
    } // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType ); 
      throw EXP( "Unexpected token" );
    } // else
  } // if
  else {
    return true;
  } // else

  return true;
} // IDlessArithExpOrBexp()

bool BooleanOperator( string &currentToken, char &currentChar, string &currentTokenType, string &OP ) {
  
  GetToken( currentToken, currentChar, currentTokenType );
  gPeekToken = true;
  if ( currentTokenType == "=" || currentTokenType == "<>" || currentTokenType == ">" || 
       currentTokenType == "<" || currentTokenType == ">=" || currentTokenType == "<=" ) {
    
    OP = currentToken;
    gIsbool = true;
    gPeekToken = false;
    return true;
  } // if
  
  return false;
} // BooleanOperator()

bool NOT_ID_StartArithExpOrBexp( string &currentToken, char &currentChar, string &currentTokenType, 
                                 double &factorValue ) {
  string operant;
  if ( NOT_ID_StartArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
    double factor1Value = factorValue;
    float tolerance = 0.0001;
    if ( BooleanOperator( currentToken, currentChar, currentTokenType, operant ) ) {
      if ( ArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
        double larger;
        double smaller;
        if ( operant == "=" ) {
          if ( factor1Value > factorValue ) {
            larger = factor1Value;
            smaller = factorValue;
          } // if
          else {
            larger = factorValue;
            smaller = factor1Value;
          } // else
          
          if ( larger - smaller <= tolerance ) {
            gTrueOrFalse = true;
          } // if
          else {
            gTrueOrFalse = false;
          } // else
        } // if
        else if ( operant == "<>" ) {
          if ( factor1Value > factorValue ) {
            larger = factor1Value;
            smaller = factorValue;
          } // if
          else {
            larger = factorValue;
            smaller = factor1Value;
          } // else
          
          if ( larger - smaller <= tolerance ) {
            gTrueOrFalse = false;
          } // if
          else {
            gTrueOrFalse = true;
          } // else
        } // else if
        else if ( operant == ">" ) {
          if ( factor1Value - tolerance > factorValue )
            gTrueOrFalse = true;
          else 
            gTrueOrFalse = false;
        } // else if
        else if ( operant == "<" ) {
          if ( factor1Value + tolerance < factorValue )
            gTrueOrFalse = true;
          else 
            gTrueOrFalse = false;
        } // else if
        else if ( operant == ">=" ) {
          if ( factor1Value - tolerance > factorValue ) {
            gTrueOrFalse = true;
          } // if
          else { // check if =         
            if ( factor1Value > factorValue ) {
              larger = factor1Value;
              smaller = factorValue;
            } // if
            else {
              larger = factorValue;
              smaller = factor1Value;
            } // else
            
            if ( larger - smaller <= tolerance ) {
              gTrueOrFalse = true;
            } // if
            else {
              gTrueOrFalse = false;
            } // else
          } // else
        } // else if
        else if ( operant == "<=" ) {
          if ( factor1Value + tolerance < factorValue ) {
            gTrueOrFalse = true;
          } // if
          else { // check if =         
            if ( factor1Value > factorValue ) {
              larger = factor1Value;
              smaller = factorValue;
            } // if
            else {
              larger = factorValue;
              smaller = factor1Value;
            } // else
            
            if ( larger - smaller <= tolerance ) {
              gTrueOrFalse = true;
            } // if
            else {
              gTrueOrFalse = false;
            } // else
          } // else
        } // else if
        else {
          cout << "non of above operant error" << endl; 
        } // else

        return true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // if
    else {
      return true;
    } // else
  } // if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" );
  } // else
  
} // NOT_ID_StartArithExpOrBexp()

bool NOT_ID_StartArithExp( string &currentToken, char &currentChar, string &currentTokenType, 
                           double &factorValue ) {
  double factor2Value;
  string plusORminus;
  if ( NOT_ID_StartTerm( currentToken, currentChar, currentTokenType, factorValue ) ) {
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    while ( currentTokenType == "+" || currentTokenType == "-" ) {
      plusORminus = currentTokenType;
      gPeekToken = false;
      if ( Term( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        
        if ( plusORminus == "+" ) {
          factorValue = factorValue + factor2Value;        
        } // if
        else if ( plusORminus == "-" ) {
          factorValue = factorValue - factor2Value;
        } // else if
        else {
          cout << "non of mul or div error" << endl;
        } // else
        
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // while()
    
    return true;
  } // if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" );
  } // else
 
} // NOT_ID_StartArithExp()

bool NOT_ID_StartTerm( string &currentToken, char &currentChar, string &currentTokenType, 
                       double &factorValue ) {
  double factor2Value;
  string mulORdiv;
  if ( NOT_ID_StartFactor( currentToken, currentChar, currentTokenType, factorValue ) ) {
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    while ( currentTokenType == "*" || currentTokenType == "/" ) { 
      mulORdiv = currentTokenType;
      gOP = currentTokenType ;
      gPeekToken = false;
      if ( Factor( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        
        if ( mulORdiv == "*" ) {
          factorValue = factorValue * factor2Value;
        } // if
        else if ( mulORdiv == "/" ) {
          if ( gNUM != "" ) {  // for 3/0
            if ( atof( gNUM.c_str() ) == 0 && gOP == "/" ) {
              currentToken = gNUM ;
              gNUM = "" ;
              gOP = "" ;
              SkipThisLine( currentToken, currentChar, currentTokenType );
              throw EXP( "ERROR" ) ;
            } // if
          } // if
          
          if ( gID != "" ) {  // for 3/a a = 0
            if ( factor2Value == 0 && gOP == "/" ) {
              currentToken = gID ;
              gID = "" ;
              gOP = "" ;
              SkipThisLine( currentToken, currentChar, currentTokenType );
              throw EXP( "ERROR" ) ;
            } // if
          } // if
          
          if ( fmod( factorValue, factor2Value ) != 0 ) gIsFloat = true;
          
          factorValue = factorValue / factor2Value;
        } // else if
        else {
          cout << "non of mul or div error" << endl;
        } // else
      
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    } // while
    
    return true;
  } // if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" );
  } // else

} // NOT_ID_StartTerm()

bool NOT_ID_StartFactor( string &currentToken, char &currentChar, string &currentTokenType, 
                         double &factorValue ) {
  GetToken( currentToken, currentChar, currentTokenType );
  gPeekToken = true;
  if ( currentTokenType == "+" || currentTokenType == "-" ) {
    string sign = currentTokenType;
    gPeekToken = false;
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    
    if ( currentTokenType == "INT" || currentTokenType == "FLOAT" ) {
      if ( currentTokenType == "INT" ) {
        if ( sign == "+" ) {
          factorValue = 1 * atoi( currentToken.c_str() ) ;
        } // if
        else if ( sign == "-" ) {
          factorValue = -1 * atoi( currentToken.c_str() ) ;
        } // else if
        else {
          cout << "sign error" << endl;
        } // else
      } // if
      else if ( currentTokenType == "FLOAT" ) {
        gIsFloat = true;
        if ( sign == "+" ) {
          factorValue = 1 * atof( currentToken.c_str() ) ;
        } // if
        else if ( sign == "-" ) {
          factorValue = -1 * atof( currentToken.c_str() ) ;
        } // else if
        else {
          cout << "sign error" << endl;
        } // else
      } // else if
      else {
        cout << "none int or flaot error" << endl;
      } // else
      
      
      gPeekToken = false;
      return true;
    } // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" );
    } // else
  } // if
  else if ( currentTokenType == "INT" || currentTokenType == "FLOAT" ) {
    if ( currentTokenType == "INT" ) {
      factorValue = 1 * atoi( currentToken.c_str() ) ;
    } // if
    else if ( currentTokenType == "FLOAT" ) {
      gIsFloat = true;
      factorValue = 1 * atof( currentToken.c_str() ) ;
    } // else if

    gPeekToken = false;
    return true;
  } // else if
  else if ( currentTokenType == "(" ) {
    gPeekToken = false;
    if ( ArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
      GetToken( currentToken, currentChar, currentTokenType );
      gPeekToken = true;
      if ( currentTokenType == ")" ) {
        gPeekToken = false;
        return true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" );
      } // else
    }  // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" );
    } // else
  } // else if
  else { 
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" );
  } // else
  
} // NOT_ID_StartFactor()

bool ArithExp( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) {

  double factor2Value;
  string plusORminus;
  if ( Term( currentToken, currentChar, currentTokenType, factorValue ) ) {
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    
    while ( currentTokenType == "+" || currentTokenType == "-" ) {
      plusORminus = currentTokenType;
      gPeekToken = false;
      if ( Term( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        
        if ( plusORminus == "+" ) {
          factorValue = factorValue + factor2Value;
        } // if
        else if ( plusORminus == "-" ) {
          factorValue = factorValue - factor2Value;
        } // else if
        else {
          cout << "non of mul or div error" << endl;
        } // else
          
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" ) ;
      } // else
    } // while

    return true;
  } // if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" ) ;
  } // else
  
  return true;
} // ArithExp()

bool Term( string &currentToken, char &currentChar, string &currentTokenType, double &factor1Value ) {
  double factor2Value;
  string mulORdiv;
  if ( Factor( currentToken, currentChar, currentTokenType, factor1Value ) ) {
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    
    while ( currentTokenType == "*" || currentTokenType == "/" ) {
      gOP = currentTokenType ;
      mulORdiv = currentTokenType;
      gPeekToken = false;
      if ( Factor( currentToken, currentChar, currentTokenType, factor2Value ) ) {
        
        if ( mulORdiv == "*" ) {
          factor1Value = factor1Value * factor2Value;
        } // if
        else if ( mulORdiv == "/" ) { // for a := 1/0 or a:= 1/b b=0
          if ( factor2Value == 0 ) {
            currentToken = gID ;
            gNUM = "" ;
            gOP = "" ;
            SkipThisLine( currentToken, currentChar, currentTokenType );
            throw EXP( "ERROR" ) ;
          } // if
          
          
          if ( fmod( factor1Value, factor2Value ) != 0 ) gIsFloat = true;
          factor1Value = factor1Value / factor2Value;
        } // else if
        else {
          cout << "non of mul or div error" << endl;
        } // else
        
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" ) ;
      } // else
    } // while
    
    return true;
  } // if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" ) ;
  } // else
  
  return true;
} // Term()

bool DefinedID( string currentToken ) {
  for ( int i = 0 ; i < gIdentList.size() ; i++ ) {
    if ( currentToken == gIdentList[i].ident ) {
      return true;
    } // if
  } // for
  
  return false;
} // DefinedID()

double FindIdentValue( string currentToken ) {
  double returnValue = -877777;
  
  for ( int i = 0 ; i < gIdentList.size() ; i++ ) {
    if ( currentToken == gIdentList[i].ident ) {
      returnValue = gIdentList[i].value;
      if ( gIdentList[i].type == "FLOAT" ) gIsFloat = true;
      else gIsFloat = false;
    } // if
  } // for
  
  return returnValue;
} // FindIdentValue()

bool Factor( string &currentToken, char &currentChar, string &currentTokenType, 
             double &factorValue ) {
  GetToken( currentToken, currentChar, currentTokenType );
  gPeekToken = true;
  if ( currentTokenType == "IDENT" ) {

    if ( gFirstTime && !DefinedID( currentToken ) ) {
      gFirstTime = false;
      gFirstToken = currentToken;
    } // if
    
    factorValue = FindIdentValue( currentToken ) ;   
    gPeekToken = false;
    gID = currentToken;
    return true;
  } // if
  else if ( currentTokenType == "+" || currentTokenType == "-" ) {
    string sign = currentTokenType;
    gPeekToken = false;
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    if ( currentTokenType == "INT" || currentTokenType == "FLOAT" ) {
      if ( currentTokenType == "INT" ) {
        if ( sign == "+" ) {
          factorValue = 1 * atoi( currentToken.c_str() ) ;
        } // if
        else if ( sign == "-" ) {
          factorValue = -1 * atoi( currentToken.c_str() ) ;
        } // else if
        else {
          cout << "sign error" << endl;
        } // else
      } // if
      else if ( currentTokenType == "FLOAT" ) {
        gIsFloat = true;
        if ( sign == "+" ) {
          factorValue = 1 * atof( currentToken.c_str() ) ;
        } // if
        else if ( sign == "-" ) {
          factorValue = -1 * atof( currentToken.c_str() ) ;
        } // else if
        else {
          cout << "sign error" << endl;
        } // else
      } // else if
      else {
        cout << "none int or flaot error" << endl;
      } // else
      
      gPeekToken = false;
      return true;
    } // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" ) ;
    } // else
  } // else if
  else if ( currentTokenType == "INT" || currentTokenType == "FLOAT" ) {
    if ( currentTokenType == "INT" ) {
      factorValue = 1 * atoi( currentToken.c_str() ) ;
    } // if
    else if ( currentTokenType == "FLOAT" ) {
      gIsFloat = true;
      factorValue = 1 * atof( currentToken.c_str() ) ;
    } // else if

    gPeekToken = false;
    gNUM = currentToken;
    return true;
  } // else if
  
  else if ( currentTokenType == "(" ) {
    gPeekToken = false;
    if ( ArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
      GetToken( currentToken, currentChar, currentTokenType );
      gPeekToken = true;
      if ( currentTokenType == ")" ) {
        gPeekToken = false;
        return true;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" ) ;
      } // else
    } // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" ) ;
    } // else
  } // else if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" ) ;
  } // else
  
} // Factor()

bool Command( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) {
  string ident = "";
  ident = currentToken;
  
  if ( currentTokenType == "IDENT" ) {
    gPeekToken = false;
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    if ( currentTokenType == ":=" ) {
        
      gPeekToken = false;
      if ( ArithExp( currentToken, currentChar, currentTokenType, factorValue ) ) {
        GetToken( currentToken, currentChar, currentTokenType );
        gPeekToken = true;
        if ( currentTokenType == ";" ) { // throw error until this command is finish ( after ; )
          if ( gID != "" ) { // for a:=b  b undefined
            if ( !DefinedID( gID ) ) {
              currentToken = gID ;
              gID = "" ;
              SkipThisLine( currentToken, currentChar, currentTokenType );
              throw EXP( "Undefined identifier" ) ;
            } // if
          } // if
          
          
          
          IDENT temp;
          temp.ident = ident;
          temp.value = factorValue;
          if ( gIsFloat ) temp.type = "FLOAT";
          else temp.type = "INT";
          
          gIdentList.push_back( temp );
          gPeekToken = false;
          return true ;
        } // if
        else {
          SkipThisLine( currentToken, currentChar, currentTokenType );
          throw EXP( "Unexpected token" ) ;
        } // else
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" ) ;
      } // else
    } // if
    else if ( currentTokenType == ";" ) { 
      if ( !DefinedID( ident ) ) { // for a; a undefined
        currentToken = ident ;
        gID = "" ;
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Undefined identifier" ) ;
      } // if
      
      factorValue = FindIdentValue( ident );
      gPeekToken = false;
      return true ;
    } // else if 
    else if ( IDlessArithExpOrBexp( currentToken, currentChar, currentTokenType, ident, factorValue ) ) {
      GetToken( currentToken, currentChar, currentTokenType );
      gPeekToken = true;
      if ( currentTokenType == ";" ) {
        
        if ( gID != "" ) { // for a+-*/b b undefined  
          if ( !DefinedID( gID ) ) {
            currentToken = gID ;
            gID = "" ;
            SkipThisLine( currentToken, currentChar, currentTokenType );
            throw EXP( "Undefined identifier" ) ;
          } // if
        } // if

        if ( gTokenList.size()-gTokenListSize == 2 ) {
          factorValue = FindIdentValue( ident );
        } // if
        
        gPeekToken = false;
        return true ;
      } // if
      else {
        SkipThisLine( currentToken, currentChar, currentTokenType );
        throw EXP( "Unexpected token" ) ;
      } // else
    } // else if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" ) ;
    } // else
  } // if
  else if ( NOT_ID_StartArithExpOrBexp( currentToken, currentChar, currentTokenType, factorValue ) ) {
    
    GetToken( currentToken, currentChar, currentTokenType );
    gPeekToken = true;
    if ( currentTokenType == ";" ) {
      
      if ( gID != "" ) { // for 456 +-*/ undefined
        if ( !DefinedID( gID ) ) {
          currentToken = gID ;
          gID = "" ;
          SkipThisLine( currentToken, currentChar, currentTokenType );
          throw EXP( "Undefined identifier" ) ;
        } // if
      } // if
      
      gPeekToken = false;
      return true;
    } // if
    else {
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" ) ;
    } // else
  } // else if
  else if ( currentTokenType == "QUIT" ) {
    gPeekToken = false;
    return true ;
  } // else if
  else {
    SkipThisLine( currentToken, currentChar, currentTokenType );
    throw EXP( "Unexpected token" ) ;
  } // else
} // Command()

void Parser( string &currentToken, char &currentChar, string &currentTokenType, double &factorValue ) {
  try {
    GetToken( currentToken, currentChar, currentTokenType );    
    if ( currentToken == "quit" ) {
      gEOF = -1;
      return;
    } // if
    
    gPeekToken = true;
    if ( gEOF == -1 ) return;
    
    if ( !Command( currentToken, currentChar, currentTokenType, factorValue ) ) { // do calculate 
      SkipThisLine( currentToken, currentChar, currentTokenType );
      throw EXP( "Unexpected token" );
    } // if
    else {
      gTokenListSize = gTokenList.size() ; 
      // cout << gTokenListSize << endl;
      currentToken = "" ;
      gPeekToken = false;
      gPeekChar = false; 
    } // else
  }
  catch ( const char* ErrorString ) {
    // cout << "Parser:" << ErrorString << endl; 
    throw ErrorString;
  } // catch()
  
} // Parser();

void RemoveErrorToken() {
  int errorNum = gTokenList.size()-gTokenListSize ;
  for ( int i = 0 ; i < errorNum ; i++ )
    gTokenList.pop_back() ;
} // RemoveErrorToken()

int main() {
  string currentToken = "", currentTokenType = "";
  int testnum;
  char currentChar = 'a';
  double factorValue;
  gEOF = scanf( "%d", &testnum );
  printf( "Program starts...\n" );
  while ( gEOF != -1 ) {
    try {
      gIsbool = false;
      gTrueOrFalse = false;
      gIsFloat = false;
      gFirstTime = true;
      gID = "";
      gNUM = "";
      gFirstToken = "";
      gOP = "";
      
      Parser( currentToken, currentChar, currentTokenType, factorValue );
      if ( currentToken == "quit" || gEOF == -1 ) {
        printf( "> Program exits..." );
        return 0;
      } // if
      
      if ( gIsbool ) { // '='  '<>'  '>'  '<'  '>='  '<='
        if ( gTrueOrFalse )
          printf( "> true\n" );
        else
          printf( "> false\n" );
          
        gIsbool = false;
        gTrueOrFalse = false;
      } // if
      else { // '+' '-' '*' '/'
        if ( gFirstToken != "" ) { // when all command is success and if there has undefined token
          printf( "> Undefined identifier : '%s'\n", gFirstToken.c_str() );
          // cout << "> Undefined identifier : '" << gFirstToken << "'" << endl;
        } // if
        else {
          if ( gIsFloat ) { // float
            printf( "> %.3f\n", factorValue );
          } // if
          else { // int
            printf( "> %.0f\n", factorValue );
          } // else
        } // else
        
        gIsFloat = false;
      } // else
    }
    catch ( string ErrorString ) {
      if ( ErrorString == "Unrecognized token" ) {
        printf( "> Unrecognized token with first char : '%s'\n", currentToken.c_str() );
        // cout << "> Unrecognized token with first char : '" << currentToken << "'" << endl;
        RemoveErrorToken();
      } // if
      else if ( ErrorString == "Unexpected token" ) {
        printf( "> Unexpected token : '%s'\n", currentToken.c_str() );
        // cout << "> Unexpected token : '" << currentToken << "'" << endl;
        RemoveErrorToken();
      } // else if
      else if ( ErrorString == "Undefined identifier" ) {
        if ( gFirstTime == false ) currentToken = gFirstToken;
        printf( "> Undefined identifier : '%s'\n", currentToken.c_str() );
        // cout << "> Undefined identifier : '" << currentToken << "'" << endl;
        RemoveErrorToken();
      } // else if
      else if ( ErrorString == "ERROR" ) {
        printf( "> Error\n" );
        // cout << "> Error" << endl;
        RemoveErrorToken();
      } // else if
      else {
        // printf( "NONE OF ABOVE ERROR\n" );
        // cout << "NONE OF ABOVE ERROR" << endl; 
      } // else
    } // catch()
  } // while
  
  printf( "> Program exits..." );
  // cout << "> Program exits..." << endl; 
  // PrintAllType();
} // main()



