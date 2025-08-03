#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = createBST(root->left, data);
    }
    else
    {
        root->right = createBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = createBST(root, data);
        cin >> data;
    }
}

int minNode(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
void maxNode(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << "maximum value: " << root->data << endl;
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minNode(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            cout << temp->data << "    ";
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data to create BST";
    takeInput(root);

    levelOrderTraversal(root);

    maxNode(root);
    cout << "minimum value: " << minNode(root) << endl;

    deleteFromBST(root,70);
    cout<<"After deleting 70"<<endl;

    levelOrderTraversal(root);
}