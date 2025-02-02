/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "null,";
            }
        }

        if (!s.empty()) s.pop_back();

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;
        vector<string> values;

        while (getline(ss, val, ',')) {
            values.push_back(val);
        }

        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < values.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (values[i] != "null") {
                curr->left = new TreeNode(stoi(values[i]));
                q.push(curr->left);
            }
            i++;

            if (i < values.size() && values[i] != "null") {
                curr->right = new TreeNode(stoi(values[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
