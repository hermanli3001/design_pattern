/*
2. 两数相加
        给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。



示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]


提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoSortNumbers(struct ListNode* _long, int longSize, struct ListNode* _short, int shortSize){
    int sum=0, carry=0;
    struct ListNode* p1=_long, *p2=_short;
    // same length part
    while(1){
        sum = p1->val + p2->val + carry;
        p1->val = sum % 10;
        carry = sum / 10;
        if(p2->next == NULL) break;
        p1 = p1->next;
        p2 = p2->next;
    }
    // p1 and p2 have been the last element in their own lists
    // calculate separate list1
    if(longSize > shortSize){
        p1 = p1->next;
        while(1){
            sum = p1->val + carry;
            p1->val = sum % 10;
            carry = sum / 10;
            if(p1->next == NULL) break;
            p1 = p1->next;
        }
    }
    // calculate the last element in the list
    if(carry == 1){
        struct ListNode* newOne = malloc(sizeof(struct ListNode));
        newOne->val = 1;
        newOne->next = NULL;
        p1->next = newOne;
    }

    return _long;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int cnt1 = 0, cnt2 = 0;
    struct ListNode* p1 = l1, *p2 = l2;
    while(p1 != NULL){
        cnt1++;
        p1 = p1->next;
    }
    while(p2 != NULL){
        cnt2++;
        p2 = p2->next;
    }
    int longSize=0, shortSize=0;
    if(cnt1 >= cnt2){
        p1 = l1;
        p2 = l2;
        longSize = cnt1;
        shortSize = cnt2;
    }else{
        p1 = l2;
        p2 = l1;
        longSize = cnt2;
        shortSize = cnt1;
    }

    return addTwoSortNumbers(p1, longSize, p2, shortSize);
}
