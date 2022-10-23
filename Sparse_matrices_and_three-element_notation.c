#include <stdio.h>
typedef struct matrix_save
{
	int col;
	int row;
	int value;
}Msave; //3���� ������ ���� ����ü

void main(void)
{
	int count = 0;
	int SMATRIX[10][10] = {
		{0,1,0,0,0,0,0,0,0,0},
		{0,0,2,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0},
		{0,0,4,0,0,0,0,0,0,0},
		{0,0,0,0,0,5,0,0,0,0},
		{0,0,0,0,0,0,0,6,0,0},
		{0,0,7,0,0,0,0,0,0,0},
		{0,0,0,0,0,8,0,0,0,0},
		{9,0,0,0,0,0,0,0,0,10},
		{0,0,0,11,0,0,0,0,0,0},
	};//������ ������
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (SMATRIX[i][j])
				count++;
		}
	}//�������� ��ȿ���� ���� ī��Ʈ

	Msave *Smtx= (Msave*)malloc(sizeof(Msave)*(count + 1));
	//�������� ũ�⸦ �ֱ����� ī��Ʈ���� 1 ���� �����Ҵ�

	Smtx[0].col = 10;
	Smtx[0].row = 10;
	Smtx[0].value = count;
	//��� ���� ���̿� ���� ��ȿ���� ���� ù�� ����

	count = 1;
	for(int i=0;i<10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if(SMATRIX[i][j])
			{
				Smtx[count].col = i;
				Smtx[count].row = j;
				Smtx[count].value = SMATRIX[i][j];
				count++;
			}
		}
	}
	//�迭�� ��ȿ���Ҹ� 3���� ���·� ����

	printf("3���� ���� ���\n");
	for (int i = 0;i < count;i++)
	{
		printf("%d %d %d\n", Smtx[i].col, Smtx[i].row, Smtx[i].value);
	}//3���� ���� ���

	int **Array;
	Array= (int**)malloc(sizeof(int*) * Smtx[0].col);
	for (int i = 0; i < Smtx[0].col; i++) {
		Array[i] = (int*)malloc(sizeof(int) * Smtx[0].row);
	}
	//������ ũ�⸸ŭ �����Ҵ�

	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
				Array[i][j] = 0;
		}
	}

	for (int i = 1;i < count;i++)
	{
		Array[Smtx[i].col][Smtx[i].row] = Smtx[i].value;
	}
	//���� 2���� �迭 ���·� ����

	printf("\n������ ������ ���\n");
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			printf("%2d ", Array[i][j]);
		}
		printf("\n");
	}

	Msave *tSmtx = (Msave*)malloc(sizeof(Msave)*(count));
	//��ġ����� ���� ����

	tSmtx[0] = Smtx[0];//ù�� ����

	for (int i = 0;i < count;i++)
	{
		tSmtx[i].col = Smtx[i].row;
		tSmtx[i].row = Smtx[i].col;
		tSmtx[i].value = Smtx[i].value;
	}
	//10*10�� �����̱⿡ row�� col�� ���� �ٲ��ָ� ��ġ�� �ȴ�.

	printf("\n��ġ ���� ���\n");
	for (int i = 0;i < count;i++)
	{
		printf("%d %d %d\n", tSmtx[i].col, tSmtx[i].row, tSmtx[i].value);
	}//3���� ���� ���

	int **Array2;
	Array2 = (int**)malloc(sizeof(int*) * tSmtx[0].col);
	for (int i = 0; i < tSmtx[0].col; i++) {
		Array2[i] = (int*)malloc(sizeof(int) * tSmtx[0].row);
	}
	//��ġ��� ũ�⸸ŭ �����Ҵ�

	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			Array2[i][j] = 0;
		}
	}

	for (int i = 1;i < count;i++)
	{
		Array2[tSmtx[i].col][tSmtx[i].row] = tSmtx[i].value;
	}
	//���� 2���� �迭 ���·� ����

	printf("\n������ ��ġ��� ���\n");
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			printf("%2d ", Array2[i][j]);
		}
		printf("\n");
	}
}