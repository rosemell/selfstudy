#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//��leetcode���������ۣ�
//��Ŀ�������б����Ͻ����������źã���������Ӵ �е���С���������Ϲ�q�������Ա����ҵ����˻������ҵ�һ���µı�������p�ڼ���͸��ڸ��¿ӷźã��������û���ˣ��ͽ�����
//
//�м�Ի�
//
//�Ϲ������ţ����������û����if�� ���ţ����ˡ���nums[p] == nums[q]���������ң�q++��
//
//�Ϲ������ţ����������û����if�� ���ţ����ˡ���nums[p] == nums[q]���������ң�q++��
//
//�Ϲ������ţ����������û����if�� ���ţ����û�У��û����� ��nums[p] != nums[q]�� �ź��ˣ��ҵ���һ��λ�õ��㣨p++�� ���ټ����Ұ�(q++)
//�����������ְ��Լ��Ĵ����д����
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
//ԭ���Ĵ��룺
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
//    return j;//���س���
//}

int main()
{
    int a[10] = { 1,1,2 };
    printf("%d", removeDuplicates(a, 3));
    return 0;
}