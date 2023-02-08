#include<iostream>
using namespace std;

void duplicateSort(int *arr,int len) {
    int lastDuplicate=arr[0];
    for(int i=0; i<len; i++) {
        if(arr[i] != arr[i+1]) continue;

        int j=i+2;
        while(arr[j] == arr[i] && j<len) j++;

        cout<<arr[i] << " occured for "<<j-i<<" times"<<endl;
        i=j-1; 
    }

}

void duplicateUnSort(int *arr,int len) {
    int count;
    /* @important */
    for(int i=0; i<len-1; i++) {
        if(arr[i] == -1) continue;
        count=1;
        for(int j=i+1; j<len; j++) 
            if(arr[j] == arr[i]){ arr[j]=-1;  count++; }
        
        if(count>1) 
            cout<<arr[i] <<" => "<<count<<endl;
        
    }
}

void duplicateHashing (int *arr,int len) {
    int max=arr[0];
    for(int i=1;i<len;i++) max = arr[i] > max ? arr[i] : max;

    /* @important */
    int * bitsets = new int[max+1];

    for(int i=0; i<len; i++) bitsets[arr[i]]++;

    /* @important */
    for(int i=0; i<=max; i++) if(bitsets[i] > 1) cout<<i<<" occured for "<<bitsets[i] <<" times "<<endl;
 }

int main() {
    int arr[]={3,6,8,8,10,12,15,15,15,15};
    int arr2[]={8,3,6,4,6,5,6,8,2,7};
    // duplicateSort(arr,10);
    duplicateHashing(arr2,10);
    return 0;
}
