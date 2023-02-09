#include<iostream>
// #include "./09_LinkedList.cpp"

using namespace std;

template<typename T>
class Queue {
    LL <T> * linkedList;
    T NILL;
    public:
    Queue(){
        NILL=(T)NULL;
        linkedList=new LL<T>();
    }
    void enqueue(T data){
        linkedList->insert(data,-1);
    }
    T dequeue() {
        if(isEmpty()) return NILL;
        Node  <T>* firstNode=linkedList->firstNode();
        T data=firstNode->data;
        linkedList->deleteNode(0);
        return data;
    }
    T top() {
        return isEmpty() ? NILL : linkedList->firstNode()->data;
    }
    bool isEmpty() {
        return linkedList->isEmpty();
    }
    T peekAt(int pos) {
        return isEmpty() || !linkedList->nodeAt(pos) ? NILL : linkedList->nodeAt(pos)->data;
    }
};

// int main() {
//     Queue <int> * Q = new Queue<int>();

//     for(int i=10;i<=100; i+=10) Q->enqueue(i);

//     while(!Q->isEmpty()) {
//         cout<<Q->top()<<endl;
//         cout<<Q->dequeue()<<endl;
//     }    
//     return 0;
// }