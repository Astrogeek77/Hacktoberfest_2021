#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front, rear, size;
    Node **Q;

public:
    Queue()
    {
        front = rear = 1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = 1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
    void Display();
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full\n";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << "\n";
}

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void CreateTree();

    void PreOrder() { PreOrder(root); };
    void PreOrder(Node *p);

    void PostOrder() { PostOrder(root); };
    void PostOrder(Node *p);

    void InOrder() { InOrder(root); };
    void InOrder(Node *p);

    void IterativePreOrder() { IterativePreOrder(root); };
    void IterativePreOrder(Node *p);

    void IterativeInOrder() { IterativeInOrder(root); };
    void IterativeInOrder(Node *p);

    void IterativePostOrder() { IterativePostOrder(root); };
    void IterativePostOrder(Node *p);

    void LevelOrder() { LevelOrder(root); };
    void LevelOrder(Node *p);

    int Height() { return Height(root); };
    int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
void Tree::InOrder(Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}
void Tree::PostOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}
void Tree::LevelOrder(Node *root)
{
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::IterativePreOrder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", "
                 << flush;
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << "\n";
}

void Tree::IterativeInOrder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", "
                 << flush;
            p = p->rchild;
        }
    }
    cout << "\n";
}

void Tree::IterativePostOrder(Node *p)
{
    stack<long int> stk;
    long int temp;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if (temp > 0)
            {
                stk.emplace(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", "
                     << flush;
                p = nullptr;
            }
        }
    }
    cout << "\n";
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder ";
    t.IterativePreOrder();
    cout << "Inorder ";
    t.IterativeInOrder();
    cout << "Postorder ";
    t.IterativePostOrder();
    t.LevelOrder();
}