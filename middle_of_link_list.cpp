//
// Created by marvinle on 2018/10/26 下午11:05.
//

// 题号: 876

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast, *slow;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
