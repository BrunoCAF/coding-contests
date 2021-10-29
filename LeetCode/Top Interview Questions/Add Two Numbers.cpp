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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ls = new ListNode();
        
        int x = 0;
        for(ListNode* p1 = l1, *p2 = l2, *ps = ls; x || p1 || p2; ps = ps->next){
            x += (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
            if(p1) p1 = p1->next; if(p2) p2 = p2->next;
            ps->val = x % 10; 
            x /= 10;
            if(x || p1 || p2) ps->next = new ListNode();
        }
        
        cout << ls->val;
        
        return ls;
        
    }
};