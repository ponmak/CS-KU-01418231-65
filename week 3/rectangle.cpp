#include <iostream>

using namespace std;

void ref_input(float *width, float *length){
    cin >> *width >> *length;
}

float calculate_area(float width, float length){
    return width * length;
}

void result_show(float area){
    cout << "Area of this rectangle: " << area << endl;
}

int main(){

    float width, length;

    ref_input(&width, &length);
    result_show(calculate_area(width, length));

    // cout << "Width: " << width << ", Length: " << length << endl;

}