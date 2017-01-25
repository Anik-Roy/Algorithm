#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int len1, len2, D[100][100], i, j, S[100][100];
    char c1, c2;
    string str1, str2, res1="", res2="", res3="";
    cout<<"Enter first string:"<<endl;
    cin>>str1;
    cout<<"Enter second string:"<<endl;
    cin>>str2;
    len1 = str1.size();
    len2 = str2.size();
    for(i=0;i<=len1;i++)
        D[i][0] = i;
    for(j=0;j<=len2;j++)
        D[0][j] = j;
    for(i=1;i<=len1;i++)
    {
        c1 = str1[i-1];
        for(j=1;j<=len2;j++)
        {
            c2 = str2[j-1];
            if(c1 == c2)
            {
                D[i][j] = D[i-1][j-1];
                S[i][j] = 3;
            }
            else
            {
                int ins, del, sub, mn;
                ins = D[i][j-1] + 1;
                del = D[i-1][j] + 1;
                sub = D[i-1][j-1] + 2;
                mn = min(min(ins, del), sub);
                D[i][j] = mn;
                if(mn == D[i-1][j-1] + 2)
                {
                    S[i][j] = 3;
                }
                else if(mn == D[i][j-1] + 1)
                {
                    S[i][j] = 1;
                }
                else if(mn == D[i-1][j] + 1)
                {
                    S[i][j] = 2;
                }
            }
        }
    }
        i = len1;
    j = len2;
    while(i>0 && j>0)
    {
        if(S[i][j] == 3)
        {
            if(str1[i-1] == str2[j-1])
                res3 += "n";
            else
                res3 += "s";
            res1 += str1[i-1];
            res2 += str2[j-1];
            i--;
            j--;
        }
        else if(S[i][j] == 1)
        {
            res3 += "i";
            res1 += "*";
            res2 += str2[j-1];
            j--;
        }
        else if(S[i][j] == 2)
        {
            res3 += "d";
            res1 += str1[i-1];
            res2 += "*";
            i--;
        }
    }
    while(i>0)
    {
        res3 += "d";
        res1 += str1[i-1];
        res2 += "*";
        i--;
    }
    while(j>0)
    {
        res3 += "i";
        res1 += "*";
        res2 += str2[j-1];
        j--;
    }
    for(i=0;i<=len1;i++)
    {
        for(j=0;j<=len2;j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<D[len1][len2]<<endl;
    reverse(res1.begin(), res1.end());
    reverse(res2.begin(), res2.end());
    reverse(res3.begin(), res3.end());
    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
}
