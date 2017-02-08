#include<iostream>
#include<string>
using std::string;
int getPre(char x)
{
 switch(x)
 {
 case '^': return 4;
 case '*':
 case '/': return 3;
 case '+':
 case '-': return 2;
 case '(': return 1;
 }
 return 0;
}
 string convert(string expr)
{
    int N, i=-1,s_ptr=-1,o_ptr=-1;
    char out[403]={0};
    char stack[300]={0};
    for(i=0;expr[i]!='\0'; i++)
 {
 
 if(expr[i]=='(')
 {
 s_ptr++;
 stack[s_ptr]='(';
 }
 else if(expr[i]==')')
 {
 while(stack[s_ptr]!='(')
 {
 o_ptr++;
 out[o_ptr]=stack[s_ptr];
 s_ptr--;
 }
 s_ptr--;
 }
 else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || expr[i]=='^')
 {
 while(getPre(stack[s_ptr])>=getPre(expr[i]))
 {
 o_ptr++;
 out[o_ptr]=stack[s_ptr];
 s_ptr--;
 }
 s_ptr++;
 stack[s_ptr]=expr[i];
 }
 else
 {
 o_ptr++;
 out[o_ptr]=expr[i];
 }
 }
 out[o_ptr+1]='\0';
 return out;
 }
int main()
{
    int t,i;
    string s,S,A[10];
    std::cin >> t;
    for (i=0; i<t; i++)
    {
        std::cin >> s;
        S=convert(s);
        A[i]=S;
    }
    for(i=0;i<t;i++)
        std::cout<<A[i]<<std::endl;
    return 0;
}