#include<iostream> 
#include<vector>
using namespace std;
int isOperator(char ch) {
    if(ch == '+' || ch == '*' || ch == '/' || ch == '-'){
        return 1;
    }
    else
    {
        return 0;
    }
}
int evaluate(vector<char> symbol, vector<int> number) {

    for (int i = 0; i < symbol.size(); i++) {
        if (symbol[i] == '*') {
            number[i] = number[i] * number[i + 1];
            number.erase(number.begin() + i + 1);
            symbol.erase(symbol.begin() + i);
            i--;
        } else if (symbol[i] == '/') {
            number[i] = number[i] / number[i + 1];
            number.erase(number.begin() + i + 1);
            symbol.erase(symbol.begin() + i);
            i--; 
        }
    }
    for (int i = 0; i < symbol.size(); i++) {
        if (symbol[i] == '+') {
            number[i] = number[i] + number[i + 1];
            number.erase(number.begin() + i + 1);
            symbol.erase(symbol.begin() + i);
            i--; 
        } else if (symbol[i] == '-') {
            number[i] = number[i] - number[i + 1];
            number.erase(number.begin() + i + 1);
            symbol.erase(symbol.begin() + i);
            i--; 
        }
    }

    return number[0];
}



int main() {
    cout << "Please Enter the infix expression : " <<endl;
    string str1;
    cin >> str1;
    vector<char> symbol;
    vector<int> number;
    int i=0;
    while(i<str1.size()){
        if (isOperator(str1[i]))
            symbol.push_back(str1[i]);
        else {
            int temp = 0;
            int index = i;
            while (index < str1.size() && !isOperator(str1[index])) {
                temp =temp * 10;
                temp =temp+ str1[index] -'0';
                index++;
            }
            number.push_back(temp);
            i = index - 1; 
        }
        i++;
    }
    int ans=evaluate(symbol, number);
    cout << "The output is : " << ans << endl;
    return 0;
}
