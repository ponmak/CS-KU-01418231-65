#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int Multiplier(int level) {
    int percent = 0;
    for (int i = 1; i <= level; ++i) {
        if (i <= 5) percent += 10;
        else if (i <= 7) percent += 15;
        else percent += 20;
    }
    return percent;
}

double knapsack(int i,int times, int mana_user, int num, int level[], int element_score[], int mana_cost[]) {

    if (i == num - 1 || times == 0 ) {
        return 0;
    }

    // 20 𝑥 (10 + 10 + 10 + 10 + 10 + 15)% = 13
    double take = 0; 

    if (mana_cost[i] <= mana_user) {
        int percent = Multiplier(level[i]);
        take = element_score[i] * ((double)percent / 100.0) + knapsack(i, times - 1, mana_user - mana_cost[i], num, level, element_score, mana_cost);
        cout << "(!) " <<  take << endl;
    }

    double  not_take = knapsack(i + 1, times, mana_user, num, level, element_score, mana_cost);

    return max(take, not_take);
}


int main(){

    int times, mana_user;
    cin >> times >> mana_user;

    int num;
    cin >> num;
    cin.ignore();

    int level[num];
    string element[num];
    int element_score[num];
    int mana_cost[num];

    for (int i = 0; i < num; ++i) {
        string line, word;
        getline(cin, line);            
        stringstream ss(line);
        vector<string> tokens;

        while (ss >> word) {
            tokens.push_back(word);    
        }

        element[i] = tokens[0];               
        level[i] = stoi(tokens[1]);           
        mana_cost[i] = stoi(tokens.back());   
    }

    for (int i = 0; i < num; ++i) {
        if (element[i] == "F") {
            element_score[i] = 12;
        } else if (element[i] == "A") {
            element_score[i] = 15;
        } else if (element[i] == "W") {
            element_score[i] = 12;
        } else if (element[i] == "E") {
            element_score[i] = 10;
        } else if (element[i] == "L") {
            element_score[i] = 20;
        } else {
            element_score[i] = 20; 
        }
    }


    double  result = knapsack(0, times, mana_user, num, level, element_score, mana_cost);

    cout << result << endl;


    
    for (int i = 0; i < num; ++i) {
        cout << "Element: " << element[i] << ", Level: " << level[i] << ", Mana Cost: " << mana_cost[i] << " " << element_score[i] <<   endl;
    }
    

    return 0; 
}
