#include<iostream>
using namespace std;

void display(int *arr,int len) {
    for(int i=0; i<len; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

// @Important - if both x and y are exactly same address;
// void swap(int &x,int &y) { if(x==y) return; x=x+y; y=x-y; x=x-y; }
// @Important - NO above issue here
void swap(int *x,int *y) {   *x=*x+*y; *y=*x-*y; *x=*x-*y; }

void bubbleSort(int *arr,int len,int last=-1) {
    if(last==-1) last=len-1;
    for(int i=0;i<last;i++){
        int flag=0;
        for(int j=0;j<len-1-i;j++)
            if(arr[j] > arr[j+1]){
                flag=1;
                swap(arr[j],arr[j+1]);
            }
        
        if(!flag) break;    
    }
    display(arr,len);
}

/**
  * TODO - Make recursive bubble sort intermediate result meaningfull.
*/

void bubbleRec(int *arr,int len,int last=-1) {
    if(len==0 || len==1) return;

    int swapped=0;
    for(int i=0; i<len-1; i++)
        if(arr[i] > arr[i+1]) {
            swap(arr[i],arr[i+1]);
            swapped=1;
        }

   if(!swapped) return;
   bubbleRec(arr,len-1);
}

void insertionSort(int *arr,int len) {
    for(int i=1; i<len; i++) {
        int j=i-1;
        int thisElem=arr[i];
        while(j>-1 && arr[j] > thisElem) {
            swap(arr[j+1],arr[j]);
            j--;
        }
        arr[j+1]=thisElem;
    }

    display(arr,len);
}

void selectionSort(int *arr,int len) {
    int i,j,min_idx;
    for(i=0; i<len-1; i++) {
        for(j=min_idx=i; j < len; j++)
            if(arr[j] < arr[min_idx]) min_idx = j;
        
        if(i!=min_idx) swap(arr[min_idx],arr[i]);
    }
}
void selectionSortStable(int *arr,int len) {
    int i,j,min_idx;
    for(i=0; i<len-1; i++) {
        for(j=min_idx+1,min_idx=i; j < len; j++)
            if(arr[j] < arr[min_idx]) min_idx = j;

        int key=arr[min_idx];
        while(min_idx > i) {
            arr[min_idx]=arr[min_idx-1];
            min_idx--;
        }   
        arr[i]=key;
    }
}

int partitionMy(int * arr,int low,int high) {
    int pivot=arr[low];
    int i=low+1,j=high;

    while(i<j) {
        while(arr[i]<=pivot && i<high)  i++;
        while(arr[j]>pivot && j<low) j--;
        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}

int partition(int *arr,int low,int high) {
    int pivot=arr[low],i=low,j=high;

    do {
        do { i++; } while(arr[i]<=pivot && i<high);
        do { j--; } while(arr[j]>pivot && j >low);
        if(i<j) swap(arr[i],arr[j]);
    } while(i<j);

    swap(arr[low],arr[j]);

    return j;
}

void QuickSort(int *arr,int l,int h) {
    if(l < h) {
    cout<<"l = "<<l<<", h = "<<h<<endl;
        int j = partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main() {
    // int len=10;
    // int arr[len]={8,6,8,10,9,4,12,5,2,7};
    int len=3;
    int arr[len]={10,30,20};
    // int len=2;
    // int arr[len]={10,2};
    // bubbleRec(arr,len,5);
    // selectionSortStable(arr,len);
    QuickSort(arr,0,len);
    display(arr,len);
    return 0;
}
