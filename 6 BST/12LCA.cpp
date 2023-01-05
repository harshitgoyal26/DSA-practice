// Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).

//Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#include<math.h>
#include<bits/stdc++.h>
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

class LinkedListNode {
    public :
    int data ;
    LinkedListNode *next ;

    LinkedListNode(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }
};

class BST {
    public :
    BinaryTreeNode<int> *root ;
    BST()
    {
        root = NULL ;
    }
    ~BST()
    {
        delete root ;
    }

    private :
    BinaryTreeNode<int> *insertData(int data , BinaryTreeNode<int> *root)
    {
        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data) ;
        if(root == NULL)
        {
            return newNode ;
        }

        if(data < root -> data)
        {
            root -> left = insertData(data , root -> left) ;
        }
        else
        {
            root -> right = insertData(data , root -> right) ;
        }
        return root ;
    }

    public :
    void insertData(int data)
    {
        this -> root = insertData(data , this -> root) ;
    }

    private :

    int smallest1(BinaryTreeNode<int> *root)
    {
        if(root == NULL)
        {
            return INT_MAX ;
        }

        return min(root -> data , smallest1(root -> left )) ;
    }

    BinaryTreeNode<int> *deleteData(int data , BinaryTreeNode<int> *root)
    {
        if(root == NULL)
        {
            return NULL ;
        }

        if(root -> data > data )
        {
            root -> left = deleteData(data , root -> left) ;
            return root ;
        }
        if(root -> data < data )
        {
            root -> right = deleteData(data , root -> right) ;
            return root ;
        }

        if(root -> data == data)
        {
            if(!root -> left && !root -> right)
            {
                delete root ;
                return NULL ;
            }
            else if(root -> left && !root -> right)
            {
                BinaryTreeNode<int> *temp = root -> left ;
                root -> left = NULL ;
                delete root ;
                return temp ;
            }
            else if(!root -> left && root -> right)
            {
                BinaryTreeNode<int> *temp = root -> right ;
                root -> right = NULL ;
                delete root ;
                return temp ;
            }
            if(root -> left && root -> right)
            {
                int n = smallest1(root -> right) ;
                root -> data = n ;
                root -> right = deleteData(n , root -> right) ;
                return root ; 
            }
        }
    }

    public :

    void deleteData(int data)
    {
        if(root == NULL)
        {
            return ;
        }
        root = deleteData(data , root) ;
    }


    private :

    bool hasData(int data , BinaryTreeNode<int> *node)
    {
        if(node == NULL)
        {
            return false ;
        }
        if(node -> data == data)
        {
            return true ;
        }

        if(data < node -> data)
        {
            return hasData(data , node -> left) ;
        }
        else
        return hasData(data , node -> right) ;
    }

    public :
    bool hasData(int data)
    {
        return hasData(data , root ) ;
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


void iterativePreorder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    stack<BinaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *top = pendingNodes.top() ;
        pendingNodes.pop() ;

        cout<<top -> data <<" ";
        if(top -> right != NULL)
        {
            pendingNodes.push(top -> right) ;
        }
        if(top -> left != NULL)
        {
            pendingNodes.push(top -> left) ;
        }
    }
}


void iterativePostorder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    stack<BinaryTreeNode<int>*> pendingNodes ;
    BinaryTreeNode<int> *node = root ;

    while(true)
    {
        if(node != NULL)
        {
            pendingNodes.push(node) ;
            node = node -> left ;
        }
        else
        {
            if(pendingNodes.empty())
            {
                break ;
            }
            node = pendingNodes.top();
            cout<<node -> data<<" " ;
            pendingNodes.pop() ;
            node = node -> right ;
        }
    }
}


int heightTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0 ;
    }

    return 1 + max(heightTree(root -> left)  , heightTree(root -> right)) ;
}

int diameterOfTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int option1 = (heightTree(root -> left) + heightTree(root -> right)) ;
    int option2 = diameterOfTree(root -> left) ;
    int option3 = diameterOfTree(root -> right) ;

    return max(option1 , max(option2 , option3)) ;
}

int sumOfNodes(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0 ;
    }

    return root -> data + sumOfNodes(root -> left) + sumOfNodes(root -> right) ;
}

