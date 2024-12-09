class Solution {
public:
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<bool> result;
    vector<int> parityChanges(n, 0); //Size n, not n+1

    //Precompute parity changes. This is O(N)
    for (int i = 1; i < n; ++i) {
        parityChanges[i] = parityChanges[i-1] + (nums[i] % 2 != nums[i - 1] % 2); //Correct calculation
    }

    //Process queries. This is O(Q)
    for (const auto& query : queries) {
        int from = query[0];
        int to = query[1];
        if (to >= n) continue; //Handle queries extending beyond nums bounds

        bool isSpecial = true;
        if (to > from) {  //Avoid unnecessary calculation for single-element subarrays.
          isSpecial = (parityChanges[to] - parityChanges[from] == to - from);
        }

        result.push_back(isSpecial);
    }
    return result;
}
};