//
// Created by Eirik Drage Steen on 05/02/2021.
//

// https://open.kattis.com/problems/balancedcut

// Algorithm to delete nodes from balanced binary search tree until the amount of nodes equal a specified amount. 
// Deleting a parent node will also delete the children.
// Result tree must also be balanced.
// The inorder traversal of tree must output nodes in lowest possible lexicographic order.

// Input is a list where index + 1 of element is the value of node and value at index is value of parent node (+ amount of nodes and amount to keep).
// Output is string of '1' * len(listOfNodes) where each '1' is replaced by '0' for removed node at the index.

// Traverse tree from right to left and check if balance is kept if node of highest value is deleted.
// Delete node if balance is kept.
// Else check next leaf to the left.
// Repeat and continue until size of tree is right.

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    explicit node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int size(node* node) {
    if (node == nullptr){
        return 0;
    }
    else{
        return size(node->right) + size(node->left) + 1;
    }
}

int maxDepth(node* node) {
    if (node == nullptr){
        return -1;
    }
    else{
        return 1 + max(maxDepth(node->right), maxDepth(node->left));
    }
}

void findSortedLeaves(node* node, vector<int> &blader){
    if (node == nullptr) return;
    if (node->right == nullptr && node->left == nullptr){
        blader.push_back(node -> data);
    }
    findSortedLeaves(node->right, blader);
    findSortedLeaves(node->left, blader);
}

bool checkBalance(node* node) {
    if (node == nullptr) {
        return true;
    }
    if (!(maxDepth(node->right) - maxDepth(node->left) == 1 ||
          maxDepth(node->right) - maxDepth(node->left) == 0 ||
          maxDepth(node->right) - maxDepth(node->left) == -1)){
        return false;
    }
    if (checkBalance(node->right) && checkBalance(node->left)){
        return true;
    }
    return false;
}

bool checkKeptBalance(node*& nodeLocal, node*& nodeGlobal, int value){
    if (nodeLocal == nullptr){
        return false;
    }
    if (nodeLocal->data == value){
        node* node2 = nodeLocal;
        nodeLocal = nullptr;
        if (!checkBalance(nodeGlobal)){
            nodeLocal = node2;
            return false;
        }
        return true;
    }
    return checkKeptBalance(nodeLocal->right, nodeGlobal, value) || checkKeptBalance(nodeLocal->left, nodeGlobal, value);
}

void addNodes(int size, vector<int> tree, node*& node){
    if (node == nullptr) return;
    for (int x = 0; x < size; x++){
        if (tree.at(x) == node->data){
            if (x + 1 < node->data){
                node->left = new struct node(x+1);
            }
            else{
                node->right = new struct node(x+1);
            }
        }
    }
    addNodes(size, tree, node->right);
    addNodes(size, tree, node->left);
}

node* processInput(int size, vector<int> tree){
    node* node;
    for (int x = 0; x < size; x++){
        if (tree.at(x) == -1){
            node = new struct node(x+1);
        }
    }

    addNodes(size, tree, node);

    return node;
}

string balancedCut(node* node, int keep){
    string result;
    vector <int> leaves;

    for (int x = 0; x < size(node); x++){
        result += '1';
    }

    while (true){
        if (size(node) == keep){
            return result;
        }

        leaves.clear();
        findSortedLeaves(node, leaves);

        for (int leaf : leaves){
            if (checkKeptBalance(node, node, leaf)) {
                result.replace(leaf - 1, 1, "0");
                break;
            }
        }
    }
}


int main(){
    vector <int> line1;
    for (int x = 0; x < 2; x++){
        int num;
        cin >> num;
        line1.push_back(num);
    }
    vector <int> tree;
    for (int x = 0; x < line1.front(); x++){
        int num2;
        cin >> num2;
        tree.push_back(num2);
    }

    int size2 = line1.front();
    int keep = line1.back();

    node* tre = processInput(size2, tree);

    cout << balancedCut(tre, keep);

    return 0;
}
