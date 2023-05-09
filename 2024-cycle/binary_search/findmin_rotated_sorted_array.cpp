class Solution {
public:
    int findMin(std::vector<int>& nums) {
        //check mid
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            int curMid = nums[mid];
            int curLeft = nums[left];
            int curRight = nums[right];
            //std::cout << "left " << left << std:: endl;
            //std::cout << "right " << right << std:: endl;
            //std::cout << "mid " << mid << std:: endl;
            if(left == right - 1) {
                return std::min(curLeft, curRight);
            }
            //we never need to check for equal values since they are unique
            if(curLeft < curMid) {
                if(curMid < curRight) {
                    return curLeft;
                } else { //curRight < curMid
                    left = mid + 1;
                }
            } else { //curLeft > curMid
                right = mid;
                left += 1;
            }
        }
        return nums[left];
    }
};