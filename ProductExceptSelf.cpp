#include <iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> answer(nums.size()); //массив для ответа с длиной данного
    
            for(int i = 0; i < nums.size(); i++){//идем с левого конца перемножая все числа левее текущего
                if(i>0){
                answer[i] = nums[i-1] * answer[i-1]; 
                } else {
                answer[i] = 1;//первое число записываем как 1, на произведение не влияет
                }   
            }
            int after = 1;
            for(int i = nums.size()-1; i >= 0; i--){//идем с правого конца, домножая на все числа справа, уже имеющийся массив
                answer[i] *= after;
                after *= nums[i];
            }
            return answer;
        }
    };

int main(){
    vector<int> nums = {2, 3, 4, 5};

    Solution solution;
    vector<int> answer = solution.productExceptSelf(nums);

    for(const auto& k : answer) {
        cout << k << " ";
    }
    cout << endl;
}