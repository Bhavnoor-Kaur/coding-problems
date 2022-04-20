#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Find the length of the longest substring with no more than K distinct characters
// Time Complexity: O(N + N) = O(N)
// Space Complexity: O(K) as we will be storing a maximum of K+1 characters in the hash map

class Substring {
    public:
        static int longestSubstring(const string& givenString, int k) {
            int result = 1;
            int start = 0;
            unordered_map<char, int> freqMap;
            for (int end = 0; end < givenString.size(); end++) {
                char right = givenString[end];
                freqMap[right]++;

                while(freqMap.size() > k) {
                    char left = givenString[start];
                    freqMap[left]--;
                    if (freqMap[left] == 0) {
                        freqMap.erase(left);
                    }
                    start++;
                }
                result = max(result, end - start + 1);
            }

            return result;
        }
};

int main() {
    cout << "Length of the longest SubString: "<< Substring::longestSubstring("araaci", 2) << endl;
    cout << "Length of the longest SubString: "<< Substring::longestSubstring("araaci", 1) << endl;
    cout << "Length of the longest SubString: "<< Substring::longestSubstring("cbbebi", 3) << endl;
}