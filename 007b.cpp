/*
date: 2022.07.07
lab set: 7 b
7. Apply Space and Time trade off technique to implement a program to
a) Perform string matching using Horspool algorithm.
b) Comparison counting sorting algorithm
*/
#include<bits/stdc++.h>
using namespace std;
void countingSort(int a[],int n,int mx){
    int count[mx+1]={0},i,j;
    for(i=0;i<n;i++)
        count[a[i]]=count[a[i]]+1;
    cout<<"Sorted elements are"<<endl;
    for(i=0;i<=mx;++i){
        for(j=1;j<=count[i];++j)
            cout<<i<<" ";
    }
}
int main(){
    int a[50],n,i,mx=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx)
            mx=a[i];
    }
    countingSort(a,n,mx);
    return 0;
}
