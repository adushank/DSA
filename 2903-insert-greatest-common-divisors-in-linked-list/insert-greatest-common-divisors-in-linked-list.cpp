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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* temp =head->next;

        while(  temp!=nullptr ){
            int g =gcd(curr->val,temp->val);
            ListNode* node =new ListNode(g);
            curr->next=node;
            node->next=temp;

            curr=temp;
            temp=temp->next;
        }
        return head;
        
    }
};