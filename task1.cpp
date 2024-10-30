#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int prev2 = 1, prev1 = 2, current;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Input:n = ";
    cin >> n;
    cout << "Output: " << climbStairs(n) << endl;
    return 0;
}
//Time Complexity:O(n)
// Space Complexity: O(1)
