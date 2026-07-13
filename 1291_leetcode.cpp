// https://leetcode.com/problems/sequential-digits/?envType=daily-question&envId=2026-07-13


class Solution {
public:
    void helper(vector<int> &nums,int dig){
        for(int i=1;i<=(9-dig+1);i++){
            int k = i;
            int num = 0;
            for(int i=1;i<=dig;i++){
                num = num*10 + k;
                k++;
            }
            nums.push_back(num);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
        for(int i=2;i<=9;i++)
        helper(nums,i);

        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= low && nums[i] <= high) res.push_back(nums[i]);
        }
        return res;
    }
};