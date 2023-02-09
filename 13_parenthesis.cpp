#include<iostream>
#include "./12_Stack.cpp"
using namespace std;

bool isOperator(char q) {
    return q=='/' || q=='*' || q=='+' || q=='-';
}

int pre(char ope){
    switch(ope) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 3;
    }
}

int compute( int a, int b, char ch ) {
    int res=0;
    switch(ch){
        case '+':res=a+b;break;
        case '-':res=a-b;break;
        case '*':res=a*b;break;
        case '/':res=a/b;break;
        default:res=0;
    }   
    return res;
} 

char * infixToPostfix(char * str) {
    int len=0; for(;str[len];len++);

    char * res= new char[len];
    Stack <char> * st=new Stack<char>();
    int k=0;
    for(int i=0; str[i]; i++){
        if(!isOperator(str[i])) res[k++]=str[i];
        else if(st->isEmpty() || pre(str[i]) > pre(st->top()) ) st->push(str[i]);
        else {
            while(!st->isEmpty() && pre(st->top()) >= pre(str[i]))
            res[k++]=st->pop();
            st->push(str[i]);
        }
    }
    while(!st->isEmpty()) res[k++]=st->pop();
    return res;
}

void log(int x,int y) {
    cout<<"x "<<x<<endl;
    cout<<"y "<<y<<endl;
}

int valuation(char *postFix) {
    int res=0;
    Stack <int> * st=new Stack<int>();
    for(int i=0; postFix[i]; i++) 
        if(isOperator(postFix[i])) st->push(compute(st->pop(), st->pop(), postFix[i]));
        else st->push(postFix[i]-'0');
    

    return st->pop();
}
int main() {
    // char str[]="3*5+6/2-4";
    // cout<<valuation(infixToPostfix(str))<<endl;
    int i=0;
    // log(++i,++i);
    // log(i++,i++);
    return 0;
}