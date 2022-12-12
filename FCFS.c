#include<stdio.h>

void sort(int arr[][2], int n){
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[j][0] < arr[i][0]){
                int a = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = a;

                int b = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = b;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arr[n][2];
    for(int i=0 ; i<n ; i++){
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    sort(arr, n);

    int wait[n], tat[n], ct[n];
    float avg_wait = 0, avg_tat = 0;

    ct[0] = arr[0][1];

    for(int i=1 ; i<n ; i++){
        ct[i] = ct[i-1] + arr[i][1];
    }

    for(int i=0 ; i<n ; i++){
        tat[i] = ct[i] - arr[i][0];
        avg_tat = avg_tat + tat[i];
    }

    for(int i=0 ; i<n ; i++){
        wait[i] = tat[i] - arr[i][1]; 
        avg_wait = wait[i] + avg_wait;
    }

    printf("Process\t\tArrival Time\t\tBurstTime\t\tTurnAroundTime\t\tWaitingTIme\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arr[i][0], arr[i][1], tat[i], wait[i]);
    }

    printf("Average turn Around Time is %f\n", avg_tat/n);
    printf("Average waiting Time is %f\n", avg_wait/n);
    return 0;
}