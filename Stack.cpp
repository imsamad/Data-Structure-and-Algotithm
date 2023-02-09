#include<iostream>
// #include "./09_LinkedList.cpp"
using namespace std;

template <typename T>
class Stack {
    
    LL <T> * ll;T NILL;
    public:
    Stack() { ll = new LL<T>(); T NILL=(T)NULL;}
    T push(T data){
        ll->insert(data,0);
        // ll->display();
        return data;
    }
    T pop() {
        if(!ll->root) return NILL;
        Node <T> * firstNode=ll->nodeAt(0);
        T data = firstNode->data;
        ll->deleteNode(0);
        // delete firstNode;
        return data;
    }
    bool isEmpty() { return ll->root ? false : true; }

    T top(){
        if(!ll->root) return NILL;
        Node <T> * firstNode=ll->nodeAt(0);
        T data = firstNode->data;
        return data;
    }
};

// int main() {
//     Stack <int>* st=new Stack<int>();
    
//     st->push(10); 
//     st->push(2332); 
//     st->push(65); 
//     st->push(89979); 
//     st->push(67567);
//     while(!st->isEmpty()) {
//         int elem = st->pop();

//         cout<<elem<<endl;
//     } 
//     return 0;
// }