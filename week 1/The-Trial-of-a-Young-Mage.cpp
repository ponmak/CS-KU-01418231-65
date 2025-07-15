#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    int n; cin >> n;

    // array of data
    vector<char> spellTypeArr(n);
    vector<int> levelArr(n);
    vector<string> spellNameArr(n);
    vector<int> costArr(n);

    for (int i = 0; i < n; i++){
        string spellName;
        cin >> spellTypeArr[i] >> levelArr[i] >> spellNameArr[i] >> costArr[i];

        cout << spellTypeArr[i] << levelArr[i] << spellName[i] << costArr[i] << endl;
    }
    


    return 0; }
