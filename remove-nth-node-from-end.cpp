//
// Created by marvinle on 2018/10/12.
//

#include <cstdlib>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 两个相隔n的节点依次遍历
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *fast, *slow, *pre;
            if(head == nullptr)
                return nullptr;
            fast = head;
            for(int i = 0; i < n; i++){
                if(fast == nullptr)
                    return head;
                fast = fast->next;
            }
            slow = head;
            pre = slow;
            while(fast != nullptr){
                pre = slow;
                fast = fast->next;
                slow = slow->next;
            }
            if(pre == slow){
                return head->next;
            } else {
                pre->next = slow->next;
                delete slow;
            }
            return head;
    }
};

