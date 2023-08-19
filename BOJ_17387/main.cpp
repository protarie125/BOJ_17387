#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

ll cross(ll x, ll y, ll p, ll q) {
	const auto val = x * q - y * p;
	if (0 == val) {
		return 0;
	}

	return 0 < val ? 1 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll v1, u1, v2, u2;
	cin >> v1 >> u1 >> v2 >> u2;

	if ((x1 == v1 && y1 == u1) ||
		(x1 == v2 && y1 == u2) ||
		(x2 == v1 && y2 == u1) ||
		(x2 == v2 && y2 == u2)) {
		cout << 1;
		return 0;
	}

	ll z1;
	{
		const auto dx = x2 - x1;
		const auto dy = y2 - y1;
		const auto p1 = v1 - x1;
		const auto q1 = u1 - y1;
		const auto p2 = v2 - x1;
		const auto q2 = u2 - y1;

		const auto k1 = cross(dx, dy, p1, q1);
		const auto k2 = cross(dx, dy, p2, q2);

		z1 = k1 * k2;
		if (0 < z1) {
			cout << 0;
			return 0;
		}
	}

	ll z2;
	{
		const auto dv = v2 - v1;
		const auto du = u2 - u1;
		const auto p1 = x1 - v1;
		const auto q1 = y1 - u1;
		const auto p2 = x2 - v1;
		const auto q2 = y2 - u1;

		const auto k1 = cross(dv, du, p1, q1);
		const auto k2 = cross(dv, du, p2, q2);

		z2 = k1 * k2;
		if (0 < z2) {
			cout << 0;
			return 0;
		}
	}

	if (0 == z1 && 0 == z2) {
		if (x2 < x1) {
			swap(x1, x2);
		}

		if (v2 < v1) {
			swap(v1, v2);
		}

		if (x2 < v1 || v2 < x1) {
			cout << 0;
			return 0;
		}

		if (y2 < y1) {
			swap(y1, y2);
		}

		if (u2 < u1) {
			swap(u1, u2);
		}

		if (y2 < u1 || u2 < y1) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}