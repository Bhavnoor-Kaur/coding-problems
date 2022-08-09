using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubString {
    public:
        static int findLength(const string& str) {
            int maxLength = 1;
            int start = 0;

            unordered_map<char, int> indexMap;
            for (int end = 0; end < str.size(); end ++) {
                char right = str[end];

                if (indexMap.find(right) != indexMap.end()) {
                    start = max(start, indexMap[right] + 1);
                }
                indexMap[right] = end;
                
                maxLength = max(maxLength, end - start + 1);
            }

            return maxLength;
        }
};

int main(int argc, char* argv[]) {
    cout << "Length of the longest Substring: " << NoRepeatSubString::findLength("aabccbb") << endl;
    cout << "Length of the longest Substring: " << NoRepeatSubString::findLength("abbbb") << endl;
    cout << "Length of the longest Substring: " << NoRepeatSubString::findLength("abccde") << endl;
}