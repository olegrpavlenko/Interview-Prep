#define xDEBUG

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector < std::tuple <int, int> > frequencyVector;
        std::map < int, int > frequencyMap;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int numCount = frequencyMap.count(num);
            if(!numCount) {
                frequencyMap[num] = 0;
            }
#ifdef DEBUG 
            std::cout << "updating num " << num << " with freq " << numCount << std::endl;
#endif
            frequencyMap[num] = frequencyMap[num] + 1; 
        }
        for(auto const& i : frequencyMap) {
            int num = i.first;
            int freq = i.second;
            frequencyVector.push_back(make_tuple(freq, num));
#ifdef DEBUG 
            std::cout << "added num " << num << " with freq " << freq << std::endl;
#endif
        }
        std::sort(frequencyVector.begin(), frequencyVector.end());
        std::vector <int> out;
#ifdef DEBUG
        std::cout << "size: " << frequencyVector.size() - 1 
        << "lower bound: " << (frequencyVector.size() - 1) - k << std::endl;
#endif
        for(int i = frequencyVector.size() - 1; i > ((int)frequencyVector.size() - 1) - k; --i) {
            out.push_back(get<1>(frequencyVector[i]));
        }
        return out;
    }
};