#include <iostream>
#include <vector>
#include <string>

// base: till end of the string
// choice: take or not take
// constraints: minimize the entire thingy
// backtrack

using namespace std;

void backtrack(vector<int>& nums, int target, int idx, int currSum, vector<int>& path, vector<vector<int>>& res) {
    if (idx == nums.size()){
        if(currSum == target)
            res.push_back(path);
        return;
    }

    // include
    path.push_back(nums[idx]);
    backtrack(nums, target, idx+1, currSum + nums[idx], path, res);
    path.pop_back();

    // exclude
    backtrack(nums, target, idx+1, currSum, path, res);

}

vector<vector<int>> subsetSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, target, 0, 0, path, res);
    return res;
}


int main() {
    vector<int> nums = {2, 4, 6, 10};
    int target = 16;
    auto res = subsetSum(nums, target);
    for (auto& subset : res) {
        for (int x : subset) cout << x << " ";
        cout << "\n";
    }
}
