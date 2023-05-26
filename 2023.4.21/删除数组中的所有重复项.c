#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//在leetcode看到的评论：
//题目：外面有宝，赶紧捡回来按序放好，不能重样哟 有点像小夫妻俩，老公q在外面淘宝，找到后运回来，找到一个新的宝，老婆p在家里就给挖个新坑放好，最后外面没宝了，就结束咯
//
//中间对话
//
//老公：老婆，这个家里有没？（if） 老婆：有了。（nums[p] == nums[q]）你再找找（q++）
//
//老公：老婆，这个家里有没？（if） 老婆：有了。（nums[p] == nums[q]）你再找找（q++）
//
//老公：老婆，这个家里有没？（if） 老婆：这个没有，拿回来吧 （nums[p] != nums[q]） 放好了，我到下一个位置等你（p++） 你再继续找吧(q++)
//大受启发，又把自己的代码改写了下
int removeDuplicates(int* nums, int numsSize)
{
    int i = 1, j = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[j])
        {
            nums[++j] = nums[i];
        }
    }
    return j + 1;
}
//原来的代码：
//int removeDuplicates(int* nums, int numsSize) {
//    int i = 0, j = 0, size_i = numsSize - 1;
//    for (i = 0; i < size_i;i++ )
//    {
//        if (nums[i] == nums[i + 1])
//        {
//            nums[j++] = nums[i];
//        }
//       
//    }
//    nums[j++] = nums[i];
//    return j;//返回长度
//}

int main()
{
    int a[10] = { 1,1,2 };
    printf("%d", removeDuplicates(a, 3));
    return 0;
}