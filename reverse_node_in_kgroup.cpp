//
// Created by marvinle on 2018/10/24 下午2:12.
//

// 题号: 25

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp, *next, *pre, *temphead,*tempend;
        next = head;
        temphead = NULL;
        pre = NULL;
        while(true){
            temp = next;
            int i;
            for(i = 0 ; i < k && next != NULL; i++)
            {
                next = next->next;
            }

            // 这一次可以反转
            if(i == k){
                // 保存这一次的最后一个元素方便下次拼接
                tempend = temp;
                // 反转
                for(int i = 0; i < k; i++)
                {
                    ListNode *t = temp->next;
                    temp->next = temphead;
                    temphead = temp;
                    temp = t;
                }
                if(pre == NULL)
                {
                    head = temphead;
                    pre = tempend;
                } else {
                    pre->next = temphead;
                    pre = tempend;
                }
                temphead = NULL;

            } else {
                if(pre != NULL)
                    pre->next = temp;
                break;
            }
        }
        return head;

    }
};