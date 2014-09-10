#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
    node(int c,int lf){
        cnt=c;
        leaf=lf;
        //data=d;
        for(int i=0;i<26;i++){
            child.push_back(NULL);
        }
    }
    int cnt;
    int leaf;
    //char data;
    vector<node*> child;
};

void insert(struct node** he,string d){
    cout << d << endl;
    struct node *h=*he;
    if(d.size()==0){
        return;
    }

    if(h->child[d[0]-'a']==NULL){
        //cout << "dfg " << d[0] << endl;
        node* x = new node(0,0);
        h->child[d[0]-'a']=x;
        h->child[d[0]-'a']->cnt+=1;
        if(d.size()==1){
        h->child[d[0]-'a']->leaf=1;
        }

        insert(&(h->child[d[0]-'a']),d.substr(1));
    }
    else{
        //scout << "as " << d[0] << endl;
        h->child[d[0]-'a']->cnt+=1;
        insert(&(h->child[d[0]-'a']),d.substr(1));
    }
}

bool search(struct node* h,string d){
    if(d.size()==1 && h->child[d[0]-'a']!=NULL && h->child[d[0]-'a']->leaf==1){
        return true;
    }
    if(d.size()==1){

        if(h->child[d[0]-'a']==NULL){
            return false;
        }
        if(h->leaf==0){
            return false;
        }
    }
    if(d.size()<1){
        return true;
    }
    if(h->child[d[0]-'a']!=NULL){
        return search(h->child[d[0]-'a'],d.substr(1));
    }
    else{
        return false;
    }
    return false;
}

bool delete_word(struct node** he,string d){
    struct node *h=*he;
    if(d.size()==0){
        return true;
    }

    cout << d << endl;
    if(d.size()==1){
        cout << d << " 1" << endl;
        if(h->child[d[0]-'a']!=NULL){
            cout << d << " 2" << endl;
            if(h->child[d[0]-'a']->leaf==1){
                cout << "fesf" << endl;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    if(h->child[d[0]-'a']!=NULL){
        if(delete_word(&h->child[d[0]-'a'],d.substr(1))){
            h->child[d[0]-'a']->cnt-=1;
            return true;
        }
        else
            return false;
    }
    else{
        return false;
    }
}

int main(){
    struct node* root = new node(0,0);
    insert(&root,"saurabh");
    insert(&root,"sun");
    if(search(root,"sau")){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }
    if(search(root,"sun")){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }
    if(delete_word(&root,"sun")){
        cout << "deleted" << endl;
    }
    else{
        cout << "not del" << endl;
    }
    if(delete_word(&root,"sau")){
        cout << "deleted" << endl;
    }
    else{
        cout << "not del" << endl;
    }
}
