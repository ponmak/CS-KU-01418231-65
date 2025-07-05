#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(long int number) {

  vector<bool> prime(number, true);
  prime[0] = prime[1] = false;

  for (long int i = 2; i * i <= number; i++) {
    if (prime[i]) {
      for (long int j = i * i; j <= number; j += i) {
        prime[j] = false;
      }
    }
  }
  
  return prime;
  
}

int main(int argc, char *argv[]) {
  long int number;
  cin >> number;

  if (number < 2) {
    cout << "ERROR!" << endl;
    return 0;
  }

  bool flag = false; 
  vector<bool> primeList = isPrime(number);

  long int count = 0;
  for (long int i = 2; i <= primeList.size(); i++) {
    if (primeList[i]) {
      count++;
      if (i == number) {
        flag = true;
        break;
      }
    }
  }

  if (!flag) {
    cout << "Unrelated" << endl;
    return 0;
  }
  
  if (count % 100 >= 11 && count % 100 <= 13 && flag) {
    cout << count << "th" << endl;
  } else if (count % 10 == 1) {
    cout << count << "st" << endl;
  } else if (count % 10 == 2) {
    cout << count << "nd" << endl;
  } else if (count % 10 == 3) {
    cout << count << "rd" << endl;
  } else {
    cout << count << "th" << endl;
  }
  
  return 0;
}
