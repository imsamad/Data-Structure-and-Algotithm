#include<iostream>
#include "./LinkedList.cpp"
#include "./Queue.cpp"
#include "./Stack.cpp"
using namespace std;

class TNode {
    public:
    TNode * left,* right;
    int data,height;
    TNode (int d,TNode * l=NULL,TNode * r=NULL,int h=1) {
        left=l;
        right=r;
        data=d;
        height=h;
    }
};

class Tree{
    public:
    TNode * root;
    Tree() {
        root=NULL;
    }
    void pre(TNode * n = NULL);
    void post(TNode * n = NULL);
    void in(TNode * n = NULL);
    void level();

    void preorder(bool showHeight=false);
    void postorder(bool showHeight=false);
    void inorder(bool showHeight=false);

    void create(int *arr,int len);

    int height(TNode * n = NULL);

    int countNodes(TNode * n=NULL);
    int countLeafNodes(TNode *n=NULL);
    int interiorNodes(TNode * n = NULL);
    int singleNodes(TNode * n = NULL);
    void display(bool showHeight=false){
    cout<<"Inorder :- "; inorder(showHeight);  
    cout<<endl;   
    cout<<"Preorder :- "; preorder(showHeight);     
    cout<<endl;   
    cout<<"Potorder :- "; postorder(showHeight);     
    cout<<endl;
    }
};

// int main() {
//     int n=11;
//     int arr[n]={989,10,20,35,32,91,90,23,56,23,57};
//     Tree * t = new Tree();
//     t->create(arr,n);
//     // t->pre();    
//     // cout<<endl;
//     // t->preorder();    
//     // cout<<endl;
//     // t->in();    
//     // cout<<endl;
//     // t->inorder();
//     // cout<<endl;
//     t->post();    
//     cout<<endl;
//     t->postorder();
//     cout<<endl;
//     // t->level();    
//     // cout<<endl;
//     cout<<"countNodes "<<t->countNodes()<<endl;
//     cout<<"interiorNodes degree 2 "<<t->interiorNodes()<<endl;
//     cout<<"countLeafNodes degree 0 "<<t->countLeafNodes()<<endl;
//     cout<<"singleNodes degree 1 "<<t->singleNodes()<<endl;
//     cout<<"height "<<t->height()<<endl;
//     return 0;
// }

int Tree::singleNodes(TNode * p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p=root; }

    if(!p) return 0;

    // if((!p->left && p->right) || (p->left && !p->right)) return 1;
    if(!!p->left ^ !!p->right) return 1;

    return singleNodes(p->left) + singleNodes(p->right);
}

int Tree::height(TNode * p ){
    static bool isStart = true;
    if(isStart) { isStart=false; p=root;}

    if(!p || (!p->left && !p->right)) return 0;
 
    int x = height(p->left), y = height(p->right);

    return x>y ? x+1 : y+1;
}
int Tree::countLeafNodes(TNode * p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p=root; }
    if(!p) return 0;
    if(!p->left && !p->right) return 1;
    return countLeafNodes(p->left) + countLeafNodes(p->right);
}

int Tree::interiorNodes(TNode * p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p = root;}

    if(!p) return 0;
    int x = interiorNodes(p->left),y = interiorNodes(p->right);
    if(p->left && p->right) return 1 + x + y;
    return x + y;
}


int Tree::countNodes(TNode * n){
    static bool isStart=true;
    if(isStart){ isStart=false; n=root;}
    return !n ? 0 : 1 + countNodes(n->left) + countNodes(n->right);
}

void Tree::postorder(bool showHeight) {
    if(!root) return;
    Stack <TNode *> * st = new Stack<TNode * >();

    TNode  * temp = root;

    while(!st->isEmpty() || temp) {
        if(temp) {
            st->push(temp);
            temp = temp->left;
        } else {
            TNode * p = st->pop();
            long int t = (long int)p;
            if(t > 0) {
                st->push((TNode *)(t * -1));
                temp = p->right;
            } else {
                temp=(TNode*)(t * -1);
                cout<<temp->data<<" ";
            if(showHeight) cout<<temp->height<<" , ";
                temp=NULL;
            }
        }
    }
}

void Tree::preorder(bool showHeight) {
    if(!root) return;
    Stack <TNode *> * st = new Stack<TNode * >();

    TNode  * temp = root;

    while( !st->isEmpty() || temp ){
        if(temp) {
            cout<<temp->data<<" ";            if(showHeight) cout<<temp->height<<" , ";

            st->push(temp);
            temp=temp->left;
        } else {
            temp=st->pop();
            temp=temp->right;
        }
    }
}

void Tree::inorder(bool showHeight) {
    if(!root) return;

    Stack <TNode * > * st = new Stack<TNode * >();
    TNode * temp = root;
    while(!st->isEmpty() || temp) {
        if(temp) {
            st->push(temp);
            temp = temp->left;
        } else {
            temp = st->pop();
            cout<<temp->data<<" ";
            if(showHeight) cout<<temp->height<<" , ";
            temp = temp->right;
        }
    }
}

void Tree::level() {
    if(!root) return;

    Queue <TNode *> * q=new Queue<TNode *>();
    q->enqueue(root);
    while(!q->isEmpty()) {
        TNode * temp = q->dequeue();
        cout<<temp->data<<" ";
        if(temp->left) q->enqueue(temp->left);
        if(temp->right) q->enqueue(temp->right);
    }
}

void Tree::create(int *arr,int len){
    Queue <TNode *> * q=new Queue<TNode *>();
    int k=0;
    root = new TNode(arr[k++]);
    q->enqueue(root);
    while(!q->isEmpty() && k < len ) {
        TNode * temp = q->dequeue();
        if(arr[k]) {
            temp->left=new TNode(arr[k++]);
            q->enqueue(temp->left);
        }
        if(arr[k] && k < len) {
            temp->right=new TNode(arr[k++]);
            q->enqueue(temp->right);
        }
    }
}

void Tree::pre(TNode *p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p=root; }
    // cout<<"isStart "<<isStart<<endl;
    if(!p) return;
    cout<<p->data<<" ";
    pre(p->left);
    pre(p->right);
}

void Tree::post(TNode *p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p=root; }
    
    if(!p) return;
    post(p->left);
    post(p->right);
    cout<<p->data<<" ";
}
void Tree::in(TNode *p) {
    static bool isStart=true;
    if(isStart) { isStart=false; p=root; }
    
    if(!p) return;
    in(p->left);
    cout<<p->data<<" ";
    in(p->right);
}
