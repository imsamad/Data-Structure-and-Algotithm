#include<iostream>
#include<climits>
#include "./19_Tree.cpp"
using namespace std;

class BTS: public Tree {
    // TNode * root;
    public:
    BTS(){
        root=NULL;
    }
    TNode * insert(int data,TNode * p =NULL,bool isStart=true);
    TNode * pred(TNode*);
    TNode * succ(TNode*);
    TNode * Delete(int data,TNode* n = NULL);
    TNode * LLRotation(TNode *);
    TNode * LRRotation(TNode *);
    TNode * RRRotation(TNode *);
    TNode * RLRotation(TNode *);
    TNode * maintainHeight(TNode *);
    int BalanceFactor(TNode *);
    int NodeHeight(TNode *);

};

int main() {
    BTS * bts = new BTS();
    int n=15;
    srand(time(0));    
    // for(int i=10;i<=100;i+=10) 
        // bts->insert(i);
    bts->insert(30);
    bts->insert(10);
    bts->insert(40);
    bts->insert(5);
    bts->insert(20);
    bts->display(true);
    cout<<"Height :- "<<bts->height()<<endl;
    bts->Delete(40);
    bts->display(true);

    return 0;
}

int BTS::NodeHeight(TNode * n) {
    int hL=n && n->left ? n->left->height : 0;
    int hR=n && n->right ? n->right->height : 0;
    return hL > hR ? hL+1 : hR + 1;
}

int BTS::BalanceFactor(TNode * n) {
    int hL=n && n->left ? n->left->height : 0;
    int hR=n && n->right ? n->right->height : 0;
    return hL - hR;
}

TNode * BTS::LLRotation(TNode * p) {
    TNode * newParent=p->left;
    TNode * newParentR=newParent->right;

    newParent->right=p;
    p->left = newParentR;
    
    p->height=NodeHeight(p);
    newParent->height=NodeHeight(newParent); 

    if(root==p) root=newParent;

    return newParent;
}

TNode * BTS::LRRotation(TNode * p) {
    TNode * newParent = p->left->right;
    TNode * newParentR = newParent->right; 
    TNode * newParentL = newParent->left; 

    newParent->left = p->left;
    newParent->right= p;

    newParent->left->right=newParentL;
    newParent->right->left=newParentR;
    
    newParent->left->height=NodeHeight(newParent->left);
    newParent->right->height=NodeHeight(newParent->right);
    newParent->height=NodeHeight(newParent);

    if(p==root) root = newParent;
    return newParent;
}

TNode * BTS::RRRotation(TNode * p) {
   TNode * pr=p->right;
   TNode * prl=pr->left;

   pr->left = p;
   p->right = prl;

   p->height=NodeHeight(p);
   pr->height=NodeHeight(pr);     

   if(p==root) root = pr;

   return pr; 
}

TNode * BTS::RLRotation(TNode * p) {
    TNode * newParent=p->right->left;
    TNode * newParentL=newParent->left;    
    TNode * newParentR=newParent->right;

    newParent->left=p->left;
    newParentR->right=p;
    p->right=newParentL;
    newParent->right->left=newParentR;

    newParent->right->height=NodeHeight(newParent->right);
    newParent->left->height=NodeHeight(newParent->left);
    newParent->height=NodeHeight(newParent);
    
    if(p==root) root=newParent;
    return newParent;    
}

TNode * BTS::Delete(int data,TNode * p) {
    static bool isStart=true;
    if(isStart) {isStart=false; p=root;}

    if(!p) return NULL;

    if(p->data == data && !p->left && !p->right) {
        if(p==root) root=NULL;
        delete p;
        return NULL;
    }
    if(data < p->data) {
        p->left=Delete(data,p->left);
    }else if(data > p->data) {
        p->right=Delete(data,p->right);
    } else {
        if(p->left && p->left && height(p->left) > height(p->right)) {
            TNode * q = pred(p->left);
            p->data = q->data;
            p->left = Delete(q->data,p->left);
        } else {
            TNode * q = succ(p->right);
            p->data = q->data;
            p->right = Delete(q->data,p->right);
        }
    }
    return maintainHeight(p);
}

TNode * BTS::pred(TNode * n) {
    while(n && n->right) n = n->right;
    return n;
}

TNode * BTS::succ(TNode * n) {
    while(n && n->left) n = n->left;
    return n;
}

TNode * BTS::maintainHeight(TNode *p){
     p->height=NodeHeight(p);
    if(BalanceFactor(p)==2){
        if(BalanceFactor(p->left)==1 )
            p = LLRotation(p);
        // else if(BalanceFactor(p->right)==-1)
        else  
            p = LRRotation(p);
    } else if(BalanceFactor(p)==-2){
        if(BalanceFactor(p->right)==-1 )
            p = RRRotation(p);
        // else if(BalanceFactor(p->left)==1)
        else 
            p = RLRotation(p);
    }
    return p;
}

TNode * BTS::insert(int data,TNode * p,bool isStart) {
    if(isStart) { isStart=false; p=root;}
 
    if(!p){ TNode * n = new TNode(data);  if(!root){ root=n;} return n;}
    if(data < p->data){
        p->left = insert(data,p->left,isStart);
    }
    else if(data > p->data){       
        p->right = insert(data,p->right,isStart);
    }
    return maintainHeight(p);
}