int depthOfTree(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0 ;
    }

    return 1 + max(depthOfTree(root -> left) , depthOfTree(root -> right));
}

bool checkBalanced(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return true ;
    }

    int leftans = depthOfTree(root -> left) ;
    int rightans = depthOfTree(root -> right) ;



    return (checkBalanced(root -> left) && checkBalanced(root -> right) && leftans - rightans <= 1 && leftans - rightans >=-1) ;
}



void printLevelWise1(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<BinaryTreeNode<int>*> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        int qSize = pendingNodes.size();
        while(qSize --)
        {
            BinaryTreeNode<int> *front = pendingNodes.front() ;
            pendingNodes.pop() ;

            cout<<front ->data <<" " ;

            if(front -> left != NULL)
            {
                pendingNodes.push(front -> left) ;
            }
            if(front -> right != NULL)
            {
                pendingNodes.push(front -> right) ;
            }
        }
        cout<<endl ;
    }
}


BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return root ;
    }

    if(root -> left == NULL && root -> right == NULL)
    {
        return NULL ;
    }

    root -> left = removeLeafNodes(root -> left) ;
    root -> right = removeLeafNodes(root -> right) ;

    return root ;
}


vector<vector<LinkedListNode *>> LevelWiseLinkedList(BinaryTreeNode<int> *root)
{
    vector<vector<LinkedListNode *>> ans ;
    if(root == NULL)
    {
        return ans ;
    }

    queue<BinaryTreeNode<int> *> pendingNodes ;
    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        ans.push_back({}) ;
        BinaryTreeNode<int> *front = pendingNodes.front() ;
        pendingNodes.pop() ;
        LinkedListNode *head = new LinkedListNode(front -> data);
        ans.back().push_back(head) ;
        LinkedListNode *temp = head ;
        int qSize = pendingNodes.size() ;

        if(front -> left != NULL)
        {
            pendingNodes.push(front -> left) ;
        }
        if(front -> right != NULL)
        {
            pendingNodes.push(front -> right) ;
        }

        while(qSize--)
        {
            BinaryTreeNode<int> *front = pendingNodes.front() ;
            pendingNodes.pop() ;
            temp -> next = new LinkedListNode(front -> data) ;
            temp = temp -> next ;

            if(front -> left != NULL)
            {
                pendingNodes.push(front -> left) ;
            }
            if(front -> right != NULL)
            {
                pendingNodes.push(front -> right) ;
            }
        }
    }
    return ans ;
}


void printVectorOfVectorLL(vector<vector<LinkedListNode*>> ans) 
{
    for(int i = 0 ; i < ans.size() ; i++)
    {
        LinkedListNode *head = ans[i].back() ;
        LinkedListNode *temp = head ;
        while(temp != NULL)
        {
            cout<<temp -> data <<" " ;
            temp = temp -> next ;
        }
        cout<<endl ;
    }
}


void iterativePostorderTraversal(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }
    stack<BinaryTreeNode<int>*> pendingNodes , s2 ;

    pendingNodes.push(root) ;

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *top = pendingNodes.top() ;
        s2.push(top) ;
        pendingNodes.pop() ;

        if(top -> left)
        {
            pendingNodes.push(top -> left) ;
        }
        if(top -> right)
        {
            pendingNodes.push(top -> right) ;
        }
    }

    while(!s2.empty())
    {
        cout<<s2.top() -> data <<" " ;
        s2.pop() ;
    }
}


bool isLeaf(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return false; 
    }

    if(root -> left == NULL && root -> right == NULL)
    {
        return true ;
    }
    return false ;
}


void addLeftBoundary(BinaryTreeNode<int> *root , vector<int> &res)
{
    BinaryTreeNode<int> *curr = root -> left ;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr -> data) ;
        }
        if(curr -> left)
        {
            curr = curr -> left ;
        }
        else
        {
            curr = curr -> right ;
        }
    }
}
void addRightBoundary(BinaryTreeNode<int> *root , vector<int> &res)
{
    BinaryTreeNode<int> *curr = root -> right ;
    stack<int> s ;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            s.push(curr-> data) ;
        }
        if(curr -> right)
        {
            curr = curr -> right ;
        }
        else
        {
            curr = curr -> left ;
        }
    }
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop() ;
    }
}


