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
    
    
    
    
    
};


#endif /* stree_h */
