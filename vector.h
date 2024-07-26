#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
	CHAR, INT, FLOAT, DOUBLE,
} type;

typedef struct Vector {
	size_t size;
	size_t cap;
	type elem_type;
	void* data;
} vector;

vector* init(size_t cap, type elem_type);

void free_vector(vector* vec);

void push_back(vector* vec, void* elem);

void pop_back(vector* vec);

char get_char(vector* vec, int index);

int get_int(vector* vec, int index);

float get_float(vector* vec, int index);

double get_double(vector* vec, int index);

#endif // VECTOR_H
