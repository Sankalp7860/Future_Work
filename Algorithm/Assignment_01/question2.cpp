#include <iostream>
#include <vector>
using namespace std;

vector<int> memo(1000);

int calculateLog2(int n) {
    int result = -1;
    while (n > 0) {
        n >>= 1;
        result++;
    }
    return result;
}

int calculateMaxHeight(int n) {
    memo[0] = 1;
    memo[1] = 2;
    if (n == 1) return 0;
    if (n == 2) return 1;

    for (int i = 2; i < n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + 1;
        if (memo[i] == n) return i;
        if (memo[i] > n && memo[i - 1] < n) return i - 1;
    }
    return 0;
}

int main() {
    int numNodes;

    cout << "Please Enter the number of nodes: ";
    cin >> numNodes;

    int maxHeight = calculateMaxHeight(numNodes);
    int minLogHeight = calculateLog2(numNodes);

    cout << "The maximum height of the tree is: " << maxHeight << endl;
    cout << "The minimum height of the tree is: " << minLogHeight << endl;

    return 0;
}
