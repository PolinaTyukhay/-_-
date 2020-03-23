#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
typedef struct  //сделали структуру
{
	int a;
	int b;
	double mod;

} Chislo;
void inputChilso(Chislo* x, FILE* f)   //функция считывания числа с файла
{
	fscanf_s(f, "%d", &(x->a));
	fscanf_s(f, "%d", &(x->b));
	x->mod = sqrt(pow(x->a, 2) + pow(x->b, 2));

}
Chislo* inputMassChislo(int* size, char* f)   //считывание массива
{
	FILE* input;
	fopen_s(&input, f, "r");
	fscanf_s(input, "%d", size);
	char tmp;
	fscanf_s(input, "%c", &tmp, 1);
	Chislo* result = (Chislo*)malloc((*size) * sizeof(Chislo));
	for (int i = 0; i < *size; ++i)
	{
		inputChilso(&result[i], input);
	}
	fclose(input);
	return result;
}
void outputChislo(Chislo* c)     // ф-ция вывод комплексного числа
{
	printf("%d+%di\n \t модуль =%f\n", c->a, c->b, c->mod);
}
void outputMassChislo(Chislo* mass, int size)   //ф-ция вывода комплекс числа в консоль
{
	for (int i = 0; i < size; ++i)
	{
		outputChislo(&mass[i]);
	}
}
void outputBiggestChislo(Chislo* m, int size)
{
	double biggestmod = 0;
	for (int i = 0; i < size; i++)
	{
		if (m[i].mod > biggestmod)
		{
			biggestmod = m[i].mod;
		}

	}
	printf("  больший модуль %f\n", biggestmod);
	for (int i = 0; i < size; i++)
	{
		if (sqrt(pow(m[i].a, 2) + pow(m[i].b, 2)) == biggestmod)
		{
			printf("большое по модулю %d+%di\n", m[i].a, m[i].b);
		}
	}

}
int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	Chislo* input = 0;
	input = inputMassChislo(&size, "A.txt");
	outputMassChislo(input, size);
	outputBiggestChislo(input, size);
	free(input);
	system("pause");






}
