#include<iostream>
#include<climits>
#include<cstdlib>
#include <time.h>
#include<cmath>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node * next;
    Node(T d,Node * n=NULL) {
        data=d;
        next=n;
    } 
};

template <typename T>
class LL {
    public:
    T NILL;
 
    Node <T> * root;
    int size;
    LL() {
        size=0;
        root=NULL;
        NILL=(T)(NULL);
    }
    Node  <T>* nodeAt(int);
    void createList(bool isToSort=false,int len=100, bool random=true) {

       srand(time(0)); 

       if(!isToSort) for(int i=1; i<=len; i++) insert(!random ? i+10 : trunc(rand() % (len)));
       
       else for(int i=1; i<=len; i++) insertSort(trunc(rand() % (len)));
       
       display();
    }

    void display(Node <T> * n = NULL, bool isStart = true);
    void insert(T,int=-1);
    void moveLastToFirst(LL<T> * l=NULL);
    Node <T>* createNode(T data,Node<T> * next=NULL){
        size++;
        return new Node(data,next);
    } 
    void insertSort(T);
    bool isSorted();

    bool isLoop();
    int lengthOfLoop(bool remove=false);
    Node <T>* loopAt();
    void removeLoop();
    
    void createLoop();
    void deleteNode(int);
    void removeDup();

    LL <T>* concat(LL * ,LL *);
    LL <T>* merge(LL * ,LL *);

    void reverse();
    void reverseRec2(Node <T>* q ,Node<T> * p);
    void reverseRec(){reverseRec2(NULL,root);}
    void middle();
    void insertSortRec2(T data,Node<T>*,Node<T>*);
    void insertSortRec(T data){
        if(!root || data < root->data) {
            insert(data,0);
        }
        else insertSortRec2(data, root, root ? root->next : NULL);
    }
    Node <T> * insertEnd(T data,Node <T> *p=NULL,bool isStart=true);
    void isPalindrom(); 
    
    void removeDupSorted();
    void intersection();
    void swapNodeWithoutSwappingData();
};

int main() {
    LL <int>* listA = new LL<int>();   
    // listA->createList(false,20,false);
    // listA->middle();
    listA->insertSortRec(10);
    listA->insertSortRec(5);
    listA->insertSortRec(50);
    listA->insertSortRec(10);
    listA->insertSortRec(10);
    listA->insertSortRec(10);
    listA->insertSortRec(-10);
    listA->display();
    return 0;
}

template<typename T>
Node <T> *  LL<T>::insertEnd(T data, Node <T> * node,bool isStart) {
    if(!root) {
        root = createNode(data);
        return root;  
    }

    if(isStart) node = root;
    isStart=false;

    if(!node) return createNode(data);
    else node->next=insertEnd(data,node->next,isStart);    
    return node;
}

template<typename T>
void LL<T>::insertSortRec2(T data,Node <T>* p ,Node <T> *q) {
    if(!q || (data < q->data && data >= p->data)) 
        p->next=createNode(data,q);
    else insertSortRec2(data, q, q->next);
}

template<typename T>
void LL<T>::middle() {
    Node <T> * p,*q;
    p=q=root;
    while(q) {
        q = q->next;
        // @important - if in case even middle is start of last half then interchange these line of codes.
        if(q) q = q->next;
        if(q) p = p->next;
    } 

    cout<<"Middle => "<<p->data<<endl;
}
template<typename T>
void LL<T>::reverseRec2(Node <T>* q, Node<T> * p) {
    if(p) {
        reverseRec2(p, p->next);
        p->next=q;
    } else root=q;
}

