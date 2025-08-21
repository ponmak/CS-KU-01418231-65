#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

int main(){

    stack<string> bookTitles;

    string line;
    getline(cin, line);
    stringstream ss(line);
    string name;
    while (ss >> name) {
        bookTitles.push(name);
    }

    queue<string> miena, luna;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "M"){
            if (!bookTitles.empty()) {
                miena.push(bookTitles.top());
                bookTitles.pop();
            }
        } else if (cmd == "L"){
            if (!bookTitles.empty()) {
                luna.push(bookTitles.top());
                bookTitles.pop();
            }
        } else if (cmd == "m") {
            if (!miena.empty()) {
                bookTitles.push(miena.front());
                miena.pop();
            }
        } else if (cmd == "l") {
            if (!luna.empty()) {
                bookTitles.push(luna.front());
                luna.pop();
            }
        
        } else if (cmd == "p" || cmd == "P"){
            // miena 
            cout << "Miena's Remaining Book(s) to be read: ";
            if (miena.empty()) {
                cout << "None" << endl;
            } else {
                queue<string> temp = miena;
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
            // luna
            cout << "Luna's Remaining Book(s) to be read: ";
            if (luna.empty()) {
                cout << "None" << endl;
            } else {
                queue<string> temp = luna;
                while (!temp.empty()) {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }

            // bookTitles
            cout << "Remaining Book(s) in the Pile: ";
            if (bookTitles.empty()) {
                cout << "None" << endl;
            } else {
                stack<string> temp = bookTitles;
                vector<string> reverse;
                while (temp.size() != 0) {
                    reverse.push_back(temp.top());
                    temp.pop();
                }

                // cout << reverse.size();

                for (int i = reverse.size() - 1; i > -1; i-- ){
                    cout << reverse[i] << " ";
                }
                cout << endl;
            }

            cout <<  "====================" << endl;
        } else {
            cout << "Input Error" << endl;
            return 0;
        }

    }

    return 0;
}