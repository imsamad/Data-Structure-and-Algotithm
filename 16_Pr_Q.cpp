#include<iostream>
#include "./LinkedList.cpp"
#include "./Queue.cpp"
using namespace std;

class PQ{
    Queue <int> ** ROOT;
    int size;
    public:
    PQ(int s=10) {
        size=s;
        ROOT=new Queue<int>*[10];
        for(int i=0; i<size; i++) ROOT[i] = new Queue<int>();
    }
    
    void enqueue(int data,int pr) {
        if(pr>size || pr<1) return;
        ROOT[pr-1]->enqueue(data);
    }
    
    int dequeue() {
        int higherQ=0;
        for(;ROOT[higherQ]->isEmpty() && higherQ < size;higherQ++);
        return ROOT[higherQ]->isEmpty() ? 0 : ROOT[higherQ]->dequeue();
    }

    bool isEmpty() {
        for(int i=0; i<size; i++)
            if(!ROOT[i]->isEmpty()) return false;
        return true;
    }
};

int main() {
    PQ * p = new PQ();
    for(int i=1; i<=10; i++)
        for(int j=1; j<13;j++) 
            p->enqueue(j+i,i);

    while(!p->isEmpty()) cout<<p->dequeue()<<endl;
    return 0;
}