void addLeaves(BinaryTreeNode<int> *root , vector<int> &res)
{
    if(isLeaf(root))
    {
        res.push_back(root -> data) ;
        return ;
    }
    if(root -> left) addLeaves(root -> left , res) ;
    if(root -> right) addLeaves(root -> right , res) ;

}

void printBoundary(BinaryTreeNode<int> *root)
{
    vector<int> res ;
    if(!root) return ;

    if(!isLeaf(root))
    {
        res.push_back(root -> data) ;
    }

    addLeftBoundary(root , res ) ;
    addLeaves(root , res) ;
    addRightBoundary(root , res) ;
    
    for(int i = 0 ; i < res.size() ; i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl ;
    return ;

}

BinaryTreeNode<int> *searchBST(BinaryTreeNode<int> *root , int k)
{
    if(root == NULL)
    {
        return NULL ;
    }
    if(root -> data == k)
    {
        return root ;
    }

    if(root -> data > k)
    {
        return searchBST(root -> left , k) ;
    }
    if(root -> data < k)
    {
        return searchBST(root -> right , k) ;
    }
}

bool returnSearchBST(BinaryTreeNode<int> *root , int k)
{
    if(root == NULL)
    {
        return false; 
    }

    if(searchBST(root , k) == NULL)
    {
        return false ;
    }
    return true ;
}


void printInRange(BinaryTreeNode<int> *root , int k1 , int k2)
{
    if(root == NULL)
    {
        return ;
    }

    if(root -> data < k1)
    {
        printInRange(root -> right , k1 , k2) ;
    }
    if(root -> data > k2)
    {
        printInRange(root -> left , k1 , k2) ;
    }
    if(k1 <= root -> data && k2 >= root -> data)
    {
        printInRange(root -> left , k1 , k2) ;
        cout<<root -> data<<" " ;
        printInRange(root -> right , k1 , k2) ;
    }
}

int maximum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MIN ;
    }

    return max(root -> data  , max(maximum(root -> left) , maximum(root -> right) ) ) ;
}

int minimum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MAX ;
    }

    return min(root -> data , min(minimum(root -> left) , minimum(root -> right))) ;
}

bool isBST1(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return true ;
    }

    int leftMax = maximum(root -> left) ;
    int rightMin = minimum(root -> right) ;

    return (root -> data > leftMax ) && (root -> data <= rightMin) && isBST1(root -> left) && isBST1(root -> right) ; 
}

class IsBstReturn {
    public :
    bool isBST ;
    int maximum ;
    int minimum ;

} ;

// IsBstReturn is class and isBST2 is a function
IsBstReturn isBST2(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        IsBstReturn output ;
        output.isBST = true ;
        output.maximum = INT_MIN ;
        output.minimum = INT_MAX ;
    }

    IsBstReturn leftOutput = isBST2(root -> left) ;
    IsBstReturn rightOutput = isBST2(root -> right) ;

    int Omaximum = max(root -> data , max(leftOutput.maximum , rightOutput.maximum)) ;
    int Ominimum = min(root -> data , min(leftOutput.minimum , rightOutput.minimum)) ;
    bool isBSTFinal = (root -> data > leftOutput.maximum) && (root -> data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST ; 

    IsBstReturn output ;
    output.maximum = Omaximum ;
    output.minimum = Ominimum ;
    output.isBST = isBSTFinal ; 
    return output ; 
}


bool isBST3(BinaryTreeNode<int> *root , int min = INT_MIN , int max = INT_MAX)
{
    if(root == NULL)
    {
        return true ;
    }

    if(root -> data < min || root -> data > max)
    {
        return false ;
    }

    bool isLeftOk = isBST3(root -> left , min , root -> data -1) ;
    bool isRightOk = isBST3(root -> right, root -> data , max) ;
    return isLeftOk && isRightOk ;
}

