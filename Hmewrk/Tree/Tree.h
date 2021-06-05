

#ifndef TREE_H
#define	TREE_H

#include <iostream>
using namespace std;


class Tree {
    private:
       struct Node {
            int value;         //value
            struct Node *left; //left child
            struct Node *right;//right child
            int height;        //height of the node
        };
        Node *root;   //Root node of the tree
       int size;      // Actual Size of the array
       void insert(Node *&,Node *&); //insert
       void dele(Node *&,int);
       int getBalance(Node *);//balance the tree       
       //function for printing
       void preOrder(Node *); 
       void inOrder(Node *);
       void postOrder(Node *);
       void printNode(Node *);
       
       void clean(Node *);//delete a node and its children
       int getHeight(Node *);//get the height of a particular node
       int max(int,int);//max of two integer
       //rotate functions
       void rotateLL(Node *&);
       void rotateLR(Node *&);
       void rotateRR(Node *&);
       void rotateRL(Node *&);
    public:      
       Tree();   //Default constructor  
       ~Tree();  // Destructor declaration
       void insert(int); //insert a number to a tree
       void dele(int);//delete
       void prePnt(); //print out tree with pre-order
       void inPnt(); //print out tree with in-order
       void postPnt(); //print out tree with post-order
       int getSize() const {return size;} //return size
};

//Constructor
Tree::Tree() {
    root=NULL; 
    size=0;
}

//Destructor
Tree::~Tree() {
    clean(root);
}

//delete a node and its children
void Tree::clean(Node *node) {
    if(node!=NULL) {
//        cout<<"clean "<<node->value<<endl;
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

//insert a number to a tree
void Tree::insert(int n) {
    //create a node to store the integer
    Node *newNode=new Node;
    newNode->value=n;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    //insert with recursion
    insert(root,newNode);
    size++;
}

//insert
void Tree::insert(Node *&node, Node *&newNode) {
    if(node==NULL)  {
        node=newNode;
    } else if(newNode->value <= node->value) {
        insert(node->left,newNode);
    } else {
        insert(node->right,newNode);
    }
    //renew the height the node
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int b=getBalance(node); //get the balance of the node
    
    //Right case
    if(b<-1) {
        if(newNode->value >= node->right->value) {
//            cout<<"RR case "<<"at "<<node->value<<endl;
            rotateRR(node);
        } else {
//            cout<<"RL case "<<"at "<<node->value<<endl;
            rotateRL(node);
        }
    }
    if(b>1) {
        if(newNode->value <= node->left->value) {
//            cout<<"LL case "<<"at "<<node->value<<endl;
            rotateLL(node);
        } else {
//            cout<<"LR case "<<"at "<<node->value<<endl;
            rotateLR(node);
        }
    }
}

//Get the balance of the node
int Tree::getBalance(Node *node) {
    if(node==NULL) return 0;
    return getHeight(node->left)-getHeight(node->right);
}


//Open the graph in the txt file from the folder

//Rotate for Left Left case
void Tree::rotateLL(Node *&z) {
//    cout<<"z is "<<z->value<<" height "<<z->height<<endl;
    //copy
    Node *y=z->left;
    Node *t3=y->right;

//    cout<<"y is "<<y->value<<" height "<<y->height<<endl<<endl;
    //Perform rotation
    y->right=z;
    z->left=t3;
    
    //renew the height
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    z=y;
//    cout<<"z is "<<z->value<<" height "<<z->height<<endl;
//    cout<<"y is "<<y->value<<" height "<<y->height<<endl;
//    cout<<"x is "<<y->left->value<<" height "<<y->left->height<<endl;
}



//Rotate for Left Right case
void Tree::rotateLR(Node *&z) {
    //change to LL case
    rotateRR(z->left);
//    cout<<z->value<<"  "<<z->height<<endl;
//    cout<<z->left->value<<"  "<<z->left->height<<endl;
//    cout<<z->left->left->value<<"  "<<z->left->left->height<<endl;
    rotateLL(z);
}

//Rotate for Right Right case 
void Tree::rotateRR(Node *&z) {
    //copy
    Node *y=z->right;
    Node *t2=y->left;
    //Perform rotation
    y->left=z;
    z->right=t2;
    //renew the height
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    
    z=y;
}

//Rotate for Right Left case
void Tree::rotateRL(Node *&z) {
    //Change to RR case first
    rotateLL(z->right);
    rotateRR(z);
}

//delete a tree
void Tree::dele(int n) {
    dele(root,n);
    //size --
}

void Tree::dele(Node *&node,int n) {
    if(node==NULL) return;
    if(n < node->value) {
        //The node to be deleted on the left side
        dele(node->left,n);
    } else if( n > node->value) {
        //The node to be deleted on the right side
        dele(node->right,n);
    } else {
        //This is the node to be deleted
        //This node has one child or no child case
        if((node->left==NULL) || (node->right==NULL)) {
            //no child
            if((node->left==NULL) && (node->right==NULL)) {
                Node *temp=node;
                node=NULL;
                delete temp;
            } else {
                //assign the child to temp
                Node *temp= node->left ? node->left : node->right;
                Node *temp2=node;
                node=temp;
                delete temp2;
            }
        } else { //the node to be deleted has two children
            
            //Get the node contains max value from the left node
//            cout<<"Here Here "<<node->value<<endl;
//            Node *temp=maxValueNode(node->left);
            Node *temp=node->left;
            if(temp!=NULL) {
                while(temp->right!=NULL) {
                    temp=temp->right;
                }
            }
//            cout<<"Temp valueaaaa = "<<temp->value<<endl;
            node->value=temp->value;
//            cout<<"Node valueaaaa = "<<node->value<<endl;
            dele(node->left,node->value);
        }
        
        size--;//tree node size -1
    }
    if(node==NULL) return;
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int b=getBalance(node); //balance
//    cout<<"Node is "<<node->value<<" height "<<node->height<<endl;
    
    //Right case
    if(b<-1) {
        
        if(getBalance(node->right)<=0) {
//            cout<<"RR case "<<"at "<<node->value<<endl;
            rotateRR(node);
        } else {
//            cout<<"RL case "<<"at "<<node->value<<endl;
            rotateRL(node);
        }
    }
    //left case
    if(b>1) {
        
        if(getBalance(node->left)>=0) {
//            cout<<"LL case "<<"at "<<node->value<<endl;
            rotateLL(node);
        } else {
//            cout<<"LR case "<<"at "<<node->value<<endl;
            rotateLR(node);
        }
    }
}


void Tree::printNode(Node *node) {
    cout<<node->value<<" ";
//    cout<<node->height<<endl;
}

void Tree::preOrder(Node *node) {
    if(node!=NULL) {
        printNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} 

void Tree::inOrder(Node *node) {
    if(node!=NULL) {
        inOrder(node->left);
        printNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node) {
    if(node!=NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printNode(node);
    }
}

void Tree::prePnt() {
    cout<<"Print with pre-order:  ";
    preOrder(root); //pre-order output
    cout<<endl;
}

void Tree::inPnt() {
    cout<<"Print with in-order:   ";
//    cout<<endl;
    inOrder(root);  //in-order output
    cout<<endl;
}

void Tree::postPnt() {
    cout<<"Print with post-order: ";
    postOrder(root);//post-order output
    cout<<endl;
}

int Tree::getHeight(Node* n) {
    if(n==NULL) return 0;
    return n->height;
}

int Tree::max(int a, int b) {
    return a>=b? a:b;
}

#endif	/* TREE_H */

