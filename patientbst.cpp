#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int patientId;
    string name;
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
    int count_nodes(node *root);
    int count_leaf_nodes(node *root);
};

// 🌱 Create root node
void binary_search_tree::create() {
    root = new node;
    cout << "\nEnter the Patient ID for root: ";
    cin >> root->patientId;
    cout << "Enter the Patient Name (single word): ";
    cin >> root->name;
    root->left = NULL;
    root->right = NULL;
    cout << "\nRoot node created successfully!";
}

// ➕ Insert new patient record
void binary_search_tree::insert() {
    node *p, *q;
    int id;
    string name;

    if (root == NULL) {
        create(); // Create first node
        return;
    }

    cout << "\nEnter Patient ID: ";
    cin >> id;
    cout << "Enter Patient Name (single word): ";
    cin >> name;

    p = new node();
    p->patientId = id;
    p->name = name;
    p->left = p->right = NULL;

    q = root;
    while (q != NULL) {
        if (id < q->patientId) {
            if (q->left == NULL) {
                q->left = p;
                cout << "\nPatient record inserted to the left of ID " << q->patientId;
                return;
            } else {
                q = q->left;
            }
        } else if (id > q->patientId) {
            if (q->right == NULL) {
                q->right = p;
                cout << "\nPatient record inserted to the right of ID " << q->patientId;
                return;
            } else {
                q = q->right;
            }
        } else {
            cout << "\nDuplicate Patient ID not allowed!";
            delete p;
            return;
        }
    }
}

// 🌳 Find the longest path (height)
int binary_search_tree::longest_path(node *root) {
    if (root == NULL)
        return 0;
    int left_depth = longest_path(root->left);
    int right_depth = longest_path(root->right);
    return 1 + max(left_depth, right_depth);
}

// 🔽 Find minimum patient ID
void binary_search_tree::minimum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    cout << "\nMinimum Patient ID: " << temp->patientId
         << " | Name: " << temp->name;
}

// 🔼 Find maximum patient ID
void binary_search_tree::maximum_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    cout << "\nMaximum Patient ID: " << temp->patientId
         << " | Name: " << temp->name;
}

// 🔍 Search patient by ID
void binary_search_tree::search_value() {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }

    int id;
    cout << "\nEnter the Patient ID to search: ";
    cin >> id;

    node *temp = root;
    while (temp != NULL) {
        if (temp->patientId == id) {
            cout << "\nPatient record found!";
            cout << "\nPatient ID: " << temp->patientId;
            cout << "\nPatient Name: " << temp->name;
            return;
        } else if (id < temp->patientId)
            temp = temp->left;
        else
            temp = temp->right;
    }

    cout << "\nThe Patient ID " << id << " is not found in the tree.";
}

// ⬆ Ascending order (Inorder)
void binary_search_tree::ascending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    cout << "\nPatients in ascending order (non-recursive):";
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

            cout << "\nPatient ID: " << temp->patientId
                 << " | Name: " << temp->name;

            temp = temp->right;
        } else break;
    }
}

// ⬇ Descending order (Reverse inorder)
void binary_search_tree::descending_order() {
    if (root == NULL) {
        cout << "\nThe tree is empty!";
        return;
    }

    cout << "\nPatients in descending order (non-recursive):";
    in_rn();
}

void binary_search_tree::in_rn() {
    node *temp = root;
    stack<node*> st;

    while (1) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->right;
        }

        if (!st.empty()) {
            temp = st.top();
            st.pop();

            cout << "\nPatient ID: " << temp->patientId
                 << " | Name: " << temp->name;

            temp = temp->left;
        } else break;
    }
}

// 🌿 Count total nodes
int binary_search_tree::count_nodes(node *root) {
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// 🍃 Count leaf nodes
int binary_search_tree::count_leaf_nodes(node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}

// Main Function
int main() {
    int ch;
    binary_search_tree obj;

    do {
        cout << "\n\n----- Patient Management (BST) -----\n";
        cout << "1. Insert Data\n2. Find Longest Path\n3. Minimum Value\n4. Maximum Value";
        cout << "\n5. Search Patient\n6. Ascending Order\n7. Descending Order";
        cout << "\n8. Count Nodes\n9. Exit";
        cout << "\n\nSelect an option: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.insert();
                break;
            case 2: {
                int longest = obj.longest_path(obj.root);
                cout << "\nNumber of nodes in the longest path: " << longest;
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
            case 8: {
                int total = obj.count_nodes(obj.root);
                int leaves = obj.count_leaf_nodes(obj.root);
                cout << "\nTotal Nodes: " << total;
                cout << "\nLeaf Nodes: " << leaves;
                break;
            }
            case 9:
                cout << "\nThank you!";
                exit(0);
            default:
                cout << "\nInvalid choice!";
        }
    } while (true);

    return 0;
}
