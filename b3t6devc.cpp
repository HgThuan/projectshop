#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int atm(int a[],int n,int total,bool isPick[],int *bestPick,int countMoney,int sumMoney,bool bestIsPick[],int step){
    //n thay cho cMoney
    //Dieu kien  de cap nhat bestSolution
    if (sumMoney==total && *bestPick>countMoney){
        for(int i=0;i<n;i++) bestIsPick[i]=isPick[i];
        *bestIsPick=countMoney;
        return 0;
    }
    // Dieu Kien dung de quy
    if (step==n || countMoney>=*bestPick) return 0;
    atm(a,n,total,isPick,bestPick,countMoney,sumMoney,bestIsPick,step+1);//Khong cho to tien thu(step)
    if(sumMoney+a[step]<=total){
        isPick[step]=true;
        sumMoney+=a[step];
        countMoney++;
    //Goi lai de de quy
    atm(a,n,total,isPick,bestPick,countMoney,sumMoney,bestIsPick,step+1);// cho to tien thu (step)
        isPick[step]=false;
        sumMoney-=a[step];
        countMoney--;

    }
}
main(){
    printf("--------------ATM-------------");
    printf("\nNhap so tien:\n");
    int cMoney,money,i;
    //cMoney: so to tien
    //Money : so tien
    scanf("%d",&cMoney);
    int a[35];
    for(i=0;i<cMoney;i++){
        printf("A[%d]=",i+1);
        scanf("%d",&a[i]);

    }
    printf("Press Ente to apply your ATM...");
    fflush(stdin);
    getchar();
    do
    {

       printf("--------------ATM-------------");
    //coutMoney so tien hien tai de so sanh voi cMoney
       int bestPick=1000000000,coutMoney=0,sumMoney=0,step=0;
       printf("\nNhap so tien ban muon rut ( Nhan 0 de thoat):");
       scanf("%d",&money);
       if(money!=0){
        // isPick de ghi nhan xem to tien rut dung hay ko
        bool isPick[100],bestIsPick[100];
        for(int i=0;i<cMoney;i++) isPick[i]=false; // ban dau khoi tao la false
        atm(a,cMoney,money,isPick,&bestPick,coutMoney,sumMoney,bestIsPick,step);
        if(bestPick==1000000000) printf("Khong du tien !");
        else{
            printf("Tong so tien la %d:\n",bestPick);
        for (int i = 0;i < cMoney; i++)
        {
            if(bestIsPick[i]) printf("%d",a[i]);

        }
        }
       }
       fflush(stdin);
       getchar();
    } while (money!=0);
    
}
