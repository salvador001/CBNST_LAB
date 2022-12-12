#include<stdio.h>


int predictPage(int page[], int frames[], int n, int nf, int pageIndex){
    int result = -1, farthestPage = pageIndex;
    int i;
    for(i=0 ; i<nf ; i++){
        int j;
        for(j=pageIndex ; j<n ; j++){
            if(frames[i] == page[j]){
                if(j > farthestPage){
                    farthestPage = j;
                    result = i;
                }
                break;
            }
        }
        if(j == n)
            return i;
    }

    if(result == -1)
        return 0;
    return result;
}

int search(int key, int frames[], int index){
    for(int i=0 ; i<index ; i++){
        if(frames[i] == key)
            return 1;
    }
    return 0;
}

void find(int page[], int frames[], int n, int nf){
    int index = 0, hits = 0;
    for(int i=0 ; i<n ; i++){
        if(search(page[i], frames, index)){
            hits++;
            continue;
        }

        if(index < nf){
            frames[index++] = page[i];
        }
        else{
            int j = predictPage(page, frames, n, nf, i+1);
            frames[j] = page[i];
        }
    }
    printf("Page Fault: %d", n-hits);
}


int main()
{
    int n, nf;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int page[n];
    for(int i=0 ; i<n ; i++){
        scanf("%d", &page[i]);
    }

    printf("Enter the frame size: ");
    scanf("%d", &nf);
    int frames[nf];
    find(page, frames, n, nf);
    return 0;
}