#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int stck[1024],top;
void operate(char tmp)
{
    int res;
    switch(tmp){
        case '*': res = stck[top - 2] * stck[top - 1];break;
        case '-': res = stck[top - 2] - stck[top - 1];break;
        case '+': res = stck[top - 2] + stck[top - 1];break;
        default: res = stck[top - 2] / stck[top - 1];
    }
    stck[--top - 1] = res; 
}
int main() {
    int top = 0;
    char** tokens[20];
    char k = getExprChar();
    int m = 0;
    while (k!='/0') {
        tokens[m] = k;
        m++;
        top++;
        k = getExprChar();
    }
    for(int i = 0; i < m; i++)
       if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i][1]))
            stck[top++] = atoi(tokens[i]);
        else
            operate(tokens[i][0]);
    return stck[0];

}
