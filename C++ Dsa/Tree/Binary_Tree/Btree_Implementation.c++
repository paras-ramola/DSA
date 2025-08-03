#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize node
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a binary tree
node *createTree()
{
    int data;
    cout << "Enter the data (-1 for no node): " << endl;
    cin >> data;

    if (data == -1)
        return NULL; // Base case: no node

    // Create a new node
    node *root = new node(data);

    // Recursively create left and right subtrees
    cout << "Enter the data for the left of " << root->data << ": ";
    root->left = createTree();

    cout << "Enter the data for the right of " << root->data << ": ";
    root->right = createTree();

    return root;
}

// Create a tree with level order input
node *createlevelOrder()
{

    int data;
    cout << "Enter the data (-1 for no node): " << endl;
    cin >> data;

    node *root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the data for the left of " << temp->data << ": " << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter the data for the right of " << temp->data << ": " << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}



void reverseOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    stack<node *> st;
    while (!q.empty())
    {
        node *temp = q.front();
        st.push(temp);
        q.pop();

        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top()->data << "\t";
        st.pop();
    }
}


void inorderTraversal(node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void iterativePreorder(node *root)
{
    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        node *temp = st.top();
        cout << st.top()->data << " ";
        st.pop();
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
}

void iterativeInorder(node *root)
{
    stack<node *> st;

    while (true)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            cout << root->data << "  ";
            st.pop();
            root = root->right;
        }
    }
}

// using two stacks
void iterativePostorder1(node *root)
{
    stack<node *> st1;
    stack<node *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        node *temp = st1.top();
        st2.push(temp);
        st1.pop();
        if (temp->left != NULL)
        {
            st1.push(temp->left);
        }
        if (temp->right != NULL)
        {
            st1.push(temp->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// using one stack
void iterativePostorder2(node *root)
{
    stack<node *> st;
    st.push(root);
    vector<int> ans;

    while (!st.empty())
    {
        node *temp = st.top();
        ans.push_back(temp->data);
        st.pop();

        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{

    node *root = createTree();

    // Create tree using level Order input
    //  node* root=createlevelOrder();

    // Traversals
    cout << endl
         << "Level Order Traversal(Level Seprated)" << endl;
    levelOrderTraversal(root);
    cout << "In-Order Traversal:    ";
    inorderTraversal(root);
    cout << endl;
    cout << "Pre-Order Traversal:   ";
    preorderTraversal(root);
    cout << endl;
    cout << "Post-Order Traversal:   ";
    postorderTraversal(root);

    return 0;
}

//  Input for normal tree: 1 3 7 -1 -1  11 -1 -1  5 17 -1 -1 -1
// level order input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1






















