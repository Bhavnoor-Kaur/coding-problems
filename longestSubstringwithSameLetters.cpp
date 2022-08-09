using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
    public:
        static int findLength(const string& str, int k) {
            unordered_map<char, int> letterFrequencyMap;
            int maximum = 0;
            int start = 0;
            int maxRepeatCount = 0;

            for (int end = 0; end < str.length(); end++) {
                char right = str[end];
                letterFrequencyMap[right]++;
                maxRepeatCount = max(maxRepeatCount, letterFrequencyMap[right]);

                if (end - start + 1 - maxRepeatCount > k) {
                    char left = str[start];
                    letterFrequencyMap[left]--;
                    start++;
                }

                maximum = max(maximum, end - start + 1);
            }

            return maximum;
        }
};

int main(int argc, char *argv[]) {
    cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
    cout << CharacterReplacement::findLength("abbcb", 1) << endl;
    cout << CharacterReplacement::findLength("abccde", 1) << endl;
}