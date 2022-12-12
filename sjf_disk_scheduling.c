#include<stdio.h>

int main()
{
    int initial, n, c=0, total = 0;
    printf("Enter the initial head position and no. of disk track: ");
    scanf("%d %d", &initial, &n);

    int arr[n];
    printf("Enter the disk track: ");
    for(int i=0 ; i<n ; i++)    
        scanf("%d", &arr[i]);
    while(c != n){
        int d = 10000, ind;
        for(int i=0 ; i<n ; i++){
            int l = initial - arr[i];

            if(l < 0)
                l *= -1;
            if(l < d){
                d = l;
                ind = i;
            }
        }

        initial = arr[ind];
        arr[ind] = 10000;
        total += d;
        c++;
    }
    printf("%d", total);
    return 0;
}