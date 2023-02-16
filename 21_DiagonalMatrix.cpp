#include<iostream>
using namespace std;
class Matrix {
    int *arr,size;
    public:
    Matrix(int s=10){
        size=s;
        arr = new int[s];
    }
    void set(int i,int j,int data){
        
        if(i==j) arr[i-1] = data;
    }
    int get(int i,int j){
        return i==j ? arr[i-1] : 0;
    }

    void display() {
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++)
                cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main() {
    int n=5;
    Matrix * m = new Matrix(n);
    for(int i=1;i<=n;i++) m->set(i,i,i*10);
    m->display();

    return 0;
}