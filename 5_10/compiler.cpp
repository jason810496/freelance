#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

inline bool is_whitespace(const char c){
    return ( c==' ' || c=='\n' || c=='\t');
}

inline bool is_letter(const char c){
    return ( ('a'<=c&&c<='z') || ('A'<=c||c<='Z') );
}

inline bool is_digit(const char c){
    return ('0'<=c&&c<='9');
}

inline bool is_float(const char c){
    return ( is_digit(c)||c=='.' );
}

inline bool is_letter_digit(const char c){
    return ( is_letter(c) || is_float(c) );
}

inline bool is_oper(const char c){
    return ( 
        '+'==c || '-'==c ||
        '*'==c || '/'==c ||
        '^'==c || '!'==c ||
        '<'==c || ','==c ||
        '>'==c || '='==c ||
        '('==c || ')'==c ||
        '['==c || ']'==c ||
        '{'==c || '}'==c ||
        '%'==c || ':'==c ||
        '?'==c || '&'==c ||
        '|'==c || ';'==c
    );
}

inline bool is_left_bracket(const char c){
    return ( '('==c ||'['==c || '{'==c );
}

inline bool is_right_bracket(const char c){
    return ( ')'==c || ']'==c ||'}'==c );
}

inline bool is_bracket(const char c){
    return is_left_bracket(c) || is_right_bracket(c) ;
}

inline bool is_sign(const char c){
    return ('+'==c || '-'==c );
}

inline bool invalid(const char c){
    return  !is_whitespace(c) &&
            !is_oper(c) &&
            !is_letter_digit(c) &&
            ( '_'!=c ) &&
            ( '~'!=c ) 
    ;
}

void ListAllVaribles();

void ListAllFunction();

void ListVariable(string name);

void ListFunction(string name);

void Done();

void SkipLine(){
    
}

/*  error message 

1.  lexical

unrecognized token with first char : '$' 

2.  syntactical error ( token recognized )

unexpected token : '*'

3. semantic error ( grammar ok )

undefined identifier : 'bcd'   


*/

/*  valid type

int 
string 
float
char 


*/

/* valid operator
+
-
*
/
<
>
<=
>=
!=

*/

/*



*/


