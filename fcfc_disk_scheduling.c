#include<stdio.h>

int main()
{
    int n, initial;
    printf("Enter the initial head position and no. of disk tracks: ");
    scanf("%d %d", &initial, &n);
    int arr[n];
    printf("Enter the disk tracks numbers: ");
    for(int i=0 ; i<n ; i++)
        scanf("%d", &arr[i]);

    int total = initial - arr[0];
    if(total < 0)
        total *= -1;
    for(int i=1 ; i<n ; i++){
        int a = arr[i-1] - arr[i];

        if(a<0)
            a *= -1;
        
        total += a;
    }
    printf("The total amount is: %d", total);
    return 0;
}