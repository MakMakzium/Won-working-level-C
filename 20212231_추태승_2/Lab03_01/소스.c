//�ʱ� �迭�� ũ�⸦ �Ѿ �Է½� �迭�� ũ�⸦ ������Ű�� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void size_add(int* s, int** arr) {
	//���ο� Size�� ȹ���Ѵ�.
	int nNewSize = *s + 3;
	int* temp;
	temp = malloc(sizeof(int) * nNewSize);

	//temp�� ������ �迭 ���ҵ��� �����Ѵ�.
	for (int i = 0; i < *s; i++) temp[i] = (*arr)[i];


	//������ arr�޸𸮵��� �����Ѵ�.
	free(*arr);

	*arr = temp;
	*s = nNewSize;
}

void main() {
	//size�� 3�� �迭 ����
	int* Np;
	int i = 0;
	int nsize = 3;
	Np = malloc(sizeof(int) * nsize);

	scanf("%d", &Np[0]);

	if (Np[0] != -1) {
		for (i = 1;; i++) {
			scanf("%d", &Np[i]);
			if (Np[i] == -1) break;
			if (i * 1 >= nsize) size_add(&nsize, &Np);
		}
		for (int j = 0; j <= i; j++)
			printf("%d", Np[j]);
	}

	free(Np);
	return 0;
}
