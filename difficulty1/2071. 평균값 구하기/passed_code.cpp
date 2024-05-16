/*
took 4mins
*/
#include<iostream>
using namespace std;

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
		int num = 0;
		int tmp;
		for (int i = 0; i < 10; i++) {
			cin >> tmp;
			num += tmp;
		}
		if (num % 10 < 5) {
			cout << "#" << test_case << " " << num / 10 << "\n";
		}
		else {
			cout << "#" << test_case << " " << num / 10 + 1 << "\n";
		}
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
