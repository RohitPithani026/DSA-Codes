#include<iostream>
using namespace std;

class bt;

class stack {
private:
    int top;
    bt* data[30];

public:
    stack();
    void push(bt* temp);
    bt* pop();
    int isFull();
    int isEmpty();
};

class bt {
public:
    int data;
    bt* left;
    bt* right;
    friend class tree;
    friend class stack;
};

class tree {
    bt* root;

public:
    tree();
    void create_r();
    void create_r(bt* temp);
    void non_recursive_inorder();
    void non_recursive_preorder();
    void non_recursive_postorder();
};

tree :: tree(){
	
	root = NULL;
}

stack::stack() {
    top = -1;
}

void stack::push(bt* temp) {
    if (!isFull()) {
        top++;
        data[top] = temp;
    }
}

bt* stack::pop() {
    if (!isEmpty()) {
        bt* temp = data[top];
        top--;
        return temp;
    }
    return NULL;
}

int stack :: isFull(){
	
	if(top == 29){
		return 1;
		
	}
	else {
		return 0;
	}
	
}

int stack :: isEmpty(){
	
	if(top == -1){
		
		return 1;
	}
	else{
		
		return 0;
	}
	
}


void tree::create_r() {
    root = new bt;

    cout << "Enter the root node" << endl;
    cin >> root->data;
    root->left = NULL;
    root->right = NULL;
    create_r(root);
}

void tree::create_r(bt* temp) {
    char ch;

    cout << "Do you want to insert a new node to the left of " << temp->data << "? (y/n)" << endl;
    cin >> ch;

    if (ch == 'y') {
        bt* curr = new bt;
        cout << "Enter data for the left node" << endl;
        cin >> curr->data;
        curr->left = NULL;
        curr->right = NULL;
        temp->left = curr;
        create_r(curr);
    }

    cout << "Do you want to insert a new node to the right of " << temp->data << "? (y/n)" << endl;
    cin >> ch;

    if (ch == 'y') {
        bt* curr = new bt;
        cout << "Enter data for the right node" << endl;
        cin >> curr->data;
        curr->left = NULL;
        curr->right = NULL;
        temp->right = curr;
        create_r(curr);
    }
}

void tree::non_recursive_inorder() {
    cout << "Non-recursive Inorder: ";
    stack stk;
    bt* curr = root;

    while (1) {
        while (curr != NULL) {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.pop();

        if (curr == NULL) {
            break;
        }

        cout << curr->data << " ";

        curr = curr->right;
    }

    cout << endl;
}

void tree::non_recursive_preorder() {
    cout << "Non-recursive Preorder: ";
    stack stk;
    bt* curr = root;

    while (1) {
        while (curr != NULL) {
            cout << curr->data << " ";
            stk.push(curr);
            curr = curr->right;
        }

        curr = stk.pop();

        if (curr == NULL) {
            break;
        }

        curr = curr->left;
    }

    cout << std::endl;
}

void tree::non_recursive_postorder() {
    cout << "Non-recursive Postorder: ";
    stack stk1, stk2;
    stk1.push(root);

    while (!stk1.isEmpty()) {
        bt* curr = stk1.pop();
        stk2.push(curr);

        if (curr->left != NULL) {
            stk1.push(curr->left);
        }

        if (curr->right != NULL) {
            stk1.push(curr->right);
        }
    }

    while (!stk2.isEmpty()) {
        cout << stk2.pop()->data << " ";
    }

    cout << endl;
}

int main() {
    tree obj;
    cout << "================Binary Tree=============" << endl;
    obj.create_r();

    cout << "================Inorder Tree=============" << endl;
    obj.non_recursive_inorder();

    cout << "================Preorder Tree=============" << endl;
    obj.non_recursive_preorder();

    cout << "================Postorder Tree=============" << endl;
    obj.non_recursive_postorder();
}