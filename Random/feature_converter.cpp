#include <vector>
#include <iostream>
using namespace std;

int convert(vector<int>& trace) {
    int ans = 0;
    for (auto it = trace.begin(); it < trace.cend(); it++) {
        ans = ans * 2 + *it;
    }
    return ans;
}

void helper(vector<int>& ans, vector<int>& trace, int nums[], int pos, int size, int p) {
    if (p == 0) {
        ans.push_back(convert(trace));
        return;
    }

    for (int i = pos; i < size ; i++) {
        trace.push_back(nums[i]);
        helper(ans, trace, nums, i + 1, size, p - 1);
        trace.pop_back();
    }
}

int main(int argc, char const* argv[]) {
    int nums[] = {1, 0, 1, 1, 0};
    int size = 5;
    int p = 3;
    vector<int> ans;
    vector<int> trace;

    helper(ans, trace, nums, 0, size, p);


    for (auto it = ans.begin(); it < ans.cend(); it++) {
        cout << *it << endl;
    }
}
