#include<iostream>
using namespace std;

/**
    Scenarios
    a.) Just Single missing element can be solved by formula n(n+1)/2
        a.1) starts with element 1 at index 0;
        a.2) Not start with 1;
    b.) First missing element
    c.) All missing elements
    d.) Unsorted array using HashTable - if storage is not constraint otherwise have to sort the array
*/



void missingByFormula(int * arr, int len,int n) {
    int sumOfElems=0;

    for(int i=0; i<len; i++) sumOfElems+=arr[i];

    int actualSum = n * (n+1) / 2;
    
    if(arr[0] != 1) actualSum = actualSum - arr[0] * ( arr[0]-1 ) /2;
    
    if(actualSum!=sumOfElems)
        cout<<"Missing element is "<<actualSum - sumOfElems<<endl;
    else cout<<"No missing element"<<endl;
}

void missingMultiple(int * arr, int len) {
    int diff=arr[0],i=0;

    for(int i=1;i<len;i++) {
        if(arr[i] - i == diff) continue;

        while(diff+i < arr[i])
            cout<<(i+diff++)<<" ";

    }
    cout<<endl;
}

void missingUnsorted(int *arr,int n) {
    int max=0;
    
    for(int i=0;i<n;i++) max = arr[i] > max ? arr[i] : max;

    int * BitSets= new int[max];

    for(int i=0; i<n; i++) BitSets[arr[i]]=1;

    for(int i=1; i<max; i++) if(!BitSets[i]) cout<<i<<" ";
    
    cout<<endl;
}

int main() {
    // int arr[10]={2,3,4,5,6,8,9,10,11,12};

    // missingByFormula(arr,10,12);  
    int n=11;  
    // int arr[n]={6,7,8,9,10,11,13,14,15,16,21};
    // missingMultiple(arr,n);

    int arr[n]={3,7,4,9,12,6,1,11,2,10,13};
    missingUnsorted(arr,n);
    return 0;
}
