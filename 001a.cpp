/*
date:
lab set: 1 a
1. Apply brute force/divide and conquer technique to recursively implement the following concepts:
a) Linear Search and Binary Search.
b) To find the maximum and minimum in a given list of n elements.
*/
#include<bits/stdc++.h>
using namespace std;
void linearSearch(int a[],int n,int key){
    if(n<0){
        cout<<"Key not found";
        return;
    }
    if(a[n]==key){
        cout<<"Key found at position "<<n+1;
        return;
    }
    linearSearch(a,n-1,key);
}
void binarySearch(int a[],int b,int e,int key){
    if(e<b){
        cout<<"Key not found";
        return;
    }
    int mid=((b+e)/2);
    if(a[mid]==key){
        cout<<"Key found at position "<<mid+1;
        return;
    }
    if(a[mid]>key)
        binarySearch(a,b,mid-1,key);
    if(a[mid]<key)
        binarySearch(a,mid+1,e,key);
}
int main(){
    int k,n,ch,*arr;
    while(1){
        cout<<"1:linear search\n2:binary search\n3:exit\nchoice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the number array elements: ";
            cin>>n;
            cout<<"Enter "<<n<<" numbers\n";
            arr=new int[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            cout<<"Enter the key to be searched: ";
            cin>>k;
            cout<<"With recursion\n";
            linearSearch(arr,n,k);
            break;
        case 2:
            cout<<"Enter the number array elements: ";
            cin>>n;
            cout<<"Enter "<<n<<" sorted numbers\n";
            arr=new int[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
            cout<<"Enter the key to be searched: ";
            cin>>k;
            cout<<"With recursion\n";
            binarySearch(arr,0,n,k);
            break;
        case 3:
            return 0;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
