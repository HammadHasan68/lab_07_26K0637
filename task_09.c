#include<stdio.h>

int main(){
    int depart,employees,days,salary;
    int departTotal,grandTotal;

    printf("\n_________________________________________________");
    printf("\nEnter number of Departments in Company: ");
    scanf("%d",&depart);
    printf("\n_________________________________________________");

    for(int i=1;i<=depart;i++){
        printf("\nEnter number of Employees in Depart %d: ",i);
        scanf("%d",&employees);
        printf("\n_________________________________________________");
        departTotal = 0;
        for(int j=1;j<=employees;j++){
            printf("\nEnter number of days worked by Employee %d: ",j);
            scanf("%d",&days);
            
            salary = (500*days);
            if(days>25){
                salary+=2000;
            }
            
            printf("\nDepartment %d ,Employee %d ,Days Worked = %d ,Salary = Rs. %d",i,j,days,salary);
            printf("\n_________________________________________________");

            departTotal += salary;
        }
        printf("\nTotal salary for Department %d: Rs. %d\n", i, departTotal);
        printf("\n_________________________________________________");
        grandTotal += departTotal;
        
        
    }
    printf("\nTotal salary paid across all departments: Rs. %d\n", grandTotal);
    printf("\n_____________________________________________________");

    return 0;
}