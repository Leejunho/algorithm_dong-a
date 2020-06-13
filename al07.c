#include <stdio.h>
int arr[201][201];
char input_temp[51];
char D_temp[40001];
int m, n;
int pLine,index;


void pD(int sX, int sY, int eX, int eY)
{
	int i, j;
	if (sX == eX)eX++;
	if (sY == eY)eY++;
	int Xsize = eX - sX;
	int Ysize = eY - sY;
	if (D_temp[index] != 'D')
	{
		for (i = sX; i < eX; i++)
		{
			for (j = sY; j < eY; j++)
			{
				arr[i][j] = D_temp[index] - '0';
			}
		}
		index++;
		return;
	}
	index++;
	
	if (Xsize != 1 && Xsize % 2 != 0)Xsize++;
	if (Ysize != 1 && Ysize % 2 != 0)Ysize++;
	pD(sX, sY, sX + (Xsize / 2), sY + (Ysize / 2));
	if (Ysize != 1)
	{
		pD(sX, sY + (Ysize / 2), sX + (Xsize / 2), eY);    
	}
	if (Xsize != 1)
	{
		pD(sX + (Xsize / 2), sY, eX, sY + (Ysize / 2));	   
	}
	if (Xsize != 1 && Ysize != 1)
	{
		pD(sX + (Xsize / 2), sY + (Ysize / 2), eX, eY);		   
	}
}

void pB(int sX, int sY, int eX, int eY, FILE *output)
{
	int i, j, cnt = 0;
	if (sX == eX)eX++;
	if (sY == eY)eY++;
	int Xsize = eX - sX;
	int Ysize = eY - sY;
	for (i = sX; i < eX; i++)
	{
		for (j = sY; j < eY; j++)
		{
			if (arr[i][j])cnt++;
		}
	}
	if (((eX - sX) * (eY - sY)) == cnt)
	{
		if (pLine == 50) {
			fprintf(output, "\n");
			pLine = 0;
		}
		fprintf(output, "1"); pLine++;
		return;
	}
	else if (!cnt)
	{
		if (pLine == 50) {
			fprintf(output, "\n");
			pLine = 0;
		}
		fprintf(output, "0"); pLine++;
		return;
	}
	else
	{
		if (pLine == 50) {
			fprintf(output, "\n");
			pLine = 0;
		}
		fprintf(output, "D"); pLine++;
		if (Xsize != 1 && Xsize % 2 != 0)Xsize++;
		if (Ysize != 1 && Ysize % 2 != 0)Ysize++;
		pB(sX, sY, sX + (Xsize / 2), sY + (Ysize / 2), output); 
		if (Ysize != 1)
		{
			pB(sX, sY + (Ysize / 2), sX + (Xsize / 2), eY, output);    
		}
		if (Xsize != 1)
		{
			pB(sX + (Xsize / 2), sY, eX, sY + (Ysize / 2), output);	   
		}
		if (Xsize != 1 && Ysize != 1)
		{
			pB(sX + (Xsize / 2), sY + (Ysize / 2), eX, eY, output);		   
		}
	}
}
int main()
{
	FILE *input = fopen("bitmap.inp", "rt");
	FILE *output = fopen("bitmap.out", "wt");
	char temp,printTemp;
	int i, j, Line = 0;
	while (1)
	{
		if (input_temp[0] == '\0')fscanf(input, "%s", input_temp);
		if (input_temp[0] == '#')return 0;
		pLine = 0, Line = 0, index = 0; //출력 라인 , 입력 라인
		fscanf(input, "%d", &m);
		fscanf(input, "%d", &n);
		
		if (input_temp[0] == 'B') printTemp = 'D';
		else printTemp = 'B';
		fprintf(output, "%c   %d   %d\n", printTemp, m, n);

		if (input_temp[0] == 'B')
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (((i*n) + j) % 50 == 0)
					{
						fscanf(input, "%c", &temp); 
					}
					fscanf(input, "%c", &temp);
					arr[i][j] = temp - '0';
				}
			}
			pB(0, 0, m, n,output);
			input_temp[0] = '\0';
		}
		else 
		{
			while (1)
			{
				fscanf(input, "%s", input_temp);
				if (input_temp[1] == '\0')
				{
					if (input_temp[0] != '#')
					{
						fscanf(input, "%c", &temp);
						if (temp == '\n')
						{
							D_temp[50 * Line] = input_temp[0];
							input_temp[0] = '\0';
						}
					}
					break;
				}
				for (i = 0; input_temp[i] != '\0'; i++)
				{
					D_temp[i + (50 * Line)] = input_temp[i];
				}
				D_temp[i + (50 * Line)] = '\0';
				Line++;
			}
			pD(0, 0, m, n);
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					if (pLine == 50) {
						fprintf(output, "\n");
						pLine = 0;
					}
					fprintf(output, "%d", arr[i][j]);
					pLine++;
				}
			}

		}
		fprintf(output, "\n");
	}

	return 0;
}