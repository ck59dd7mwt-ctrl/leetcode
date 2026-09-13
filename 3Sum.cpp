#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result; // вектор для хранения найденных троек
    sort(nums.begin(), nums.end()); // сортируем массив по возрастанию для того, чтобы решать через two pointers
    int sum;

    for(int i = 0; i < nums.size(); i++){
        
        if(i > 0 && nums[i] == nums[i - 1]) continue; // пропускаем одинаковые значения i, чтобы не получать одинаковые тройки
        int j = i + 1; // left
        int k = nums.size() - 1; // right

        while(j < k){
            sum = nums[i] + nums[j] + nums[k]; // сумма трех чисел

            if(sum == 0){
                result.push_back({nums[i], nums[j], nums[k]}); // добавляем найденную тройку в результат
                j++;
                while(j < k && nums[j] == nums[j - 1]) { // пропускаем одинаковые значения left
                    j++;
                }
                k--;
                while(k > j && nums[k] == nums[k + 1]) { // пропускаем одинаковые значения right
                    k--;
                }
            } else if(sum < 0) {
                j++; // сумма слишком маленькая, двигаем left вправо
            } else {
                k--; // сумма слишком большая, двигаем right влево
            }
        }
    }

    return result; // возвращаем все найденные тройки
}

int main() {
    vector<int> nums = {-2, 0, 0, 0, 2, 2};
    vector<vector<int>> result = threeSum(nums);

    for(auto triple : result) {
        cout << triple[0] << ", " << triple[1] << ", " << triple[2] << endl;
    }

    return 0;
}