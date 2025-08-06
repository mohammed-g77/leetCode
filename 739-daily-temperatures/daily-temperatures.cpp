class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temps) {
    stack<int> st;
    int n = temps.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temps[i] > temps[st.top()]) {
            int idx = st.top(); st.pop();
            res[idx] = i - idx;
        }
        st.push(i);
    }
    return res;
}

};