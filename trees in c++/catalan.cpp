#include <iostream>
using namespace std;

int factorial(int num) {
    long long fact = num;
    while(--num) {
        fact *= num;
    }
    return fact;
}

int main() {
    int n;
    cout << "Enter the number of nodes: " ;
    cin >> n;

    cout << "Number of different trees formed are(unlabeled): ";
    cout << (factorial(2*n)/(factorial(n)*factorial(n))) / (n+1);

    cout << "\nNumber of different trees formed are(labeled): ";
    cout << ((factorial(2*n)/(factorial(n)*factorial(n))) / (n+1))*factorial(n);


}