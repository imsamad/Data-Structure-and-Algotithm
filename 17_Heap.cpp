#include<iostream>
#include <time.h>

using namespace std;
void swap(int &x,int &y) {
    if(x==y) return;
    x=x+y;
    y=x-y;
    x=x-y;
}

class Heap{
    int last,size,*arr;
    public:
    Heap(int s=10){
        last = 0;
        size = s;
        arr = new int[size+1];
    }
    void display() {
        for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void insert(int data) {
        last++;
        arr[last]=data;
        int i=last;
        while(i>1 && data > arr[i/2]) {
            arr[i]=arr[i/2];
            i/=2;
        }
        arr[i]=data;
    }
    void sort() {
        int f=last;
        for(int i=0; i<f;i++) pop();
    }
    int pop() {
        int rootElem=arr[1];
        arr[1]=arr[last--];
        int i=1,j=2;
        while(j < last) {
            if(arr[j+1] > arr[j]) j++;
            if(arr[j] > arr[i]){
                swap(arr[j],arr[i]);
                i=j;
                j=2*i;
            }
            else break;
        }
        arr[last+1] = rootElem;
        return rootElem;
    }
};

int main() {
    int n=20;
    Heap * h = new Heap(n);
  int arr[]= {240, 62, 347, 454, 516, 567, 625, 723, 769, 794, 932, 1000 ,1084, 1275, 1293, 1559, 1698, 1788 ,1867 ,1984};
    for(int i=0;i<n;i++)
        h->insert(arr[i]);
    h->sort();
    h->display();
    
    return 0;
}