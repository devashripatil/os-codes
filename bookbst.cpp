#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node {
public:
    int bookID;
    string title;
    Node *left, *right;
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    void insert();
    int longest_path(Node* root);
    void minimum_value();
    void maximum_value();
    void search_value();
    void ascending_order();
    void in_n();
    void descending_order();
    void in_rn();
};

// Insert a new book record
void BST::insert() {
    int id;
    string title;
    Node *p, *q;

    if (root == NULL) {
        root = new Node;
        cout << "\nEnter the root Book ID: ";
        cin >> root->bookID;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, root->title);
        root->left = root->right = NULL;
        return;
    }

    cout << "\nEnter Book ID: ";
    cin >> id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);

    p = new Node();
    p->bookID = id;
    p->title = title;
    p->left = p->right = NULL;

    q = root;
    while (q != NULL) {
        if (id < q->bookID) {
            if (q->left == NULL) {
                q->left = p;
                return;
            } else
                q = q->left;
        } else if (id > q->bookID) {
            if (q->right == NULL) {
                q->right = p;
                return;
            } else
                q = q->right;
        } else {
            cout << "Duplicate Book ID not allowed!\n";
            return;
        }
    }
}

// Find number of nodes in longest path
int BST::longest_path(Node* root) {
    if (root == NULL)
        return 0;
    int left_depth = longest_path(root->left);
    int right_depth = longest_path(root->right);
    return 1 + max(left_depth, right_depth);
}

// Find minimum Book ID
void BST::minimum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    cout << "\nMinimum Book ID: " << temp->bookID 
         << ", Title: " << temp->title;
}

// Find maximum Book ID
void BST::maximum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }
    Node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    cout << "\nMaximum Book ID: " << temp->bookID 
         << ", Title: " << temp->title;
}

// Search a book by ID
void BST::search_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }
    int id;
    cout << "\nEnter the Book ID to search: ";
    cin >> id;
    Node* temp = root;
    while (temp != NULL) {
        if (temp->bookID == id) {
            cout << "\nBook Found! ID: " << temp->bookID
                 << ", Title: " << temp->title;
            return;
        } else if (id < temp->bookID)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "\nBook with ID " << id << " not found.";
}

// Display books in ascending order
void BST::ascending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }
    cout << "\nBooks in Ascending Order (by ID): ";
    in_n();
}

// Non-recursive inorder traversal
void BST::in_n() {
    Node* temp = root;
    stack<Node*> st;
    while (true) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        if (!st.empty()) {
            temp = st.top();
            st.pop();
            cout << "\nBook ID: " << temp->bookID << ", Title: " << temp->title;
            temp = temp->right;
        } else
            break;
    }
}

// Display books in descending order
void BST::descending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }
    cout << "\nBooks in Descending Order (by ID): ";
    in_rn();
}

// Non-recursive reverse inorder traversal
void BST::in_rn() {
    Node* temp = root;
    stack<Node*> st;
    while (true) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->right;
        }
        if (!st.empty()) {
            temp = st.top();
            st.pop();
            cout << "\nBook ID: " << temp->bookID << ", Title: " << temp->title;
            temp = temp->left;
        } else
            break;
    }
}

int main() {
    int choice;
    BST bst;
    do {
        cout << "\n\n------ Book Management (BST) ------";
        cout << "\n1. Insert Book";
        cout << "\n2. Longest Path (Height)";
        cout << "\n3. Minimum Book ID";
        cout << "\n4. Maximum Book ID";
        cout << "\n5. Search Book by ID";
        cout << "\n6. Display in Ascending Order";
        cout << "\n7. Display in Descending Order";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bst.insert(); break;
            case 2: {
                int longest = bst.longest_path(bst.root);
                cout << "\nNumber of nodes in longest path from root: " << longest;
                break;
            }
            case 3: bst.minimum_value(); break;
            case 4: bst.maximum_value(); break;
            case 5: bst.search_value(); break;
            case 6: bst.ascending_order(); break;
            case 7: bst.descending_order(); break;
            case 8: cout << "\nExiting program..."; return 0;
            default: cout << "\nInvalid choice! Try again."; break;
        }
    } while (choice != 8);
}
