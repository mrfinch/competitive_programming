#include <iostream>

using namespace std;

struct node{
	node(int x){
		data=x;
		this->next=NULL;
	}
	int data;
	node* next;
};

void addNode(struct node *h,int x){
    cout << "Add node" << endl;
    node* cur = h;
    struct node* n = new node(x);
    while(cur){
        if(cur->next==NULL){
            cur->next=n;
            break;
        }
        cur=cur->next;
    }
}

void insertFront(struct node** h,int x){
    cout << "Insert front" << endl;
    struct node* n = new node(x);
    n->next = *h;
    *h = n;
}

void reverse(struct node **h){
    cout << "Reverse" << endl;
    node *cur = *h;
    node *prev = NULL;
    while(cur){
        cout << cur->data << endl;
        //cur->next=prev;
        node *temp = cur;
        //prev=cur;
        cur=cur->next;
        temp->next=prev;
        prev=temp;
    }
    *h = prev;
}

struct node* searchNode(struct node *h,int x){
    node *cur = h;
    while(cur){
        if(cur->data==x){
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}

bool deleteNode(struct node *h,int data){
    node* cur = h;
    node *x = searchNode(cur,data);
    if(x==NULL){
        return false;
    }
    node *prev=NULL;
    while(cur!=x){
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    return true;
}

void display(struct node* h){
    cout << "display" << endl;
    node *l = h;
    while(l){
        cout << l->data << endl;
        l=l->next;
    }
}

int main(){
	struct node* head = new node(50);
	addNode(head,23);
	display(head);
	insertFront(&head,34);
	display(head);
	reverse(&head);
	display(head);
	node *x = searchNode(head,50);
	cout << x->data << endl;
	if(deleteNode(head,50)){
        cout << "Deleted" << endl;
	}
	else{
        cout << "Not" << endl;
	}
	display(head);
	return 0;
}
