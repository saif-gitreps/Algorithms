/**
attempt 1 didnt work because the logic isnt correct.
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode *temp,*ptr=head;
    int check;
    queue<ListNode*> q;
    if(head->val==head->next->val){
        while(head->next!=NULL && head->val==head->next->val){
            temp = head;
            check = head->val;
            head = head->next;
            delete temp;
        }
        if(head->next==NULL && head->val==check){
            head = NULL;
            return head;
        }
        else{
            temp = head;
            head = head->next;
            delete temp;
        }   
    }
    /*
    for (; ptr->next != nullptr; ptr = ptr->next) {
        if (ptr->val == ptr->next->val) {
            q.push(ptr);
            q.push(ptr->next);
            ptr=ptr->next;
        } 
        else if (!q.empty() && q.front()->val == ptr->val) {
            q.push(ptr);
        }
    }
    */
    return head;

}
};


class Solution {
    // try two , didnt work.
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* ptr = head;
    unordered_map<int, int> mp;
    
    while (ptr != nullptr && ptr->next != nullptr) {
        if (ptr->val == ptr->next->val) {
            ListNode* temp = ptr->next;
            mp[ptr->val]++;
            ptr->next = ptr->next->next;
            delete temp;
        }
        else {
            ptr = ptr->next;
        }
    }
    
    if (mp[head->val] > 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    ptr = head;
    ListNode* prev = nullptr;
    
    while (ptr != nullptr) {
        if (mp[ptr->val] > 0) {
            if (prev != nullptr) {
                prev->next = ptr->next;
            }
            ListNode* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    
    return head;
}

    
};
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

ListNode *pseudo = new ListNode(0);

pseudo->next = head;

ListNode *temp,*ptr = pseudo;

while(ptr->next!=NULL && ptr->next->next!=NULL){
	if(ptr->next->val==ptr->next->next->val){
		int variable = ptr->next->val;
		while(ptr->next!=NULL && ptr->next->val==variable) {
			temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
		}
	}
		else{
			ptr=ptr->next;}
}

return pseudo->next;
}

    
};
