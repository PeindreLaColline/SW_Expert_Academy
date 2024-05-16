/*
took 17 mins
*/
#include<iostream>
#include<vector>
using namespace std;

int n;

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
		cin >> n;
		vector<vector<int>> v;
		vector<int> tmp(n, 0);
		for (int i = 0; i < n; i++) {
			v.push_back(tmp);
		}

		int x1, x2, y1, y2;
		//x1좌 x2우 y1상 y2하

		x1 = 0;
		x2 = n - 1;
		y1 = 0;
		y2 = n - 1;

		int num = 1;
		while (num <= n * n) {
			//right
			for (int i = x1; i <= x2; i++) {
				v[y1][i] = num;
				num++;
			}
			y1++;
			if (y1 > y2) break;

			//down
			for (int i = y1; i <= y2; i++) {
				v[i][x2] = num;
				num++;
			}
			x2--;
			if (x1 > x2) break;

			//left
			for (int i = x2; i >= x1; i--) {
				v[y2][i] = num;
				num++;
			}
			y2--;
			if (y1 > y2) break;

			//up
			for (int i = y2; i >= y1; i--) {
				v[i][x1] = num;
				num++;
			}
			x1++;
			if (x1 > x2) break;
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
