#include <iostream>

using namespace std;

int Ti[15];
int Pi[15];

typedef struct _oneDay {
	double PioverTi;
	int day_idx;
}oneDay;

int reserved_date[15];
oneDay myDays[15];

int days, pay;
int pay;

// ���� ���ķ� pi/ti ���� ������ ����
void DaySort(oneDay *myDays, int n)
{
	oneDay temp;
	for (int i = n; i > 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (myDays[j - 1].PioverTi<myDays[j].PioverTi)
			{
				temp = myDays[j - 1];
				myDays[j - 1] = myDays[j];
				myDays[j] = temp;
			}
		}
	}
}

void View(oneDay *myDays, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %f\n",
			myDays[i].day_idx, myDays[i].PioverTi);
	}
}

int main()
{
	cin >> days;

	for (int i = 0; i < days; i++)
	{
		cin >> Ti[i];
		cin >> Pi[i];
		myDays[i].PioverTi = (double)Pi[i] / Ti[i];
		myDays[i].day_idx = i;
	}

	DaySort(myDays, days);
	View(myDays, days);

	int isOkay = 0;

	for (int i = 0; i < days; i++)
	{
		isOkay = 1; //���� Ȯ�ο�

		if (myDays[i].day_idx + Ti[myDays[i].day_idx]> days)
			continue;

		for (int j = 0; j < Ti[myDays[i].day_idx]; j++)
		{
			if (reserved_date[myDays[i].day_idx + j] == 1)
				isOkay = 0;//���� �����Ϸ��� ��¥�� �̹� ������ ������ 0
		}

		if (isOkay == 1) //�����Ϸ��� ��¥�� ��������
		{
			for (int j = 0; j < Ti[myDays[i].day_idx]; j++)
			{
				reserved_date[myDays[i].day_idx+j] = 1;
			}
			pay += Pi[myDays[i].day_idx];
		}
	}

	cout << pay;


	return 0;
}