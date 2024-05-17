/*
took 21 mins
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> v;

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
		int n;
		cin >> n;
		int ans = 0;
		
		v.clear();
		vector<int> vtmp(n);
		for (int i = 0; i < n; i++) {
			v.push_back(vtmp);
		}

		string tmp;
		for(int i =0; i<n; i++){
			cin >> tmp;
			for (int j = 0; j < n; j++) {
				v[i][j] = int(tmp[j] - '0');
			}
		}

		for (int a = 0; a < n / 2; a++) {
			for (int i = n / 2 - a; i <= n / 2 + a; i++) {
				ans += v[a][i];
				ans += v[n - 1 - a][i];
			}
		}

		for (int i = 0; i < n; i++) {
			ans += v[n / 2][i];
		}

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
