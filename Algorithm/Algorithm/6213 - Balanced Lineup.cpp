#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define inf 987654321
using namespace std;

int n, m;

int min_init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(min_init(arr, tree, node * 2, start, mid), min_init(arr, tree, node * 2 + 1, mid + 1, end));
}

int max_init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = max(max_init(arr, tree, node * 2, start, mid), max_init(arr, tree, node * 2 + 1, mid + 1, end));
}

int min_find(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return inf + inf;

	if (left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return min(min_find(tree, node * 2, start, mid, left, right), min_find(tree, node * 2 + 1, mid + 1, end, left, right));
}

int max_find(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return max(max_find(tree, node * 2, start, mid, left, right), max_find(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	std::cin.tie(nullptr);  std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<long long> arr(n);
	vector<long long> minsegtree(n * 4);
	vector<long long> maxsegtree(n * 4);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	min_init(arr, minsegtree, 1, 0, n - 1);
	max_init(arr, maxsegtree, 1, 0, n - 1);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << max_find(maxsegtree, 1, 0, n - 1, a - 1, b - 1)  - min_find(minsegtree, 1, 0, n - 1, a - 1, b - 1) << endl;
	}
}