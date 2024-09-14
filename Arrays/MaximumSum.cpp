#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int negative = 0;

        for (int i = 0; i < nums.size(); i++){
            if ( nums[i] < 0 ){
                negative++;
            }
        }

        for (int j = 0; j < min(k, negative); j++){
            nums[j] = nums[j] * -1;
        }
        
        k -= min(k, negative);

        sort(nums.begin(), nums.end());

        for (int m = 0; m < k ; m++){
            nums[0] = -nums[0];
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};