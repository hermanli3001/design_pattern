/*1. 两数之和

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案*/


#include "uthash.h"

typedef struct{
    int key;
    int val;
    UT_hash_handle hh;
}hashTable;

hashTable* ht;

hashTable* find(int _key){
    hashTable* ret;
    HASH_FIND_INT(ht, &_key, ret);
    return ret;
}

void insert(int _key, int _val){
    hashTable* item = find(_key);
    if(item == NULL){
        hashTable* tmp = malloc(sizeof(hashTable));
        tmp->key = _key;
        tmp->val = _val;
        HASH_ADD_INT(ht, key, tmp);
    }else{
        item->val = _val;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    ht = NULL;
    for(int i=0; i<numsSize; ++i){
        hashTable* tmp = find(target - nums[i]);
        if(tmp != NULL){
            int* ret = malloc(sizeof(int)*2);
            ret[0] = tmp->val;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}