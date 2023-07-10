#include<iostream>
#include<queue>

using namespace std;

int relation[101][101];
int visited[101];
int n, m, a, b;
void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b >> m;
	int x, y;
	while (m--) {
		cin >> x >> y;
		relation[x][y] = 1;
		relation[y][x] = 1;
	}
	BFS();
	if (visited[b])
		cout << visited[b];
	else
		cout << -1;
}

void BFS() {
	queue<int> myqueue;
	myqueue.push(a);
	while (!myqueue.empty()) {
		int child = myqueue.front();
		myqueue.pop();
		int tmp = visited[child];
		for (int i = 1; i <= n; i++) {
			if (relation[child][i] && !visited[i]) {
				myqueue.push(i);
				visited[i] = tmp + 1;
			}
		}
	}
}