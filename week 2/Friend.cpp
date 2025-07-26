// 6710405427 
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int character_num;

    cin >> character_num;

     // Miena input
    vector<float> Miena_power_up(4); // index, atk_multi, def_multi, duration
    vector<vector<int>> Miena_gundam(character_num, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        cin >> Miena_power_up[i];
    }

    // Input Miena Gundam stats
    for (int i = 0; i < character_num; i++) {
        string name;
        cin >> name;
        for (int j = 0; j < 4; j++) {
            cin >> Miena_gundam[i][j];
        }
    }

    // Luna input
    vector<float> Luna_power_up(4);
    vector<vector<int>> Luna_gundam(character_num, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        cin >> Luna_power_up[i] ;
    }

    for (int i = 0; i < character_num; i++) {
        string name;
        cin >> name;
        for (int j = 0; j < 4; j++) {
            cin >> Luna_gundam[i][j];
        }
    }

    int turn = 1;
    int energy_luna = 0;
    int energy_miena = 0;

    // Miena gundam index
    int miena_gundam_index = 0;
    // Luna gundam index
    int luna_gundam_index = 0;

    bool is_miena = true;
    // game loop
    while (true){

        // Miena's turn
        int current_atk_miena = Miena_gundam[miena_gundam_index][1];
        int current_def_miena = Miena_gundam[miena_gundam_index][2];

        // Luna's turn
        int current_atk_luna = Luna_gundam[luna_gundam_index][1];
        int current_def_luna = Luna_gundam[luna_gundam_index][2];


        if (turn % 2 != 0){
            // Miena's turn
            if (miena_gundam_index == (int)Miena_power_up[0] && Miena_power_up[3] > 0){
                current_atk_miena *= Miena_power_up[1];
                Miena_power_up[3]--;
            }

            if (luna_gundam_index == (int)Luna_power_up[0] && Luna_power_up[3] > 0){
                current_def_luna *= Luna_power_up[2];
            }

            // Miena attack Luna
            if (energy_miena == Miena_gundam[miena_gundam_index][3]) {
                current_atk_miena *= 2;
            }

            //cout << "Miena " << current_atk_miena << " " << current_def_luna << endl;

            int damage_to_luna = pow(current_atk_miena, 2) / current_def_luna;
            Luna_gundam[luna_gundam_index][0] -= damage_to_luna;

            if (energy_miena < Miena_gundam[miena_gundam_index][3]) {
                energy_miena++;
            } else {
                energy_miena = 0;
            }   

            // log 
            //cout << "Miena " << turn << " " << damage_to_luna << " Luna hp " << Luna_gundam[luna_gundam_index][0] << endl;
        } else {
            // Luna's turn
            if (luna_gundam_index == (int)Luna_power_up[0] && Luna_power_up[3] > 0){
                current_atk_luna *= Luna_power_up[1];
                Luna_power_up[3]--;
            }

            if (miena_gundam_index == (int)Miena_power_up[0] && Miena_power_up[3] > 0){
                current_def_miena *= Miena_power_up[2];
            }

            // Luna attack Miena
            if (energy_luna == Luna_gundam[luna_gundam_index][3]) {
                current_atk_luna *= 2;
            }

            //cout << "Luna " << current_atk_luna << " " << current_atk_miena << endl;

            int damage_to_miena =  pow(current_atk_luna, 2) / current_def_miena;
            Miena_gundam[miena_gundam_index][0] -= damage_to_miena;

            if (energy_luna < Luna_gundam[luna_gundam_index][3]) {
                energy_luna++;
            } else {
                energy_luna = 0;
            }

            // log 
            //cout << "Luna " << turn << " " << damage_to_miena << " Miena hp " << Miena_gundam[miena_gundam_index][0] << endl;
        }

        if((int)Miena_gundam[miena_gundam_index][0] <= 0){
            miena_gundam_index++;
            energy_miena = 0; // Reset energy 
        }

        if((int)Luna_gundam[luna_gundam_index][0] <= 0){
            luna_gundam_index++;
            energy_luna = 0; // Reset energy                                                                                                                              
        }        

        if (miena_gundam_index >= character_num ){
            is_miena = false;
            // cout << "Luna " << turn << endl;
            break;
        } else if (luna_gundam_index >= character_num) {
            is_miena = true;
            // cout << "Miena " << turn << endl;
            break;
        }

        turn++;

        //cout << "-------------------------" << endl;
    }
    
    if (is_miena){
        cout << "Miena is victorious with ";
        if (character_num - miena_gundam_index > 1){
            cout << character_num - miena_gundam_index << " characters left." << endl;
        } else {
            cout << "1 character left." << endl;
        }
    } else {
        cout << "Luna is victorious with ";
        if (character_num - luna_gundam_index > 1){
            cout << character_num - luna_gundam_index  << " characters left." << endl;
        } else {
            cout << "1 character left." << endl;
        }
    }

    if (turn == 1){
        cout << "The battle took 1 turn.";
    } else {
        cout << "The battle took " << turn << " turns.";
    }
    
    return 0;
}