#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

class avl_node{
    public:
        char word[20], meaning[20];
        avl_node *left;
        avl_node *right;
        friend class avlTree;
};

class avlTree{
    avl_node *root;
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotational(avl_node *);
        avl_node *ll_rotational(avl_node *);
        avl_node *lr_rotational(avl_node *);
        avl_node *rl_rotational(avl_node *);
        avl_node *balance(avl_node *);
        void insert();
        avl_node *insert(avl_node *, avl_node *);
        void display(avl_node *, int);
        void inorder(avl_node *);
        avlTree(){
            root = NULL;
        }
};

avl_node* avlTree::ll_rotational(avl_node *parent){
    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node* avlTree::rr_rotational(avl_node *parent){
    avl_node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node* avlTree::rl_rotational(avl_node *parent){
    avl_node *temp = parent->right;
    parent->right = rr_rotational(temp);
    return ll_rotational(parent);
}

avl_node* avlTree::lr_rotational(avl_node *parent){
    avl_node *temp = parent->left;
    parent->left = ll_rotational(temp);
    return rr_rotational(parent);
}

int avlTree::diff(avl_node *temp){
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

int avlTree::height(avl_node *temp){
    int h = 0;
    if(temp != NULL){
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height,r_height);
        h = max_height+1;
    }
    return h;
}

avl_node *avlTree::balance(avl_node *temp){
    int bal_factor = diff(temp);
    if(bal_factor > 1){
        if(diff(temp->left) > 0)
            temp = ll_rotational(temp);
        else
            temp = lr_rotational(temp);
    }
    else if(bal_factor < -1){
        if(diff(temp->right) > 0)
            temp = rl_rotational(temp);
        else
            temp = rr_rotational(temp);
    }
    return temp;
}

void avlTree::insert(){
    char ch;
    do{
        avl_node *temp = new avl_node;
        cout << "Enter a word and its meaning : ";
        cin >> temp->word >> temp->meaning;
        root = insert(root,temp);
        display(root,0);
        cout << "Enter your choice (Y/N) : ";
        cin >> ch;
    } while(ch == 'Y');
}

avl_node *avlTree::insert(avl_node *root, avl_node *temp){
    if(root == NULL){
        root = new avl_node;
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(strcmp(temp->word, root->word) < 0){
        root->left = insert(root->left, temp);
        root = balance(root);
    }   
    else if(strcmp(temp->word, root->word) >= 0){
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

void avlTree::display(avl_node* ptr ,int level){
    if(ptr != NULL){
        display(ptr->right, level + 1);
        cout << "\n";
        if(ptr == root)
            cout << "Root->";
        for(int i = 0; i < level && ptr != root; i++)
            cout << "  ";
            cout << ptr->word <<" " << ptr->meaning<<endl;
        display(ptr->left, level + 1);
    }
}

int main(){
    avlTree at;
    at.insert();
}