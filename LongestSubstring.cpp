#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s = "abcdef";
    int left = 0; //левая граница плавающего окна
    int right = 0; //правая граница
    int maxlength = 0; //храним длину окна самого длинного

    unordered_set<char> k;

    while(right < s.size()) { //пока не дойдем правой граней до конца 
        if(!k.count(s[right])){ //если правой границы нету в нашей подстроке, то мы ее добавляем и двигаем границу правее
            k.insert(s[right]);
            right++;
        } else if(k.count(s[right])){ //если правая граница уже есть в подстроке, то двигаем левую границу до повтора, попутно удаляя символы
            while(k.count(s[right])){
                k.erase(s[left]);
                left++;
            }
            k.insert(s[right]); //после удаления повтора двигаем правую границу, сначала добавиви ее в подстроку
            right++;
        }
        maxlength = max(maxlength, (int)k.size());//после всего сравниваем длину имеющийся подстроки с новой
    }
    cout << maxlength << endl;
}