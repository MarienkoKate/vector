#include <stdio.h>

typedef struct {
	int* mas;
	size_t size;
	size_t cap;
} vector_t;

void init(vector_t* v) { // инициализация
	v->mas = NULL;
	v->size = 0;
	v->cap = 0;
}

void PB(vector_t* v, int val) { // вставка в конец
	int* newmas = NULL;
	int i = 0;
	if (v->size == v->cap) {
		if (v->cap == 0) v->cap = 1;
		v->cap *= 2;
			newmas = malloc(sizeof(int) * v->cap);
			for (i; i < v->size; i++)
				newmas[i] = v->mas[i];
			free(v->mas);
			v->mas = newmas;
	}
	v->mas[v->size] = val;
	v->size++;
}

void print(vector_t* v) { // напечатай 
	int i = 0;
	for (i; i < v->size ; i++)
		printf("%d ", v->mas[i]);
}

void destr(vector_t* v) { // удаление 
	if (v->mas != NULL) v->mas = NULL;
}

char set(vector_t* v, int i, int val) { // замена
	char mas[] = "m";
	if (i >= 0 && i < v->size) v->mas[i] = val;
	else return -1;
}

void insert(vector_t* v, int i, int val) { // вставка одного элемента 
	PB(v, 0);
	for (int g = v->size - 1; g > i; g--)
		v->mas[g] = v->mas[g - 1];
	v->mas[i] = val;
}
void arace(vector_t* v, int i) { // удаление одного элемента 
	for (int g = i; g < v->size - 1; g++ )
		v->mas[g] = v->mas[g+1];
	v->size--;
}

int get(vector_t* v, int i) { // вызов элемента массива
	if (i >= 0 && i < v->size) return v->mas[i];
	else return -1;
}

main() {
	vector_t v;
	init(&v);
	PB(&v , 13);
	PB(&v, 113);
	insert(&v, 1, 12);
	arace(&v, 0);
	set(&v, 2, 0);
	print(&v);
	destr(&v);
}
