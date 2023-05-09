#define xDEBUG

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sorting each string approach
        if(strs.size() == 0) {
            std::vector <std::vector < std::string>> out;
            return out;
        } else if(strs.size() == 1) {
            std::vector <std::vector < std::string>> out;
            std::vector<std::string> onlyWord;
            onlyWord.push_back(strs[0]);
            out.push_back(onlyWord);
            return out;
        }
        
        std::vector<std::tuple<std::string, std::string>> sortedstrs; //sorted val first, original second
        std::vector<std::string> strsCopy = strs;
        
        for(std::string s : strsCopy) {
            std::tuple<std::string, std::string> curTuple;
            std::string curStr = s;
            std::sort(s.begin(), s.end());
            sortedstrs.push_back(make_tuple(s, curStr));
        }
        std::sort(sortedstrs.begin(), sortedstrs.end());
        //we have now sorted each string while remembering its original word, and sorted that vector
        //so the sorted string should be in alphabetical order
    #ifdef DEBUG
        for(std::tuple<std::string, std::string> curTuple : sortedstrs) {
            std::cout << get<0>(curTuple) << endl;
        }
    #endif    
        //now we need to group by anagram
        std::vector <std::vector < std::string>> out;
        std::vector <std:: string> curGroup; //current anagram group
        std::string prevWord = get<0>(sortedstrs[0]);
        std::string prevWordUnsorted = get<1>(sortedstrs[0]);
        curGroup.push_back(prevWordUnsorted);    
        for(int i = 1; i < sortedstrs.size(); ++i) {
            std::string curWord = get<0>(sortedstrs[i]);
            std::string curWordUnsorted = get<1>(sortedstrs[i]);
            
            if(curWord != prevWord) {
                out.push_back(curGroup);
                curGroup.clear();
                prevWord = curWord; //if the words are different, push the current group of anagrams, then clear to start the next
            }

            prevWordUnsorted = curWordUnsorted;
            curGroup.push_back(prevWordUnsorted);    
            
        }
        out.push_back(curGroup);
        return out;
    }
};

/* parsing into maps of counts of each character in each word approach
std::map< std::string, std::map <char, int > > charCount; 
        for(std::string curWord : strs) {
            std::map<char, int> curWordCharCount;
            for(char c : curWord) {
                int curCharCount = curWordCharCount.count(c);
                curWordCharCount[c] = curCharCount + 1;
            }
            charCount[curWord] = (curWordCharCount);
        }
*/