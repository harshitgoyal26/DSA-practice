#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data ;
    BinaryTreeNode *left ;
    BinaryTreeNode *right ;

    BinaryTreeNode(T data)
    {
        this -> data = data ;
        this -> left = NULL ;
        this -> right = NULL ;
    }

    ~BinaryTreeNode()
    {
        delete left ;
        delete right ;
    }
};

void printTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root -> data<<" : ";
    if(root -> left != NULL)
    {
        cout<<"L"<<root -> left -> data ;
    }
    if(root -> right != NULL)
    {
        cout<<" R"<<root -> right -> data ;
    }

    cout<<endl;
    printTree(root -> left) ;
    printTree(root -> right) ;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData ;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData ;

    if(rootData == -1)
    {
        return NULL ;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData) ;

    BinaryTreeNode<int> *leftChild =  takeInput();
    BinaryTreeNode<int> *rightChild =  takeInput();

    root -> left  = leftChild ;
    root -> right = rightChild ;

    return root ;
}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData ;
    cout<<"Enter data"<<endl ;
    cin>>rootData ;

    if(rootData == -1)
    {
        return NULL ;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData) ;

    queue<BinaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop() ;

        int leftChild ;
        cout<<"Enter Left child of "<<front -> data<<endl ;
        cin>>leftChild ;

        if(leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild) ;
            front -> left = child ;
            pendingNodes.push(child) ;
        }

        int rightChild ;
        cout<<"Enter Right child of "<<front -> data<<endl ;
        cin>>rightChild ;

        if(rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild) ;
            front -> right = child ;
            pendingNodes.push(child) ;
        }
    }
  
    return root ;
}


void printLevelWise(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<BinaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front() ;
        pendingNodes.pop();
        cout<<front -> data<<" : ";

        if(front -> left != NULL)
        {
            cout<<"L"<<front -> left -> data ;
            pendingNodes.push(front -> left) ;
        }

        if(front -> right != NULL)
        {
            cout<<" R"<<front -> right -> data ;
            pendingNodes.push(front -> right) ;
        }
        cout<<endl;
    }
}



int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root) ;
    return 0 ;
}
