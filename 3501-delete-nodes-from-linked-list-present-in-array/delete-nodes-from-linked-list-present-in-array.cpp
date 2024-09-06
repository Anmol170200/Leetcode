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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
            unordered_set< int > s;
            for( int i =0 ;i < nums.size() ; i++ ){
                s.insert(nums[i]);
            }

            while( (head != NULL) && (s.find(head->val) != s.end()) ){
                head = head->next;
            }

            if( head == NULL ){
                return head;
            }

            ListNode* cp = head;
            while( (cp != NULL) && (cp->next != NULL) ){
                while( (cp->next != NULL) && (s.find(cp->next->val) != s.end()) ){
                    cp->next = cp->next->next;
                }

                cp = cp->next;
            }

            return head;
        
    }
};