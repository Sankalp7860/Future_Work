#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";

    int n = num1.size();
    int m = num2.size();

    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string ans;
        for (int i = 0; i < result.size(); i++) {
    int digit = result[i];
        ans += (digit + '0');
    }
    int i = 0;
    while (i < ans.length() && ans[i] == '0') {
        i++;
    }
    if (i == ans.length()) {
        return "0";
    }
    return ans.substr(i);
}

int main() {
    cout << "Please Enter the first number: ";
    string str1;
    cin >> str1;

    cout << "Please Enter the second number: ";
    string str2;
    cin >> str2;

    string ans = multiply(str1, str2);
    cout <<"The multiplied value of 1st number and 2nd number is: "<< ans << endl;

    return 0;
}
