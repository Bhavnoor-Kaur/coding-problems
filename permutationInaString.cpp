using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
    public:
        static string findPermutation( const string &str, const string &pattern) {
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
                    return "true";
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
            return "false";
        }
};

int main(int argc, char *argv[]) {
    cout << StringPermutation::findPermutation("oidbcaf", "abc" )<< endl;
    cout << StringPermutation::findPermutation("odicf", "dc" )<< endl;
    cout << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx" )<< endl;
    cout << StringPermutation::findPermutation("aaacb", "abc" )<< endl;
}