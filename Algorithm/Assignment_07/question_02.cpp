#include <iostream>
#include <vector>
using namespace std;
using namespace chrono;
int MCM_topDown(int i, int j,vector<int> &arr)
{
    if (i == j) return 0;
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM_topDown(i, k, arr) + MCM_topDown(k + 1, j, arr);
        if (steps < mini) mini = steps;
    }



    return mini;
}

int MCM_topDownMemo(int i, int j, vector<vector<int> > &memo,vector<int> &arr)
{
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM_topDownMemo(i, k, memo, arr) + MCM_topDownMemo(k + 1, j, memo, arr);
        if (steps < mini) mini = steps;
    }
    return memo[i][j] = mini;
}





int MCM_dp(vector<int> &arr)
{
    int N = arr.size();
    vector<vector<int> > dp(N,vector<int>(N, 0));
    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i < N - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (steps < dp[i][j])
                {
                    dp[i][j] = steps;
                }
            }
        }
    }
    return dp[1][N - 1];
}

int main(){
    cout << "Enter the array of matrices dimensions : " <<endl;
    cout << "Enter -1 to stop" <<endl;
    vector<int> arr;
    int temp=0;
    while (1)
    {
        cin >> temp;
        if (temp == -1) break;
        arr.push_back(temp);
    }
    int ans1 = MCM_topDown(1, arr.size() - 1, arr);
    cout << "MCM_TopDown     " << ans1 << endl;

    vector<vector<int> > memo(arr.size(), vector<int>(arr.size(), -1));
    int ans2 = MCM_topDownMemo(1, arr.size() - 1, memo, arr);
    cout << "MCM_TopDownMemo " << ans2  << endl;

    int ans3 = MCM_dp(arr);
    cout << "MCM_Dp          " << ans3 << endl;
}