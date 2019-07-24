#include <iostream>

using namespace std;

#define MAX_ROW 50
#define MAX_COL 50

int arr[MAX_ROW][MAX_COL]; //t�϶� ����
int next_arr[MAX_ROW][MAX_COL]; //t+1�϶� ����
int directions[MAX_ROW][MAX_COL]; //�� ��ġ���� �̵��� �� �ִ� ������ ������ �迭

typedef pair<int, int> pos;
int row, col, time;
int dust;

int main()
{
	// �迭ũ�� �Է� �ޱ�
	cin >> row;
	cin >> col;
	cin >> time;

	// �迭 �Է� �ޱ�
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	int direction = 0;

	////////////////////////////////////// ����û���� ��ġ �ľ�
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
		////////////////////////////////////// Ȯ��
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
		////////////////////////////////////// ��ȯ

		for (int ii = 0; ii < top_pos.first; ii++) //top_pos, ������ �Ʒ�
			next_arr[top_pos.first - ii][0] = next_arr[top_pos.first - ii - 1][0];
		next_arr[top_pos.first][top_pos.second] = -1;

		for (int ii = 0; ii < col - 1; ii++) //top_pos, �����ʿ��� ����
			next_arr[0][ii] = next_arr[0][ii + 1];
		next_arr[top_pos.first][top_pos.second] = -1;

		for (int ii = 0; ii < top_pos.first; ii++) //top_pos, �Ʒ����� ����
			next_arr[ii][col - 1] = next_arr[ii + 1][col - 1];

		for (int ii = 0; ii < col - 2; ii++) //top_pos, ���ʿ��� ������
			next_arr[top_pos.first][col - 1 - ii] = next_arr[top_pos.first][col - 1 - ii - 1];
		next_arr[top_pos.first][top_pos.second+1 ] = 0;


		for (int ii = 0; ii < row - bottom_pos.first; ii++) //�Ʒ����� ����
			next_arr[bottom_pos.first + ii][0] = next_arr[bottom_pos.first + ii + 1][0];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < col - 1; ii++) //�����ʿ��� ��������
			next_arr[row - 1][ii] = next_arr[row - 1][ii + 1];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < row - bottom_pos.first; ii++)
			next_arr[row - ii][col - 1] = next_arr[row - ii - 1][col - 1];
		next_arr[bottom_pos.first][bottom_pos.second] = -1;

		for (int ii = 0; ii < col - 2; ii++)
			next_arr[bottom_pos.first][col - 1 - ii] = next_arr[bottom_pos.first][col - 1 - ii - 1];
		next_arr[bottom_pos.first][bottom_pos.second + 1] = 0;

		////////////////////////////////////// ������
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

