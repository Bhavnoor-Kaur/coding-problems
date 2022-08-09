using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
    public:
        static int findLength(const vector<int>& arr, int k) {
            int maxLength = 0;
            int start = 0;
            int numZeros = 0;
            int numOnes = 0;

            for (int end = 0; end < arr.size(); end++) {
                if (arr[end] == 0) {
                    numZeros++;
                } 

                if (numZeros > k) {
                    if (arr[start] == 0) {
                        numZeros--;
                    }
                    start++;
                }

                maxLength = max(maxLength, end-start+1);

            }
            return maxLength;
        }
};

int main(int argc, char* argv[]) {
    cout << ReplacingOnes::findLength(vector<int>{0,1,1,0,0,0,1,1,0,1,1}, 2) << endl;
    cout << ReplacingOnes::findLength(vector<int>{0,1,0,0,1,1,0,1,1,0,0,1,1}, 3) << endl;
}