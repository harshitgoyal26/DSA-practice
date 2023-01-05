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

BinaryTreeNode<int> *Helper1(int *in , int *pre , int inS , int inE , int preS , int preE)
{
    if(inS > inE)
    {
        return NULL ;
    }

    int rootData = pre[preS] ;

    int rootIndex = -1 ;
    for(int i = inS ; i <= inE ; i++)
    {
        if(in[i] == rootData)
        {
            rootIndex = i ;
            break ;
        }
    }

    int lInS = inS;
    int lInE = rootIndex -1;
    int lPreS = preS +1;
    int lPreE = lPreS + lInE - lInS ;

    int rPreS = lPreE +1;
    int rPreE = preE;
    int rInS = rootIndex +1;
    int rInE  = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData) ;
    root -> left = Helper1(in , pre , lInS , lInE , lPreS , lPreE) ;
    root -> right = Helper1(in , pre , rInS , rInE , rPreS , rPreE) ;

    return root ;

}

BinaryTreeNode<int> *buildTreeFromPreorder_Inorder(int *in , int *pre , int size)
{
    return Helper1(in , pre , 0 , size-1 , 0 , size-1);
}




int main()
{
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // printLevelWise(root) ;

    // cout<<numNodes(root)<<endl; 

    // cout<<isNodePresent(root , 1)<<endl;

    // cout<<heightOfTree(root)<<endl;

    // mirrorTree(root) ;
    // printLevelWise(root) ;

    // inorder(root) ;

    // preorder(root) ;

    // postorder(root) ;


    cout<<"*****"<<endl;

    int in[] =   {4 , 2 , 5 , 1 , 8 , 6 , 9 , 3 , 7} ;
    int pre[] = {1 , 2 ,4 , 5 , 3 , 6 , 8 , 9 , 7} ;
    int size = 9 ;
    BinaryTreeNode<int> *root1 = buildTreeFromPreorder_Inorder(in , pre , size) ;
    printLevelWise(root1) ;






    return 0 ;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
