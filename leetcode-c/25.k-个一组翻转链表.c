/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (64.16%)
 * Likes:    912
 * Dislikes: 0
 * Total Accepted:    135.6K
 * Total Submissions: 211.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *l, *pre, *prep, *p, *q;
    int count = 0;

    l = (struct ListNode*)malloc(sizeof(struct ListNode));
    l->next = head;
    pre = prep = l;
    p = head;

    while(p && p->next) {
        q = p;
        while (count < k && q) {
            count++;
            q = q->next;
        }

        if (count < k) break;
        else count = 0;

        while(count < k && p) {
            q = p->next;
            prep->next = q;
            p->next = pre->next;
            pre->next = p;
            if (prep == pre) {
                prep = prep->next;
            }
            p = q;
            count++;
        }
        pre = prep;
        count = 0;
    }    

    head = l->next;
    free(l);

    return head;
}
// @lc code=end

