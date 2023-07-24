 
#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 

class Solution{
    private:
    pair<bool,int> isBlanaceFast(Node* root){
        //base case 
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
      
      pair<int,int> leftsubtree =  isBlanaceFast(root->left);
      pair<int,int> rightsubtree =  isBlanaceFast(root->right);
      
      // getting balance
      bool leftAns = leftsubtree.first;
      bool rightAns = rightsubtree.first;
      
      //difference 
      bool difference = abs((leftsubtree.second - rightsubtree.second))<=1;
      
      pair<bool,int>ans;
      //height nikalne ka tarika
      ans.second = max(leftsubtree.second,rightsubtree.second)+1;
      
      if(leftAns && rightAns && difference){
          ans.first = true;
      }
      else{
          ans.first = false;
      }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       return isBlanaceFast(root).first;
    }
};
