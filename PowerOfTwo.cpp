#include<iostream>

using namespace std;

class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if(n > 0 && (n & (n-1))==0){
                return true;
            } else {
                return false;
            }
        }
    };

int main(){
    int num = 2;

    Solution solution;

    if(solution.isPowerOfTwo(num)) {
        cout << "True";
    } else {
        cout << "False";
    }
}