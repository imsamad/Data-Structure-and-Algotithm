#include<iostream>

using namespace std;
 
void display(int *arr,int len) {
    for(int i=0; i<len; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void intersect(int *arr1,int len1,int *arr2,int len2) {
    int * res= new int[len1>len2 ? len1 : len2];
    int i=0,j=0,k=0;
    while(i<len1 && j<len2) {
        cout<<i<<" => "<<j<<endl;
        if(arr1[i] == arr2[j] ){
            cout<<"executed for "<<i<<" -> "<<j<<endl;
            res[k]=arr1[i];
            i++;j++;k++;
        } else if(arr1[i] < arr2[j] )
            i++;
        else j++;    
    }
    cout<<"k "<<k<<endl;
    display(res,k);
}

void unionSet(int *arr1,int len1,int *arr2,int len2) {
    int i=0,j=0,k=0;
    int * res= new int[len1+len2];
    while(i<len1 && j<len2) {
        if(arr1[i] < arr2[j])
            res[k]=arr1[i++];
        else if(arr1[i] > arr2[j])
            res[k]=arr2[j++];
        else {
            res[k]=arr1[i++];
            j++;
        } 
        k++;
    }

    for(;i<len1;i++)    res[k++]=arr1[i];
    for(;j<len2;j++)    res[k++]=arr2[j];

    display(res,len1+len2);
}

int main() {
    int arr1[5]={3,4,5,6,10};
    int arr2[5]={2,3,6,10,12};
    // unionSet(arr1,5,arr2,5);
    intersect(arr1,5,arr2,5);
    
    return 0;
}