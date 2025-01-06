#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// logic ham
void printfFunction() {
	printf("***___Quan ly danh muc___***\n");
	printf("=============================\n");
	printf("1.Hien thi danh muc\n");
	printf("2.Them danh muc\n");
	printf("3.Sua danh muc\n");
	printf("4.Xoa danh muc\n");
	printf("5.Tim kiem danh muc\n");
	printf("6.Sap xep danh muc\n");
	printf("7.Thoat\n");
	printf("=============================\n");
}
void printfCategory(Category categories[],int n) {
	printf("___________________________________________\n");
	printf("|Id     |                 Danh muc        |\n");
	printf("-------------------------------------------\n");
	for(int i=0;i<n;i++) {
		printf("|%d      |%25s        | \n",categories[i].id,categories[i].nameCategory);
		printf("|_______|_________________________________|\n");
	}
}
void addCategory(Category categories[],int location,int n) {
	fflush(stdin);
	printf("Moi ban chon vi tri muon them:");
	scanf("%d",&location);
	getchar();
	if(location<1||location>n) {
		printf("Vi tri khong hop le\n");
		return ;
	} else {
		n++;
		for(int i=n-1;i>location-1;i--) {
			categories[i].id=categories[i-1].id;
			strcpy(categories[i].nameCategory, categories[i-1].nameCategory);
		}
		printf("Moi ban nhap id cho danh muc muon them:");
		scanf("%d",&categories[location-1].id);
  		checkIdcategory(categories,n);
		fflush(stdin);
		printf("Moi nhap ten cho danh muc muon them:");
		fgets(categories[location-1].nameCategory,50,stdin);
		categories[location-1].nameCategory[strcspn(categories[location-1].nameCategory,"\n")]='\0';
		checkNamecategory(categories,n);
	}
}
void fixCategory(Category categories[],int checkId,int n){
	fflush(stdin);
	printf("Moi ban chon id muon sua:");
	scanf("%d",&checkId);
	getchar();
	int check=-1;
	for (int i=0;i<n;i++) {
		if(categories[i].id==checkId) {
			printf("Moi nhap ten cho danh muc muon sua:");
			fgets(categories[i].nameCategory,50,stdin);
			categories[i].nameCategory[strcspn(categories[i].nameCategory,"\n")]='\0';
			checkNamecategory(categories,n);
			check++;
		}
	}
	if(check==-1) {
		printf("id khong hop le\n");
		return ;
	}
}
void deleteCategory(Category categories[],int checkId,int n) {
	printf("Moi ban nhap id muon xoa:");
	scanf("%d",&checkId);
	int check=-1;
	for (int i=0;i<n;i++) {
		if(categories[i].id==checkId) {
			n--;
			for(int j=i;j<n+1;j++) {
				categories[j].id=categories[j+1].id;
				strcpy(categories[j].nameCategory,categories[j+1].nameCategory);
				check++;
			}	
		}
	}
	if(check!=-1) {
		printf("id khong hop le\n");
		return ;
	}
}
void toLowerCase(char str[], int length) {
    for (int i = 0; i < length; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
void findCategory(Category categories[],int n) {
	char input[50];
	fflush(stdin);
	printf("Moi ban nhap danh muc can tim kiem:");
	fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    toLowerCase(input,strlen(input));
    int check=-1;
    char temp[50];
    for(int i=0;i<n;i++) {
    	strcpy(temp, categories[i].nameCategory);
        toLowerCase(temp,strlen(temp));
    	if(strstr(input,temp)!=NULL) {
    		printf("Danh muc ban can tim o vi tri:%d\n",i+1);
    		printf("___________________________________________\n");
			printf("|Id     |                 Danh muc        |\n");
			printf("-------------------------------------------\n");
			printf("|%d      |%25s        | \n",categories[i].id,categories[i].nameCategory);
			printf("|_______|_________________________________|\n");
			check++;
		}
	}
	if(check==-1) {
		printf("Danh muc khong co trong cua hang\n");
	}
}
void arrangeCategory(Category categories[],int n,int choose ) {
while(choose!=3) {
	printf("1.Sap xep danh muc tu a->z\n");
	printf("2.Sap xep danh muc tu z->a\n");
	printf("3.Thoat\n");
	printf("Moi ban nhap lua chon cua minh:");
	scanf("%d",&choose);
	switch (choose) {
		case 1://Sap xep tu a->z
			for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (strcmp(categories[j].nameCategory, categories[j+1].nameCategory) > 0) {
            			int count;
                		char temp[100];
                		strcpy(temp, categories[j].nameCategory);
                		strcpy(categories[j].nameCategory, categories[j+1].nameCategory);
                		strcpy(categories[j + 1].nameCategory, temp);
                		
                		count=categories[j].id;
              			categories[j].id=categories[j+1].id;
              			categories[j+1].id=count;
            		}
        		}
    		}
    		printfCategory(categories,n);
		    break;
     	case 2://Sap xep tu z->a
			for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (strcmp(categories[j].nameCategory, categories[j+1].nameCategory) < 0) {
            			int count;
                		char temp[100];
                		strcpy(temp, categories[j].nameCategory);
                		strcpy(categories[j].nameCategory, categories[j+1].nameCategory);
                		strcpy(categories[j + 1].nameCategory, temp);
                		
                		count=categories[j].id;
              			categories[j].id=categories[j+1].id;
              			categories[j+1].id=count;
            		}
        		}
    		}
    		printfCategory(categories,n);
       		break;
       	default:
			printf("Lua chon khong hop le\n");
			break;
     	case 3://Thoat
			break;
	}
}
}
void checkNamecategory(Category categories[],int n) {
	for(int i=0;i<n;i++) {
		int letters =0;
		for(int j=0;j<50;j++) {
			if (((categories[i].nameCategory)[j]>= 'A' && (categories[i].nameCategory)[j] <= 'Z') || ((categories[i].nameCategory)[j] >= 'a' && (categories[i].nameCategory)[j] <= 'z')) {
            letters++;
        }
		}
		if(letters>20) {
			fflush(stdin);
			printf("Do dai danh muc khong hop le moi ban nhap lai danh muc o vi tri %d:",i+1);
			fgets(categories[i].nameCategory,50,stdin);
			categories[i].nameCategory[strcspn(categories[i].nameCategory,"\n")]='\0';
		}
		if(letters==0) {
			fflush(stdin);
			printf("Danh muc khong duoc de trong moi ban nhap lai danh muc o vi tri %d:",i+1);
			fgets(categories[i].nameCategory,50,stdin);
			categories[i].nameCategory[strcspn(categories[i].nameCategory,"\n")]='\0';
		}
	}
	for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n; j++) {
        	 if (strcmp(categories[i].nameCategory, categories[j].nameCategory)==0) {
            	printf("Danh muc (%s) lap lai o vi tri %d va %d\n", categories[i].nameCategory, i+1, j+1);
                printf("Moi ban nhap lai ten danh muc cho 1 trong 2 vi tri:");
                fflush(stdin);
                fgets(categories[i].nameCategory,50,stdin);
				categories[i].nameCategory[strcspn(categories[i].nameCategory,"\n")]='\0';
				
			}
        }
    }
}
void checkIdcategory(Category categories[],int n){
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n; j++) {
            if (categories[i].id == categories[j].id) {
                printf("Id khong duoc trung lap (%d) lap lai o vi tri %d va %d\n", categories[i].id, i+1, j+1);
                printf("Moi ban nhap lai id cho 1 trong 2 vi tri:");
                scanf("%d",&categories[i].id);
                
            }
        }
    }
}
int loadCategory(const char *filename, Category categories[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Khong the mo tep\n");
        return 0;
    }

    int n = 0;
    while (fread(&categories[n], sizeof(Category), 1, file) == 1) {
        n++;
    }

    fclose(file);
    return n;
}
void saveCategory(const char *filename, Category categories[], int n) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Khong the mo tep\n");
        return;
    }

    fwrite(categories, sizeof(Category), n, file);

    fclose(file);
    printf("Danh muc da duoc luu vao tep '%s'.\n", filename);
}


