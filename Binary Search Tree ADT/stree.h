//
//  stree.h
//  Binary Search Tree ADT
//
//  Created by blane on 10/3/22.
//

#ifndef stree_h
#define stree_h
#include <iostream>
using namespace std;
#include<vector>

struct node {
    int data;
    node* left;
    node* right;
};

class stree {
private:
    node* root;
public:
    stree() {
        root = nullptr;
    }
    
    int returnRoot() {
        return root->data;
    }
    
    bool isEmpty() {
        if (root == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void insert(int val) {
        //new node created
        node* newNode = new node;
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        
        //sets new node to root if tree is empty
        if (root == nullptr) {
            root = newNode;
        }
        else {
            //check subtrees of root
            insert2(root,newNode);
            
        }
    }
    
    //insert function using recursion
    node* insert2(node* r, node* n) {
        //BASE CASE -- if node is empty, insert node
        if (r == nullptr) {
            r = n;
        }
        //if root is not empty, check if left is less than root
        else if (n->data < r->data){
            r->left = insert2(r->left,n);
        }
        else{
            r->right = insert2(r->right, n);
        }
        return r;
    }
    
    void preOrder(node* r) {
        //if node is empty, do nothing
        if(r == nullptr) {
            return;
        }
        //otherwise -- output data
        cout << r->data << " ";
        //recursive call for rest of tree
        preOrder(r->left);
        preOrder(r->right);
    }
    
    //user facing print
    void pre() {
        //call recursive print function
        preOrder(root);
    }
    
    void postOrder(node* r) {
        if(r == nullptr) {
            return;
        }
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << " ";
    }
    
    void post() {
        postOrder(root);
    }
    
    //find nth largest item
    //EX: 2 for 1 3 2 5 4 -- output: 4
    
    //theory: traverse in order, insert values in order and pushes into vector, then sort through vector to find nth val
    void inOrder(node* r, vector<int>& vec) {
        if( r == nullptr ) {
            return;
        }
        inOrder(r->left, vec);
        vec.push_back(r->data);
        inOrder(r->right, vec);
    }

    int nth(node* r, int key) {
        int retVal = 0;
        
        if(r == nullptr) {
            return 0;
        }
        
        vector<int>myVec;
        inOrder(root,myVec);
        
        unsigned long x = myVec.size();

        //reverse vector, store in another vector
        vector<int>newVec;
        for( unsigned long i = x - 1; i < x; i--) {
            newVec.push_back(myVec.at(i));
        }
        
        retVal = newVec.at(key-1);
        return retVal;
    }
    
   
    //user facing function
    void findnth(int key) {
        cout << nth(root, key) << endl;
    }
    
    
    
    
    
};


#endif /* stree_h */
