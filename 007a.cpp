/*
date: 2022.06.30
lab set: 7 a
7. Apply Space and Time trade off technique to implement a program to
a) Perform string matching using Horspool algorithm.
b) Comparison counting sorting algorithm
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 500
int t[MAX];
void shiftTable(char p[]){
    int i,j,m;
    m=strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m;j++)
        t[p[j]]=m-i-j;
}
int horspool(char src[],char p[]){
    int i,j,k,m,n;
    n=strlen(src);
    m=strlen(p);
    cout<<"Length of text: "<<n<<endl;
    cout<<"Length of pattern: "<<m<<endl;
    i=m-1;
    while(i<n){
        k=0;
        while(k<m && p[m-1-k]==src[i-k])
            k++;
        if(k==m)
            return (i-m+1);
        else
            i+=t[src[i]];
    }
    return -1;
}
int main(){
    char src[100],p[100];
    int pos;
    //clrscr();
    cout<<"Enter the search text"<<endl;
    gets(src);
    cout<<"Enter the search pattern"<<endl;
    gets(p);
    shiftTable(p);
    pos=horspool(src,p);
    if(pos>=0)
        cout<<"Pattern at position "<<pos+1<<endl;
    else
        cout<<"Pattern not found"<<endl;
    return 0;
}
