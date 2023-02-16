#include<iostream>
#include<climits>

using namespace std;

class Symm_Matx {
    public:
    int * arr,size;
    
    Symm_Matx(int s) {
        size=s;
        arr=new int[s*(s+1)/2];
    }

    void create()  {
        int k=10;
        for(int i=1;i<=size;i++)
        for(int j=1;j<=size;j++)
           if(isValid(i,j)) { set(i,j,k++);}
    }
    int getIndex(int i,int j){
        return (i-1)*i/2+(j-1);
    }   

    bool isValid(int i,int j){
        return i >= j; 
    } 

    void set(int i,int j,int data){
        if(!isValid(i,j)) return;

        int index=getIndex(i,j);
        arr[index]=data;
    }

    int get(int i,int j) {
        if(j>i) {
            i=i+j;
            j=i-j;
            i=i-j;
        }
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
  
    Symm_Matx * u = new Symm_Matx(10);
    u->create();
    u->display();
    return 0;
}