#include<iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;

    int num;
    while (cin >> num) {
        vec.push_back(num);
    }
    int target = vec.back();

    int left = 0, right = vec.size() - 2, round = 0;

    bool found = false;
    while (left <= right){
        round++;
        int mid = left + (right - left) / 2;

        if (vec[mid] == target){
            found = true;
            break;
        }

        if (vec[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found)
        cout << "Present - " << round;
    else
        cout << "Absent";

    return 0;
}