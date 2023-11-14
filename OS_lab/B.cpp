#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c,i,j,k;
    ifstream file("if.txt");
    file>>r>>c;
    int R[r][c],A[r][c],N[k];
    cout<<"\nRequired\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {

            file>>R[i][j];
            cout<<R[i][j]<<"\n";
        }
    }
    cout<<"\nAllocated\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            file>>A[i][j];
            cout<<A[i][j]<<"\n";
        }
    }
    cout<<"\nNeed\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            N[i]=R[i][j]-A[i][j];
            cout<<N[i]<<"\n";
        }
    }
    int total_allocated=0,resources=12;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            total_allocated+=A[i][j];
        }
    }
    int available=resources-total_allocated;
    cout<<"\nAvailable: "<<available;
    file.close();
    int temp;
    for(i=0; i<r-1; i++)
    {
        for(j=0; j<r-1-i; j++)
        {
            if(N[j]>N[j+1])
            {
                swap(N[j],N[j+1]);
                //swap(R[i][0],R[i+1][0]);
                //swap(A[i][0],A[i+1][0]);
            }
        }
    }
    cout<<"\nSorted Need: \n";
    for(i=0; i<r; i++)
    {
        cout<<N[i];
        cout<<endl;
    }
    return 0;
}


