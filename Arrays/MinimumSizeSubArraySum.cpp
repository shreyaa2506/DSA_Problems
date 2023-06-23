int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
    int left = 0;  // left pointer of the subarray
    int sum = 0;   // current sum of the subarray
    int minLen = INT_MAX;  // minimum subarray length found so far

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return minLen != INT_MAX ? minLen : 0;
    }