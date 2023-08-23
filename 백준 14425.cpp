#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, M;
int cnt = 0;
set<string> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		s.insert(temp);
	}

	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		
		if (s.find(temp) != s.end())
			cnt++;
	}

	cout << cnt;

	return 0;
}