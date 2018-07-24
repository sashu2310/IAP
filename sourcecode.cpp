#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<utility>
#include<set>
#include<time.h>
#define ll long long int
#define pb push_back
#define RAND_MAX 100
#define repo(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rep2(i,n) for(i=2;i<=n;i++)
#define repa(i,a,n) for(i=a;i<=n;i++)
#define sc(a) cin>>a;
#define pr(a) cout<<a;
#define pl() cout<<endl;
#define min(a,b) (((a)<(b))?a:b)
#define max(a,b) (((a)>(b))?a:b)
#define lg(a) log10(a)
#define nlg(a) log(a)
#define ull unsigned long long
#define ul unsigned long
using namespace std;
int arr[10000];
class kisan
{
    string name,addr;
    int land_size;
    ul ann_inc;
    ul l_amt;
    float rate;
    double rem_bal;
    double p_amt;
    ul ins_amt;
    ul ins_emi;
    public:
    void details();
    void status();
    void loan();
    void insurance();
    void rates();
    void fs();
    void msp();
    void pay_loan();
    void admin();
}obj[10000];
int menu()
{
    int choice;
    cout<<"---------------------------------------------INDIAN AGRICULTURE PORTAL--------------------------------------------------"<<endl;
    cout<<"1. REGISTRATION 2. GOVERNMENT AIDE 3. ADMIN 4. EXIT\n";
    cout<<"Enter your choice\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"WELCOME TO REGISTRATION PORTAL\n";
            cout<<"ENTER YOUR DETAILS\n";
            kisan().details();
            cout<<"Press 1 : exit\n";
            cout<<"Press 2 : Main Menu\n";
            int ch1;
            cin>>ch1;
            if(ch1==1)
                exit(1);
            else if(ch1==2)
               menu();
            break;
        }
        case 2:
        {
            cout<<"GOVERNMENT OF INDIA\n";
            cout<<"1. APPLY FOR LOAN 2. KISAN BIMA YOJANA 3. SEED AND FERTILISER RATE 4.MSPs 5. PAY YOUR LOAN\n";
            int ch2;
            cin>>ch2;
            if(ch2==1)
                kisan().loan();
            else if(ch2==2)
                kisan().insurance();
            else if(ch2==3)
                kisan().fs();
            else if(ch2==4)
                kisan().msp();
            else if(ch2==5)
                kisan().pay_loan();
            break;
        }
        case 3:
        {
            cout<<"WELCOME ADMIN\n";
            char uname[15];
            char pass[5];
            char psw[5]={'a','d','m','i','n'};

     printf("Enter your credentials\n");
     printf("USERNAME: ");
                scanf("%s",uname);
     printf("PASSWORD: ");
                scanf("%s",pass);
                int flag=1;
                int i=0;
                while(i<strlen(pass))
                {
                    if(pass[i]!=psw[i])
                    {
                        flag=0;
                        break;
                    }
                    i++;
                }
                if(flag==0)
                {
                    printf("Authentication failed try again\n");
                    menu();
                }
                else if(flag)
                   kisan().admin();
                break;
        }
        case 4:
            {
                exit(1);
                break;
            }
        default:
            {
                exit(1);
            }
}
        return 0;
}
void kisan ::admin()
{
    int ch;
    cout<<"press 1. SEED FILE 2. MSP FILE\n";
    cin>>ch;
     FILE *f;
    char sub[10001];
    if(ch==1)
        f=fopen("seed.txt","a");
    else if(ch==2)
        f=fopen("msp.txt","a");
    if(f==NULL)
        {
            puts("cannot\n");
            exit(1);
        }
    printf("Enter name and price\n");
    gets(sub);
    while(strlen(gets(sub))>0)
        {
            fputs(sub,f);
            fputs("\n",f);
        }

    fclose(f);
    cout<<"DATA SAVED REDIRECTING TO MAIN MENU...\n";
    menu();

}
int main()
{
    int choice,i;
    rep1(i,10000)
        arr[i]=-1;
    menu();
    return 0;
}
void kisan :: details()
{
    int i=1;
             while(arr[i]!=-1)
             {
                 i++;
             }
             arr[i]=i;
             cout<<"NAME:";
             cin>>obj[i].name;
             cout<<"ADDRESS:";
             cin>>obj[i].addr;
             cout<<"LAND_SIZE:";
             cin>>obj[i].land_size;
             cout<<"ANNUAL INCOME:";
             cin>>obj[i].ann_inc;
             cout<<"THANKYOU FOR YOUR RESPONSE\n";
             cout<<"YOUR UNIQUE KISAN ID IS: ";
             cout<<"110"<<arr[i]<<"\n";

}
void kisan :: status()
{
    int id;
    int flag=0;
    while(flag==0)
    {
    cout<<"Enter your id\n";
    cin>>id;
    id=id%1100;
    if(arr[id]==-1)
        cout<<"USER DOES NOT EXIST PLEASE ENTER VALID ID\n";
    else
        flag=1;
    }

    cout<<"NAME : "<<obj[id].name<<endl;
    cout<<"ANNUAL INCOME : "<<obj[id].ann_inc<<endl;
    cout<<"LAND SIZE : "<<obj[id].land_size<<endl;
    cout<<"LOAN AMOUNT : "<<obj[id].l_amt<<endl;
    cout<<"INTEREST RATE : "<<obj[id].rate<<endl;
    cout<<"AMOUNT PAYABLE : "<<obj[id].p_amt<<endl;
    cout<<"REMAINING BALANCE : "<<obj[id].rem_bal<<endl;
    cout<<"INSURANCE AMOUNT : "<<obj[id].ins_amt<<endl;
    cout<<"INSURANCE EMI  : "<<obj[id].ins_emi<<endl;
    cout<<"Press 1 : exit\n";
    cout<<"Press 2 : Main Menu\n";
    int ch1;
    cin>>ch1;
    if(ch1==1)
    exit(1);
    else if(ch1==2)
    menu();
}
void kisan :: loan()
{
    cout<<"NOTICE::LOAN AMOUNT MUST BE LESS THAN THE DOUBLE OF YOUR ANNUAL INCOME\n";
    int flg=0;
    int id;
    ul amt;
    while(flg==0)
    {
    cout<<"Enter your id\n";
    cin>>id;
    id=id%1100;
    if(arr[id]==-1)
        cout<<"USER DOES NOT EXIST PLEASE ENTER VALID ID\n";
    else
        flg=1;
    }
    int flag=0;
    while(flag==0)
    {
    cout<<"Enter loan amount\n";
    cin>>amt;
    if(amt>obj[id].ann_inc*2)
    {
        cout<<"Not eligible for this much amount\n";
        cout<<"Enter amount again\n";
    }
    else
        flag=1;
    }
    if(obj[id].ann_inc<=400000)
    {
        obj[id].l_amt=amt;
        obj[id].rate=2.5;
        obj[id].p_amt=((amt*2.5)/100);
        obj[id].rem_bal=amt;
    }
    if(obj[id].ann_inc>400000 && obj[id].ann_inc<=1000000)
    {
        obj[id].l_amt=amt;
        obj[id].rate=5;
        obj[id].p_amt=((amt*5)/100);
        obj[id].rem_bal=amt;
    }
    if(obj[id].ann_inc>1000000)
    {
        obj[id].l_amt=amt;
        obj[id].rate=10;
        obj[id].p_amt=((amt*10)/100);
        obj[id].rem_bal=amt;
    }
    cout<<"LOAN ALLOCATED PRESS 1 TO SEE THE STATUS\n";
    int ch3;
    cin>>ch3;
    if(ch3==1)
        kisan().status();
    else
        exit(1);
}
void kisan :: insurance()
{
    cout<<"WELCOME TO KISAN INSURANCE PORTAL\n";
    cout<<"NOTICE:: DO NOT EXCEED THE LAND SIZE TO BE INSURED THAN YOUR TOTAL LAND SIZE\n";
    int id,siz,flg=0;
    while(flg==0)
    {
    cout<<"Enter your id\n";
    cin>>id;
    id=id%1100;
    if(arr[id]==-1)
        cout<<"USER DOES NOT EXIST PLEASE ENTER VALID ID\n";
    else
        flg=1;
    }
    int flag=0;
    while(flag==0)
    {
    cout<<"Enter land size\n";
    cin>>siz;
    if(siz>obj[id].land_size)
    {
        cout<<"Not eligible for this insurance\n";
        cout<<"Enter size again\n";
    }
    else
        flag=1;
    }
    if(siz<=100)
    {
        obj[id].ins_amt=10000;
        obj[id].ins_emi=1500;
    }
    else if(siz>100 && siz<=500)
    {
        obj[id].ins_amt=30000;
        obj[id].ins_emi=6000;
    }
    else
    {
        obj[id].ins_amt=50000;
        obj[id].ins_emi=12500;
    }
    cout<<"LAND INSURED PRESS 1 TO SEE THE STATUS\n";
    int ch3;
    cin>>ch3;
    if(ch3==1)
        kisan().status();
    else
        exit(1);

}
void kisan :: fs()
{
    FILE *f;
    char ch;
    f=fopen("seed.txt","r");
    if(f==NULL)
        {
            puts("cannot\n");
            exit(1);
        }
     while(1)
        {
            ch=fgetc(f);
            if(ch==EOF)
                break;
            printf("%c",ch);
        }
    fclose(f);
    cout<<"press 1. EXIT 2. MAIN MENU\n";
    int che;
    cin>>che;
    if(che==1)
        exit(1);
    else if(che==2)
        menu();

 }
 void kisan :: msp()
 {
 FILE *f;
    char ch;
    int i;
    f=fopen("msp.txt","r");
    if(f==NULL)
        {
            puts("cannot\n");
            exit(1);
        }
     while(1)
        {
            ch=fgetc(f);
            if(ch==EOF)
                break;
            printf("%c",ch);
        }
    fclose(f);
    cout<<"press 1. EXIT 2. MAIN MENU\n";
    int che;
    cin>>che;
    if(che==1)
        exit(1);
    else if(che==2)
        menu();
 }
 void kisan :: pay_loan()
 {
     int id,flag=0;
     while(flag==0)
     {
    cout<<"Enter your id\n";
    cin>>id;
    id=id%1100;
    if(arr[id]==-1)
        cout<<"USER DOES NOT EXIST PLEASE ENTER VALID ID\n";
    else
        flag=1;
     }
    cout<<"AMOUNT TO PAY : "<<obj[id].p_amt<<endl;
    cout<<"PRESS 1. SUBMIT 2. DECLINE\n";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        cout<<"Amount submitted \n";
        obj[id].rem_bal-=obj[id].p_amt;
    }
    else if(ch==2)
    {
        cout<<"PAYMENT DECLINE\n";
    }
    cout<<"press 1. STATUS 2. MAIN MENU\n";
    int che;
    cin>>che;
    if(che==1)
        kisan().status();
    else if(che==2)
        menu();
 }
