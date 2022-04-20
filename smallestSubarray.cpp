#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Find the smallest subarray with given sum 
// Time Complexity: O(N + N) = O(N)
// Space Complexity: O(1)

class smallestSubarray {
    public:
        static int smallestSubarraySize(const vector<int>&arr, int S) {
            int sum = 0;
            int result = numeric_limits<int>::max();
            int start = 0;
            for (int end = 0; end < arr.size(); end++) {
                sum += arr[end];
                while ( sum >= S ) {
                    result = min(result, end - start + 1);
                    sum -= arr[start];
                    start++;
                }
            }
            return result == numeric_limits<int>::max() ? 0 : result;
        }
};

int main() {
    cout << "Length of Smallest Subarray:" << smallestSubarray::smallestSubarraySize({2, 1, 5, 2, 3, 2}, 7) << endl;
    cout << "Length of Smallest Subarray:" << smallestSubarray::smallestSubarraySize({2, 1, 5, 2, 8}, 7) << endl;
    cout << "Length of Smallest Subarray:" << smallestSubarray::smallestSubarraySize({3, 4, 1, 1, 6}, 8) << endl;
}