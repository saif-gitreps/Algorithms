//attempt 1: passed
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> mp;
        ListNode *ptr = head;
        while(ptr != NULL){
            if(mp[ptr] != false){
                return ptr;
            }
            mp[ptr] = true;
            ptr = ptr->next;
        }
        return NULL;
    }
};
