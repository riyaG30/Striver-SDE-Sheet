void solve(vector<int> &a, vector<int> &b, vector<int> &ans, int i, int j, int &carry)
{
    // base case
    if (i < 0 && j < 0 && carry == 0)
        return;

    int first = 0, second = 0;
    if (i >= 0)
        first = a[i];
    if (j >= 0)
        second = b[j];

    int sum = first + second + carry;
    int last = sum % 10;
    carry = sum / 10;
    ans.push_back(last);

    solve(a, b, ans, i - 1, j - 1, carry);
    
}

vector<int> findSum(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    solve(a, b, ans, i, j, carry);
    if(carry > 0)
    ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

