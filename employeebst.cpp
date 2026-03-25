#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int empId;
    float salary;
    node* left;
    node* right;
};

class binary_search_tree {
public:
    node* root;
    binary_search_tree() {
        root = NULL;
    }

    void create();
    void insert();
    int longest_path(node *root);
    void minimum_value();
    void maximum_value();
    void search_value();
    void ascending_order();
    void in_n();
    void descending_order();
    void in_rn();
};

// Create root node
void binary_search_tree::create() {
    root = new node;
    cout << "\nEnter the Employee ID for root: ";
    cin >> root->empId;
    cout << "Enter the Salary: ";
    cin >> root->salary;
    root->left = NULL;
    root->right = NULL;
}

// Insert new employee record
void binary_search_tree::insert() {
    node *p, *q;
    int id;
    float sal;

    if (root == NULL) {
        create(); // same as your style
        return;
    }

    cout << "\nEnter Employee ID: ";
    cin >> id;
    cout << "Enter Salary: ";
    cin >> sal;

    p = new node();
    p->empId = id;
    p->salary = sal;
    p->left = p->right = NULL;

    q = root;
    while (q != NULL) {
        if (id < q->empId) {
            if (q->left == NULL) {
                q->left = p;
                return;
            } else {
                q = q->left;
            }
        } else if (id > q->empId) {
            if (q->right == NULL) {
                q->right = p;
                return;
            } else {
                q = q->right;
            }
        } else {
            cout << "\nDuplicate Employee ID not allowed!\n";
            delete p;
            return;
        }
    }
}

// Find the longest path (height)
int binary_search_tree::longest_path(node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = longest_path(root->left);
    int right_depth = longest_path(root->right);
    return 1 + max(left_depth, right_depth);
}

// Find minimum value
void binary_search_tree::minimum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }

    cout << "\nMinimum Employee ID: " << temp->empId
         << " | Salary: " << temp->salary;
}

// Find maximum value
void binary_search_tree::maximum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    cout << "\nMaximum Employee ID: " << temp->empId
         << " | Salary: " << temp->salary;
}

// Search an employee
void binary_search_tree::search_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }

    int id;
    cout << "\nEnter the Employee ID to search: ";
    cin >> id;

    node *temp = root;
    while (temp != NULL) {
        if (temp->empId == id) {
            cout << "\nEmployee record found!";
            cout << "\nEmployee ID: " << temp->empId;
            cout << "\nSalary: " << temp->salary;
            return;
        }
        else if (id < temp->empId) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    cout << "\nThe Employee ID " << id << " is not found in the tree.";
}

// Ascending order (non-recursive)
void binary_search_tree::ascending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    cout << "\nEmployees in ascending order (non-recursive):";
    in_n();
}

// Non-recursive inorder traversal
void binary_search_tree::in_n() {
    node *temp = root;
    stack<node*> st;

    while (1) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }

        if (!st.empty()) {
            temp = st.top();
            st.pop();

            cout << "\nEmployee ID: " << temp->empId
                 << " | Salary: " << temp->salary;

            temp = temp->right;
        }
        else
            break;
    }
}

// Descending order (non-recursive)
void binary_search_tree::descending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    cout << "\nEmployees in descending order (non-recursive):";
    in_rn();
}

// Non-recursive reverse inorder traversal
void binary_search_tree::in_rn() {
    node *temp = root;
    stack<node*> st;

    while (1) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->right; // visit right subtree first
        }

        if (!st.empty()) {
            temp = st.top();
            st.pop();

            cout << "\nEmployee ID: " << temp->empId
                 << " | Salary: " << temp->salary;

            temp = temp->left; // then go to left
        } else {
            break;
        }
    }
}

// Main menu
int main() {
    int ch;
    binary_search_tree obj;

    do {
        cout << "\n\n----- Employee Management (BST) -----\n";
        cout << "1. Insert Data\n2. Find Longest Path\n3. Minimum Value\n4. Maximum Value";
        cout << "\n5. Search Value\n6. Ascending Order\n7. Descending Order\n8. Exit";
        cout << "\n\nSelect an option: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.insert();
                break;
            case 2: {
                int longest = obj.longest_path(obj.root);
                cout << "\nNumber of nodes in the longest path from root: " << longest;
                break;
            }
            case 3:
                obj.minimum_value();
                break;
            case 4:
                obj.maximum_value();
                break;
            case 5:
                obj.search_value();
                break;
            case 6:
                obj.ascending_order();
                break;
            case 7:
                obj.descending_order();
                break;
            case 8:
                cout << "\nThank you!";
                exit(0);
            default:
                cout << "\nPlease enter a valid choice!";
        }
    } while (true);

    return 0;
}