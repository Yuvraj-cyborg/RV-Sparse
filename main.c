#include<stdio.h>

int main() {
    int arr[3][3];
    int num[10];
    int idx[10];
    int k=0;
    int a=0;

    printf("enter inputs for array :- \n");

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("==================== \n");
    
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("==================== \n");

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(arr[i][j] == 0) {
                continue;
            }
            else {
                num[k]=arr[i][j];
                idx[k]=i * 3 + j;
                k++;
            }
        }
    }    

    while(a != k) {
        printf("%d\t",num[a]);
        printf("%d\n",idx[a]);
        a++;
    }
}
