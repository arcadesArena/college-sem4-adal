/*
date:
lab set: 10 b
10. Apply dynamic programming technique to implement
a) All pair shortest path problem using Floyd's algorithm.
b) Find the Binomial Coefficient.
*/
#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int binomial(int n,int k){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0 || j==i)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    return a[n][k];
}
int main(){
    int n,r;
    cout<<"Enter the integer n: ";
    cin>>n;
    cout<<"Enter the integer r: ";
    cin>>r;
    cout<<"Binomial coefficient of C("<<n<<","<<r<<"): "<<binomial(n,r)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=r;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
