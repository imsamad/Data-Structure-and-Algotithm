#include<iostream>
using namespace std;

void fun(int * arr, int len, int sum) {
    int max=arr[0],min=arr[0];
    for(int i=0; i<len; i++) if(arr[i] < min) min=arr[i]; else if(arr[i] > max) max = arr[i];

    int * bitSets= new int[max+1];

    for(int i=0; i<len; i++) 
        bitSets[arr[i]]++;
    
    // missing;
    cout<<"Missing :- ";
    for(int i=min; i<=max; i++)
        if(!bitSets[i]) cout<<i<<" ";
    cout<<endl;

    cout<<"Duplicate :- "<<endl;
    for(int i=min; i<=max; i++)
        if(bitSets[i] > 1) cout<<i<<" => "<<bitSets[i] <<endl;
    cout<<endl;


    // for pair of elems;
    // for(int i=0; i<len; i++) 
    //     if(sum-arr[i] > 0 && bitSets[sum-arr[i]]){
    //         cout<<arr[i] << " + "<<sum-arr[i]<<endl;
    //         /* @important :- to display all no matter if repeated*/
    //         bitSets[arr[i]]=0;
    //     }

    for(int i=min; i<=max; i++)
        /* @important :- 10 = 5 + 5 */
        if( sum > i && bitSets[i] && bitSets[sum-i]  ) {
            if(i==sum-i && bitSets[i]==1) continue;
            cout<<i << " + "<<sum-i<<endl;
            /* @important :- to display all duplicated -- 
            to display distinct pairs 0 */
            bitSets[i]--;
            bitSets[sum-i]--;
        }
}

int main() {
            int arr2[]={9,7,10,8,8,9,10,12,2,12};
        fun(arr2,10,10);

    return 0;
}