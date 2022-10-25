#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {

            // check if the complement exists
            if(m.find(target - nums[i]) != m.end()) {

                // put the complement index in the result
                result.push_back(m[target - nums[i]]);

                // put the current index in the result
                result.push_back(i);

                return result;
            }

            // put the current number and index in the map
            m[nums[i]] = i;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // example 1
    nums = { 2, 7, 11, 15 };
    cout << "Input: nums = [2, 7, 11, 15], target = 9" << endl;
    cout << "Output: ";
    for(int i : sol.twoSum(nums, 9)) {
        cout << i << " ";
    }
    cout << endl;

    // example 2
    nums = { 3, 2, 4 };
    cout << "Input: nums = [3, 2, 4], target = 6" << endl;
    cout << "Output: ";
    for(int i : sol.twoSum(nums, 6)) {
        cout << i << " ";
    }
    cout << endl;

    // example 3
    nums = { 3, 3 };
    cout << "Input: nums = [3, 3], target = 6" << endl;
    cout << "Output: ";
    for(int i : sol.twoSum(nums, 6)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}