#include <iostream>
#include <vector>
using namespace std;

// Find the largest sum of a subarray of size K in a given array
// Time Complexity: O(N)
// Space complexity: O(1)
class maxSumSubarrayOfSizeK {
    public:
        static double maxSum(int K, const vector<int>&arr) {
            vector<double> result(arr.size() - K + 1);
            double maxSum = 0;
            double sum = 0;
            int start = 0;
            for (int end = 0; end < arr.size(); end++) {
                sum += arr[end];
                if (end >= K - 1) {
                    if(sum > maxSum) {
                        maxSum = sum;
                    }
                    sum -= arr[start];
                    start++;
                }
            }
            return maxSum;
        };
};


int main() {
    cout <<"Maximum Sum: " << maxSumSubarrayOfSizeK::maxSum(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
    cout <<"Maximum Sum: " << maxSumSubarrayOfSizeK::maxSum(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
