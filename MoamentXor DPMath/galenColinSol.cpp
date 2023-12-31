#include "bits/stdc++.h"
using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

/*
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks
*/

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

typedef long long ll;
// typedef int ll;
// #pragma warning("int")

typedef long double lld;
typedef unsigned long long ull;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

// #include <atcoder/all>
// using namespace atcoder;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}

	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	bool __factorials_generated__ = 0;
	void gen_factorial(ll n) {
		__factorials_generated__ = 1;
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
		if (k < 0 || n < k) return 0;
		ll den = (ifact[k] * ifact[n - k]) % mod;
		return (den * fact[n]) % mod;
	}
}

using namespace modop;

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16813;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;



void solve(int tc = 0) {
	cin >> n >> k;

	if (n % 2 == 1) {
		ll ans = 1;
		for (ll i = 0; i < n; i += 2) {
			ans = (ans + nck(n, i)) % mod;
		}
		ans = mpow(ans, k);
		cout << ans << '\n';
	} else {
		ll eq = 0;
		for (ll i = 0; i < n; i += 2) {
			eq = (eq + nck(n, i)) % mod;
		}

		ll ans = 0;
		for (ll i = 0; i <= k; i++) {
			ll cur = 1;
			cur = (cur * mpow(eq, i)) % mod;

			if (i < k - 1) {
				cur = (cur * mpow(2, n * (k - i - 1))) % mod;
			}
			ans = (ans + cur) % mod;
		}
		cout << ans << '\n';
	}
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif

	send help

	#ifndef galen_colin_local
		// usaco("evacuation");
	#endif

	// usaco("cowland");

	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);

	cout << setprecision(15) << fixed;

	gen_factorial(3e5);

	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);

	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}
