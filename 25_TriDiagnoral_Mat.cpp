#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;

class Tri_Diag_Matx {
    public:
    int * arr,size;
    
    Tri_Diag_Matx(int s) {
        size=s;
        arr=new int[3*s-1];
    }

    void create()  {
        int k=10;
        for(int i=1;i<=size;i++)
        for(int j=1;j<=size;j++)
           if(isValid(i,j)) { set(i,j,k++);}
    }
    int getIndex(int i,int j){
        int index;
        if(i-j==-1) index = j-1;
        else if(i-j==0) index = size-1+j-1;
        else index = (2 * size)-1+j-1;
        return index;
    }   

    bool isValid(int i,int j){ 
        return abs(i-j) <=1 ; 
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
  
    Tri_Diag_Matx * u = new Tri_Diag_Matx(4);
    u->create();
    // u->display();
    return 0;
}