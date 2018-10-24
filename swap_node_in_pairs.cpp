//
// Created by marvinle on 2018/10/24 下午1:41.
//

// 题号: 24

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head, *s;
        ListNode* pre = NULL;
        if(temp == NULL || temp->next == NULL)
            return head;
        while(temp != NULL && temp->next != NULL)
        {
            // 下一对节点的开始节点
            s = temp;
            temp = temp->next->next;
            // 交换两个节点
            s->next->next = s;
            if(pre == NULL)
            {
                head = s->next;
                s->next = NULL;
                pre = s;
            } else {
                pre->next = s->next;
                s->next = NULL;
                pre = s;
            }
        }
        // 如果最后剩一个单的节点
        if(temp != NULL)
            pre->next = temp;
        return head;
    }
};
