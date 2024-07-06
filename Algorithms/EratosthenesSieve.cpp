#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define btoe(x) (x).begin(), (x).end()
#define pb push_back
#define print(x) cout << x << endl

const int INF = 1e9;
const int MOD = 1e9 + 7;

/**
 * DATE: 2024.07.04
 * INTUITION:
 * 
 * TC: O(nloglogn)
 * SC: 
 * 
 * TOIMPROVE: 
 */
vector<int> primeSieve(ll n) {
    vector<bool> primes(n+1, 1); // mark all as primes
    primes[0] = 0; primes[1] = 0;
    ll end = (ll) ceil( sqrt(n) );
    
    for (ll i=2; i<=end; i++) {
        if (primes[i]) {
            for (int j=i*i; j<=n; j+=i)
                primes[j] = 0;
        }
    }
    vector<int> ans;
    for (int i=0; i<=n; i++) {
        if (primes[i]) ans.pb(i);
    }
    return ans;
}

int main() {
    vector<int> primes(primeSieve(10));

    for (const auto &p : primes)
        print(p);
}