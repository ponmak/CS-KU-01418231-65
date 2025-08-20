#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 20;

struct item{
    string name;
    float x;
    float y;
    float z;
};

int main(){

    vector<item> items(TABLE_SIZE);
    
    int insert_counter = 0;
    while (true){

        string checker;
        cin >> checker;
        
        if (checker == "--------------------"){
            break;
        } else {
            item newItem;
            newItem.name = checker;
            cin >> newItem.x >> newItem.y >> newItem.z;
            items[insert_counter] = newItem;
            insert_counter++;
        }
    }

    vector<string> names;
    string name;
    while(cin >> name;){
        
    }

    for (int i = 0; i < insert_counter; i++) {
        cout << items[i].name << " " << items[i].x << " " << items[i].y << " " << items[i].z << endl;
    }

    return 0;
}