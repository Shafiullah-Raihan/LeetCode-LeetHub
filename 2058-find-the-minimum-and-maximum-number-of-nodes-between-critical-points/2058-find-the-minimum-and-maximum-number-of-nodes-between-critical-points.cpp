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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>store;
        while(head)
        {
            store.push_back(head->val);
            head = head->next;
        }
        int n=store.size();
        if(n<=3) 
        {
            return {-1,-1};
        }
        vector<int>idx;
        for(int i=1;i<n-1;i++)
        {
            if(store[i-1]<store[i] && store[i]>store[i+1])
            {
                idx.push_back(i);
            }
            if(store[i-1]>store[i] && store[i]<store[i+1])
            {
                idx.push_back(i);
            }
        }
        if(idx.size()<2)
        {
            return {-1,-1};
        }
        int mx = idx.back() - idx.front();int mn=INT_MAX;
        for(int i=1;i<idx.size();i++)
        {
            mn =min(mn,  idx[i]-idx[i-1]);
        }
        return {mn,mx};

    }
};