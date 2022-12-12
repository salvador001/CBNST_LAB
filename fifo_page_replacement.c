#include<stdio.h>

int main()
{
    int n, i, j, k, count=0, nf;
    int avail;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the page string: ");
    for(i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter the no. of frames: ");
    scanf("%d", &nf);
    int frames[nf];

    for(k=0 ; k<nf ; k++){
        frames[k] = -1;
    }

    j=0;
    printf("ref string\t\tpage frames\n");
    for(i=0 ; i<n ; i++){
        printf("%d", a[i]);
        avail = 0;
        for(k=0 ; k<nf ; k++){
            if(frames[k] == a[i]){
                avail = 1;
            }
        }

        if(avail == 0){
            frames[j] = a[i];
            j = (j+1)%nf;
            count++;
            for(k=0 ; k<nf ; k++){
                printf("%d\t", frames[k]);
            }
        }
        printf("\n");
    }
    printf("Page fault: %d", count);
    return 0;
}