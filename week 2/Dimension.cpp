// 6710405427 : dimension's shift
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double mymin(double a, double b) {
    return (a < b) ? a : b;
}

double mymax(double a, double b) {
    return (a > b) ? a : b;
}

int main(){
 
    int num ;

    cin >> num;

    vector<vector<double>> dimension(num, vector<double>(4));

    for (int i = 0; i < num; i++){
        for (int j = 0; j < 4; j++){
            cin >> dimension[i][j];
        }
    }

    
    double overlapping_area = 0;
    for (int i = 0; i < num; i++){

        double x1 = mymin(dimension[i][0], dimension[i][2]);
        double y1 = mymin(dimension[i][1], dimension[i][3]);
        double x2 = mymax(dimension[i][0], dimension[i][2]);
        double y2 = mymax(dimension[i][1], dimension[i][3]);
        
        for (int j = i + 1; j < num; j++){
            
            double x3 = mymin(dimension[j][0], dimension[j][2]);
            double y3 = mymin(dimension[j][1], dimension[j][3]);
            double x4 = mymax(dimension[j][0], dimension[j][2]);
            double y4 = mymax(dimension[j][1], dimension[j][3]);

            double x_overlap = mymin(x2, x4) - mymax(x1, x3);
            double y_overlap = mymin(y2, y4) - mymax(y1, y3);

            double area_overlap = 0;
            //cout << x_overlap << " " << y_overlap << endl;
            if (x_overlap > 0 && y_overlap > 0){
                area_overlap = x_overlap * y_overlap;
            }
            overlapping_area = mymax(overlapping_area, area_overlap);
        }
    }

    printf ("%.6f\n", overlapping_area);

    return 0;
}