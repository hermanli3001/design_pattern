/*
3. 无重复字符的最长子串
        给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0


提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

*/


#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
#include "func.h"


typedef struct {
    int key;
    UT_hash_handle hh;
}HashTable;

HashTable* hs = NULL;

HashTable* find(int _key){
    HashTable * ret = NULL;
    HASH_FIND_INT(hs, &_key, ret);
    return ret;
}

void insert(int _key){
    HashTable * tmp = find(_key);
    if(tmp == NULL){
        HashTable * s = malloc(sizeof(HashTable));
        s->key = _key;
        HASH_ADD_INT(hs, key, s);
    }
}

void delete(int _key){
    HashTable * tmp = find(_key);
    HASH_DEL(hs, tmp);
    free(tmp);
}

int max(int num1, int num2){
    return num1>=num2 ? num1 : num2;
}

int lengthOfLongestSubstring(char * s){
    int size = (int)strlen(s);
    int maxDis = 0;

    int r = 0;
    for(int l=0; l<size; ++l){
        while(r<size && !find(s[r])){
            insert(s[r]);
            maxDis = max(maxDis, r-l+1);
            r++;
        }
        delete(s[l]);
    }

    return maxDis;
}
