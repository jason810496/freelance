
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>

using namespace std;


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    while(t.tt!=EOF){
        if(t.tt==integer){
            numstack.push(t);
            t=S.getnext();
        }
        else if(t.tt==lptok){
            opstack.push(t);
            t=S.getnext();
        }
        else if(t.tt==rptok){
            if(opstack.peek().tt==lptok){
                opstack.pop();
                t=S.getnext();
            }
            else{
                Token num1=numstack.pop();
                Token num2=numstack.pop();
                Token op=opstack.pop();
                switch(op.tt){
                    case pltok:
                    num1.val=num1.val+num2.val;
                    break;

                    case mitok:
                    num1.val=num1.val-num2.val;
                    break;

                    case asttok:
                    num1.val=num1.val*num2.val;
                    break;

                    case slashtok:
                    num1.val=num1.val/num2.val;
                    break;
                }
                numstack.push(num1);
            }
        }
        else if(t.tt==pltok||t.tt==mitok||t.tt==EOF){
            if(opstack.isEmpty()==false&&(opstack.peek().tt==pltok||opstack.peek().tt==mitok||opstack.peek().tt==asttok||opstack.peek().tt==slashtok)){
                Token num1=numstack.pop();
                Token num2=numstack.pop();
                Token op=opstack.pop();
                switch(op.tt){
                    case pltok:
                    num1.val=num1.val+num2.val;
                    break;

                    case mitok:
                    num1.val=num1.val-num2.val;
                    break;

                    case asttok:
                    num1.val=num1.val*num2.val;
                    break;

                    case slashtok:
                    num1.val=num1.val/num2.val;
                    break;
                }
                numstack.push(num1);             
            }
            else{
                opstack.push(t);
                t=S.getnext();
            }
        }
        else if(t.tt==asttok||t.tt==slashtok){
            if(opstack.isEmpty()==false&&(opstack.peek().tt==asttok||opstack.peek().tt==slashtok)){
                Token num1=numstack.pop();
                Token num2=numstack.pop();
                Token op=opstack.pop();
                switch(op.tt){
                    case pltok:
                    num1.val=num1.val+num2.val;
                    break;

                    case mitok:
                    num1.val=num1.val-num2.val;
                    break;

                    case asttok:
                    num1.val=num1.val*num2.val;
                    break;

                    case slashtok:
                    num1.val=num1.val/num2.val;
                    break;
                }
                numstack.push(num1);             
            }
            else{
                opstack.push(t);
                t=S.getnext();
            }
        }
    }
    return numstack.pop().val;

    // pretty printer coding demo.  please remove before coding
    /*while (t.tt != eof) {
        if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
            cout << t;
        } else if (t.tt == pltok || t.tt == mitok || 
                   t.tt == asttok || t.tt == slashtok) {
            cout << ' ' << t << ' ';
        }

        t = S.getnext();
    }*/

    cout << endl;
    // end pretty printer

    return 0;
}


