// Problem Statement: Node with maximum child sum


// Not working ***** Recursion Problem

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

    ~TreeNode()
    {
        for(int i = 0 ; i < children.size() ; i++)
        {
            delete children[i];
        }
        delete this;
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

void postorder(TreeNode<int> *root)
{
    if(root -> children.size() == 0)
    {
        cout<<root -> data<<" ";
    }

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        postorder(root -> children[i]);
        if(i == root -> children.size() -1)
        {
            cout<<root -> data<<" ";
        }
    }
    
} 


void deleteTree(TreeNode<int> *root)
{
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        deleteTree(root -> children[i]);
    }
    delete root ;
}


int countX(TreeNode<int> *root , int x)
{
    int count = 0;
    if(root -> data > x)
    {
        count = count + 1;
    }

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        count  = count + countX(root -> children[i] , x);
    }

    return count;
}

TreeNode<int>* nodeWithMaxSum(TreeNode<int> *root)
{
    // int max = 0;
    // int sum = root -> data;
    // for(int i = 0 ; i < root -> children.size() ; i++)
    // {
    //     sum = sum + root -> children[i] -> data ;
    // } 

    // if(sum > max)
    // {
    //     max = sum ;
        
    // }

    // for(int i = 0 ; i < root -> children.size() ; i++)
    // {
    //     nodeWithMaxSum(root -> children[i]);
    // }

    // return root -> data;


    TreeNode<int> *ans = root;
    int sum = ans -> data;
    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        sum = sum + root -> children[i] -> data ;
    }

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        TreeNode<int> *x = nodeWithMaxSum(root -> children[i]);
        int xSum = x -> data ;
        for(int j = 0 ; j < x -> children.size() ; j++)
        {
            xSum = xSum + x -> children[j] -> data;
        }
        if(xSum > sum)
        {
            ans = root -> children[i];
            sum = xSum ;
        }
    } 
    return ans;
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
    cout<<endl<<"PostOrder : ";
    postorder(root);
    cout<<endl;

    cout<<"Node having Max Sum : ";
    TreeNode<int> *ans = nodeWithMaxSum(root);
    cout<<ans -> data<<endl;

    // cout<<"Enter x : ";
    // int x;
    // cin>>x;

    // cout<<countX(root , x)<<endl;
    
    
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0  
    // cout<<"Enter level K to be printed : ";
    // cin>>n;

    // printAtLevelK(root , n);
    delete root;
    printTreeLevelWise(root);
    deleteTree(root);
    return 0;
}