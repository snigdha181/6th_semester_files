#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bn,pn,bs[10],ps[10],i,j,temp,m=9999,lock=0;
    int frag,b[10],a[10];
    cout<<"Enter the number of process: ";
    cin>>pn;
    cout<<"Enter the size of process: \n";
    for(i=0; i<pn; i++)
    {
        cout<<"P"<<i<<"-";
        cin>>ps[i];
    }
    cout<<"Enter the number of block: ";
    cin>>bn;

    cout<<"Enter the size of block: \n";
    for(i=0; i<bn; i++)
    {
        cout<<"B"<<i<<"-";
        cin>>bs[i];
    }
    for(i=0; i<pn; i++)
    {
        for(j=0; j<bn; j++)
        {
            if(ps[i]<=bs[j])
            {
                if(bs[j]<temp)
                {
                    temp=bs[j];
                }
            }
            frag=bs[j]-ps[i];
            if(frag>=0)
                if(m>frag)
                {
                    b[i]=j;
                }
        }
        a[b[i]]=1;
    }
    cout<<"\nProcess number\tProcess size\tBlock number\tBlock size\n";
    for(i=0; (i<pn && bs[i]!=0); i++)
    {
        cout<<i<<"\t\t"<<ps[i]<<"\t\t"<<bs[i]<<"\t\t"<<bs[b[i]];
    }
    return 0;
}
