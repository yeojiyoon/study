#include <stdio.h>

int Binary_Search(int ary[], int search, int low, int high);

int main(void)
{
    int search = 7;
    int array[7] = {1, 3, 4, 6, 7, 9, 10};

    printf("%d", Binary_Search(array, search, 0, 6));
    printf("test");
}


int Binary_Search(int ary[], int search, int low, int high)
{
    int mid;

    if (low > high) return 0;
    else mid = (low + high) / 2;

    if(ary[mid] == search)
        return mid;
    else if (search < ary[mid])
        return Binary_Search(ary, search, low, mid-1);
    else
        return Binary_Search(ary, search, mid+1, high);
}