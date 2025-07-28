#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> b;
    vector<int> c;

    for(int i=0;i<n;i++){
        if(a[i] %2 == 0){
            c.push_back(a[i]);
        }else{
            b.push_back(a[i]);
        }
    }
    if(b.size() == 0){
        //Copy c to b
        for(int i=c.size()-1;i>=0;i--){
            b.push_back(c[i]);
            c.pop_back();
        }
    }

    if(c.size() == 0){
        sort(b.begin(),b.end());

        int i = b.size()-1;
        while(1){
            c.push_back(b[i]);
            b.pop_back();
            if(b[i] != b[i-1]){
                break;
            }else{
                i--;
            }
        }
    }

    if(b.size() == 0 || c.size() == 0){
        cout<<-1<<"\n";
    }else{
        cout<<b.size()<<" "<<c.size()<<"\n";
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<c.size();i++){
            cout<<c[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}