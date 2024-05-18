/*
took more than an hour
note: pay attention to index, check range, array direction
*/
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;
	//cin >> T;
	T = 10;

	char arr[8][8];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int leng;
		cin >> leng;
		string s;
		for (int i = 0; i < 8; i++) {
			cin >> s;
			for (int j = 0; j < 8; j++) {
				arr[i][j] = s[j];
			}
		}

		int ans = 0;
		bool check = true;
		//가로줄
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8-leng; j++) {
				check = true;
				//구간체크
				for (int a = 0; a < leng / 2; a++) {
					if (arr[i][j + a] == arr[i][j + leng - a-1]) {
						continue;
					}
					else {
						check = false;
						break;
					}
				}
				if (check == true) ans++;
			}
		}

		//세로줄
		for (int i = 0; i <= 8-leng; i++) {
			for (int j = 0; j < 8; j++) {
				check = true;
				//구간체크
				for (int a = 0; a < leng / 2; a++) {
					if (arr[i + a][j] == arr[i + leng - a - 1][j]) {
						continue;
					}
					else {
						check = false;
						break;
					}
				}
				if (check == true) ans++;
			}
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
