/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
// need to stop making dumb mistakes like while (!ptr) X_X
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int len = 0;
        ListNode *ptr = head;
        while(ptr){
            st.push(ptr);
            ptr = ptr -> next;
            len ++;
        }
        
        ptr = head;
        len = len / 2;
        
        while(len){
            ListNode *temp = ptr -> next;
            ListNode *st_element = st.top();
            st.pop(); 
            len--;
            st_element -> next = temp;
            ptr -> next = st_element; 
            ptr = ptr -> next -> next;
        }        

        ptr -> next = NULL;
    }
};
