#include "vector.h"
#include <stdio.h>
vector* init(const size_t cap, const type elem_type)
{
	vector* vec = malloc(sizeof(vector));
	if(!vec)
	{
		perror("Failed to allocate memory for vector");
		exit(EXIT_FAILURE);
	}

	vec->size = 0;
	vec->cap = cap;
	vec->elem_type = elem_type;

	switch(elem_type)
	{
		case CHAR:
			vec->data = malloc(cap * sizeof(char));
			if(!vec->data)
			{
				perror("Failed to allocate memory for char array");
				free(vec);
				exit(EXIT_FAILURE);
			}
			break;
		case INT:
			vec->data = malloc(cap * sizeof(int));
			if(!vec->data)
			{
				perror("Failed to allocate memory for int array");
				free(vec);
				exit(EXIT_FAILURE);
			}
			break;
		case FLOAT:
			vec->data = malloc(cap * sizeof(float));
			if(!vec->data)
			{
				perror("Failed to allocate memory for float array");
				free(vec);
				exit(EXIT_FAILURE);
			}
			break;
		case DOUBLE:
			vec->data = malloc(cap * sizeof(double));
			if(!vec->data)
			{
				perror("Failed to allocate memory for double array");
				free(vec);
				exit(EXIT_FAILURE);
			}
			break;
		default:
			fprintf(stderr, "Unknown type\n");
			free(vec);
			exit(EXIT_FAILURE);
	}

	return vec;
}

void free_vector(vector* vec)
{
	free(vec->data);
	free(vec);
}

void push_back(vector* vec, void* elem)
{
	if(vec->size == vec->cap)
	{
		vec->cap *= 2;
		vec->data = realloc(vec->data, vec->cap *
									   (vec->elem_type == CHAR ? sizeof(char) :
										vec->elem_type == INT ? sizeof(int) :
										vec->elem_type == FLOAT ? sizeof(float)
																: sizeof(double)));
		if(!vec->data)
		{
			perror("Failed to reallocate memory for array");
			exit(EXIT_FAILURE);
		}
	}

	switch(vec->elem_type)
	{
		case CHAR:
			((char*) vec->data)[vec->size] = *(char*) elem;
			break;
		case INT:
			((int*) vec->data)[vec->size] = *(int*) elem;
			break;
		case FLOAT:
			((float*) vec->data)[vec->size] = *(float*) elem;
			break;
		case DOUBLE:
			((double*) vec->data)[vec->size] = *(double*) elem;
			break;
		default:
			fprintf(stderr, "Unknown type\n");
			exit(EXIT_FAILURE);
	}
	vec->size++;
}

void pop_back(vector* vec)
{
	if(vec->size == 0)
	{
		fprintf(stderr, "Cannot pop from an empty vector\n");
		return;
	}
	vec->size--;
	if(vec->size <= vec->cap / 4 && vec->cap > 1)
	{
		vec->cap /= 2;
		vec->data = realloc(vec->data, vec->cap *
									   (vec->elem_type == CHAR ? sizeof(char) :
										vec->elem_type == INT ? sizeof(int) :
										vec->elem_type == FLOAT ? sizeof(float)
																: sizeof(double)));
		if(!vec->data)
		{
			perror("Failed to reallocate memory for array\n");
			exit(EXIT_FAILURE);
		}
	}
}

void* get(const vector* vec, const int index)
{
	if(index>vec->size||-index>vec->size)
	{
		fprintf(stderr,"Index out of bounds. Index: %d,Size: %zu ",index,vec->size);
		exit(EXIT_FAILURE);
	}
	switch(vec->elem_type)
	{
		case CHAR:
			return &((char*)(vec->data))[index];
		case INT:
			return &((int*)(vec->data))[index];
		case FLOAT:
			return &((float*)(vec->data))[index];
		case DOUBLE:
			return &((double*)(vec->data))[index];
		default:
			fprintf(stderr, "Unknown type\n");
			return NULL;
	}
}

char get_char(const vector* vec, const int index)
{
	if(index>vec->size||-index>vec->size)
	{
		fprintf(stderr,"Index out of bounds. Index: %d,Size: %zu ",index,vec->size);
		exit(EXIT_FAILURE);
	}
	if (vec->elem_type != CHAR)
	{
		fprintf(stderr, "Incorrect type for get_char\n");
		exit(EXIT_FAILURE);
	}
	return ((char*)vec->data)[index];
}

int get_int(const vector* vec, const int index)
{
	if(index>vec->size||-index>vec->size)
	{
		fprintf(stderr,"Index out of bounds. Index: %d,Size: %zu ",index,vec->size);
		exit(EXIT_FAILURE);
	}
	if (vec->elem_type != INT)
	{
		fprintf(stderr, "Incorrect type for get_int\n");
		exit(EXIT_FAILURE);
	}
	return ((int*)vec->data)[index];
}

float get_float(const vector* vec, const int index)
{
	if(index>vec->size||-index>vec->size)
	{
		fprintf(stderr,"Index out of bounds. Index: %d,Size: %zu ",index,vec->size);
		exit(EXIT_FAILURE);
	}
	if (vec->elem_type != FLOAT)
	{
		fprintf(stderr, "Incorrect type for get_float\n");
		exit(EXIT_FAILURE);
	}
	return ((float*)vec->data)[index];
}

double get_double(const vector* vec, const int index)
{
	if(index>vec->size||-index>vec->size)
	{
		fprintf(stderr,"Index out of bounds. Index: %d,Size: %zu ",index,vec->size);
		exit(EXIT_FAILURE);
	}
	if (vec->elem_type != DOUBLE)
	{
		fprintf(stderr, "Incorrect type for get_double\n");
		exit(EXIT_FAILURE);
	}
	return ((double*)vec->data)[index];
}
