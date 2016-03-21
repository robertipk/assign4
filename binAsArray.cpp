#include <iostream>

using namespace std;
//Robert Ip Data Structures Assignment #4 - using static storage and arrays
void children(int binaryArray[], int index){
    if(binaryArray[index]==-1){
        return;
    }
    int numChildren=0;
    if(binaryArray[index*2]!=-1){
        children(binaryArray,2*index);
        numChildren++;
    }
    if(binaryArray[index*2+1]!=-1){
        children(binaryArray,2*index+1);
        numChildren++;
    }
    cout << "The node with " << binaryArray[index] << " has " <<  numChildren << " children." << endl;
}

bool arrSearch(int binaryArray[],int data,int counter){
    if(binaryArray[counter]==-1)
        return false;
    if (binaryArray[counter]>data)
        arrSearch(binaryArray,data,counter*2);
    else if (binaryArray[counter]<data)
        arrSearch(binaryArray,data,counter*2+1);
    else if(binaryArray[counter]==data)
        return true;
}

void makeDeletion(int binaryTree[], int index){
    cout << "MAKE DELETION CALLED" << endl;
    int counter = 1;
    if (binaryTree[2*index]==-1 && binaryTree[2*index+1]==-1) //if the node has no children
        binaryTree[index]=-1;
    else if (binaryTree[2*index]!=-1 && binaryTree[2*index+1]==-1){
        //if only left child exists
        //replace item to be deleted with the highest value in the left subtree
        int leftTree = 2*index;
        int greatest=binaryTree[leftTree];
        int nextValue=binaryTree[leftTree*2+1];
        while(nextValue!=-1){
            nextValue = binaryTree[leftTree*2*2*counter+1];
            greatest = binaryTree[leftTree*2*counter+1];
            counter++;
        }
        if (counter>=2)
            counter--;
        binaryTree[leftTree*2*counter+1] = -1;
        binaryTree[index]=greatest;
        cout << "Only left child exists" << endl;
    }
     //else (binaryTree[2*index]==-1 && binaryTree[2*index+1]!=-1)
     else
        {
        //if only right tree exists OR if both left and right children exist
        //switch item to be deleted with the smallest value in right sub-tree
        int rightTree = 2*index+1;
        int smallest=binaryTree[rightTree];
        int nextValue=binaryTree[(rightTree)*2];
        while(nextValue != -1){
            nextValue = binaryTree[rightTree*2*2*counter];
            smallest = binaryTree[rightTree*2*counter];
            counter++;
        }
        if (counter>=2)
            counter--;
        binaryTree[rightTree*2*counter] = -1;
        binaryTree[index] = smallest;
        cout << "Only right child exists, or both nodes exist" << endl;
    }
}

void removeNode(int binaryArray[], int data, int index){
    if (binaryArray[index]==-1){
        //empty array
        cout << "Unable to make the deletion" << endl;
        return;
    }
    if (binaryArray[index]>data)
        removeNode(binaryArray,data,index*2);
    else if (binaryArray[index]<data)
        removeNode(binaryArray,data,index*2+1);
    else if(binaryArray[index]==data)
        makeDeletion(binaryArray, index);
}

void insertNode(int binaryArray[], int data,int index){
    //index = 1
    if (binaryArray[1]==-1){
        //the binary is empty
        binaryArray[1]=data;
        return;
    }
    if(binaryArray[index]==-1)
        binaryArray[index]=data;
    else if(binaryArray[index]>data)
        insertNode(binaryArray,data,index*2);
    else if(binaryArray[index]<data)
        insertNode(binaryArray,data,index*2+1);
}

void inOrder(int binaryArray[],int index){
    if(binaryArray[1]==-1)
       cout << endl << "This array is empty" << endl;
    else if(binaryArray[index]==-1)
       return;
    else{
       inOrder(binaryArray,index*2);
       cout << binaryArray[index] << " ";
       inOrder(binaryArray,index*2+1);
    }
}

void postOrder(int binaryArray[],int index){
    if(binaryArray[1]==-1)
        cout << endl << "This array is empty" << endl;
    else if(binaryArray[index]==-1)
        return;
    else{
        postOrder(binaryArray,index*2);
        postOrder(binaryArray,index*2+1);
        cout << binaryArray[index] << " ";
    }
}

void preOrder(int binaryArray[],int index){
    if(binaryArray[1]==-1)
        cout << endl << "This array is empty" << endl;
    else if(binaryArray[index]==-1)
        return;
    else{
        cout << binaryArray[index] << " ";
        preOrder(binaryArray,index*2);
        preOrder(binaryArray,index*2+1);
    }
}

void deleteTree(int binaryArray[]){
    for (int i=0;i<300;i++)
        binaryArray[i]=-1;
}

int* createTree(){
    int arr [300];
    for (int i=0;i<300;i++)
        arr[i]=-1;
    return arr;
}
int main()
{
    int binaryArray[300];
    for (int i=0;i<300;i++)
        binaryArray[i]=-1;
    insertNode(binaryArray,11,1);
    insertNode(binaryArray,25,1);
    insertNode(binaryArray,75,1);
    insertNode(binaryArray,12,1);
    insertNode(binaryArray,37,1);
    insertNode(binaryArray,60,1);
    insertNode(binaryArray,90,1);
    insertNode(binaryArray,8,1);
    insertNode(binaryArray,15,1);
    insertNode(binaryArray,32,1);
    insertNode(binaryArray,45,1);
    insertNode(binaryArray,50,1);
    cout << "Calling the children method: " << endl;
    children(binaryArray,1);
    cout << endl << "The end!" << endl;
    cout << endl << "Printing the array in ORDER" << endl;
    inOrder(binaryArray,1);
    //cout << endl << "Printing the array in PREORDER" << endl;
   // preOrder(binaryArray,1);
   // cout << endl << "Printing the array in POSTORDER" << endl;
    //postOrder(binaryArray,1);
    cout << "Performing the arraysearch function" << endl;
    cout << arrSearch(binaryArray,21,1) << endl;
    cout << "Removing node" << endl;
    removeNode(binaryArray,12,1);
    cout << "Printing in order again after the removal of the node" << endl;
    inOrder(binaryArray,1);
    removeNode(binaryArray,40,1);
    cout << "Printing in order again after the removal of the node" << endl;
    inOrder(binaryArray,1);
    removeNode(binaryArray,2,1);
    cout << "Printing in order again after the removal of the node" << endl;
    inOrder(binaryArray,1);
    removeNode(binaryArray,7,1);
    cout << "Printing in order again after the removal of the node" << endl;
    inOrder(binaryArray,1);
  //  cout << "---------------------" << endl;
  //  for (int i=0;i<100;i++)
  //      cout << " " << binaryArray[i];

    return 0;
}
