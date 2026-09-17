#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxV = 0;
            int length;
            int left = 0;
            int right = height.size()-1; //решаем через two pointers расстивили указатели
            while(left < right){ //будем выполнять цикл, пока указатели не встретятся
                length = right - left; //длина равно вычету индекса правого указателя минус левый индекс
                if(height[right] <= height[left]){ //если правый столбик меньше, то мы считаем площадь по нему
                    if(maxV < height[right] * length){ //если предыдущий записанный обьем был больше, то ничего не меняем
                        maxV = height[right] * length;
                    } 
                    right--; //двигаем правую границу, так как мы проверили, что она меньше
                } else {
                    if(maxV < height[left] * length){ //сравниваем обьем с предыдущим результатом
                        maxV = height[left] * length;
                    } 
                    left++; //двигаем левую границу, так как мы проверили что правая не меньше
                }
            }
            return maxV;
        }
};

int main() {
    vector<int> height = {4,3,2,1,4};

    Solution solution;
    cout << solution.maxArea(height) << endl;;
}