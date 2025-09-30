#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Custom gcd function
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Helper function to calculate product modulo MOD
long long modProduct(const vector<int>& subset) {
    long long result = 1;
    for (int num : subset) {
        result = (result * num) % MOD;
    }
    return result;
}

// Main solving function
int solveUnitGcdSubsets(const vector<int>& arr) {
    int n = arr.size();
    int totalWays = 0;

    for (int mask = 1; mask < (1 << n) - 1; ++mask) {
        vector<int> subset1, subset2;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                subset1.push_back(arr[i]);
            else
                subset2.push_back(arr[i]);
        }

        long long prod1 = modProduct(subset1);
        long long prod2 = modProduct(subset2);

        if (gcd(prod1, prod2) == 1)
            totalWays = (totalWays + 1) % MOD;
    }

    return totalWays;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        int result = solveUnitGcdSubsets(arr);
        cout << result << endl;
    }

    return 0;
}