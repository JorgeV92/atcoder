#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A, B; cin >> A >> B;
    string nine = "Nine";
    string nein = "Nein";
    if ((A + B) == 9 || 
        (A - B) == 9 ||
        (A * B) == 9 || 
        A  == 9 * B) {
        cout << nine << '\n';
    } else {
        cout << nein << '\n';
    }
    return 0;
}