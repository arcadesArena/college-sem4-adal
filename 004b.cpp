/*
date: 2022.05.19
lab set: 4 b
4. Apply decrease and conquer technique to implement
a) Topological ordering of vertices in a given digraph.
b) Insertion sort algorithm to sort a given set of elements
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void ascending(int *a,int n){
    for(int i=0; i<n; i++)
        a[i]=i+1;
}
void descending(int *a,int n){
    for(int i=0; i<n; i++)
        a[i]=n-i;
}
void variable(int *a,int n){
    for(int i=0; i<n; i++)
        a[i]=rand();
}
void show(int *a,int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<"\t";
}
void insertion(int *a,int n){
    int j,v;
    for(int i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
}
int main(){
    int a[5000];
    int ch,n;
    clock_t t;
    while(1)
    {
        cout<<"1:ascending\t3:variable\n2:descending\t4:exit\nEnter your choice: ";
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
            insertion(a,n);
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
            insertion(a,n);
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
            insertion(a,n);
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
