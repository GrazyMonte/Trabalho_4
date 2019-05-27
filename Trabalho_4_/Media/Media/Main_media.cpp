#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	FILE *fp = NULL, *arquivo_aux = NULL;
	FILE *fp_1 = NULL, *arquivo_aux_1 = NULL;
	char id;
	int a, larg, alt, maior, aux = 0, x, y, i, j;
	
	int **matriz = NULL, **media = NULL;
	int maior_media;
	long int cont = 0, cont_aux = 0;


	fp = fopen("D:/Backup Zizi/Disco Local C/Documentos/Programacao_Avancada/Trabalho_4_/barbara.ascii.pgm", "r");

	fscanf(fp, "%c%d %d %d %d", &id, &a, &larg, &alt, &maior);
	printf("%c%d %d %d %d \n", id, a, larg, alt, maior);

	matriz = new int*[alt];
	for (i = 0; i < alt; i++) matriz[i] = new int[larg];

	for (i = 0; i < alt; i++)
	{
		for (j = 0; j < larg; j++)
		{
			fscanf(fp, "%d", &aux);
			matriz[i][j] = aux;
			cont++;
		}
	}

	media = new int*[alt];
	for (i = 0; i < alt; i++) media[i] = new int[larg];

	//Filtro de média
	for (y = 1; y < alt - 2; y++)
	{
		for (x = 1; x < larg - 2; x++)
		{
			int s = 0;
			for (i = -1; i < 2; i++)
			{
				for (j = -1; j < 2; j++)
				{
					s += matriz[x + i][y + j];
				}
			}
			media[x][y] = s / 9;
		}
	}

	maior_media = media[0][0];
	for (int i = 1; i < alt; i++)
	{
		for (int j = 1; j < larg; j++)
		{
			if (media[i][j] > maior_media) maior_media = media[i][j];
		}
	}

	arquivo_aux = fopen("D:/Backup Zizi/Disco Local C/Documentos/Programacao_Avancada/Trabalho_4_/Media/media_barbara.ascii.pgm", "w");

	fprintf(arquivo_aux, "%c%d %d %d %d \n", id, a, larg, alt, maior_media);

	for (int i = 0; i < alt; i++)
	{
		for (int j = 0; j < larg; j++)
		{
			aux = media[i][j];
			fprintf(arquivo_aux, "%d ", aux);
			cont_aux++;
		}
	}

	fclose(arquivo_aux);

	for (i = 0; i < alt; i++) delete[] media[i];
	delete[] media;

	for (i = 0; i < alt; i++) delete[] matriz[i];
	delete[] matriz;

	printf("largura x altura = %d \ncontador = %d \n", larg*alt, cont);
	fclose(fp);

	fp_1 = fopen("D:/Backup Zizi/Disco Local C/Documentos/Programacao_Avancada/Trabalho_4_/mother_daughter.ascii.pgm", "r");

	fscanf(fp_1, "%c%d %d %d %d", &id, &a, &larg, &alt, &maior);
	printf("\n\n%c%d %d %d %d \n", id, a, larg, alt, maior);

	matriz = new int*[alt];
	for (i = 0; i < alt; i++) matriz[i] = new int[larg];

	for (i = 0; i < alt; i++)
	{
		for (j = 0; j < larg; j++)
		{
			fscanf(fp_1, "%d", &aux);
			matriz[i][j] = aux;
			cont++;
		}
	}

	media = new int*[alt];
	for (i = 0; i < alt; i++) media[i] = new int[larg];

	//Filtro de média
	for (y = 1; y < alt - 2; y++)
	{
		for (x = 1; x < larg - 2; x++)
		{
			int s = 0;
			for (i = -1; i < 2; i++)
			{
				for (j = -1; j < 2; j++)
				{
					s += matriz[x + i][y + j];
				}
			}
			media[x][y] = s / 9;
		}
	}

	maior_media = media[0][0];
	for (int i = 1; i < alt; i++)
	{
		for (int j = 1; j < larg; j++)
		{
			if (media[i][j] > maior_media) maior_media = media[i][j];
		}
	}

	arquivo_aux_1 = fopen("D:/Backup Zizi/Disco Local C/Documentos/Programacao_Avancada/Trabalho_4_/Media/media_mother_daughter.ascii.pgm", "w");

	fprintf(arquivo_aux_1, "%c%d %d %d %d \n", id, a, larg, alt, maior_media);

	for (int i = 0; i < alt; i++)
	{
		for (int j = 0; j < larg; j++)
		{
			aux = media[i][j];
			fprintf(arquivo_aux_1, "%d ", aux);
			cont_aux++;
		}
	}

	fclose(arquivo_aux_1);

	for (i = 0; i < alt; i++) delete[] media[i];
	delete[] media;

	for (i = 0; i < alt; i++) delete[] matriz[i];
	delete[] matriz;

	printf("largura x altura = %d \ncontador = %d \n", larg*alt, cont);
	fclose(fp_1);

	system("pause");
	return 0;
}