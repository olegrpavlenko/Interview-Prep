class Solution {
public:
//recursively hash each index to the product of all indices above it (inclusive)
//then do same for down
//then we form the output
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out; 
        if(nums.size() == 1) {
            out.push_back(nums[0]);
            return out;
        }
        std::unordered_map <int, int> prodAbove;
        std::unordered_map <int, int> prodBelow;
        calcProdAbove(prodAbove, nums, nums.size() - 1, 0);
        calcProdBelow(prodBelow, nums, 0, nums.size() - 1);
        for(int i = 0; i < nums.size(); ++i) {
            //std::cout << "pushing prod " << prodAbove[i - 1] << " * " << prodBelow[i + 1] << std::endl;
            int curProd = prodAbove[i - 1] * prodBelow[i + 1];
            out.push_back(curProd);
        }
        return out;
    }
    //visualizing hashtable as vertical. lower index is at the top, higher index at the bottom
    void calcProdAbove(std::unordered_map <int, int>& prodAbove, std::vector<int>& nums, int i, int limit) {
        if(i == limit) { //check to see if we reached lower limit index
            prodAbove[i] = nums[i];
            prodAbove[i - 1] = 1;
        } else {
            calcProdAbove(prodAbove, nums, i - 1, limit); //-1 to go "up"
            prodAbove[i] = prodAbove[i - 1] * nums[i];
        }
    }

    void calcProdBelow(std::unordered_map <int, int>& prodBelow, std::vector<int>& nums, int i, int limit) {
        if(i == limit) { //check to see if we reached upper limit index
            prodBelow[i] = nums[i];
            prodBelow[i + 1] = 1;
        } else {
            calcProdBelow(prodBelow, nums, i + 1, limit); //+1 to go "down"
            prodBelow[i] = prodBelow[i + 1] * nums[i];
        }
    }
};



