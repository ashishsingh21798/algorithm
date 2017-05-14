/*
This program computes weighted averages for a
several individuals. The program reads scores
weighted averages for each individual, prints
and prints averages for each of the exams and
set of exam scores for
from a file, computes
out a table of scores,
for the weighted average.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define COLS 5
int getwts(float wts[]);
FILE *openinfile(void);
int read_scores(int ex[][COLS], int lim, int nexs);
void wtd_avg(int ex[][COLS], int lim, int nexs, float wts[]);
void avg_scores(int ex[][COLS], int avg[], int lim, int nexs);
void print_scores(int ex[][COLS], int lim, int nexs);
void print_avgs(int avg[], int nexs);

int main()
{
	int no_of_stds, no_of_exams;
	int avg[COLS];
	int scores[MAX][COLS];
	float wts[COLS];
	printf("***Weighted Average of Scores***\n\n");
	no_of_exams = getwts(wts);
	no_of_stds = read_scores(scores, MAX, no_of_exams);
	wtd_avg(scores, no_of_stds, no_of_exams, wts);
	print_scores(scores, no_of_stds, no_of_exams);
	avg_scores(scores, avg, no_of_stds, no_of_exams);
	print_avgs(avg, no_of_exams);
	return 0;
}

int getwts(float wts[])
{
	int i, n;
	printf("Number of exams: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) 
	{
		printf("Percent Weight for Exam %d: ", i);
		scanf("%f", &wts[i]);
	}
	while (getchar() != '\n');
	return n;
}


FILE *openinfile(void)
{
	FILE *fp;
	char infile[25];
	printf("Input File, RETURN to quit: ");
	while (gets(infile)) 
	{
		if (!*infile) 
			exit(0);
		fp = fopen(infile, "r");
		if (!fp) 
		{	
			printf("Unable to open input file - retype\n");
			continue;
		}
		else 
			return fp;
	}
	exit(0);

}


int read_scores(int ex[][COLS], int stds, int nexs)
{
	int row, col, n, x;
	FILE * fp;
	fp = openinfile();
	for (row = 0; row < stds; row++)
		for (col = 0; col <= nexs; col++) 
		{
			x = fscanf(fp, "%d", &n);
			if (x == EOF) 
			{
				fclose(fp);
				return row;
			}

			ex[row][col] = n;
		}
	fclose(fp);
	return row;
}



void wtd_avg(int ex[][COLS], int lim, int nexs, float wts[])
{
	int i, j;
	float wtdavg;
	for (i = 0; i < lim; i++) 
	{
		wtdavg = 0.0;
		for (j = 1; j <= nexs; j++)
			wtdavg += ex[i][j] * wts[j] / 100.0;

		ex[i][nexs + 1] = (int) (wtdavg + 0.5);
	}
}


void avg_scores(int ex[][COLS], int avg[], int lim, int nexs)
{
	int i, j;
	for (j = 1; j <= nexs + 1; j++) 
	{
		avg[j] = 0;
		for (i = 0; i < lim; i++)
			avg[j] += ex[i][j];

		avg[j] = (int) (0.5 + (float) avg[j] / (float) lim);
	}
}


void print_scores(int ex[][COLS], int lim, int nexs)
{
	int i, j;
	printf("ID #\t");
	for (j = 1; j <= nexs; j++)
		printf("Ex%d\t", j); 
		
	printf("WtdAvg\n");

	for (i = 0; i < lim; i++) 
	{ 	
		for (j = 0; j <= nexs + 1; j++)
		printf("%d\t", ex[i][j]);
		printf("\n");
	}
}


void print_avgs(int avg[], int nexs)
{
	int i;
	for (i = 1; i <= nexs; i++)
		printf("Average for Exam %d = %d\n", i, avg[i]);
	
	printf("Average of the weighted average = %d\n", avg[nexs + 1]);
}
