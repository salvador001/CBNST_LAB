#include<stdio.h>

int main()
{
    int i, j, k, l, n, nf, a, b, count = 0, pos;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the page string: ");
    for(i=0 ; i<n ; i++)
        scanf("%d", &arr[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &nf);

    int frames[nf], temp[nf];
    for(k=0 ; k<nf ; k++)
        frames[k] = -1;
    
    for(i=0 ; i<n ; i++){
        printf("%d", arr[i]);
        a=0, b=0;
        for(k=0 ; k<nf ; k++){
            if(frames[k] == arr[i]){
                a=1;
                b=1;
                break;
            }
        }

        if(a == 0){
            for(k=0 ; k<nf ; k++){
                if(frames[k] == -1){
                    frames[k] = arr[i];
                    count++;
                    b=1;
                }
            }
        }

        if(b == 0){
            for(k=0 ; k<nf ; k++){
                temp[k] = 0;
            }

            for(j=i-1, l=1 ; l<=nf-1 ; l++, j--){
                for(k=0 ; k<nf ; k++){
                    if(frames[k] == arr[j]){
                        temp[k] = 1;
                    }
                }
            }

            for(k=0 ; k<nf ; k++){
                if(temp[k] == 0)
                    pos = k;
            }

            frames[pos] = arr[i];
            count++;
        }
        for(k=0 ; k<nf ; k++){
            printf("%d\t", frames[k]);
        }
    printf("\n");
    }
}