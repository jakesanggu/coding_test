#include <iostream>

using namespace std;

int row, col;

int main()
{
	int safe_area = 0;
	int max_area = 0;

	// �迭ũ�� �Է� �ޱ�
	cin >> row;
	cin >> col;

	// �޸� �Ҵ�
	int **arr = new int*[row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];

	int **arr_ori = new int*[row];
	for (int i = 0; i < row; i++)
		arr_ori[i] = new int[col];

	int **arr0 = new int*[row];
	for (int i = 0; i < row; i++)
		arr0[i] = new int[col];

	int **arr_wall = new int*[row];
	for (int i = 0; i < row; i++)
		arr_wall[i] = new int[col];

	// �迭 �Է� �ޱ�
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr_ori[i][j];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = arr_ori[i][j];

	// ���� ���� �� �ִ� ��ġ �ľ�
	for (int w1_row = 0; w1_row < row; w1_row++)
	{
		for (int w1_col = 0; w1_col <col; w1_col++)
		{
			for (int w2_row = 0; w2_row < row; w2_row++)
			{
				for (int w2_col = 0; w2_col < col; w2_col++)
				{
					for (int w3_row = 0; w3_row < row; w3_row++)
					{
						for (int w3_col = 0; w3_col < col; w3_col++)
						{


							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < col; j++) {
									if (arr[i][j] == 0) {
										arr0[i][j] = 1; //0�� ����
										arr_wall[i][j] = 1; //0�� ����
									}
								}
							}
							
							if (arr0[w1_row][w1_col] == 1) 
								arr0[w1_row][w1_col]--;
							if (arr0[w2_row][w2_col] == 1)
								arr0[w2_row][w2_col]--;							
							if (arr0[w3_row][w3_col] == 1)
								arr0[w3_row][w3_col]--;

							for (int i = 0; i < row; i++)
								for (int j = 0; j < col; j++) {
									arr[i][j] += arr_wall[i][j] xor arr0[i][j];
								}
							

							for (int k = 0; k < row*col; k++) // 4x6 ������ �ڲ� �бⰡ �̻��ϰ� �ż� ����� ���� ���� �ݺ��� �ϰ� ��.
							{
								for (int i = 0; i < row; i++)
								{
									for (int j = 0; j < col; j++)
									{
										if (arr[i][j] == 2)
										{
											if (i - 1 >= 0 && arr[i - 1][j] == 0)
												arr[i - 1][j] += 2;
											if (j - 1 >= 0 && arr[i][j - 1] == 0)
												arr[i][j - 1] += 2;
											if (i + 1 < row && arr[i + 1][j] == 0)
												arr[i + 1][j] += 2;
											if (j + 1 < col && arr[i][j + 1] == 0)
												arr[i][j + 1] += 2;
										}
									}
								}
							}

							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < col; j++) {
									if (arr[i][j] == 0)
										safe_area++;
								}
							}
							if (safe_area > max_area)
								max_area = safe_area;

							safe_area = 0;

							for (int i = 0; i < row; i++)
								for (int j = 0; j < col; j++)
									arr[i][j] = arr_ori[i][j];
						}
					}
				}
			}
		}
	}

	cout << max_area << endl;

	return 0;
}

