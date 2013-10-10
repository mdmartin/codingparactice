//
//  main.cpp
//  ValidateBinarySearchTree
//
//  Created by 马 丁 on 10/10/13.
//  Copyright (c) 2013 马 丁. All rights reserved.
//

#include <iostream>
#include <limits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!root)
        {
            return true;
        }
        
        return valid(root, INT_MIN, INT_MAX);
    }
    
    bool valid(TreeNode* root, int min, int max)
    {
        if (root == NULL)
        {
            return true;
        }
        int curVal = root->val;
        if (curVal < max && curVal > min)
        {
            return valid(root->left, min, curVal) && valid(root->right, curVal, max);
        }
        else
        {
            return false;
        }
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution* sl = new Solution();
    TreeNode* r = new TreeNode(10);
    r->left = new TreeNode(5);
    r->right = new TreeNode(15);
    r->right->left = new TreeNode(6);
    r->right->right = new TreeNode(20);
    cout << sl->isValidBST(r) << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}

