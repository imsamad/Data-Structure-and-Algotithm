#include<iostream>
using namespace std;

void pairOfElems(int *arr,int len,int sum) {
    for(int i=0; i<len-1; i++) {
        if(arr[i]==-1) continue;
        for(int j=i+1; j<len; j++) {
            if(arr[i] + arr[j] == sum) {
                cout<<arr[i] << " + "<<arr[j] <<endl;
                arr[j]=-1;
            }
        }
    }
}

void pairOfElemSorted(int *arr,int len,int sum) {
    int curSum;
    for(int i=0,j=len-1; i<j;) {
        curSum=arr[i] + arr[j];
        if(curSum == sum) 
            cout<<arr[i++] << " + "<<arr[j--] <<endl;
        else if (curSum > sum) j--;
        else i++;
    }
}

int main() {
    // int arr[]={6,3,8,10,16,7,5,9,2,14};
    int arr[]={1,3,4,5,6,8,9,10,12,14};
    
    pairOfElemSorted(arr,10,10);
    return 0;
}