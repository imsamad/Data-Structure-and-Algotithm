#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int d,Node * n) { data=d; next=n; }
};

class CLL {
    public:
    Node * root;
    CLL() { root=NULL; }
    Node * createNode(int data,Node * next) { return new Node(data,next); }
    void display() {
        if(!root) return;
        Node * iNode=root;
        do {
            cout<<iNode->data<<" ";
            iNode=iNode->next;
        }while(iNode!=root);
        if(root) cout<<endl;
    }
    void insert(int data, int pos=-1) {
        if(pos < -1) return;
        if(!root){
            Node * newNode=createNode(data,root);
            newNode->next=newNode;
            root=newNode;
            return;
        }

        if(pos==0) {
            Node * lastNode=root;
            do{
                lastNode=lastNode->next;
            }while(lastNode->next!=root);
            lastNode->next=createNode(data,root);
            root=lastNode->next;
            return;
        }

        if(pos==-1) {
            Node * lastNode=root;
            do {
                lastNode=lastNode->next;
            } while(lastNode->next!=root);

            lastNode->next=createNode(data,root);
            return;
        }
        Node * iNode=root;
        int i=0;
        for(; i<pos-1 && iNode->next!=root; i++) iNode=iNode->next;
        cout<<"iNode->data "<<iNode->data<<endl;
        if(i==pos-1) {
            iNode->next=createNode(data,iNode->next);
        } else {

        }
    }
    void deleteNode(int pos) {
        if(!root)return;
        Node * iNode=root;
        if(pos==0 || pos==1) {
            if(iNode->next==root) {
                delete root;
                root=NULL;
                return;
            }

            do {
                iNode=iNode->next;
            } while(iNode->next!=root);
            iNode->next=root->next;
            delete root;
            root = iNode->next;
            return;
        }
        int i=0;
        for(; i<pos-2 && iNode->next!=root; i++) iNode=iNode->next;

        if(i!=pos-2 || iNode->next==root) return;

        Node * deletedNode=iNode->next;
        iNode->next=deletedNode->next;
        delete deletedNode;  
    }
};

int main() {
    CLL * cll = new CLL();
    cll->insert(10);
    cll->insert(20);
    cll->insert(30);
    cll->insert(40);
    cll->insert(50);
    cll->insert(60);
    cll->insert(70);
    cll->display();
    cll->deleteNode(6);
    // cll->deleteNode();
    cll->display();
    return 0;
}