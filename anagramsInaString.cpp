using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
    public:
        static vector<int> findStringAnagrams(const string &str, const string &pattern) {
            vector<int> resultIndices;

            int start = 0;
            int matched = 0;

            unordered_map<char, int> charFrequencyMap;
            for (auto chr : pattern) {
                charFrequencyMap[chr]++;
            }

            for (int end = 0; end < str.length(); end++) {
                char right = str[end];
                if(charFrequencyMap.find(right) != charFrequencyMap.end()) {
                    charFrequencyMap[right]--;
                    if(charFrequencyMap[right] == 0) {
                        matched++;
                    }
                }

                if (matched == (int)charFrequencyMap.size()) {
                    resultIndices.push_back(start);
                }

                if (end >= pattern.length() - 1) {
                    char left = str[start++];
                    if(charFrequencyMap.find(left) != charFrequencyMap.end()) {
                        if (charFrequencyMap[left] == 0) {
                            matched--;
                        }
                        charFrequencyMap[left]++;
                    }
                }
            }
            return resultIndices;
        }
};

int main(int argc, char *argv[]) {
    auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
    for (auto num : result) {
        cout << num << " " ;
    }
    cout << endl;

    result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
    for (auto num : result) {
        cout << num << " " ;
    }
    cout << endl;
}