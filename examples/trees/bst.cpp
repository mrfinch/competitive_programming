#include <iostream>
#include <climits>
//#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

struct node{
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
    int data;
    node* left;
    node* right;
    node* parent;
};

struct node* insertNode(struct node* h,int x){
    static node *p;
    if(h==NULL){
        node* y = new node(x);
        y->parent=p;
        return y;
    }
    if(h->data>x){
        p=h;
        h->left=insertNode(h->left,x);
    }
    else{
        p=h;
        h->right=insertNode(h->right,x);
    }
    return h;
}

bool searchNode(struct node* h,int x){
    if(h==NULL){
        return false;
    }
    if(h->data==x){
        return true;
    }
    if(x<h->data){
        searchNode(h->left,x);
    }
    else{
        searchNode(h->right,x);
    }
}

void inorder(struct node* h){
    if(h==NULL){
        return;
    }
    inorder(h->left);
    cout << h->data << endl;
    inorder(h->right);
}

void iterative_inorder(struct node* h){
    stack<node*> s;
    bool done=false;
    //s.push(h);
    node* curr=h;
    while(!done){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            if(!s.empty()){
                node* x=s.top();
                s.pop();
                cout << x->data << endl;
                curr=x->right;
            }
            else{
                done=true;
            }
        }
    }
}

void postorder(struct node* h){
    if(h==NULL)
        return;
    postorder(h->left);
    postorder(h->right);
    cout << h->data << endl;
}

void iterative_postorder(struct node *h){
    if(h==NULL)
        return;
    stack<node*> s;
    node *curr=h;
    do{
        while(curr!=NULL){
            if(curr->right!=NULL){
                s.push(curr->right);
            }
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        //cout << curr->data << " hg " << s.size() << endl;
        if(curr->right && !s.empty() &&curr->right==s.top()){
            s.pop();
            s.push(curr);
            curr=curr->right;
        }
        else{
            cout << curr->data << endl;
            curr=NULL;
        }

    }while(!s.empty());
}

bool isBST(struct node* h,int mx,int minm){
    if(h==NULL){
        return true;
    }
    if(h->data<minm || h->data>mx){
        return false;
    }
    return isBST(h->left,h->data-1,minm)&&isBST(h->right,mx,h->data+1);
}

int height(struct node* h){
    if(h==NULL){
        return 0;
    }
    else{
        return 1+max(height(h->left),height(h->right));
    }
}

bool isBalanced(struct node* h){
    if(h==NULL){
        return 1;
    }
    int lh = height(h->left);
    int rh = height(h->right);
    return (abs(lh-rh)<=1 && isBalanced(h->left) && isBalanced(h->right));
}


struct node* findMin(struct node *h){
    while(h->left!=NULL){
        h=h->left;
    }
    return h;
}

struct node* inorderSuccessor(struct node* h,struct node *n){
    node *root = h;
    node *inp = n;
    if(inp->right!=NULL){
        return findMin(inp->right);
    }
    else{
        node *p = n->parent;
        while(p!=NULL && inp==p->right){
            inp=p;
            p=p->parent;
        }
        return p;
    }
}

struct node* findMax(struct node *h){
    while(h->right!=NULL){
        h=h->right;
    }
    return h;
}

struct node* inorderPredecessor(struct node* h,struct node *n){
    //root nt needed
    if(n->left!=NULL){
        return findMax(n->left);
    }
    else{
        return n->parent;
    }
}

node* lca(node* root,node* n1,node* n2){
    if(root==NULL){
        return NULL;
    }
    if((n1->data <= root->data && root->data <= n2->data) || (n2->data <= root->data && root->data <= n1->data)){
        return root;
    }
    else if(root->data > n2->data && root->data > n1->data){
        lca(root->left,n1,n2);
    }
    else if(root->data < n1->data && root->data < n2->data){
        lca(root->right,n1,n2);
    }
}

int treeSize(struct node* h){
    if(h==NULL){
        return 0;
    }
    return 1+treeSize(h->left)+treeSize(h->right);
}

void printPath(const vector<int> m,int level){
    cout << "Start path\n";
    for(int i=0;i<level;i++){
        cout << m[i] << " ";
    }
    cout << endl;
    cout << "End" << endl;
}

void printPathRootToLeaf(struct node* h,vector<int>& path,int level){
    if(h==NULL){
        return;
    }
    path[level]=h->data;
    level++;

    if(h->left==NULL && h->right==NULL){
        printPath(path,level);
    }
    printPathRootToLeaf(h->left,path,level);
    printPathRootToLeaf(h->right,path,level);
}

bool isIdenticalTree(struct node* t1,struct node* t2){
    if(t1==NULL && t2==NULL){
        return true;
    }
    if(t1==NULL || t2==NULL){
        return false;
    }
    if(t1->data!=t2->data){
        return false;
    }
    return isIdenticalTree(t1->left,t2->left)&&isIdenticalTree(t1->right,t2->right);
}

void mirrorTree(struct node* root){
    if(root==NULL)
        return;
    node* temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

bool isSubtree(struct node* n1,struct node* n2){
    if(n2==NULL)
        return true;
    if(n1==NULL)
        return false;
    if(isIdenticalTree(n1,n2))
        return  true;
    return isSubtree(n1->left,n2)||isSubtree(n1->right,n2);
}

int main(){
    node *root = new node(40);
    insertNode(root,45);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,32);
    insertNode(root,43);
    cout << "inorder" << endl;
    inorder(root);
    cout << "iterative_inorder" << endl;
    iterative_inorder(root);
    cout << "postorder" << endl;
    postorder(root);
    cout << "Iter postorder" << endl;
    iterative_postorder(root);
    if(searchNode(root,21)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    if(isBST(root,INT_MAX,INT_MIN)){
        cout << "Is BST" << endl;
    }
    else{
        cout << "Not BST" << endl;
    }
    int ht = height(root);
    cout << ht << endl;
    if(isBalanced(root)){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not balanced" << endl;
    }
    node* temp=root;
    cout << "Inorder successor of ";
    cout << temp->data << endl;
    node *a = inorderSuccessor(root,temp);
    cout << a->data << endl;
    cout << "Inorder predecessor of ";
    cout << temp->left->data << endl;
    node *b = inorderPredecessor(root,temp->left);
    cout << b->data << endl;
    cout << "LCA of ";
    cout << temp->left->left->data << " " << temp->right->left->data << endl;
    node* c = lca(root,temp->left->left,temp->right->left);
    cout << c->data << endl;
    cout << treeSize(root) << endl;
    vector<int> path(treeSize(root),0);
    printPathRootToLeaf(root,path,0);

    node *r = new node(40);
    insertNode(r,45);
    insertNode(r,30);
    insertNode(r,20);
    insertNode(r,32);
    insertNode(r,43);
    if(isIdenticalTree(root,r)){
        cout << "Identical" << endl;
    }
    else{
        cout << "Not Identical" << endl;
    }
    //mirrorTree(root);
    inorder(root);
    node *rr = new node(30);
    //insertNode(rr,45);
    insertNode(rr,32);
    insertNode(rr,20);

    if(isSubtree(root,rr)){
        cout << "Subtree" << endl;
    }
    else{
        cout << "Not subtree" << endl;
    }

}
