#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321
#define ll long long
#define endl "\n"
using namespace std;

int n;
struct Work {
	int s, e;
	bool operator<(const Work& rhs) const {
		return e < rhs.e;
	}
};
priority_queue<int, vector<int>, greater<int>> pq;
vector<Work> v;

int main()
{
	fastip; sws;

	cin >> n;
	v.resize(n);
	for (auto& e : v) {
		cin >> e.s >> e.e;
	}
	sort(v.begin(), v.end());
	pq.push(0);
	for (const auto& e : v) {
		auto now = pq.top(); pq.pop();
		if (e.s < now) {
			pq.push(e.e);
		}
		else {
			now = e.e;
		}
		pq.push(now);
	}
	cout << pq.size();
}