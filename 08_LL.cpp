#include<iostream>
#include <climits>
#include <typeinfo>
using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node  * next;
    Node(T d,Node * n = NULL) {
        data=d;
        next=n;
    }
};

template<typename T>
class LL {
    Node <T> *root; 
    T nill;
    public:
    
    LL() {
        root = NULL; 
        nill = (T)(NULL);
    }

    void insertAfter(T,int at =-1);
    void insertSortRes(T data, Node <T> * p, Node <T> * q);
    
    void insertSort(T data) {
        if(!root) { insertAfter(data); }
        else if(!root->next && data < root->data) { insertAfter(data,0); }
        else { insertSortRes(data,root,NULL); }
    }

    void display(bool reverse = false,Node <T> * node = NULL, bool isStarting=true);
    int count(Node   <T> *   node = NULL, bool isStarting=true);
    
    Node  <T>* searchCom(T data,Node  <T> * node = NULL, bool isStarting=true);

    Node  <T>* searchRes(T data, Node <T> * p, Node <T> * q);

    void removeDuplicate() {
        Node <T> * p = root,*q = NULL;
        while(p) {
            q=p->next;
            while(q && q->data == p->data) { 
                Node <T> * dupNode = q;
                q = q->next;
                delete dupNode;
            }
            p->next = q;
            p=q;
        }
    }    
    T search(T data) {
        if(!root) return nill;
        
        if(root->data == data) return root->data;

        Node <T> * res= searchRes(data,root,NULL);
        
        return res ? res->data : nill;
    }

    T max(Node  <T>  *  node = NULL, bool isStarting=true);
};

int main() {

    LL <int>*l=new LL<int>();
    // l->insertAfter(23,0);
    // cout<<l->count()<<endl;
    // for(int i=10; i<=100; i+=10) l->insertAfter(i);
    // l->insertAfter(112,1);
    l->insertSort(10);
    l->display();cout<<endl;
    l->insertSort(50);
    l->display();cout<<endl;
    return 0;
    l->insertSort(7);
    l->display();cout<<endl;
    l->insertSort(50);
    l->display();cout<<endl;
    l->insertSort(423);
    l->display();cout<<endl;
    l->insertSort(434);
    l->display();cout<<endl;
    l->insertSort(434);
    l->display();cout<<endl;
    l->insertSort(4343423);
    l->display();cout<<endl;
    l->insertSort(5);
    l->display();cout<<endl;
    l->insertSort(5);
    l->display();cout<<endl;
    l->insertSort(5);
    l->display();cout<<endl;
    l->insertSort(5);
    l->display();cout<<endl;
    l->insertSort(434);
    l->display();cout<<endl;
    l->insertSort(4546);
    l->display();cout<<endl;
    l->insertSort(4234);
    l->display();cout<<endl;
    l->insertSort(543);
    l->display();cout<<endl;
    l->removeDuplicate();
    cout<<endl;
    // cout<<endl;
    // cout<<"Count - "<<l->count()<<endl; 
    // cout<<"Max - "<<l->max()<<endl; 
    // cout<<"Search - "<<l->search(20)<<endl; 
 
    l->display();cout<<endl;

    cout<<endl;
    return 0;
}
 
template <typename T>
void LL<T>::insertAfter(T data,int at) {
    /**
    * a.) LL might be empty and @at > 0;
    * b.) LL is empty && @at = 0
    * c.) Prepend at start if @at = 0
    * d.) Append at last if @at = -1 (default)
    * e.) Insert at any index @at = n;
    */

    if(!root && at!=0 && at!=-1){
        cout<<"Linked list is empty!"<<endl;
        return;
    }

    Node  <T> * newNode = new Node <T> (data);

    if(!root) {
        root=newNode;
        return;
    }

    // At starting
    if(at==0){
        newNode->next=root;
        root=newNode;
        return;        
    }

    Node  <T>* iNode=root;
    // at last

    if(at==-1) {
        while(iNode->next) iNode=iNode->next;
        iNode->next=newNode;    
        return; 
    }

    for(int i=0;i<at-1 && iNode;i++)iNode=iNode->next;
    
    if(!iNode) {
        cout<<"Provide Proper Index"<<endl;
        return;
    }
    
    newNode->next = iNode->next;
    iNode->next=newNode;
}

template <typename T>
void LL<T>::display(bool reverse,Node  <T>* node, bool isStarting) {
    if(isStarting) node = root;

    if(!node) return;
    
    if(!reverse) {
        cout<<node->data<<"  ";
        display(reverse,node->next,false);
    } else {
        display(reverse,node->next,false);
        cout<<node->data<<"  ";
    }
} 

template <typename T>
int LL<T>::count(Node  <T>* node, bool isStarting) {
    if(isStarting) node = root;

    if(!node) return 0;
    
    return count(node->next,false) + 1;
} 

template <typename T>
T LL<T>::max(Node  <T> * node, bool isStarting) {
    if(isStarting) node = root;

    if(!node) return INT_MIN;
    T nextMax=max(node->next,false);   
    return node->data > nextMax ? node->data : nextMax;
} 

template <typename T>
Node <T>* LL<T>::searchCom(T data,Node  <T>* node, bool isStarting) {
    if(isStarting) node = root;

    if(!node) return NULL;
    if(node->data==data) return node;
    
    return searchCom(data,node->next,false);
}

template <typename T>
Node <T>* LL<T>::searchRes(T data, Node  <T>* p, Node  <T>* q) {
    if(!p) return NULL;
    if(q && p->data == data) {
        Node <T> * temp = p;
        q->next = temp->next;
        temp->next = root;
        root = temp;
        return p;
    }
    return searchRes(data,p->next,p);

}

template <typename T>
void LL<T>::insertSortRes(T data, Node <T> * p, Node <T> * q) {
    // incoming data inserting index is at last
    if(!p){ 
        q->next= new Node<T>(data);
        return;
    }
    // incoming data inserting index happens to second last i.e. value < than last && > last item
    // or data is duplicated
    if((!p->next && p->data > data) ||  p->data == data) {
       if(q) q->next=new Node<T>(data,p);
       // if incoming data == 0th item   
       else p->next=new Node<T>(data,p->next);
       return;
    }    
    if(p->data < data) insertSortRes(data,p->next,p);
}