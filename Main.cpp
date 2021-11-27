#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "f(A) x g(A).h"
using namespace std;
#define FNAME_LEN 200

int main(long argc, char* argv[])
{

	long long i;
	char fname_in[FNAME_LEN], fname_out[FNAME_LEN];
	//
	FILE* fr;
	FILE* fo;
	//проверяем на коректность файлы заданные коандной строкой
	if ((fr = fopen(argv[1], "rt")) == NULL || (fo = fopen(argv[2], "w")) == NULL) {
		cout << "Не удалось открыть файлы" << endl;
		cin >> fname_in;
		cin >> fname_out;
		while ((fr = fopen(fname_in, "rt")) == NULL || (fo = fopen(fname_out, "w")) == NULL)
		{
			cout << "Не удалось открыть файлы" << endl;
			cin >> fname_in >> fname_out;
		}
	}



	f_A_x_g_A(fr, fo);

	fclose(fr);
	fclose(fo);
}

