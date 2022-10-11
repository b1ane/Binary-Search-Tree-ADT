//
//  main.cpp
//  Binary Search Tree ADT
//
//  Created by blane on 10/3/22.
//

#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "stree.h"
#include <vector>


int main() {
    
    string input;
    getline(cin, input);
    
    int nth;
    cin >> nth;
    
    int num;
    stringstream ss(input);
    
    stree tree;
    
    //holds number of elements in tree

    
    while(ss>>num) {
        tree.insert(num);
    }
    
    //tree.pre();
    //cout << endl;
    
    //tree.post();
    //cout << endl;
    
    tree.findnth(nth);

    
    
    return 0;
}
