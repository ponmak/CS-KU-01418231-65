// The Journey of the little cow : 6710405427
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
double EPSILON = 1e-9;

int main() {

  int j;
  double k;
  cin >> j >> k;

  int d;
  cin >> d;

  vector<int> n(d);

  // Nutrient
  double p = pow(10, j);
  double Nu = 0;

  int milk = 0;
  int milk_promax = 0;
  for (int i = 0; i < d; i++) {

    cin >> n[i];

    double cow_funmu = 0;
    for (int j = 0; j < n[i]; j++) {
      cow_funmu += p;
    }

    Nu += cow_funmu;
    double uncle_funmu = n[i] * p;
    
    // cout << "(?)" << fabs(cow_funmu - k) << endl;
if (fabs(cow_funmu + uncle_funmu - k) <= EPSILON) {
      milk_promax += 1;
    }

    if ((cow_funmu / k) >= 1 || fabs(cow_funmu - k) <= EPSILON) {
      milk += 1;
    } 
  }

  printf("Milk : %d\nProMax Milk : %d\nNutrient : %.17f\n", milk, milk_promax,
         Nu);

  return 0;
}
