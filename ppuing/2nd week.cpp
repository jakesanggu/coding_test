#include <iostream>

using namespace std;

#define MAX_ROW 50
#define MAX_COL 50

int arr[MAX_ROW][MAX_COL]; //t일때 먼지
int next_arr[MAX_ROW][MAX_COL]; //t+1일때 먼지
int directions[MAX_ROW][MAX_COL]; //각 위치에서 이동할 수 있는 방향을 저장할 배열

typedef pair<int, int> pos;
int row, col, time;
int dust;

int main()
{
	// 배열크기 입력 받기
	cin >> row;
	cin >> col;
	cin >> time;

	// 배열 입력 받기
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	int direction = 0;

	////////////////////////////////////// 공기청정기 위치 파악
	pos top_pos(-1, 0);
	pos bottom_pos(-1, 0);

	for (int i = 0; i < row; i++)
	{
		if (arr[i][0] == -1)
		{
			if (top_pos.first < 0)
				top_pos.first = i;
			if (top_pos.first > 0)
				bottom_pos.first = i;
		}
	}

	for (int t = 0; t < time; t++)
	{
		////////////////////////////////////// 확산
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				direction = 0;

				if (arr[i][j] == -1)
					continue;

				if (i - 1 >= 0 && arr[i - 1][j] != -1)
					direction++;
				if (j - 1 >= 0 && arr[i][j - 1] != -1)
					direction++;
				if (i + 1 < row && arr[i + 1][j] != -1)
					direction++;
				if (j + 1 < col && arr[i][j + 1] != -1)
					direction++;

				if (i - 1 >= 0 && arr[i - 1][j] != -1)
					next_arr[i - 1][j] += arr[i][j] / 5;
				if (j - 1 >= 0 && arr[i][j - 1] != -1)
					next_arr[i][j - 1] += arr[i][j] / 5;
				if (i + 1 < row && arr[i + 1][j] != -1)
					next_arr[i + 1][j] += arr[i][j] / 5;
				if (j + 1 < col && arr[i][j + 1] != -1)
					next_arr[i][j + 1] += arr[i][j] / 5;

				next_arr[i][j] += arr[i][j] - arr[i][j] / 5 * direction;
			}
		}
		////////////////////////////////////// 순환

		for (int ii = 0; ii < top_pos.first; ii++) //top_pos, 위에서 아래
			next_arr[top_pos.first - ii][0] = next_arr[top_pos.first - ii - 1][0];
		next_arr[top_pos.first][top_pos.second] = -1;

		for (int ii = 0; ii < col - 1; ii++) //top_pos, 오른쪽에서 왼쪽
			next_arr[0][ii] = next_arr[0][ii + 1];
		next_arr[top_pos.first][top_pos.second] = -1;

		for (int ii = 0; ii < top_pos.first; ii++) //top_pos, 아래에서 위쪽
			next_arr[ii][col - 1] = next_arr[ii + 1][col - 1];

		for (int ii = 0; ii < col - 2; ii++) //top_pos, 왼쪽에서 오른쪽
			next_arr[top_pos.first][col - 1 - ii] = next_arr[top_pos.first][col - 1 - ii - 1];
		next_arr[top_pos.first][top_pos.second+1 ] = 0;


		for (int ii = 0; ii < row - bottom_pos.first; ii++) //아래에서 위로
			next_arr[bottom_pos.first + ii][0] = next_arr[bottom_pos.first + ii + 1][0];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < col - 1; ii++) //오른쪽에서 왼쪽으로
			next_arr[row - 1][ii] = next_arr[row - 1][ii + 1];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < row - bottom_pos.first; ii++)
			next_arr[row - ii][col - 1] = next_arr[row - ii - 1][col - 1];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < col - 2; ii++)
			next_arr[bottom_pos.first][col - 1 - ii] = next_arr[bottom_pos.first][col - 1 - ii - 1];
		next_arr[bottom_pos.first][bottom_pos.second + 1] = 0;

		////////////////////////////////////// 결과출력
		dust = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				arr[i][j] = next_arr[i][j];
				next_arr[i][j] = 0;
				if (arr[i][j] != -1)
					dust += arr[i][j];
			}
		//cout << endl;
		//for (int i = 0; i < row; i++)
		//{
		//	for (int j = 0; j < col; j++)
		//		cout << arr[i][j] << ' ';
		//	cout << endl;
		//}
	}
	cout << dust << endl;
	return 0;
}

