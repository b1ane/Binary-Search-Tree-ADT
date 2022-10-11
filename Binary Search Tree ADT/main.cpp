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


int main() {
    
    string input;
    getline(cin, input);
    
    int num;
    stringstream ss(input);
    
    stree tree;
    
    while(ss>>num) {
        tree.insert(num);
    }
    
    tree.pre();
    
    return 0;
}
