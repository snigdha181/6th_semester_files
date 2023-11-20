#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c,i,j,k;
    ifstream file("if.txt");
    file>>r>>c;
    int R[r][c],A[r][c],N[k];
    cout<<"\nRequired: ";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {

            file>>R[i][j];
            cout<<R[i][j]<<"  ";
        }
    }
    cout<<"\n\nAllocated: ";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            file>>A[i][j];
            cout<<A[i][j]<<"  ";
        }
    }
    cout<<"\n\nNeed: ";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            N[i]=R[i][j]-A[i][j];
            cout<<N[i]<<"  ";
        }
    }
    int total_allocated=0,resources=12;
    for(i=0; i<r-1; i++)
    {
        for(j=0; j<c; j++)
        {
            total_allocated+=A[i][j];
        }
    }
    int available=resources-total_allocated;
    cout<<"\n\nAvailable: "<<available;
    file.close();
    int temp;
    for(i=0; i<r-1; i++)
    {
        for(j=0; j<r-1-i; j++)
        {
            if(N[j]>N[j+1])
            {
                swap(N[j],N[j+1]);
                swap(R[j][0],R[j+1][0]);
                swap(A[j][0],A[j+1][0]);
            }
        }
    }
    cout<<"\n\nSorted Need: \n";
    for(i=0; i<r; i++)
    {
        cout<<N[i]<<"  ";
    }
    cout<<"\nSorted resources: \n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout<<R[i][j]<<"  ";
        }
    }
    cout<<"\nSorted allocated: \n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout<<A[i][j]<<" ";
        }
    }
    bool safe=true;
    for(i=0; i<r; i++)
    {
        if(available>N[i])
        {
            safe=false;
            break;
        }
    }
    if(safe)
    {
        cout<<"\n\nSafe State...";
    }
    else
    {
        cout<<"\n\nUnsafe State..!!!";
    }
    return 0;
}
