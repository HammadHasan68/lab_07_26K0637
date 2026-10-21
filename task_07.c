#include<stdio.h>

int main(){
    int n;

    printf("\n Enter nth value: ");
    scanf("%d",&n);


    printf("\nTriangular pattern of digits\n");
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    
    printf("\nReverse Triangular pattern of digits\n");
    for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    
    printf("\nTriangular pattern of Multiples\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%3d",(i*j));
        }
        printf("\n");
    }

    return 0;
}