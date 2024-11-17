#include<iostream>
using namespace std;

class node {
public:
    int uid;
    char name[20];
    node *next;
    friend class graph;
    friend class stack;
};

class graph {
public:
    node *head[10];
    int visit[10];
    int no_vert;
    void create_g();
    void display_g();
    void dfs();
    void dfs_rec(int s);
    void dfs_nonrec();
};

class stack {
    int stack[20];
    int top = -1;
    int t;
    friend class graph;
public:
    void push(int v);
    int pop();
    int isempty();
};

void stack::push(int v) {
    top++;
    stack[top] = v;
}

int stack::pop() {
    t = stack[top];
    top--;
    return t;
}

int stack::isempty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void graph::create_g() {
    int i;
    node *temp;
    char ch;
    cout << "Enter no of users: ";
    cin >> no_vert;
    for (i = 0; i < no_vert; i++) {
        head[i] = new node();
        head[i]->uid = i;
        cout << "Enter username of " << i << endl;
        cin >> head[i]->name;
        head[i]->next = NULL;
    }
    for (i = 0; i < no_vert; i++) {
        temp = head[i];
        do {
            node *curr;
            curr = new node();
            cout << "Enter id of friend of " << head[i]->uid << endl;
            cin >> curr->uid;
            cout << "Enter name of friend of " << head[i]->uid << endl;
            cin >> curr->name;
            curr->next = NULL;
            temp->next = curr;
            temp = curr;
            cout << "Do you want to add more friends of " << head[i]->uid << endl;
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
}

void graph::display_g() {
    node *temp;
    for (int i = 0; i < no_vert; i++) {
        temp = head[i];
        cout << endl;
        while (temp != NULL) {
            cout << "Friend ID is: " << temp->uid << endl;
            cout << "Friend Name is " << temp->name << "-->" << endl;
            temp = temp->next;
        }
    }
}

void graph::dfs() {
    int start;
    cout << endl;
    cout << "Enter starting id" << endl;
    cin >> start;
    for (int i = 0; i < no_vert; i++) {
        visit[i] = 0;
    }
    visit[start] = 1;
    dfs_rec(start);
}

void graph::dfs_rec(int s) {
    node* temp;
    cout << head[s]->uid << endl;
    cout << head[s]->name << endl;
    temp = head[s]->next;
    while (temp != NULL) {
        if (visit[temp->uid] == 0) {
            visit[temp->uid] = 1;
            dfs_rec(temp->uid);
        }
        temp = temp->next;
    }
}

void graph::dfs_nonrec() {
    cout << "\nDFS non-rec traversal\n";
    stack s;
    int starting_index;
    cout << "Enter starting vertex\n";
    cin >> starting_index;
    for (int i = 0; i < no_vert; i++) {
        visit[i] = 0;
    }
    node *temp;
    s.push(starting_index);
    visit[starting_index] = 1;
    while (s.isempty() == 0) {
        int current_index = s.pop();
        temp = head[current_index];
        cout << temp->uid << temp->name << " ";
        visit[temp->uid] = 1;
        temp = temp->next; // Move to the next adjacent node
        while (temp != NULL) {
            if (visit[temp->uid] == 0) {
                s.push(temp->uid);
                break; // Exit the inner loop after pushing to the stack
            }
            temp = temp->next;
        }
    }
}

int main() {
    graph g1;
    g1.create_g();
    g1.display_g();
    g1.dfs();
    g1.dfs_nonrec();
	return 0;
}