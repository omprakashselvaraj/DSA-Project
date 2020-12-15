#include<stdio.h>
#include<conio.h>
struct profit
{
    int buy;
    int sell;
};
void stockspan(void);
int maxprofit(void);
void push(int [],int* ,int);
void pop(int [],int*);
int main()
{
    int opt;
    char ch;
    printf("\n\t\t\t\t\t\t\t **********************************************");
    printf("\n\t\t\t\t\t\t\t *WELCOME TO STOCK MARKET FINANCIAL ASSISTANCE*");
    printf("\n\t\t\t\t\t\t\t **********************************************");
    printf("\n\t\t\t\t\t\t\t **************************");
    printf("\n\t\t\t\t\t\t\t * PRESS ENTER TO PROCEED *");
    printf("\n\t\t\t\t\t\t\t **************************");
    ch=fgetc(stdin);
    if(ch==0x0A)
    {
       while(1)
       {
            printf("\n\t\t\t\t\t\t\t ***************************************");
            printf("\n\t\t\t\t\t\t\t *HOW CAN WE HELP YOU?                 *");
            printf("\n\t\t\t\t\t\t\t *CHOOSE OPTION IN MENU:               *");
            printf("\n\t\t\t\t\t\t\t *1.STOCK SPAN CALCULATOR              *");
            printf("\n\t\t\t\t\t\t\t *2.BUY STOCK AND SELL TO MAXIMUM PRICE*");
            printf("\n\t\t\t\t\t\t\t *3.EXIT                               *");
            printf("\n\t\t\t\t\t\t\t ***************************************\n\t\t\t\t\t\t\t ");
            scanf("%d",&opt);
            switch(opt)
            {
                case 1:
                    stockspan();
                    break;
                case 2:
                    maxprofit();
                    break;
                case 3:
                    return 0;
            }
            printf("\n\n\t\t\t\t\t\t\t **********************************************");
        }
    }
}
void stockspan(void)
{
    int n,i,a;
    int stack[50],j=-1;
    int *top=&j;
    Y:
    printf("\n\n\t\t\t\t\t\t\t HOW MANY DAYS STOCK PRICE YOU HAVE?\n\t\t\t\t\t\t\t ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("\n\t\t\t\t\t\t\t CAN'T CALCULATE SPAN WITH ONE DAY STOCK PRICE");
        printf("\n\t\t\t\t\t\t\t PRESS 1 TO RE-ENTER DATA\n\t\t\t\t\t\t\t ");
        scanf("%d",&a);
        if(a==1)
        {
            goto Y;
        }
    }
    else
    {
        int stock[n],span[n];
        span[0]=1;
        for(i=0;i<n;i++)
        {
            printf("\n\t\t\t\t\t\t\t ENTER STOCK PRICE FOR DAY %d: ",i+1);
            scanf("%d",&stock[i]);
        }
        push(stack,top,0);
        for(i=1;i<n;i++)
        {
            while(*top!=-1 && stock[stack[*top]]<=stock[i])
            {
                pop(stack,top);
            }
            if(*top==-1)
            {
                span[i]=i+1;
            }
            else
            {
                span[i]=i-stack[*top];
                push(stack,top,i);
            }
        }
        printf("\n\t\t\t\t\t\t\t\t DAY\t PRICE\t SPAN");
        printf("\n\t\t\t\t\t\t\t\t ***\t *****\t ****");
        for(i=0;i<n;i++)
        {
            printf("\n\t\t\t\t\t\t\t\t %d\t %d\t %d",i+1,stock[i],span[i]);
        }
    }
}

void push(int stack[],int *top,int x)
{
    *top=*top+1;
    stack[*top]=x;
}

void pop(int stack[],int *top)
{
    *top=*top-1;
}

int maxprofit(void)
{
    int n;
    X:
    printf("\n\n\t\t\t\t\t\t\t HOW MANY DAYS STOCK PRICES YOU HAVE?\n\t\t\t\t\t\t\t ");
    scanf("%d",&n);
    int stock[n],i;
    if(n==1)
    {
        int r;
        printf("\n\t\t\t\t\t\t\t CAN'T CALCULATE PROFIT WITH ONE DAY STOCK PRICE!!!\n");
        printf("\t\t\t\t\t\t\t\t ENTER 1 RE-ENTER CHOICE");
        scanf("%d",&r);
        if(r==1)
            goto X;
        else
            return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            printf("\n\t\t\t\t\t\t\t ENTER STOCK PRICE FOR DAY %d: ",i+1);
            scanf("%d",&stock[i]);
        }
    }
    struct profit solution[n/2+1];
    i=0;
    int count=0;
    while(i<n-1)
    {
        while(i<n-1 && stock[i]>=stock[i+1])
        {
            i++;
        }
        if(i==n-1)
            break;
        solution[count].buy=i++;
        while(i<n && stock[i]>=stock[i-1])
        {
            i++;
        }
        solution[count].sell=i-1;
        count++;
    }
    if(count==0)
    {
        printf("\n\t\t\t\t\t\t\t NO PROFIT ON BUYING AND SELLING STOCK IN THESE PRICES!!!");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t NUMBER OF MAXIMUM POSSIBILITY PROFIT=%d",count);
        printf("\n\t\t\t\t\t\t\t S.NO    BUY ON    SELL ON    PROFIT    PROFIT PERCENTAGE");
        printf("\n\t\t\t\t\t\t\t ****    *** **    **** **    ******    ****** **********");
        for(i=0;i<count;i++)
        {
            float pro,p,q;
            float per;
            p=stock[solution[i].sell];
            q=stock[solution[i].buy];
            pro=p-q;
            per=(pro/p)*100;
            printf("\n\t\t\t\t\t\t\t %d       %d         %d           %.2f     %.2f",i+1,solution[i].buy+1,solution[i].sell+1,pro,per);
        }
    }
}
