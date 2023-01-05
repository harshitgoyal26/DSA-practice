// Check if given Tree Contains int x 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data ;
    vector<TreeNode<T>*> children ;

    TreeNode(T data)
    {
        this -> data = data ;
    }
};


TreeNode<int> *takeInputLevelWise()
{
    int rootData ;
    cout<<"Enter root data" <<endl;
    cin>> rootData ;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes ;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter No. of Children of "<<front -> data <<endl;
        int numChild;
        cin>>numChild;
        for(int i = 0 ; i < numChild ; i++)
        {
            cout<<"Enter "<<i<<"th child of "<<front -> data <<endl;
            int childData;
            cin>>childData ;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}



void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        TreeNode<int> *front  = pendingNodes.front();
        pendingNodes.pop();
        cout<<front -> data <<" : ";
        for(int i = 0 ; i < front -> children.size() ; i++)
        {
            TreeNode<int> *child = front -> children[i];
            pendingNodes.push(child);
            cout<<child -> data<<", ";
        }
        cout<<endl;
    }
}



int numNodes(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return  0;
    }
    int ans = 1;
    
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        ans  = ans + numNodes(root -> children[i]);
    }
    return ans ;
}

int sumNodes(TreeNode<int> *root)
{
    int sum = root -> data;
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        sum = sum + sumNodes(root -> children[i]);
    }
    return sum;
}

int largestNode(TreeNode<int> *root)
{
    int max = root -> data;
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        int ans = largestNode(root -> children[i]);
        if(ans > max)
        {
            max = ans ;
        }
    } 
    return max;
}


int heightOfTree(TreeNode<int> * root)
{
    int height = 0;
    
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        height =  max(height , heightOfTree(root -> children[i]));
    }
    return 1+ height ;
}

void printAtLevelK(TreeNode<int> *root , int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        cout<<root -> data<<" , ";
        return;
    }

    for(int i = 0 ; i < root ->children.size() ; i++)
    {
        printAtLevelK(root -> children[i] , k-1);
    }

}

int countLeaf(TreeNode<int> *root)
{
    int count = 0 ;
    if(root -> children.size() == 0)
    {
        count = 1;
    }

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        count = count + countLeaf(root -> children[i]);
    }
    return count ;
}

void preorder(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root -> data<<" ";

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        preorder(root -> children[i]);
    }
}

bool checkX(TreeNode<int> * root , int x)
{
    if(root -> data == x)
    {
        return true;
    }

    if(root == NULL)
    {
        return false;
    }

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        return checkX(root -> children[i] , x);
    }

    // return false;

}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1) ; 
    // TreeNode<int> *node1 = new TreeNode<int>(2) ; 
    // TreeNode<int> *node2 = new TreeNode<int>(3) ; 

    // root -> children.push_back(node1);
    // root -> children.push_back(node2);

    int n;
    TreeNode<int> *root = takeInputLevelWise() ;

    printTreeLevelWise(root);

    cout<<"Count :" <<numNodes(root)<<endl ;
    cout<<"Sum : "<<sumNodes(root)<<endl;
    cout<<"Max : "<<largestNode(root)<<endl;
    cout<<"Height : "<<heightOfTree(root)<<endl;
    cout<<"No of Leaf Nodes :"<<countLeaf(root)<<endl;
    cout<<endl;
    cout<<"PreOrder : ";
    preorder(root);
    cout<<endl;

    // cout<<"Enter level K to be printed : ";
    // cin>>n;

    // printAtLevelK(root , n);


    int x;
    cout<<"Enter int x to check : ";
    cin>>x;
    cout<<checkX(root , x)<<endl;


    return 0;
}