/*
date: 2022.06.30
lab set: 6
6. Apply transform and conquer technique to implement a program to
a) Sort a given set of elements using the Heap sort and determine the time required to sort the elements.
b) Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n.
c) The elements can be read from a file or can be generated using the random number generator.
*/
#include<bits/stdc++.h>
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
        a[i]=rand()%5000;
}
void heapify(int arr[],int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int ch,n,*a;
    clock_t t;
    while(1){
        cout<<"1:ascending\t2:descending\n3:variable\t4:exit\nchoice-";
        cin>>ch;
        if(ch==4)
            exit(0);
        switch(ch){
        case 1:
            cout<<"enter number of elements: ";
            cin>>n;
            a=new int[n];
            ascending(a,n);
            cout<<"\nascending order elements are\n";
            show(a,n);
            t=clock();
            heapSort(a,n);
            t=clock()-t;
            cout<<"elements after sorting\n";
            show(a,n);
            cout<<"Total time taken: "<<((double)t)/CLOCKS_PER_SEC<<endl;
            break;
        case 2:
            cout<<"enter number of elements-";
            cin>>n;
            a=new int[n];
            descending(a,n);
            cout<<"descending order elements are\n";
            show(a,n);
            t=clock();
            heapSort(a,n);
            t=clock()-t;
            cout<<"elements after sorting\n";
            show(a,n);
            cout<<"Total time taken: "<<((double)t)/CLOCKS_PER_SEC<<endl;
            break;
        case 3:
            cout<<"enter number of elements-";
            cin>>n;
            a=new int[n];
            variable(a,n);
            cout<<"variable order elements are\n";
            show(a,n);
            t=clock();
            heapSort(a,n);
            t=clock()-t;
            cout<<"elements after sorting\n";
            show(a,n);
            cout<<"Total time taken: "<<((double)t)/CLOCKS_PER_SEC<<endl;
            break;
        }
        cout<<endl;
    }
    return 0;
}
