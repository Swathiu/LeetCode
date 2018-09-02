/*
   LeetCode Problem - 1
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.
   You may assume that each input would have exactly one solution, and you may not use the same element twice.
   Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
        return [0, 1].
*/


#inlcude <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        int num_of_loops = 0;
        for(std::vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it) {
            int second_num = target - (*it);
            num_of_loops+=1;
            std::cout <<"2nd num - "<<second_num << std::endl;
            std::vector<int>::iterator second_element = find (nums.begin() + num_of_loops, nums.end(), second_num);
            if (second_element != nums.end()) {
                auto index1 = std::distance(nums.begin(), it);
                auto index2 = std::distance(nums.begin(), second_element);
                std::cout <<index1 << ","<< index2 << std::endl;
                indices.push_back (index1);
                indices.push_back (index2);
                break;
            }
        }
        return indices;
    }
};
