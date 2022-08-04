/*
date: 2022.05.19
lab set: 2
2. Apply divide and conquer technique to implement merge sort algorithm to sort a given set of elements. Determine the time required to sort the elements. Plot a graph of the time taken versus n elements. The elements can be read from a file or can be generated using the random number generator.
*/
#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int comp=0;
void ascending(int *a,int n)
{
    for(int i=0; i<n; i++)
        a[i]=i+1;
}
void descending(int *a,int n)
{
    for(int i=0; i<n; i++)
        a[i]=n-i;
}
void variable(int *a,int n)
{
    for(int i=0; i<n; i++)
        a[i]=rand()%10000;
}
void show(int *a,int n)
{
    for(int i=0; i<n; i++)
        cout<<setw(4)<<a[i]<<"\t";
}
void merger(int *b,int *c,int *a,int p,int q)
{
    int i,j,k;
    i=j=k=0;
    while(i<p && j<q)
    {
        comp++;
        b[i]<c[j] ? a[k++]=b[i++] : a[k++]=c[j++];
    }
    if(i==p)
    {
        while(j<q)
            a[k++]=c[j++];
    }
    else
    {
        while(i<p)
            a[k++]=b[i++];
    }
}
void mergeSort(int *a,int n)
{
    int b[20],c[20],i=0,j,k;
    if(n>1)
    {
        for(i=0; i<n/2; i++)
            b[i]=a[i];
        k=i;
        for(j=n/2,i=0; j<n; j++,i++)
            c[i]=a[j];
        mergeSort(b,k);
        mergeSort(c,i);
        merger(b,c,a,k,i);
    }
}
int main()
{
    int a[5000];
    int ch,n;
    clock_t t;
    while(1)
    {
        comp=0;
        cout<<"Enter your choice-\n1:ascending\t3:variable\n2:descending\t4:exit\nchoice-";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"enter number of elements-";
            cin>>n;
            ascending(a,n);
            cout<<"\nascending order elements are\n";
            show(a,n);
            t= clock();
            mergeSort(a,n);
            t=clock()-t;
            cout<<"after sorting elements are\n";
            show(a,n);
            break;
        case 2:
            cout<<"enter number of elements-";
            cin>>n;
            descending(a,n);
            cout<<"descending order elements are\n";
            show(a,n);
            t= clock();
            mergeSort(a,n);
            t=clock()-t;
            cout<<"after sorting elements are\n";
            show(a,n);
            break;
        case 3:
            cout<<"enter number of elements-";
            cin>>n;
            variable(a,n);
            cout<<"variable order elements are\n";
            show(a,n);
            t= clock();
            mergeSort(a,n);
            t=clock()-t;
            cout<<"after sorting elements are\n";
            show(a,n);
            break;
        case 4:
            exit(0);
        }
        double comp=((double)t)/CLOCKS_PER_SEC;
        cout<<"\nTime: "<<comp<<endl;
    }
    return 0;
}
