/*
correct: 12 out of 15 test cases
*/

#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> v;
vector<bool> visited;
int trial;
int ans;
int ideal;

bool compare(int a, int b) {
	return a > b;
}

int get_number(vector<int> vv) {
	int num = 0;
	for (int i = 0; i < vv.size(); i++) {
		num += vv[i];
		num *= 10;
	}
	return num /= 10;
}

void get_ideal(vector<int> vv) {
	sort(vv.begin(), vv.end(), compare);
	ideal = get_number(vv);
}

void dfs(int time, vector<int> vv) {
	if (ans == ideal) return;
	if (time == trial) {
		int num;
		num = get_number(vv);
		if (ans < num) ans = num;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			swap(vv[i], vv[j]);
			dfs(time + 1, vv);
			swap(vv[i], vv[j]);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//init
		v.clear();
		int tmp;
		stack<int> s;
		visited.clear();

		//input
		cin >> tmp >> trial;
		ans = tmp;
		while (tmp) {
			s.push(tmp % 10);
			tmp /= 10;
		}
		while (s.size()) {
			v.push_back(s.top());
			s.pop();
		}
		visited.resize(v.size() - 1, false);

		//output
		get_ideal(v);
		if (v.size() < trial) {
			int check;
			if (v.size() % 2 == 1) {
				check = v.size() / 2 + 1;
			}
			else {
				check = v.size() / 2;
			}
			if ((trial - check) % 2 == 1) {
				int a, b;
				a = ideal % 10;
				ideal /= 10;
				b = ideal % 10;
				ideal /= 10;
				ideal *= 10;
				ideal += a;
				ideal *= 10;
				ideal += b;
			}
			cout << "#" << test_case << " " << ideal << "\n";
		}
		else {
			dfs(0, v);
			cout << "#" << test_case << " " << ans << "\n";
		}
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
