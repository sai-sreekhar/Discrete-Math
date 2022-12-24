#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void readFile(FILE *filePointer, int *n)
{
    fscanf(filePointer, "%d", n);
}

void setAdjacencyMatrix(int adjacencyMatrix[20][20], int degreeArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                count++;
            }
        }
        degreeArray[i] = count;
    }
}

void arrange(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
}

void setEdges(FILE *filePointer, int arr[20][20], int e, int *a, int *b, char *c)
{
    for (int i = 0; i < e; i++)
    {
        fscanf(filePointer, "%d%c%d", a, c, b);
        arr[*a - 1][*b - 1] = 1;
        arr[*b - 1][*a - 1] = 1;
    }
}

void sortDegreesArray(int arr[], int len)
{
    arrange(arr, len);
}

void getDegreeArray(FILE *filePointer, int *v, int *e, int arr[20][20], int degreeArray[20], int *a, int *b, char *c)
{

    readFile(filePointer, v);
    readFile(filePointer, e);

    setEdges(filePointer, arr, *e, a, b, c);

    setAdjacencyMatrix(arr, degreeArray, *v);
    sortDegreesArray(degreeArray, *v);
}

bool compareDegreeArray(int degreeArray1[20], int degreeArray2[20], int n)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (degreeArray1[i] == degreeArray2[i])
        {
            flag = flag * 1;
        }
        else
        {
            flag = flag * 0;
        }
    }
    return flag;
}

bool compareInvariants(int vertex1, int vertex2, int edge1, int edge2, int degreeArray1[20], int degreeArray2[20])
{
    if (vertex1 == vertex2)
    {
        if (edge1 == edge2 && compareDegreeArray(degreeArray1, degreeArray2, vertex1))
        {
            return true;
        }
        return false;
    }
    return false;
}

bool compareAdjMatrix(int arr1[20][20], int arr2[20][20], int n)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i][j] == arr2[i][j])
            {
                flag = flag * 1;
            }
            else
            {
                flag = flag * 0;
            }
        }
    }
    return flag;
}

bool isBijection(int b[], int arr1[20][20], int arr2[20][20], int size)
{
    int temp[20][20];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][j] = arr2[b[i] - 1][b[j] - 1];
        }
    }
    return compareAdjMatrix(temp, arr1, size);
}

void displayBijection(int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", i + 1);
        printf("%d\n", b[i]);
    }
    printf("\n");
}

void getAllCombinations(int arr[], int arr1[20][20], int arr2[20][20], int index_0, int index_n, bool *isIsomorphic)
{
    if (index_0 == index_n)
    {
        if (isBijection(arr, arr1, arr2, index_n + 1))
        {
            *isIsomorphic = true;
            printf("Isomorphic\n");
            displayBijection(arr, index_n + 1);
        }
        return;
    }
    int i;
    for (i = index_0; i < (index_n + 1); i++)
    {
        swap(&(arr[i]), &(arr[index_0]));
        getAllCombinations(arr, arr1, arr2, index_0 + 1, index_n, isIsomorphic);
        if (*isIsomorphic)
        {
            break;
        }
        swap(&(arr[i]), &(arr[index_0]));
    }
}

void isIsomorphic(int arr1[20][20], int arr2[20][20], int vertex1, int vertex2, int edge1, int edge2, int degreeArray1[20], int degreeArray2[20], int b[])
{
    bool isIsomorphic;

    if (!compareInvariants(vertex1, vertex2, edge1, edge2, degreeArray1, degreeArray2))
    {
        printf("Not Isomorphic, No bijections found\n");
        return;
    }
    else
    {
        if (compareAdjMatrix(arr1, arr2, vertex1))
        {
            return;
        }
        else
        {
            getAllCombinations(b, arr1, arr2, 0, vertex1 - 1, &isIsomorphic);
            if (!isIsomorphic)
            {
                printf("Not Isomorphic, No bijections found\n");
            }
            return;
        }
    }
}

void setArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = i + 1;
    }
}

int main(int argc, char *argv[])
{
    char inputFile1[20];
    strcpy(inputFile1, argv[1]);
    FILE *filePointer = fopen(inputFile1, "r");
    int vertex1, edge1, a1, b1;
    char c1;

    int adjacencyMatrix1[20][20] = {0};
    int degreeArray1[20];
    getDegreeArray(filePointer, &vertex1, &edge1, adjacencyMatrix1, degreeArray1, &a1, &b1, &c1);

    char inputFile2[20];
    strcpy(inputFile2, argv[2]);
    FILE *file2 = fopen(inputFile2, "r");
    char outputFileName[20];
    strcpy(outputFileName, argv[3]);
    freopen(outputFileName, "w", stdout);
    int vertex2, edge2, a2, b2;
    char c2;

    int adjacencyArray2[20][20] = {0};
    int degreeArray2[20];

    getDegreeArray(file2, &vertex2, &edge2, adjacencyArray2, degreeArray2, &a2, &b2, &c2);

    int arr1[20];
    int arr2[20];
    setArray(arr1, vertex1);
    setArray(arr2, vertex1);

    isIsomorphic(adjacencyMatrix1, adjacencyArray2, vertex1, vertex2, edge1, edge2, degreeArray1, degreeArray2, arr2);
}