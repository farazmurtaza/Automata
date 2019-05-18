#include<iostream>
#include<string.h>
using namespace std;
int top;
char s[10];
class Stack
{
    public:
    void push(int x)
    {
        s[top++]=x;
    }
    void pop()
    {
        s[top--]='0';
    }
};


int main()
{

    int i,n;
    char a[10];
    n=strlen(a);
    Stack st;
    top=-1;
    int temp = 0;
    int n2 = n/2;
    bool x = true;
    cout<<"\nProgram For PDA Which Accepts Strings Of L= { a^n b^n; n>0} U {b, bb)\n";
    
    do{
        cout<<"\nEnter String:";
        cin>>a;
        if(a[0]=='a')
        {
            for(i=0;i<n/2;i++) 
            {
            if(a[i]=='a')
                {
                    st.push(a[i]);
                }   
                else
                {
                    x = false;
                }    
            }
            for(i=n2; i<n; i++)
            {
                if(a[i]=='b')
                {
                    st.pop();
                }
                else
                {
                    x = false;
                    break;
                }
            }
            if(top==-1 && x==true)
            {
                cout<<"\nString Accepted.\n";
            }
            else
            {
                cout<<"\nString Rejected.\n";
            }    
        }
        else if(a[0]=='b')
        {
            if(strlen(a)<3)
            {
                st.push(0);
                for(i=0; i<n; i++)
                {
                    if(a[i]=='b')
                    {
                        st.push(a[i]);
                        temp++;
                    }
                    else
                    {
                        x = false;
                        break;
                    }
                }
                for(i=0; i<temp; i++)
                {
                    st.pop();
                }
                if(top==0 && x==true)
                {
                    cout<<"\nString Accepted.\n";
                }
                else
                {
                    cout<<"\nString Rejected.\n";
                }
            }
            else
            {
                cout<<"\nString Rejected.\n";
            }
        }
    }
    while(a[0]!='e');
}