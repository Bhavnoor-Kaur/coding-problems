using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

// given an array, where character represents fruits, you have two baskets, goal is to put max number of fruits in each basket, each  basket can have only one type of fruit
// can start with any fruit, but once you have started, you cannot skip a fruit.
// Time Complexity: O(N + N) = O(N)
// Space Complexity: O(1) as there can be max of three types of fruits stored in the map
template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}
 
class MaxFruitCountOf2Types {
    public:
        static int findMaxFruits(const vector<char>& arr) {
            int maxCount = 0;
            int start = 0;

            unordered_map<char, int> fruitCount;

            for (int end = 0; end < arr.size(); end ++) {
                fruitCount[arr[end]]++;

                while (fruitCount.size() > 2) {
                    fruitCount[arr[start]]--;
                    if (fruitCount[arr[start]] == 0) {
                        fruitCount.erase(arr[start]);
                    };
                    start++;
                };

                maxCount = max(maxCount, end - start + 1);

            };

            return maxCount;
        }
};

int main() {
    cout << "Maximum Number of Fruits: " << MaxFruitCountOf2Types::findMaxFruits(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
    cout << "Maximum Number of Fruits: " << MaxFruitCountOf2Types::findMaxFruits(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}