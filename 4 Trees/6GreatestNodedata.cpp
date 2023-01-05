// Node with largest data

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


TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data : "<<endl;
    cin>>rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n ;
    cout<<"Enter No of Children of "<<rootData<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput(); 
        root -> children.push_back(child);
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


void printTree(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return ; 
    }

    cout<< root -> data <<":";
    for (int i = 0; i < root -> children.size() ; i++)
    {
        cout<< root -> children[i] -> data <<" , "; 
    }
    cout<<endl;
    for (int i = 0; i < root -> children.size(); i++)
    {
        printTree(root -> children[i]);
    }
    
}

int numNodes(TreeNode<int> *root)
{
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



int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1) ; 
    // TreeNode<int> *node1 = new TreeNode<int>(2) ; 
    // TreeNode<int> *node2 = new TreeNode<int>(3) ; 

    // root -> children.push_back(node1);
    // root -> children.push_back(node2);


    TreeNode<int> *root = takeInputLevelWise() ;

    printTreeLevelWise(root);

    cout<<"Count :" <<numNodes(root)<<endl ;
    cout<<"Sum : "<<sumNodes(root)<<endl;
    cout<<"Max : "<<largestNode(root)<<endl;

    return 0;
}