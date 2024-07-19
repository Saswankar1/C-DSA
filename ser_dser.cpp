#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string result = to_string(root->val);
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                result += "," + to_string(node->left->val);
                q.push(node->left);
            } else {
                result += ",null";
            }
            
            if (node->right) {
                result += "," + to_string(node->right->val);
                q.push(node->right);
            } else {
                result += ",null";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!getline(s, str, ',')) break;
            if (str != "null") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            if (!getline(s, str, ',')) break;
            if (str != "null") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

int main() {
    Codec ser, deser;
    // Example binary tree: [1,2,3,null,null,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string serialized = ser.serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = deser.deserialize(serialized);
    cout << "Deserialized Root Value: " << deserialized->val << endl;

    return 0;
}
