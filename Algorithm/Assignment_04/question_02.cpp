#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = left+( right-left) / 2;

    int left_majority = findMajorityElement(nums, left, mid);
    int right_majority = findMajorityElement(nums, mid + 1, right);

    int left_count = 0;
    int right_count = 0;
    for (int i = left; i <= right; i++) {
        if (nums[i] == left_majority) {
            left_count++;
        } else if (nums[i] == right_majority) {
            right_count++;
        }
    }

    if (left_count > (right - left + 1) / 2) {
        return left_majority;
    } else if (right_count > (right - left + 1) / 2) {
        return right_majority;
    } else {
        return -1; 
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n) ;;
    cout<<"Enter the Elements of the array";
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int result = findMajorityElement(nums,0,nums.size()-1);
    if (result != -1) {
        cout << "The majority element is " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}
