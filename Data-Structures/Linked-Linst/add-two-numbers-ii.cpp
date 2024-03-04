
class Solution {
// easy solved it on the first go.
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *i = l1, *j = l2;
        while(j != NULL || i != NULL){
            if(i){
                s1.push(i -> val);
                i = i -> next;
            }
            if(j){
                s2.push(j -> val);
                j = j -> next;
            }
        }
        int carry = 0;
        ListNode *ans = NULL;
        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;
            
            if(s1.size()){
                sum += s1.top(); s1.pop();
            }

            if(s2.size()){
                sum += s2.top(); s2.pop();
            }

            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            newNode->next = ans;
            ans = newNode;
        }

        return ans;
    }
};
