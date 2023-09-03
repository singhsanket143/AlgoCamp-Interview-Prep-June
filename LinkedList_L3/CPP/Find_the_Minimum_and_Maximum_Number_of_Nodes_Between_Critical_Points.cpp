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
      int count=2;
      vector<int>v;
      ListNode * temp=head->next;
      ListNode * prev=head;
      while(temp->next)
      {
          if(temp->val > prev->val && temp->val > temp->next->val)
          {
              v.push_back(count);
          }
          if(temp->val < prev->val && temp->val < temp->next->val)
          {
              v.push_back(count);
          }
          count++;
          prev=temp;
          temp=temp->next;
      }
      if(v.size()<2)
      {
          return {-1,-1};
      }
    sort(v.begin(), v.end()); // Sort the vector

    int maxDifference = v[v.size() - 1] - v[0];
    int minDifference = INT_MAX;

    for (int i = 1; i < v.size(); ++i) {
        int diff = v[i] - v[i - 1];
        minDifference = min(minDifference, diff);
    }
    return {minDifference,maxDifference};
    }
};
