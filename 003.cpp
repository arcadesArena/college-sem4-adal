/*
date: 2022.06.02
lab set: 3
3. Apply divide and conquer technique to implement quick sort algorithm to sort a given set of elements. Determine the time required to sort the elements. Plot a graph of the time taken versus n elements. The elements can be read from a file or can be generated using the random number generator.
*/
#include<time.h>
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
        a[i]=rand()%5000;
}
void show(int *a,int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
void swapp(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
int partitions(int arr[],int low,int high){
    int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
        if (arr[j] < pivot)
		{
			i++;
			swapp(arr[i], arr[j]);
		}
	}
	swapp(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort(int arr[],int low,int high){
    if (low < high){
		int pi = partitions(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
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
            quickSort(a,0,n-1);
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
            quickSort(a,0,n-1);
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
            quickSort(a,0,n-1);
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
