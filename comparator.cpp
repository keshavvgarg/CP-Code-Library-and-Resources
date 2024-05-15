// https://codeforces.com/problemset/problem/1970/A1


// In C++, comparator should return false if its arguments are equal.
// https://codeforces.com/blog/entry/72525
bool comp(pair<int, int> pair1, pair<int, int> pair2) {
    if(pair1.first < pair2.first) return true;
    else if(pair1.first > pair2.first) return false;
    else return pair1.second > pair2.second;
}
 
void solve() {
    string s;
    cin >> s;
 
    int n = s.size();
 
    vector<pair<int, int>> vect(n); // balance, index
 
    int balance = 0;
    fl(n) {
        vect[i] = {balance, i};
        balance += s[i] == '(';
        balance -= s[i] == ')';
    }
    
    sort(vect.begin(), vect.end(), comp);
 
    fl(n) cout << s[vect[i].second];
}
