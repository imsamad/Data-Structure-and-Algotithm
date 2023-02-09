#include<iostream>
#include "./LinkedList.cpp"
#include "./Stack.cpp"

using namespace std;

class Queue{
    Stack <int>* S1,*S2;
    public:
    Queue(){ S1=new Stack<int>(); S2=new Stack<int>();}
    void enqueue(int data) {
        S1->push(data);
    }
    int dequeue() {
        if(S2->isEmpty())
            while(!S1->isEmpty()) S2->push(S1->pop());
        return S2->pop();
    }
    bool isEmpty() {
        return S1->isEmpty() && S2->isEmpty();
    }
};

int main() {
    Queue * Q = new Queue();
    Q->enqueue(78923);
    for(int i=10;i<=100; i+=10) Q->enqueue(i);
    Q->enqueue(789237979);

    while(!Q->isEmpty()) {
        cout<<Q->dequeue()<<endl;
    }    
    return 0;
}