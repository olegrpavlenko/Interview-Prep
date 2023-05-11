class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        /* test bin_search
        for(int i = 0; i < nums.size(); ++i) {
            std::cout << "searching for element " << nums[i] << " at index " << i << std::endl;
            int look = bin_search(0, nums.size() - 1, nums[i], nums);
            if(look != -1) {
            std::cout << "found " << nums[i] << " at index " << look << std::endl;                
            } */
        vector<int> curTriple;
        std::vector<std::vector<int>> out;
        int prev_n1 = nums[0] + 1;
        int prev_n2 = nums[1] + 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            int n1 = nums[i];
            if(n1 == prev_n1) {
                continue;
            }
            for(int j = i + 1; j < nums.size(); ++j) {
                int n2 = nums[j];
                if(n2 == prev_n2) {
                    continue;
                }
                int target = 0 - (n1 + n2);
                int k = bin_search(j + 1, nums.size() - 1, target, nums);   
                if(k > -1) {
                    int n3 = nums[k];
                    curTriple.push_back(n1);
                    curTriple.push_back(n2);
                    curTriple.push_back(n3);
                    out.push_back(curTriple);
                    curTriple.clear();
                }
                prev_n2 = n2;
            }
            prev_n1 = n1;
        }
        return out;
    }

    int bin_search(int left, int right, int target, std::vector<int>& nums) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int curMid = nums[mid];
            if(curMid < target) {
                left = mid + 1;
            } else if(curMid > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};