#include<bits/stdc++.h>
using namespace std;
string LCS(string a,string b)
{
    int c[a.length()+1][b.length()+1];
    int s[a.length()+1][b.length()+1];

    string ans;
    for(int i=0;i<=a.length();i++)
        c[i][0]=0;
    for(int i=0;i<=b.length();i++)
        c[0][i]=0;
    for(int i=1;i<=a.length();i++)
    {
        for(int j=1;j<=b.length();j++)
        {
            if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                s[i][j]=0;
            }
            else{
                if(c[i-1][j]>=c[i][j-1])
                {    c[i][j]=c[i-1][j];
                    s[i][j]=-1;
                }
                else
                {    c[i][j]=c[i][j-1];
                    s[i][j]=-2;
                }
            }
        }
    }
    int i=a.length(),j=b.length();
    while(1)
    {
        if(i==0||j==0)
            break;
        else if(s[i][j]==0)
        {    
            ans+=a[i-1];
            i--;
            j--;
        }
        else{
            if(s[i][j]==-1)
                i--;
            else
                j--;
        }
    }
    string ans1;
    for(int i=ans.length()-1;i>=0;i--)
        ans1+=ans[i];
    return ans1;
    
}
int main(){
    string a,b;
    cout<<"Enter string a"<<endl;
    cin>>a;
    cout<<"Enter string b"<<endl;
    cin>>b; 
    cout<<LCS(a,b)<<endl;

}