BinaryTreeNode<int> *helperConstruct(vector<int> &arr , int n , int start , int end)
{
    if(start > end)
    {
        return NULL ;
    }
    int mid = (start + end) /2 ;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]) ;
    root -> left  = helperConstruct(arr , n , start , mid -1) ;
    root -> right = helperConstruct(arr , n , mid +1 , end) ;

    return root ;
}

BinaryTreeNode<int> *constructBST(vector<int> &arr , int n)
{
    if(n==0)
    {
        return NULL ;
    }
    return helperConstruct(arr , n , 0 , n-1) ;
}

pair<LinkedListNode *, LinkedListNode *> bstToLL(BinaryTreeNode<int> *root)
{
    pair<LinkedListNode * , LinkedListNode *> ans ;
    if(root == NULL)
    {
        ans.first = NULL ;
        ans.second = NULL ;
        return ans ;
    }

    if(root -> left && root -> right)
    {
        pair<LinkedListNode * , LinkedListNode *> left = bstToLL(root -> left) ;
        pair<LinkedListNode * , LinkedListNode *> right = bstToLL(root -> right) ;

        LinkedListNode *mid = new LinkedListNode(root -> data) ;
        mid -> next = right.first ;
        left.second -> next = mid ;

       ans.first = left.first ;
       ans.second = right.second ;
       return ans ;
    }
    if(!root -> left && !root -> right)
    {
        LinkedListNode *mid = new LinkedListNode(root -> data) ;
        ans.first = mid ;
        ans.second = mid ;
        return ans ;
    }

    if(!root -> left && root -> right)
    {
        pair<LinkedListNode * , LinkedListNode *> right = bstToLL(root -> right) ;

        LinkedListNode *mid = new LinkedListNode(root -> data) ;
        mid -> next = right.first ;

       ans.first = mid ;
       ans.second = right.second ;
       return ans ;
    }
    if(root -> left && !root -> right)
    {
        pair<LinkedListNode * , LinkedListNode *> left = bstToLL(root -> left) ;

        LinkedListNode *mid = new LinkedListNode(root -> data) ;
        mid -> next = NULL ;

       ans.first = left.first ;
       ans.second = mid ;
       return ans ;
    }
    
}


vector<int> *findPath(BinaryTreeNode<int> *root , int k)
{
    if(root == NULL)
    {
        return NULL ;
    }

    if(root -> data == k)
    {
        vector<int> *output = new vector<int>() ;
        output->push_back(root -> data) ;
        return output ;
    }

    vector<int> *leftOutput = findPath(root -> left , k) ;
    if(leftOutput != NULL)
    {
        leftOutput->push_back(root -> data) ;
        return leftOutput ;
    }

    vector<int> *rightOutput = findPath(root -> right , k) ;
    if(rightOutput != NULL)
    {
        rightOutput -> push_back(root -> data) ;
        return rightOutput ;
    }
    return NULL ;

}

void insertDuplicate(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }
    if(root -> left)
    {
        insertDuplicate(root -> left) ;
    }
    if(root -> right)
    {
        insertDuplicate(root -> right) ;
    }
    
    BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(root -> data) ;

    if(root -> left && temp -> data > root -> left -> data)
    {
        temp -> left = root -> left ;
    }
    else if(root -> left && temp -> data < root -> left -> data)
    {
        temp -> right  = root -> left ;
    }
    root -> left = temp ;
}




bool findNode(BinaryTreeNode<int> *root , int n)
{
    if(root == NULL)
    {
        return false ;
    }

       
    if(root -> data == n)
    {
        root -> data = INT_MIN ;
        return true ;
    }
    return findNode(root -> left , n) || findNode(root -> right , n) ; 

}

void printPairs(BinaryTreeNode<int> *curr , int s , BinaryTreeNode<int> *root)
{
    if(curr == NULL)
    {
        return ;
    }
    if(curr -> data != INT_MIN && findNode(root , s - (curr -> data))) 
    {
        cout<<min(curr -> data , s- (curr -> data)) <<" "<<max(curr -> data , s- (curr -> data))<<endl ;
        curr -> data = INT_MIN ;
    }
    if(curr -> left)
    printPairs(curr -> left , s , root) ;
    if(curr -> right)
    printPairs(curr -> right , s , root) ;
}


BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root , int n1 , int n2) 
{
    if(root == NULL)
    {
        return NULL ;
    }
    if(root -> data == n1 || root -> data == n2)
    {
        return root ;
    }
    BinaryTreeNode<int> *a = LCA(root -> left , n1 , n2) ;
    BinaryTreeNode<int> *b = LCA(root -> right , n1 , n2) ;

    if(!a &&  b)
    {
        return b ;
    }
    if(a &&  !b)
    {
        return a ;
    }

    if(a && b)
    {
        return root ;
    }

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

    // int in[] =   {4 , 2 , 5 , 1 , 8 , 6 , 9 , 3 , 7} ;
    // int pre[] = {1 , 2 ,4 , 5 , 3 , 6 , 8 , 9 , 7} ;
    // int size = 9 ;
    // BinaryTreeNode<int> *root1 = buildTreeFromPreorder_Inorder(in , pre , size) ;
    // printLevelWise(root1) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // iterativePreorder(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // iterativePostorder(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // cout<<diameterOfTree(root) <<endl ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // cout<<sumOfNodes(root)<<endl ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // cout<<checkBalanced(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // printLevelWise1(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // root = removeLeafNodes(root) ;
    // printLevelWise(root) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // printVectorOfVectorLL(LevelWiseLinkedList(root)) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // iterativePostorderTraversal(root) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // printBoundary(root) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // cout<<"Enter k"<<endl;
    // int k ;
    // cin>> k;
    // cout<<returnSearchBST(root , k) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // int k1 , k2 ;
    // cout<<"Enter k1 , k2"<<endl ;
    // cin>>k1>>k2 ;
    // printInRange(root , k1 , k2) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // cout<<isBST1(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // // IsBstReturn ans  = isBST2(root) ;
    // // cout<<"Here" << ans.isBST<<"Here" ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // cout<<isBST3(root) ;

    // int n , k;
    // cout<<"Enter n "<<endl ;
    // cin>> n ;
    // vector<int> arr ;
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cin>> k ;
    //     arr.push_back(k) ;
    // }
    // BinaryTreeNode<int> *root = constructBST(arr , n) ;
    // printLevelWise(root) ;




    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // pair<LinkedListNode * , LinkedListNode *> ans = bstToLL(root) ;
    // LinkedListNode *head = ans.first ;
    // while(head != NULL)
    // {
    //     cout<<head -> data<<"->" ;
    //     head = head -> next ;
    // }
    // cout<<endl ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // vector<int> *output = findPath(root , 2) ;
    // for(int i = 0 ; i < output->size() ; i++)
    // {
    //     cout<<output->at(i)<<" ";
    // }
    // cout<<endl;
    // delete output ;


    // BST b ;
    // b.insertData(1) ;
    // b.insertData(2) ;
    // b.insertData(3) ;
    // b.insertData(4) ;
    // b.insertData(5) ;
    // b.insertData(6) ;
    // b.insertData(7) ;
    // b.insertData(8) ;
    // b.insertData(9) ;
    // b.insertData(10) ;
    // cout<<"********" ;
    // cout<<b.hasData(5)<<endl ;
    // cout<<b.hasData(45)<<endl ;
    // cout<<b.hasData(9)<<endl ;
    // cout<<b.hasData(69)<<endl ;
    // cout<<"****";
    // b.deleteData(5) ;
    // cout<<b.hasData(5)<<endl ;
    // cout<<b.hasData(45)<<endl ;
    // cout<<b.hasData(9)<<endl ;
    // cout<<b.hasData(69)<<endl ;
    // cout<<b.hasData(4)<<endl ;
    // // printLevelWise(b -> root) ;


    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // insertDuplicate(root) ;
    // cout<<"Here" ;
    // printLevelWise(root) ;

    // BinaryTreeNode<int> *root = takeInputLevelWise() ;
    // printPairs(root , 9 , root) ;




    cout<<"*****"<<endl;


    BinaryTreeNode<int> *root = takeInputLevelWise() ;
    BinaryTreeNode<int> *ans =  LCA(root , 2 , 6) ;
    if(ans == NULL)
    {
        cout<<"-1";
    }
    else
    {
        cout<<ans -> data ;
    }
















    return 0 ;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1


