/*
date:
lab set: 15
15.Apply Back Tracking technique to implement a program on nQueen's problem.
*/
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int x[100],countt=0;
int place(int k,int i){
    for(int j=1; j<k; j++){
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
            return 0;
    }
    return  1;
}
void nqueens(int k,int n){
    for(int i=1; i<=n; i++){
        if (place(k,i)){
            x[k]=i;
            if(k==n){
                countt++;
                cout<<"\n";
                for(int j=1; j<=n; j++){
                    for(int p=1; p<=n; p++){
                        if(x[j]==p)
                            cout<<"q\t";
                        else
                            cout<<"#\t";
                    }
                    cout<<endl;
                }
            }
            else
                nqueens(k+1,n);
        }
    }
}
int main(){
    int n;
    cout<<"enter the no. of queens : ";
    cin>>n;
    nqueens(1,n);
    if(countt==0)
        cout<<"there is no solution\n";
    else
        cout<<"\nthe no. of solutuons "<<countt;
    return 0;
}
