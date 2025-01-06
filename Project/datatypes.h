#include <stdbool.h>

typedef struct menu {
	int id;
	char nameCategory[50];
} Category;

typedef struct list {
	int id;
	char nameProduct[50];
	char nameCategory[50];
	float priceProduct;
} Product;


