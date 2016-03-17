#include "LCS.h"
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

/*void print_lcs(char *x,char **y,int i,int j)
{
    if(i=0||j==0)
        return;
    if(*((char *)y+(i+1)*(j+1)-1)=='\\')
    {
        print_lcs(x,y,i-1,j-1);
        cout<<x[i-1];
    }
    else if(*((char *)y+(i+1)*(j+1)-1) == '|')
    {
        print_lcs(x,y,i-1,j);
    }
    else
    {
        print_lcs(x,y,i,j-1);
    }
}*/

void get_lcs(char *x,char *y)
{
    int maxnum,mx,my;           //记录最长连续相同字符串值个数与位置
    int m = strlen(x);
    int n = strlen(y);
    int c[m+1][n+1];            //记录lcs个数
    char b[m+1][n+1];           //记录符号，简化最优解的构造
    int d[m+1][n+1];            //记录最长连续相同字符串个数

    /**初始化三个数组**/
    for(int i = 0 ; i < m+1 ; i++)
    {
        c[i][0] = 0;
        b[i][0] = ' ';
        d[i][0] = 0;
    }
    for(int i = 0 ; i < n+1 ; i++)
    {
        c[0][i] = 0;
        b[0][i] = ' ';
        d[0][i] = 0;
    }

    /**按照已经设置好的递归式实现代码**/
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(x[i]==y[j])
            {
                c[i+1][j+1] = c[i][j] + 1;
                b[i+1][j+1] = '\\';
                d[i+1][j+1] = d[i][j] + 1;
            }
            else
            {
                if(c[i][j+1]>=c[i+1][j])
                {
                    c[i+1][j+1] = c[i][j+1];
                    b[i+1][j+1] = '|';
                }
                else
                {
                    c[i+1][j+1] = c[i+1][j];
                    b[i+1][j+1] = '-';
                }
                d[i+1][j+1] = 0;
            }
        }
    }

    /**输出三个数组，并找到要求解最长连续相同字符串的最大值的位置\
    用mx，my记录**/
    maxnum = d[0][0];
    for(int i = 0 ; i < m+1 ; i++)
    {
        for(int j = 0; j < n+1 ; j++)
        {
            cout<<c[i][j]<<b[i][j]<<d[i][j]<<' ';
            if(maxnum <= d[i][j])
            {
                maxnum = d[i][j];
                mx = i;
                my = j;
            }
        }
        cout<<endl;
    }

    /**LCS.H中提到，此处使用栈实现求得字符串的顺序输出**/
    stack <char>s;
    stack <char>stk;
    for(int i = m ,j = n ; i > 0 && j >0 ; )
    {
        if(b[i][j]=='\\')
        {
            s.push(x[i-1]);
            i--;
            j--;
        }
        else if(b[i][j] == '|')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }

    /**此处，仅仅看连续的\标志即可，因为只有字符串连续相同，才设置相应的b为\**/
    cout <<endl;
    for(int i = mx ,j = my ; i > 0 && j >0 ; )
    {
        if(b[i][j]=='\\')
        {
            stk.push(x[i-1]);
            i--;
            j--;
        }
        else
            break;
    }

    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }
    //print_lcs(x,(char **)b,m,n);
}



