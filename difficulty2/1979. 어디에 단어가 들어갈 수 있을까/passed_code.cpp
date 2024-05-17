/*
took 13mins
*/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;
int n, k;

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
		cin >> n >> k;
		vector<int> vtmp(n);
		
		//input
		for (int i = 0; i < n; i++) {
			v.push_back(vtmp);
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}

		//output
		int row, col;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			row = 0;
			col = 0;

			for (int j = 0; j < n; j++) {
				if (v[i][j] == 1) {
					row++;
				}
				else {
					if (row == k) ans++;
					row = 0;
				}
				if (v[j][i] == 1) {
					col++;
				}
				else {
					if (col == k) ans++;
					col = 0;
				}
			}
			if (row == k) ans++;
			if (col == k) ans++;
		}

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
