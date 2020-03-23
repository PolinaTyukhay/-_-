#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "rus");
	printf("Введите количество символв в пароле :\n");
	int n, i;
	scanf_s("%d", &n);
	char* password = (char*)malloc(n * sizeof(char));
	printf("Введите пароль:\n");
	for (i = 0; (password[i] = getch()) != '\r';)
	{
		if (password[i] == '\b' && i != 0) {
			printf("%s", "\b \b");
			i--;
		}
		else if (password[i] != '\b') {
			printf("%c", '*');
			i++;
		}
	}
	password[i] = '\0';
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%c", password[i]);
	}





}
