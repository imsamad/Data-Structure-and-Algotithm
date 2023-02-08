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
        // cout<<i<<" "<<j<<endl;
        while(arr[i]<=pivot && i < high+1)  i++;
        //  no need to put it - && j > low-1
        while(arr[j]>pivot) j--;
        if(i<j) swap(arr[i++],arr[j--]);
    }

    swap(arr[low],arr[j]);
    return j;
}

int partitionMyWithInfinity(int * arr,int low,int high) {
    int pivot=arr[low];
    int i=low,j=high;

    while(i<j) {
        // cout<<i<<" "<<j<<endl;
        do { i++; }while(arr[i]<=pivot);
        do { j++; }while(arr[j]>pivot);
        // while(arr[i]<=pivot)  i++;
        // while(arr[j]>pivot && j > low-1) j--;
        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}



int partition(int *arr,int low,int high) {
    int pivot=arr[low],i=low,j=high;

    do {
        do { i++; } while(arr[i]<=pivot);
        do { j--; } while(arr[j]>pivot);
        if(i<j) swap(arr[i],arr[j]);
    } while(i<j);

    swap(arr[low],arr[j]);

    return j;
}
// Lomuto Partition
int partitionLomutoOrCLRS(int *arr,int low,int high) {
    int i =low-1,pivot=arr[high];

    for(int j=low; j<=high; j++)
        if(arr[j] < pivot)
            swap(arr[j],arr[++i]);

    swap(arr[++i],arr[high]);
    return i;    
}

int partitionHoare(int arr[], int l,int h)   
// Initially, l = 0, h = size of array - 1
{
    int pivot = arr[l];

    int i = l-1, j = h+1;
    while(true) {
        cout<<i<<" "<<j<<endl;
        do { i++; } while(arr[i] < pivot);

        cout<<i<<" "<<j<<endl;
        do { j--; } while(arr[j] > pivot);
        
        cout<<i<<" "<<j<<endl;
        if(i >= j)
            return j;
        
        swap(arr[i], arr[j]);
    }
    return -1;
}

void QuickSort(int *arr,int l,int h) {
    if(l < h) {
        int partitionedAt = partitionHoare(arr,l,h);
        QuickSort(arr, l, partitionedAt-1);
        QuickSort(arr, partitionedAt+1, h);
        // int partitionedAt = partition(arr,l,h);
        // QuickSort(arr, l, partitionedAt);
        // QuickSort(arr, partitionedAt+1, h);
    }
}

void merging(int *arr,int low,int mid,int high) {
    int i=low,j=mid+1;

    int * temp=new int[(high-low)+1];
    int k=-1;    

    while(i<=mid && j<=high) {
        if(arr[i] < arr[j])
            temp[++k]=arr[i++];
        else if(arr[i] > arr[j])
            temp[++k]=arr[j++];
        else { 
            arr[++k]=arr[i++];
            j++;
        }
    }

    for(;i<=mid;i++) temp[++k]=arr[i];
    for(;j<=high;j++) temp[++k]=arr[j];

    for(i=0; i<=k; i++) arr[low+i]=temp[i]; 

}


void IMerge(int * arr,int len) {
    int gap=2;
    
    for(;gap<=len;gap*=2){
        for(int low=0; low+gap-1 < len; low+=gap) {
            int high=low+gap-1;
            merging(arr,low,(low+high)/2,high);
        }   
    }

    if((gap/2) < len)
        merging(arr,0,(gap/2)-1,len-1);
    
}
void recMerge(int *arr,int low, int high) {
    if(!(low < high)) return;
    int mid=(low+high)/2;
    recMerge(arr,low,mid);
    recMerge(arr,mid+1,high);
    merging(arr,low,mid,high);
}

int main() {
    // int len=10;
    // int arr[len]={8,6,8,10,9,4,12,5,2,7};
    // int len=3;
    // int arr[len]={10,30,20};
    // int arr[]={10,20,5,40,50,60};
    // int len=2;
    // int arr[len]={10,2};
    // bubbleRec(arr,len,5);
    // selectionSortStable(arr,len);
    // cout<<1/2<<endl;
    int arr[]={50,70,60,90,40,80,10,30};
    int len = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Lean -> "<<len<<endl;
    // display(arr,len);
    // QuickSort(arr,0,len-1);
    display(arr,len);
    
    // cout<<
    recMerge(arr,0,len-1);
    // <<endl;
    display(arr,len);
    return 0;
}

/**

Dear HR Mam,

I am delighted to know that you have decided to elevate my status from probation to permanent and I guarantee that you will not regret your decision.
Regarding the raise in CTC , it is minimal as per my expectations & not compatible with industry standards for someone in my position.
Therefore, I request you to please enhance my increment minimum up to 30,000 per month.

I am available to discuss if there is any additional question or query. I will be grateful to you.

Thanks
Abdus Samad
*/