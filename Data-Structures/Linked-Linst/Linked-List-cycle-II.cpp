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



class Solution {
// Clever solution . just simulate it and see , i need to use this method, fast and slow method.
// basically we wait till fast and slow meets , when  they meet , we run another loop till slow and entry meets, then return that meeting
// point of entry and slow.
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                while(entry != slow)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
         return NULL;
    }
};
