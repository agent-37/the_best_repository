#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "f(A) x g(A).h"
void read_f_mat(FILE* fr, long n, long  (&a)[1000][1000]) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			fscanf(fr, "%d", &a[i][j]);
}
void write_f_mat(FILE* fo, long n, long(&a)[1000][1000]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fprintf(fo, "%d", a[i][j]);
		   fprintf(fo, "%c", '\n');
	}
}
void mult_numXmat(long n,long q, long(&a)[1000][1000],  long(&b)[1000][1000]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = a[i][j] * q;
}
void sum_mat(long n, long(&a)[1000][1000], long(&b)[1000][1000], long(&c)[1000][1000]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] +b[i][j];

}
void mult_matXmat(long n, long(&a)[1000][1000], long(&b)[1000][1000], long(&c)[1000][1000]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int h = 0; h < n; h++)			
			c[i][j] = a[i][h] * b[h][j];

}
void f_A(long n, long(&a)[1000][1000], long(&b)[1000][1000]) {
	long e[1000][1000],x1[1000][1000], x2[1000][1000], rez[1000][1000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				e[i][j] = -1;
			else
				e[i][j] = 0;
	mult_matXmat(n, a, a, x2);
	mult_numXmat(n, 2, x2, x1);
	mult_numXmat(n, -7, a, x2);
	sum_mat(n, x1, x2, rez);
	sum_mat(n, rez, e, b);

}
void g_A(long n, long(&a)[1000][1000], long(&b)[1000][1000]) {
	long  x1[1000][1000], x2[1000][1000];
	
	mult_matXmat(n, a, a, x2);
	mult_numXmat(n, 2, x2, x1);
	mult_numXmat(n, -1, a, x2);
	sum_mat(n, x1, x2, b);
}

void f_A_x_g_A(FILE* fr, FILE* fo) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long long x, t;
	 long n, fA[1000][1000], gA[1000][1000], A[1000][1000];
	fscanf(fr, "%d", &n);
	read_f_mat(fr, n, A);
	f_A(n, A, fA);
	g_A(n, A, gA);
	mult_matXmat(n, fA, gA, A);
	write_f_mat(fo, n, A);
	
}