void printfProductfunction() {
	printf("***___Quan ly san pham___***\n");
	printf("=============================\n");
	printf("1.Hien thi san pham\n");
	printf("2.Them san pham\n");
	printf("3.Sua san pham\n");
	printf("4.Xoa san pham\n");
	printf("5.Tim kiem san pham\n");
	printf("6.Sap xep san pham\n");
	printf("7.Thoat\n");
	printf("=============================\n");
}
void printfProduct(Product products[],int n) {
		printf("_____________________________________________________________________________________\n");
		printf("|ID     |Ten san pham             |Danh muc                           |Gia tien     |\n");
		printf("-------------------------------------------------------------------------------------\n");
	for(int i=0;i<n;i++) {
		printf("|%d      |%20s     |%25s          |%.3f\t    | \n",products[i].id,products[i].nameProduct,products[i].nameCategory,products[i].priceProduct);
		printf("|_______|_________________________|___________________________________|_____________|\n");
}
}
void addProduct(Product products[],int n,int location) {
	fflush(stdin);
	printf("Moi ban chon vi tri muon them:");
	scanf("%d",&location);
	getchar();
	
	if(location<1||location>n) {
		printf("Vi tri khong hop le\n");
		return ;
	} else {
		n++;
		for(int i=n-1;i>location-1;i--) {
			products[i].id=products[i-1].id;
			strcpy(products[i].nameProduct, products[i-1].nameProduct);
			strcpy(products[i].nameCategory, products[i-1].nameCategory);
			products[i].priceProduct=products[i-1].priceProduct;
		}
		printf("Moi ban nhap id cho san pham muon them:");
		scanf("%d",&products[location-1].id);
		checkIdproduct(products,n);
		
		fflush(stdin);
		printf("Moi nhap ten san pham muon them:");
		fgets(products[location-1].nameProduct,50,stdin);
		products[location-1].nameProduct[strcspn(products[location-1].nameProduct,"\n")]='\0';
		checkNameproduct(products,n);
		
		printf("Moi nhap danh muc cho san pham vua roi:");
		fgets(products[location-1].nameCategory,50,stdin);
		products[location-1].nameCategory[strcspn(products[location-1].nameCategory,"\n")]='\0';
		
		
		printf("Moi ban nhap gia cho san pham:");
		scanf("%f",&products[location-1].priceProduct);
		}
}
void fixProduct(Product products[],int n,int checkId) {
	fflush(stdin);
	printf("Moi ban chon id muon sua:");
	scanf("%d",&checkId);
	getchar();
	int check=-1;
	for (int i=0;i<n;i++) {
		if(products[i].id==checkId) {
			printf("Moi nhap ten cho san pham muon sua:");
			fgets(products[i].nameProduct,50,stdin);
			products[i].nameProduct[strcspn(products[i].nameProduct,"\n")]='\0';
			printf("Moi nhap ten cho danh muc cua san pham ban muon them:");
			checkNameproduct(products,n);
			fgets(products[i].nameCategory,50,stdin);
			products[i].nameCategory[strcspn(products[i].nameCategory,"\n")]='\0';
			checkNameinventory(products,n);
			printf("Moi ban nhap gia cho san pham:");
			scanf("%f",&products[i].priceProduct);
			check++;
		}
	}
	if(check==-1) {
		printf("id khong hop le\n");
		return ;
	}
}
void deleteProduct(Product products[],int n,int checkId) {
	printf("Moi ban nhap id muon xoa:");
	scanf("%d",&checkId);
	getchar();
	int check=-1;
	for (int i=0;i<n;i++) {
		if(products[i].id==checkId) {
			n--;
			for(int j=i;j<n+1;j++) {
				products[j].id=products[j+1].id;
				strcpy(products[j].nameProduct,products[j+1].nameProduct);
				strcpy(products[j].nameCategory,products[j+1].nameCategory);
				products[j].priceProduct=products[j+1].priceProduct;
				check++;
			}
		}
	}
	if(check!=-1) {
		printf("id khong hop le\n");
		return ;
	}
}
void findProduct(Product products[],int n) {
		char input[50];
		fflush(stdin);
		printf("Moi ban nhap san pham can tim kiem:");
		fgets(input, 50, stdin);
    	input[strcspn(input, "\n")] = '\0';
    	toLowerCase(input,strlen(input));
    	int check=-1;
    	char temp[50];
    	for(int i=0;i<n;i++) {
    		strcpy(temp, products[i].nameProduct);
        	toLowerCase(temp,strlen(temp));
    		if(strstr(input,temp)!=NULL) {
    			printf("Danh muc ban can tim o vi tri:%d\n",i+1);
    			printf("_____________________________________________________________________________________\n");
				printf("|ID     |Ten san pham             |Danh muc                           |Gia tien     |\n");
				printf("-------------------------------------------------------------------------------------\n");
				printf("|%d      |%20s     |%25s          |%.3f\t    | \n",products[i].id,products[i].nameProduct,products[i].nameCategory,products[i].priceProduct);
				printf("|_______|_________________________|___________________________________|_____________|\n");
				check++;
			}
		}
		if(check==-1) {
		printf("San pham khong co trong cua hang\n");
		}
}
void arrangeProduct(Product products[],int n,int choose) {
	while(choose!=3) {
	printf("1.Sap xep danh muc tu a->z\n");
	printf("2.Sap xep danh muc tu z->a\n");
	printf("3.Thoat\n");
	printf("Moi ban nhap lua chon cua minh:");
	scanf("%d",&choose);
	switch (choose) {
		case 1://Sap xep tu a->z
			for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (strcmp(products[j].nameProduct, products[j+1].nameProduct) > 0) {
            			int count;
                		char temp[100];
                		strcpy(temp, products[j].nameProduct);
                		strcpy(products[j].nameProduct, products[j+1].nameProduct);
                		strcpy(products[j + 1].nameProduct, temp);
                		
                		strcpy(temp, products[j].nameCategory);
                		strcpy(products[j].nameCategory, products[j+1].nameCategory);
                		strcpy(products[j + 1].nameCategory, temp);
                		
				  		count=products[j].id;
              			products[j].id=products[j+1].id;
              			products[j+1].id=count;
              			
              			count=products[j].priceProduct;
              			products[j].priceProduct=products[j+1].priceProduct;
              			products[j+1].priceProduct=count;
            		}
        		}
    		}
    		printfProduct(products,n);
		    break;
     	case 2://Sap xep tu z->a
			for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (strcmp(products[j].nameProduct, products[j+1].nameProduct) < 0) {
            			int count;
                		char temp[100];
                		strcpy(temp, products[j].nameProduct);
                		strcpy(products[j].nameProduct, products[j+1].nameProduct);
                		strcpy(products[j + 1].nameProduct, temp);

                		strcpy(temp, products[j].nameCategory);
                		strcpy(products[j].nameCategory, products[j+1].nameCategory);
                		strcpy(products[j + 1].nameCategory, temp);

				  		count=products[j].id;
              			products[j].id=products[j+1].id;
              			products[j+1].id=count;

              			count=products[j].priceProduct;
              			products[j].priceProduct=products[j+1].priceProduct;
              			products[j+1].priceProduct=count;
            		}
        		}
    		}
    		printfProduct(products,n);
       		break;
       	default:
			printf("Lua chon khong hop le\n");
			break;
     	case 3://Thoat
			break;
	}
}
}
void checkNameproduct(Product products[],int n) {
	for(int i=0;i<n;i++) {
		int letter =0;
		for(int j=0;j<50;j++) {
			if ((products[i].nameProduct[j]>= 'A' && products[i].nameProduct[j] <= 'Z') || (products[i].nameProduct[j] >= 'a' && products[i].nameProduct[j] <= 'z')) {
            letter++;
        }
		}
		if(letter>25) {
			fflush(stdin);
			printf("Do dai san pham khong hop le moi ban nhap lai san pham o vi tri %d:",i+1);
			fgets(products[i].nameProduct,50,stdin);
			products[i].nameProduct[strcspn(products[i].nameProduct,"\n")]='\0';
		}
		if(letter==0) {
			fflush(stdin);
			printf("San pham khong duoc de trong moi ban nhap lai san pham o vi tri %d:",i+1);
			fgets(products[i].nameProduct,50,stdin);
			products[i].nameProduct[strcspn(products[i].nameProduct,"\n")]='\0';
		}
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        	 if (strcmp(products[i].nameProduct, products[j].nameProduct)==0) {
            	printf("San pham (%s) lap lai o vi tri %d va %d\n", products[i].nameProduct, i, j);
                printf("Moi ban nhap lai ten san pham cho 1 trong 2 vi tri:");
                fflush(stdin);
                fgets(products[i].nameProduct,50,stdin);
				products[i].nameProduct[strcspn(products[i].nameProduct,"\n")]='\0';

			}
        }
    }
}
void checkNameinventory(Product products[],int n) {
	int count =0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<50;j++) {
			if ((products[i].nameCategory[j]>= 'A' && products[i].nameCategory[j] <= 'Z') || (products[i].nameCategory[j] >= 'a' && products[i].nameCategory[j] <= 'z')) {
            count++;
        }
		}
		
		if(count>25) {
			fflush(stdin);
			printf("Do dai danh muc khong hop le moi ban nhap lai danh muc o vi tri %d:",i+1);
			fgets(products[i].nameCategory,50,stdin);
			products[i].nameCategory[strcspn(products[i].nameCategory,"\n")]='\0';
		}
		if(count==0) {
			fflush(stdin);
			printf("Danh muc khong duoc de trong moi ban nhap lai danh muc o vi tri %d:",i+1);
			fgets(products[i].nameCategory,50,stdin);
			products[i].nameCategory[strcspn(products[i].nameCategory,"\n")]='\0';
		}
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        	 if (strcmp(products[i].nameCategory, products[j].nameCategory)==0) {
            	printf("Danh muc (%s) lap lai o vi tri %d va %d\n", products[i].nameCategory, i, j);
                printf("Moi ban nhap lai danh muc cho 1 trong 2 vi tri:");
                fflush(stdin);
                fgets(products[i].nameCategory,50,stdin);
				products[i].nameCategory[strcspn(products[i].nameCategory,"\n")]='\0';

			}
        }
    }
}
void checkIdproduct(Product products[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (products[i].id == products[j].id) {
                printf("Id khong duoc trung lap (%d) lap lai o vi tri %d va %d\n", products[i].id, i, j);
                printf("Moi ban nhap lai id cho 1 trong 2 vi tri:");
                scanf("%d",&products[i].id);
            }
        }
    }
}
int loadProduct(const char *filename, Product products[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Khong the mo tep\n");
        return 0;
    }

    int n = 0;
    while (fread(&products[n], sizeof(Product), 1, file) == 1) {
        n++;
    }

    fclose(file);
    return n;
}
void saveProduct(const char *filename, Product products[], int n) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Khong the mo tep\n");
        return;
    }

    fwrite(products, sizeof(Product), n, file);

    fclose(file);
    printf("Danh muc da duoc luu vao tep '%s'.\n", filename);
}











