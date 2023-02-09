#include<iostream>
using namespace std;

class CQ{
    int front,rear,size,* arr;
    public:
    CQ(int size){this->size=size; arr = new int[size]; front=rear=1; }
    bool isFull(){ return (rear+1) % size == front; }
    bool isEmpty(){ return rear == front; }
    void enqueue(int data){
        if(isFull()) return;
        rear=(rear+1) % size;
        arr[rear]=data;
        // return data;
    }
    int dequeue() {
        if(isEmpty()) return 0;
        
        front = (front+1) % size;
        return arr[front]; 
    }

};

int main() {
    CQ * q = new CQ(10);
    // for(int i=0; i<10; i++) q->enqueue((i+1) * 10);
    for(int i=10; i>0; i--) q->enqueue((i+1) * 10);

    while(!q->isEmpty()) cout<<q->dequeue()<<endl;
    return 0;
}