#include <stdio.h>
#include <string.h>
#include <math.h>
#define SHOP_LEN 3
#define STUDENTS_LEN 3
#define ROWS 7

typedef struct
{
    char name[40];
    float cost;
    int count;
} product;

typedef struct
{
    char day[20];
    char month[20];
    char year[40];
} data;

typedef struct
{
    char full_name[50];
    char group[50];
    data date;
} student;

typedef struct
{
    float real;
    float imaginary;
} complex_number;

typedef struct
{
    char name[50];
    char breed[50];
    char color[50];
    double height;
    double weight;
    char birthday[50];
} csv_row;

void add_complex_numbers(complex_number a, complex_number b,
complex_number *res, int param)
{
    if (param > 0)
    {
        res->real = a.real + b.real;
        res->imaginary = a.imaginary + b.imaginary;
    }
    else
    {
        res->real = a.real - b.real;
        res->imaginary = a.imaginary - b.imaginary;
    }
}

void mult_complex_numbers(complex_number a, complex_number b,
complex_number *res)
{
    res->real = a.real*b.real - a.imaginary*b.imaginary;
    res->imaginary = a.imaginary*b.real + a.real*b.imaginary;
}

void divide_complex_numbers(complex_number a, complex_number b,
complex_number *res)
{
    if (b.real == 0 && b.imaginary == 0)
        printf("\nZero division error\n");
    else
    {
        res->real = (a.real*b.real + a.imaginary*b.imaginary)
        / (b.real*b.real + b.imaginary*b.imaginary);
        res->imaginary = (a.imaginary*b.real - a.real*b.imaginary)
        / (b.real*b.real + b.imaginary*b.imaginary);
    }
}

void scalar_mult_complex_numbers(complex_number *num, float scalar)
{
    num->real *= scalar;
    num->imaginary *= scalar;
}

void print_complex_number(complex_number num)
{
    if (num.imaginary < 0)
        printf("%g - %gi\n", num.real, (fabs(num.imaginary)));
     else if (num.imaginary == 0)
        printf("%g\n", num.real);
    else
        printf("%g + %gi\n", num.real, num.imaginary);
}

void bubble_sort(student *students, int array_lenght)
{
    student temp;
    for (int i = 0; i < array_lenght; i++)
    {
      for (int j = i + 1; j < array_lenght; j++)
      {
          if (strcmp(students[i].full_name, students[j].full_name) > 0)
          {
            temp = students[i];
            students[i] = students[j];
            students[j] = temp;
          }
       }
    }
}

