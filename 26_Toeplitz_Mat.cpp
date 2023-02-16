#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;

class Toeplitz_Mat {
    public:
    int * arr,size;
    
    Toeplitz_Mat(int s) {
        size=s;
        arr=new int[2*s-1];
    }

    void create()  {
        int k=10;
        for(int i=1;i<=size;i++)
        for(int j=1;j<=size;j++)
           if(isValid(i,j)) { set(i,j,k++);}
    }

    int getIndex(int i,int j){
        int index;
        if(i<=j) index=j-i;
        else index = size + i - j - 1;
        return index;
    }   

    bool isValid(int i,int j){ 
        return i==1 || j==1; 
    } 

    void set(int i,int j,int data){
        if(!isValid(i,j)) return;

        int index=getIndex(i,j);
        arr[index]=data;
    }

    int get(int i,int j) {
        return arr[getIndex(i,j)];
    }

    void display() {
        for(int i=1;i<=size;i++) {
            for(int j=1;j<=size;j++)
            cout<<get(i,j)<<"\t";
            cout<<endl<<endl;
        }
    }
};
 
int main() { 
    Toeplitz_Mat * u = new Toeplitz_Mat(10);
    u->create();
    u->display();
    return 0;
}