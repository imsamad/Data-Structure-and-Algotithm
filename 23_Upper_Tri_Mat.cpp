#include<iostream>
#include<climits>

using namespace std;

class UpperTri {
    public:
    int * arr,size;
    UpperTri(int s) {
        size=s;
        arr=new int[s*(s+1)/2];
    }
    void create()  {
        int k=10;
        for(int i=1;i<=size;i++)
        for(int j=1;j<=size;j++)
        set(i,j,k++);
    }
    int getIndex(int i,int j){
        return (j-1)*j/2+(i-1);
    }   

    bool isValid(int i,int j){
        return i <= j; 
    } 
    void set(int i,int j,int data){
        if(!isValid(i,j)) return;

        int index=getIndex(i,j);
        arr[index]=data;
    }

    int get(int i,int j) {
        return !isValid(i,j) ? 0 : arr[getIndex(i,j)];
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
  
    UpperTri * u = new UpperTri(10);
    u->create();
    u->display();
    return 0;
}