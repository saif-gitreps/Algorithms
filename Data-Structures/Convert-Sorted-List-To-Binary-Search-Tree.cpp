class Solution {
// Naive attempt, worked tho but its naive attempt.
public:
    TreeNode* buildBSTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBSTree(nums, start, mid - 1);
        root->right = buildBSTree(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> a;
        ListNode * ptr = head;
        while(ptr != NULL){
            a.push_back(ptr -> val);
            ptr = ptr -> next;
        }
        return buildBSTree(a, 0, a.size() - 1);
    }
};


class Solution {
// this solution is simulating binary search :

/*    
    this will go to the lest most node first , create a node , make a parent node, make the left node its left child
    then we move head to next link, then move to the right, now for the first element of the linked list , when we make a right call
    then left > right so we get null, as perfect as we need.
*/
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* cnt = head;
        int len = 1;
        while(cnt->next != NULL){
            cnt = cnt->next;
            len++;
        }
        return inorderRe(head, 1, len);
    }
    
    TreeNode* inorderRe(ListNode*& head, int left, int right) {
        if(left>right) return NULL;
        int mid = left + (right-left)/2;
        
        TreeNode* leftnode = inorderRe(head, left, mid-1);
        
        TreeNode* cur = new TreeNode(head->val);
        cur->left = leftnode;
        
        head = head->next;
        
        cur->right = inorderRe(head, mid+1, right);
        return cur;
    }
};

class Solution{
// i had the same sort of intuition with fast and slow pointer.
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case: if the linked list is empty, return nullptr
        if (!head) return nullptr;
        
        // Base case: if there's only one node in the linked list, create a leaf node
        if (!head->next) return new TreeNode(head->val);
    
        // Initialize pointers for finding the middle of the linked list
        auto fast = head->next, slow = head;
        
        // Use a fast and slow pointer to find the middle of the linked list
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // 'mid' is the node at the middle of the linked list
        auto mid = slow->next;
        // Disconnect the linked list at the middle to split it into two halves
        slow->next = nullptr;
    
        // Create a new tree node using the value of the middle node
        auto root = new TreeNode(mid->val);
    
        // Recursively build the left and right subtrees using the two halves of the linked list
        root->left = sortedListToBST(head);       // left subtree with nodes before 'mid'
        root->right = sortedListToBST(mid->next); // right subtree with nodes after 'mid'
    
        // Return the root of the constructed BST
        return root;
    }
};
