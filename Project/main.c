#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc,char *argv[]) {
Category categories[50];
Product products[50];

int choose,location,checkId;
const char *filename;
int n;

while(choose!=3) {
	system("cls");
	printf("=============================\n");
	printf("***___STORE MANAGEMENT___***\n");
	printf("1.Quan ly danh muc\n");
	printf("2.Quan ly san pham\n");
	printf("3.Thoat\n");
	printf("=============================\n");
	printf("Moi ban nhap lua chon cua minh:");
	scanf("%d",&choose);
	switch (choose) {
		case 1:// Quan ly danh muc
		filename="categories.dat";
		n=loadCategory(filename,categories);
		while(choose!=7) {
			system("cls");
				printfFunction();
				printf("Lua chon cua ban:");
				scanf("%d",&choose);
			switch (choose) {
				case 1:
					system("cls");
					printfCategory(categories,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 2:
					system("cls");
					n++;
					addCategory(categories,location,n);
					saveCategory("categories.dat", categories, n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 3:
					system("cls");
					fixCategory(categories,checkId,n);
					saveCategory("categories.dat", categories, n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 4:
					system("cls");
					n--;
					deleteCategory(categories,checkId,n);
					saveCategory("categories.dat", categories, n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 5:
					system("cls");
					findCategory(categories,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 6:
					system("cls");
					arrangeCategory(categories,n,choose);
					break;
				case 7:
					break;
				default:
					printf("Lua chon khong hop le");
					break;
			}
		}
			break;
		case 2://Quan ly san pham
		filename="products.bin";
		n=loadProduct(filename,products);
		while(choose!=7) {
			system("cls");
				printfProductfunction();
				printf("Lua chon cua ban:");
				scanf("%d",&choose);
			switch (choose) {
				case 1:
					system("cls");
					printfProduct(products,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 2:
					system("cls");
					n++;
					addProduct(products,n,location);
					saveProduct("products.bin",products,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 3:
					system("cls");
					fixProduct(products,n,checkId);
					saveProduct("products.bin",products,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 4:
					system("cls");
					n--;
					deleteProduct(products,n,checkId);
					saveProduct("products.bin",products,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 5:
					system("cls");
					findProduct(products,n);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 6:
					system("cls");
					arrangeProduct(products,n,choose);
					printf("-------------------------------\n");
					printf("Moi nhap phim bat ky de tro ve:");
					getchar();
					getchar();
					break;
				case 7:
					break;
				default:
					printf("Lua chon khong hop le");
					break;
			}
		}
			break;
		case 3://Thoat
			break;
		default:
			printf("Lua chon khong hop le");
			break;
	}
}
	printf("Ket thuc chuong trinh!");
	return 0;
}
