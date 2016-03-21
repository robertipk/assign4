#include <iostream>

using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    cout << "insert method was called " << data << endl;
    if(root==NULL){ //insert tree
        root = GetNewNode(data);
    }
    else if(data<=root->data)
        root->left = Insert(root->left,data);

    else
        root->right = Insert(root->right,data);
    return root;
}

bool Search(BstNode* root, int data){
    cout << "search method was called" << endl;
    if(root==NULL){
        cout << 1111 << endl;
        return false;
    }
    else if(root->data==data){
        cout << 2222 << endl;
        return true;
    }
    else if(data<=root->data) {
            cout<< 33333 << endl;
            return Search(root->left,data);
    }
    else return Search(root->right,data);
}

int countNodes(BstNode* root){
    if(root==NULL)
        return 0;
    else
        return (countNodes(root->left) + countNodes(root->right)+1);
}

//traverse the tree


void deleteTree(BstNode* &root){
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout << "Deleting the node " << root->data;
    delete root;
}

void makeDeletion(BstNode* &root){
    cout << "Make deletion method called" << endl;
    BstNode* nodetodelete = root; //hold the node that is to be deleted
    //locate the point where the left subtree is attached
    //if the node has only one child
    BstNode* attachpoint;
    if(root->right == NULL){
        root = root->left;
        cout << "going to root left" << endl;
    }
    else if(root->left == NULL){
        root = root->right;
        cout << "going to root right" << endl;
    }
    //if the node has two children
    else{
        attachpoint = root->right;
        while(attachpoint->left != NULL){
            attachpoint = attachpoint->left;
        }
        attachpoint->left = root->left;
        root = root->right;
    }
    delete nodetodelete;
}

//navigates the tree to locate and call the removal function on the appropriate node
void removeNode(BstNode* &root, int num){
    cout <<"RemoveNode function now called" << endl;
    if(root==NULL){
        cout << "The value was not found" << endl;
    }
    if(num<root->data)
        removeNode(root->left,num);
    else if(num>root->data)
        removeNode(root->right,num);
    else //we have found the node to delete
        makeDeletion(root);
}


//in order
void printInOrder(BstNode* root){
    if(root){
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

//pre order
void printPreOrder(BstNode* root){
    if(root){
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

//post order
void printPostOrder(BstNode* root){
    if(root){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }
}

void children(BstNode* root){
    if(root){
        int count=0;
        if (root->left != NULL)
            count++;
        if (root->right != NULL)
            count++;
        children(root->left);
        cout << endl << root->data << " has " << count << " children" << endl;
        children(root->right);
    }
}

int main()
{
    BstNode* root = NULL;
    root = Insert(root,12);
    root = Insert(root,23);
    root = Insert(root,89);
    root = Insert(root,87);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root,11);
    cout << "Down with insertions" << endl;
    bool d = Search(root,89);
    if(d == true) cout << "FOUNDDDD";
    else cout << "NOT FOUND" << endl;
    cout << "The number of nodes is " << countNodes(root) << endl;
    cout << "Printing in order: ";
    printInOrder(root);
    cout << endl;
    cout << "Printing pre order: ";
    printPreOrder(root);
    cout << endl;
    cout << "Printing post order: ";
    printPostOrder(root);
    removeNode(root,8);
    cout << endl;
    printInOrder(root);
    cout << endl;
    children(root);
    deleteTree(root);
    cout << "After deleting the entire tree, the value in the node is " << root->data << endl;
    cout << "THE END" << endl;

    //cout << "Printing pre order: " << printPreOrder(root);
   // cout << "Printing post order: " << printPostOrder(root);
    return 0;
}
