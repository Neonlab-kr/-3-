#include <stdio.h>
typedef struct matrix_save
{
	int col;
	int row;
	int value;
}Msave; //3원소 저장을 위한 구조체

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
	};//임의의 희소행렬
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (SMATRIX[i][j])
				count++;
		}
	}//희소행렬의 유효원소 갯수 카운트

	Msave *Smtx= (Msave*)malloc(sizeof(Msave)*(count + 1));
	//희소행렬의 크기를 넣기위해 카운트보다 1 많게 동적할당

	Smtx[0].col = 10;
	Smtx[0].row = 10;
	Smtx[0].value = count;
	//행과 열의 길이와 값이 유효원소 갯수 첫줄 저장

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
	//배열에 유효원소를 3원소 형태로 저장

	printf("3원소 형태 출력\n");
	for (int i = 0;i < count;i++)
	{
		printf("%d %d %d\n", Smtx[i].col, Smtx[i].row, Smtx[i].value);
	}//3원소 형태 출력

	int **Array;
	Array= (int**)malloc(sizeof(int*) * Smtx[0].col);
	for (int i = 0; i < Smtx[0].col; i++) {
		Array[i] = (int*)malloc(sizeof(int) * Smtx[0].row);
	}
	//희소행렬 크기만큼 동적할당

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
	//원래 2차원 배열 형태로 복구

	printf("\n복구된 희소행렬 출력\n");
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			printf("%2d ", Array[i][j]);
		}
		printf("\n");
	}

	Msave *tSmtx = (Msave*)malloc(sizeof(Msave)*(count));
	//전치행렬을 위한 선언

	tSmtx[0] = Smtx[0];//첫줄 동일

	for (int i = 0;i < count;i++)
	{
		tSmtx[i].col = Smtx[i].row;
		tSmtx[i].row = Smtx[i].col;
		tSmtx[i].value = Smtx[i].value;
	}
	//10*10의 구조이기에 row와 col의 값만 바꿔주면 전치가 된다.

	printf("\n전치 형태 출력\n");
	for (int i = 0;i < count;i++)
	{
		printf("%d %d %d\n", tSmtx[i].col, tSmtx[i].row, tSmtx[i].value);
	}//3원소 형태 출력

	int **Array2;
	Array2 = (int**)malloc(sizeof(int*) * tSmtx[0].col);
	for (int i = 0; i < tSmtx[0].col; i++) {
		Array2[i] = (int*)malloc(sizeof(int) * tSmtx[0].row);
	}
	//전치행렬 크기만큼 동적할당

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
	//원래 2차원 배열 형태로 복구

	printf("\n복구된 전치행렬 출력\n");
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			printf("%2d ", Array2[i][j]);
		}
		printf("\n");
	}
}