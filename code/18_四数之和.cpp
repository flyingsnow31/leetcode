class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int a = 0; a < size - 3; a++) {
            if(a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            if((long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) {
                break;
            }
            if((long)nums[a] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) {
                continue;
            }
            for(int b = a + 1; b < size - 2; b++) {
                if(b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                if((long)nums[a] + nums[b + 1] + nums[b + 2] + nums[b] > target) {
                    break;
                }
                if((long)nums[a] + nums[b] + nums[size - 1] + nums[size - 2] < target) {
                    continue;
                }
                int c = b + 1, d = size - 1;
                while(c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    printf("%d %d %d %d\n", nums[a], nums[b], nums[c], nums[d]);
                    if(sum == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(c < d && nums[c] == nums[c + 1]) {
                            c++;
                        }
                        c++;
                        while(c < d && nums[d] == nums[d - 1]) {
                            d--;
                        }
                        d--;
                    }
                    else if (sum < target) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};