template<typename T>
void LL<T>::reverse() {
    Node <T> *p=root,*q=NULL,*r=NULL;
    while(p) {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    root=q;
}

template<typename T>
LL <T>* LL<T>::merge(LL * listA,LL * listB) {
    LL <T> * listC=new LL<T>();
    Node <T> * lastNode = listA->root;
    listC->size=listA->size + listB->size;
    if(!listA->root && !listB->root) return listC;
    else {
        if(!listA->root) {
            listC->root=listB->root;
            return listC;
        }else if(!listB->root) {
            listC->root=listA->root;
            return listC;
        }
    }
    
    Node <T> * p = listA->root, *q = listB->root,*r;
    
    if(p->data < q->data) {
        listC->root = p;
        p=p->next;
    } else {
        listC->root = q;
        q=q->next;
    }
    
    r=listC->root;
    r->next=NULL;

    while(p && q) {
        if(p->data < q->data){
            r->next=p;
            r=p;
            p=p->next;
        } else {
            r->next=q;
            r=q;
            q=q->next;
        }
        r->next=NULL;
    }
    if(p) r->next=p;
    if(q) r->next=q;

    delete listA;
    delete listB;
    return listC;
}

template<typename T>
LL <T>* LL<T>::concat(LL * listA,LL * listB) {
    LL <T> * listC=new LL<T>();
    Node <T> * lastNode = listA->root;
    listC->size=listA->size + listB->size;
    if(!listA->root && !listB->root) return listC;
    else {
        if(!listA->root) {
            listC->root=listB->root;
            return listC;
        }else if(!listB->root) {
            listC->root=listA->root;
            return listC;
        }
    }
    while(lastNode && lastNode->next) lastNode=lastNode->next;
    
    listC->root=listA->root;
    lastNode->next = listB->root;

    delete listA;
    delete listB;
    return listC;
}

template<typename T>
void LL<T>::deleteNode(int pos) {
    if(pos<0 || !root) return;
    if(pos==0 || pos==1){
        Node <T> * temp=root;
        root=root->next;
        delete temp;
        size--;
        return;
    }
    Node <T>* iNode=root; 
    for(int i=0; i<pos-2 && iNode; i++){ iNode=iNode->next;}
    if(!iNode || !iNode->next) return;
    Node <T> * temp=iNode->next;
    iNode->next=temp->next;
    delete temp;
    size--;
}

template<typename T>
void LL<T>::removeDup() {
    Node  <T> *p=root,*q=NULL;

    while(p && p->next){
        q=p->next;
        while(q && q->data==p->data) { 
            size--; 
            p->next = q->next;
            delete q;
            q = p->next;
        }
        p=q;
    }
}

template<typename T>
bool LL<T>::isSorted() {
    if(!root) return false;
    Node <T> * temp=root;

    while(temp->next) {
        if(temp->data > temp->next->data) return false; 
        temp=temp->next;
    }
    return true;
}
template<typename T>
void LL<T>::insertSort(T data) {
    if(!root || data <= root->data) {
        root=createNode(data,root);
        return;
    }

    Node <T> * p,*q=NULL;
    p=root;
    while(p && data > p->data) {
        q=p;
        p=p->next;
    }
    q->next = createNode(data,q->next);
}

template<typename T>
void LL<T>::removeLoop() {
    Node <T> * loopingNode=loopAt();

    Node <T>* temp=loopingNode;
    while(temp->next!=loopingNode)
        temp=temp->next;
    
    temp->next=NULL; 
}

template<typename T>
Node <T>* LL<T>::loopAt() {
    if(!root) return NULL; 
    int lengthOfLoopX=lengthOfLoop();
    if(!lengthOfLoopX) return NULL;
    int nthNodeLoop=size - lengthOfLoopX;

    Node <T>* loopAtNode = nodeAt(nthNodeLoop);
    return loopAtNode;
}

template<typename T>
void LL<T>::createLoop() {
    if(!root)return;    
    srand(time(0));
    int randNo=rand();
    randNo = randNo % size; 
    randNo=trunc(randNo);
   
    if(randNo<1) randNo=1;

    Node <T>*lastNode,*randNode;
    lastNode=nodeAt(size),randNode=nodeAt(randNo);
    // cout<<"size "<<size<<"randNo "<<randNo<<endl;
    // cout<<"randNode "<<randNode->data<<endl;
    // cout<<"lastNode "<<lastNode->data<<endl;
    // cout<<"length must be "<<size-randNo+1<<endl;
    lastNode->next=randNode;
}

template<typename T>
int LL<T>::lengthOfLoop(bool remove) {
    if(!root) return 0;
    Node <T> *p,*q;
    p=q=root;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
        if(q==p && p) break;
    } while(p && q);

    if(!p) return 0;

    int i=0;

    do {
        i++;
        p=p->next;
    } while(p!=q);
    return i;
}

template<typename T> 
Node <T>* LL<T>::nodeAt(int at) {
    Node <T>*n=root;
    for(int i=0;i<at-1 && n;i++) n=n->next;
    return n;
} 

template<typename T>
bool LL<T>::isLoop() {
    if(!root) return false;
    Node <T> *p,*q;
    p=q=root;
    int i=0;
    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
        if(q==p && p) return true;
    } while(p && q);
    return false;
}

template<typename T>
void LL<T>::moveLastToFirst(LL * list) {
    Node <T> * secondLast = root;
    if(list) secondLast = list->root;
    if(!secondLast || !secondLast->next) return;

    while(secondLast->next->next) secondLast=secondLast->next;
    Node <T> * last = secondLast->next;
    secondLast->next = NULL;
    last->next = root;
    root = last;
}

template<typename T>
void LL<T>::display(Node <T>* node,bool isStart) {
    if(isStart) node = root;
    // For fomatting purpose
    if(!node){ if(!isStart) cout<<endl; return; }
    isStart=false;
    cout<<node->data<<" ";
    display(node->next,isStart);    
}

template<typename T>
void LL<T>::insert(T data,int pos) {
    if(!root && pos!=-1 && pos!=0) {
        return;
    }
 
    if(!root || pos == 0) {
        root = createNode(data,root);
        return;
    }
    Node <T>* iNode = root;
    if(pos == -1) {
        while(iNode->next) iNode = iNode->next;
        iNode->next = createNode(data);
        return;
    }

    for(int i=0; i<pos-1 && iNode; i++) iNode=iNode->next;

    if(!iNode) return;

    iNode->next = createNode(data,iNode->next);
}