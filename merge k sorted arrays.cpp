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
class Compare{
public: 
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;

    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        for(ListNode* node:lists)
        {
            if(node)
              pq.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty())
        {
            ListNode* min = pq.top();
            pq.pop();
            curr->next = min;
            curr= curr->next;
            if(min->next!=nullptr)
              pq.push(min->next);
        }
        return dummy->next;
    }
};