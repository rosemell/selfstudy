int missingNumber(int* nums, int numsSize){
int i=0,temp=0,flag=(int)(numsSize*(1+numsSize)/2);
for(i=0;i<numsSize;i++)
{
    temp+=nums[i];
}
return flag-temp;
}