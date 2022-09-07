class Solution_ {   //暴力，超时
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int a = INT_MAX;
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    int tmp = nums[i] + nums[j] + nums[k];
                    if(abs(tmp - target) < a){
                        a = abs(tmp - target);
                        ans = tmp;
                        //cout<<nums[i] <<nums[j]<<nums[k]<<endl;
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {    //双指针 O(n^2)
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int tmp = 1e7;

        auto update = [&](int t){
            if(abs(t - target) < abs(tmp - target)) {
                tmp = t;
            }
        };

        for(int i = 0 ; i < size - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1;
            int k = size - 1;
            while(j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if(t == target)
                    return target;
                if(t > target) {
                    update(t);
                    int k0 = k - 1;
                    while(k0 > j && nums[k0] == nums[k]) k0--;
                    k = k0;
                }
                else {
                    update(t);
                    int j0 = j + 1;
                    while(j0 < k && nums[j0] == nums[j]) j0++;
                    j = j0;
                }
            }
        }
         return tmp;
    }
};