using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubString {
    public:
        static string findSubString(const string&str, const string &pattern) {
            int start = 0;
            int matched = 0;
            int minLength = str.length() + 1;
            int subStrStart = 0;

            unordered_map<char, int> charFrequencyMap;
            for (auto chr : pattern) {
                charFrequencyMap[chr]++;
            }

            for (int end = 0; end < str.length(); end++) {
                char right = str[end];
                if (charFrequencyMap.find(right) != charFrequencyMap.end()) {
                    charFrequencyMap[right]--;
                    if(charFrequencyMap[right] >= 0) {
                        matched++;
                    }
                }

                while (matched == pattern.length()) {
                    if(minLength > end - start + 1) {
                        minLength = end - start + 1;
                        subStrStart = start;
                    }

                    char left = str[start++];
                    if (charFrequencyMap.find(left) != charFrequencyMap.end()) {
                        if (charFrequencyMap[left] == 0) {
                            matched--;
                        }
                        charFrequencyMap[left]++;
                    }
                }
            }

            return minLength > str.length() ? "": str.substr(subStrStart, minLength);
        }
};

int main(int argc, char *argv[]) {
    cout << MinimumWindowSubString::findSubString("aabdec", "abc") << endl;
    cout << MinimumWindowSubString::findSubString("abdabca", "abc") << endl;
    cout << MinimumWindowSubString::findSubString("adcad", "abc") << endl;
}