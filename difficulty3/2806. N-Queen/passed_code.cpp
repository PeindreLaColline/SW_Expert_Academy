/*
took around 1 hour
first time that I solved N queen problem
*/
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> v;
vector<bool> col; //true사용가능 false사용불가능(occupied)
int ans = 0;

void bruth(int queen) {
	if (queen == n) {
		ans++;
		return;
	}

	int a;
	int i = queen;

	vector<vector<int>> vv;

	for (int j = 0; j < n; j++) {
		if (col[j] == false) continue;
		if (v[i][j] == 0) {
			v[i][j] = 1;
			col[j] = false;
			
			vv = v;

			//down L
			a = 0;
			while ((i+a <n) && (j-a >=0)) {
				v[i + a][j - a] = -1;
				a++;
			}
		
			//down R
			a = 0;
			while ((i + a < n) && (j + a < n)) {
				v[i + a][j + a] = -1;
				a++;
			}

			bruth(queen + 1);

			v[i][j] = 0;
			col[j] = true;
			v = vv;
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
		cin >> n;
		v.clear();
		vector<int> vtmp(n, 0); //0빈곳 1퀸 -1불가능
		for (int i = 0; i < n; i++) {
			v.push_back(vtmp);
		}
		col.clear();
		col.resize(n, true);

		//output
		bruth(0);
		cout << "#" << test_case << " " << ans << "\n";
		ans = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