int main()
{
    // Task 1
    int count_goods = 0;
    float inp_cost;
    product shop[SHOP_LEN];

    for (int i = 0; i < SHOP_LEN; i++)
    {
        printf("Insert name, cost and number of the product %i\n", i+1);
        scanf("%s", (shop[i].name));
        scanf("%g", &(shop[i].cost));
        scanf("%d", &(shop[i].count));
    }

    printf("\nList of products:\n");

    for (int i = 0; i < SHOP_LEN; i++)
        printf("Product %d - %s, %g, %d\n", i+1, shop[i].name,
        shop[i].cost, shop[i].count);

    puts("\nInsert a product cost to filter goods");
    scanf("%g", &inp_cost);

    for (int i = 0; i < SHOP_LEN; i++)
    {
        if (shop[i].cost > inp_cost)
        {
            printf("\nProduct %i - %s, %g, %d\n", i+1, shop[i].name,
            shop[i].cost, shop[i].count);
            count_goods++;
        }
    }

    if (!count_goods)
        puts("\nThere is no such products in the shop\n");

    // Task 2
    student students[STUDENTS_LEN];
    for (int i = 0; i < STUDENTS_LEN; i++)
    {
        printf("\nInsert full name\n");
        scanf("%s", students[i].full_name);

        printf("group\n");
        scanf("%s", students[i].group);

        printf("Date of birth in format dd.mm.yyyy separated by new line\n");
        scanf("%s", students[i].date.day);
        scanf("%s", students[i].date.month);
        scanf("%s", students[i].date.year);
    }

    bubble_sort(students, STUDENTS_LEN);
    printf("\nSorted List of students:\n");

    for (int i = 0; i < STUDENTS_LEN; i++)
        printf("%d. %-7s %s.%s.%s %7s\n", i+1, students[i].full_name,
        students[i].date.day, students[i].date.month, students[i].date.year,
        students[i].group);

    printf("\n");

    // Task 3
    complex_number a = {1, 7};
    complex_number b = {1, 1};
    complex_number z, z1, z2;

    add_complex_numbers(a, b, &z, 1);
    mult_complex_numbers(a, b, &z1);
    divide_complex_numbers(a, b, &z2);
    scalar_mult_complex_numbers(&a, 5);

    print_complex_number(z);
    print_complex_number(z1);
    print_complex_number(z2);
    print_complex_number(a);

    printf("\n");

    // Task 4
    FILE *pFile= fopen("b.txt", "rt");
    student test[STUDENTS_LEN];

    if (pFile == NULL)
        return 1;

    for (int i = 0; i < STUDENTS_LEN; i++)
        fread(&test[i], sizeof(student), 1, pFile);
/*
    for (int i = 0; i < STUDENTS_LEN; i++)
    {   
        fwrite(&students[i].full_name, 50, 1, pFile);
        fwrite(&students[i].group, 50, 1, pFile);
        fwrite(&students[i].date, sizeof(data), 1, pFile);
    }
*/  

    for (int i = 0; i < STUDENTS_LEN; i++)
    {
        printf("%d. %-15s, %s.%s.%s, %s\n", i+1, test[i].full_name, test[i].date.day, 
        test[i].date.month, test[i].date.year, test[i].group);
    }

    printf("\n");
    fclose(pFile);

    // Task 5
    FILE *file = fopen("test.bin", "rb");
    product shop1[SHOP_LEN]; 

    if (file == NULL)
        return 1;
/*    
    for (int i = 0; i < SHOP_LEN; i++)
        fwrite(&shop[i], sizeof(product), 1, file);
*/
    for (int i = 0; i < SHOP_LEN; i++)
        fread(&shop1[i], sizeof(product), 1, file);

    printf("List of products:\n");
    for (int i = 0; i < SHOP_LEN; i++)
        printf("Product %d - %-7s, %g, %d\n", i+1, shop1[i].name,
        shop1[i].cost, shop1[i].count);

    printf("\n");
    fclose(file);

    // Task 6
    FILE *dog_file = fopen("dogs.txt", "rt");
    if (dog_file == NULL)
        return 1;

    csv_row row_0 = {"Bella", "Labrador", "Brown", 56, 24, "2013-07-01"};
    csv_row row_1 = {"Charlie", "Poodle", "Black", 43, 24, "2016-09-16"};
    csv_row row_2 = {"Lucy", "Chow Chow", "Brown", 46, 24, "2014-08-25"};
    csv_row row_3 = {"Cooper", "Schnauzer", "Gray", 49, 17, "2011-12-11"};
    csv_row row_4 = {"Max", "Labrador", "Black", 59, 29, "2017-01-20"};
    csv_row row_5 = {"Stella", "Chihuahua", "Tan", 18, 2, "2015-04-20"};
    csv_row row_6 = {"Bernie", "St. Bernard", "White", 77, 74, "2018-02-27"};

    csv_row dogs_csv[ROWS] = {row_0, row_1, row_2, row_3, row_4, row_5, row_6};
    csv_row new[ROWS];

    for (int i = 0; i < ROWS; ++i)
        fread(&new[i], sizeof(csv_row), 1, dog_file);
/*
    for (int i = 0; i < ROWS; ++i)
        fwrite(&dogs_csv[i], sizeof(csv_row), 1, dog_file);
*/

    puts("Csv file of dogs:\n");
    for (int i = 0; i < ROWS; ++i)
        printf("%-d. %-15s %-15s %-15s %-11g %-11g %-11s\n", i, dogs_csv[i].name, dogs_csv[i].breed,
            dogs_csv[i].color, dogs_csv[i].height, dogs_csv[i].weight, dogs_csv[i].birthday);

/*
    puts("Csv file of dogs:\n");
    for (int i = 0; i < ROWS; ++i)
        printf("%-d. %-15s %-15s %-15s %-11g %-11g %-11s\n", i, new[i].name, new[i].breed,
            new[i].color, new[i].height, new[i].weight, new[i].birthday);
*/
    fclose(dog_file);

    return 0;
}
