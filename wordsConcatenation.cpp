using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
    public:
        static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
            vector<int> resultIndices;
            unordered_map<string, int> wordsMap;

            for (auto word: words) {
                wordsMap[word]++;
            }

            int wordsCount = words.size();
            int wordsLength = words[0].length();
            
            for (int i = 0; i < str.length() - wordsCount*wordsLength; i++) {
                unordered_map<string, int> wordsSeen;
                for (int j = 0; j < wordsCount; j++) {
                    int nextWordIndex = i + j*wordsLength;
                    string word = str.substr(nextWordIndex, wordsLength);
                    if(wordsMap.find(word) == wordsMap.end()) {
                        break;
                    }
                    wordsSeen[word]++;

                    if(wordsSeen[word] > wordsMap[word]) {
                        break;
                    }

                    if (j+1 == wordsCount) {
                        resultIndices.push_back(i);
                    }
                }
            }
            return resultIndices;
        }
};

int main (int argc, char *argv[]) {
    vector<int> result = WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}