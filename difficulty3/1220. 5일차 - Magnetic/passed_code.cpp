/*
took long time
solution: need to think logically before code
(in tbis case, it was not obligated to count how many times it change the color
so it was much easier)
ps: still there's better and more simple way than this
*/
#include<iostream>
#include<vector>
using namespace std;

int arr[100][100];

int main(int argc, char** argv)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tmp;
		cin >> tmp;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		bool red;
		int ans = 0;
		for (int j = 0; j < 100; j++) {
			red = false;
			int i;
			for (i = 0; i < 100; i++) {
				if (arr[i][j] == 1) {
					red = true;
					ans++;
					break;
				}
			}
			i++;
			for (i; i < 100; i++) {
				if (arr[i][j] == 0) continue;
				else if (arr[i][j] == 1) {
					if (red) {
						continue;
					}
					else {
						red = true;
						ans++;
					}
				}
				else if (arr[i][j] == 2) {
					red = false;
					continue;
				}
			}
		}

		for (int i = 99; i >= 0; i--) {
			for (int j = 99; j >= 0; j--) {
				if (arr[j][i] == 1) {
					ans--;
					break;
				}
				else if (arr[j][i] == 2) break;
			}
		}
		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
