/*
took 18mins
need to pay attention to the input format
*/
#include<iostream>
using namespace std;

int arr[100][100];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	T = 10;

	int tmp;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> tmp;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		int a, b; //가로 세로
		int ans = 0;
		for (int i = 0; i < 100; i++) {
			a = 0;
			b = 0;
			for (int j = 0; j < 100; j++) {
				a += arr[i][j];
				b += arr[j][i];
			}
			if (ans < max(a, b)) ans = max(a, b);
		}
		//대각선
		a = 0;
		b = 0;
		for (int i = 0; i < 100; i++) {
			a += arr[i][i];
			b += arr[100 -1 - i][100 -1 - i];
		}
		if (ans < max(a, b)) ans = max(a, b);	

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
