/*
date:
lab set: 14
14.Apply Back Tracking technique to implement a program to find a subset of a given set S = {s1, s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 there are two solutions {1,2,6} and {1,8}. A suitable message is to be displayed if the given problem instance doesn't have a solution.
*/
#include<bits/stdc++.h>
using namespace std;
class Subset{
public:
    int sett[10],x[10],n,d,c;
    Subset(){c=0;}
    void sumOfSubset(int s,int k,int r){
        x[k]=1;
        if(s+sett[k]==d){
            cout<<"Subset = {";
            for(int i=0;i<=k;i++){
                if(x[i]){
                    cout<<sett[i];
                    if(i!=k){
                        cout<<",";
                        c=1;
                    }
                }
            }
            cout<<"}\n";
        }
        else if(s+sett[k]+sett[k+1]<=d)
            sumOfSubset(s+sett[k],k+1,r-sett[k]);
        if((s+r-sett[k]>=d) && (s+sett[k+1]<=d)){
            x[k]=0;
            sumOfSubset(s,k+1,r-sett[k]);
        }
    }
    void check(){
        if(c==0)
            cout<<"Not possible"<<endl;
    }
};
int main(){
    int r=0;
    Subset s;
    cout<<"Enter the number of elements: ";
    cin>>s.n;
    cout<<"Enter the elements\n";
    for(int i=0;i<s.n;i++)
        cin>>s.sett[i];
    cout<<"Enter the sum: ";
    cin>>s.d;
    for(int i=0;i<s.n;i++)
        s.x[i]=0;
    for(int i=0;i<s.n;i++)
        r+=s.sett[i];
    cout<<endl;
    s.sumOfSubset(0,0,r);
    s.check();
    return 0;
}
