#include <iostream>
#include "PilaChar.h"
using namespace std;

char contrari(char c){return c=='('?')':(c=='{'?'}':(c=='['?']':3));}

bool benparentitzat(string s){
    bool b=true; PilaChar p; int c=-1;
    while(++c<s.length() && b)
        if(s[c]=='(' || s[c]=='[' || s[c]=='{')p.empila(s[c]);
        else if(s[c]==')' || s[c]==']' || s[c]=='}')
            if(!p.buida() && contrari(p.cim())==s[c])p.desempila();
            else b=false;
    return b && p.buida();
}

int main()
{
    string cadena;
    while(1234){
        cin>>cadena;
        cout<<(benparentitzat(cadena)?"Ok":"Mec")<<endl;
    }
    return 0;
}

/*
char contrari(char c){
    if(c=='(')return ')';
    if(c=='{')return '}';
    if(c=='[')return ']';
}

bool benparentitzat(string s){
    bool estabe=true;
    PilaChar p;
    int cmpt=0;
    while(estabe and cmpt<s.length()){
        if(s[cmpt]=='(' || s[cmpt]=='[' || s[cmpt]=='{')p.empila(s[cmpt]);
        else if(s[cmpt]==')' || s[cmpt]==']' || s[cmpt]=='}'){
            if(p.cim()==contrari(s[cmpt]))p.desempila();
            else estabe=false;
        }
        cmpt++;
    }
    if(!p.buida())estabe=false;
    return estabe;
}*/

/* versio que ufnciona
bool benparentitzat(string s){
    bool estabe=true; PilaChar p; int c=0;
    while(c<s.length() and estabe){
        if(s[c]=='(' || s[c]=='[' || s[c]=='{')p.empila(s[c]);
        else if(s[c]==')' || s[c]==']' || s[c]=='}')
            if(!p.buida() && contrari(p.cim())==s[c])p.desempila();
            else estabe=false;
        c++;
    }
    if(!p.buida())estabe=false;
    return estabe;
}*/
