#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * prev;
    Node * next;
    Node (int data,Node * prev=NULL, Node * next=NULL) {
        this->data=data;
        this->prev=prev;
        this->next=next;        
    }    
};

class DLL{
    Node * root;
    bool isReverse;
    public:
    DLL() {
        root=NULL;
        isReverse=false;
    }
    Node * createNode(int data,Node * prev=NULL, Node * next=NULL) {
        return new Node(data,prev,next);
    }
    void insert(int data,int pos=-1);
    void display(Node * n=NULL,bool isStart=true);
    void reverse() {
        Node * iNode=root,*next;
        while(iNode) {
            if(!iNode->next) root=iNode;
            next=iNode->next;            
            iNode->next=iNode->prev;
            iNode->prev=next;
            iNode=next;
        }
    }

    void deleteNode(int pos) {
        if(!root) return;
        
        Node * temp=root;
        if(pos==0 || pos==1){
            root=root->next;
            if(root) root->prev=NULL;
            delete temp;
            return;    
        }
        
        for(int i=0;i<pos-2 && temp->next; i++)
            temp=temp->next;
        
        // @important - in case pos = size of list + 1
        if(!temp || !temp->next) return;
        
        Node * deletedNode=temp->next;

        temp->next=deletedNode->next;
        // @if deletedNode is not last is list
        if(temp->next) temp->next->prev=temp;

        delete deletedNode;
    }
};

int main() {
    DLL * dll = new DLL();
    dll->insert(10);
    dll->insert(20);
    dll->insert(30);
    dll->insert(40);
    dll->insert(50);
    dll->insert(60);
    dll->insert(70);
    dll->display();    
    // dll->reverse();
    // cout<<"After reverse"<<endl;
    // dll->display();    
    cout<<"After delete 1"<<endl;
    dll->deleteNode(8);
    dll->display();    

    return 0;
}

void DLL::display(Node * n,bool isStart) {
    if(isStart) n=root;
    if(!n){ if(!isStart) cout<<endl; return; }
    // cout<<n<<endl;
    cout<<n->data<<" ";
    // cout<<n->prev<<" "<<n->data<<" "<<n<<" "<<n->next<<", ";
    display(isReverse ? n->prev : n->next,false);
}

void DLL::insert(int data,int pos) {
    if(!root && pos!=-1 && pos!=0) {
        return;
    }
    if(!root || pos==0) {
        Node * n=createNode(data,NULL,root);
        if(root) root->prev=n;
        root=n;
        return;
    }
 
    Node * iNode=root;
 
    if(pos==-1) {
        while(iNode->next) iNode=iNode->next;
        iNode->next=createNode(data,iNode,NULL);
        return;
    }    

    for(int i=0; i<pos-1 && iNode; i++) iNode=iNode->next;
 
    if(!iNode) return;

    iNode->next=createNode(data,iNode,iNode ? iNode->next : NULL);
}

