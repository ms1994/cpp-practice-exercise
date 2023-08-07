#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int score(const vector<int>& dice);
int main()
{

    cout << score({2, 3, 4, 6, 2}) << endl;
    cout << score({2, 4, 4, 5, 4}) << endl;

}
int score(const vector<int>& dice) {
    int sum = 0;
    if (dice.size() == 0) return 0;
    unordered_map <int, int> result;
    for (auto it : dice){
        result[it]++;
        if (result[it] == 3) {
            switch (it){
            case 1:
                sum += 1000;
                result[it] = result[it] % 3;
                break;
            case 2:
                 sum += 200;
                break;
            case 3:
                 sum += 300;
                break;
            case 4:
                sum += 400;
                break;
            case 5:
                sum += 500;
                result[it] = result[it] % 3;
                break;
            case 6:
                sum += 600;
                break;
            }
        }
    }
    if (result.count(1)) sum += result[1]*100;
    if (result.count(5)) sum += result[5]*50;
    return sum;
}
int score2(const std::vector<int>& dice) {
  unsigned cs[7] = {};// otra solucion igual de efectiva y mas simple
  for (auto d : dice)
    cs[d]++;
  return
    cs[1] / 3 * 1000 + cs[6] / 3 * 600 + cs[5] / 3 * 500 +
    cs[4] / 3 * 400 + cs[3] / 3 * 300 + cs[2] / 3 * 200 +
    cs[1] % 3 * 100 + cs[5] % 3 * 50;
}
