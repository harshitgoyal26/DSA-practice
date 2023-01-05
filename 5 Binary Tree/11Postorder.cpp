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

int numNodes(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0 ;
    }

    // return 1+ numNodes(root -> left) + numNodes(root -> right);
    //OR
    int ans = 1;

    ans = ans + numNodes(root -> left) + numNodes(root -> right);
    return ans ;
}

bool isNodePresent(BinaryTreeNode<int> *root , int x)
{

    if(root == NULL)
    {
        return false ;
    }

    if(root -> data == x)
    {
        return true ;
    }

    if(isNodePresent(root -> left , x))
    {
        return true ;
    }
    return isNodePresent(root -> right , x);

    // return true ;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0 ;
    }
    int height = 0 ;

    height = max(height , heightOfTree(root -> left)) ;
    height = max(height , heightOfTree(root -> right)) ;

    return 1+height ;
    
}

void mirrorTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }
    BinaryTreeNode<int> *temp = root -> left ;
    root -> left = root -> right ;
    root -> right = temp ;

    mirrorTree(root -> left) ;
    mirrorTree(root -> right) ;
}

void inorder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root -> left) ;
    cout<<root -> data <<" " ;
    inorder(root -> right) ;
}

void preorder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root -> data<<" " ;
    preorder(root -> left) ;
    preorder(root -> right) ;
}


void postorder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    postorder(root -> left) ;
    postorder(root -> right) ;
    cout<<root -> data <<" ";
}



int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root) ;

    // cout<<numNodes(root)<<endl; 

    // cout<<isNodePresent(root , 1)<<endl;

    // cout<<heightOfTree(root)<<endl;

    // mirrorTree(root) ;
    // printLevelWise(root) ;

    // inorder(root) ;

    // preorder(root) ;


    cout<<"*****"<<endl;

    postorder(root) ;





    return 0 ;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
