#include "main.h"
int n1,limit=0,limit1=0,count=0,one=0;
void loadcontact(ab *a)
{
    FILE *fp=fopen("database.csv","r");
    fscanf(fp,"%*c%d%*c\n",&n1);
   // printf("%d\n",count);
    for(int i=0;i<n1;i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",a[i].name,a[i].mobile_no,a[i].mailid);
    }
}
void creatcontact(ab *a){
    char n[100];
    char m[11];
    char ma[200];
    int flag=0;
    do{
        flag = 0;
        printf("Enter your Name : ");
        scanf(" %[^\n]",n);
        int i=0;
        while(n[i]!='\0')
        {
            if(isdigit(n[i]) || ispunct(n[i]))
            {
                printf("OOPs !! Must enter name in charachters \n");
                flag = 1;
                break;
            }
            i++;
        }
    }while(flag);
    int flag1=0;
    do{
        flag1=0;
        printf("Enter your contact : ");
        scanf("%s",m);
        int n=strlen(m);
        if(n<10 || n>10)
        {
            printf("OOPs !! Must Enter 10 digits \n");
            flag1=1;
        }
        int i=0;
        while(m[i]!='\0')
        {
            if(!(m[i]>=48 && m[i]<=57))
            {
                printf("OOPs !! Must enter contact in integers \n");
                flag1=1;
                break;
            }
            i++;
        }
        if(limit)
        {
            for(int i=0;m[i]!='\0';i++)
            {
                if(!strcmp(m,a[i].mobile_no))
                {
                    printf("OOPs !! Enter your Number must be Unique \n");
                    flag1=1;
                    break;
                }
            }
        }
        limit++;
    }while(flag1);
    
    int flag2=0;
    do{
        flag2=0;
        printf("Enter your mail : ");
        scanf("%s",ma);
        char str[]="@gmail.com";
        char *ret=strstr(ma,str);

        if(ret==NULL)
        {
            printf("OOPs !! You Entered mail is Wrong \n");
            flag2=1;
        }
        for(int i=0;ma[i]!='\0';i++)
        {
            if(!(islower(ma[i]) ||  ma[i]=='@' || ma[i]=='.' || isdigit(ma[i])))
            {
                printf("OOPs !! must Eneter mail in Samll digits \n");
                flag2=1;
                break;
            }
        }
        int count=0;
        for(int i=0;ma[i]!='@';i++)
        {
            if(ma[i]>=97 && ma[i]<=122){
                count+=1;
            }
        }
        if(count<1)
        {
            printf("OOPs !! You Entered mail is Wrong \n");
            flag2=1;
        }
        if(limit1)
        {
            for(int i=0;m[i]!='\0';i++)
            {
                if(!strcmp(ma,a[i].mailid))
                {
                    printf("OOPs !! Enter your Mail must be Unique \n");
                    flag2=1;
                    break;
                }
            }
        }
        limit1++;

    }while(flag2);

    strcpy(a[n1].name,n);
    strcpy(a[n1].mobile_no,m);
    strcpy(a[n1].mailid,ma);
    (a[n1].sn)=n1+1;
    n1+=1;

    printf("Successfully Created the contact \n\n");
}

void searchcontact(ab *a)
{
    if(n1>0)
    {
        int n;
        printf("1.By name \n2.By Mobileno \n3.By Mailid \n");
        printf("choose option : ");
        scanf("%d",&n);
        if(n==1)
        {
            printf("By name your searching !! \n");
            int pass=0;
            do{
                pass=0;
                char c[100];
                printf("Enter the valid Name : ");
                scanf(" %[^\n]",c);
                int flag=1;
                for(int i=0;i<n1;i++)
                {
                    
                    char *ret=strstr(a[i].name,c);
                    if(ret!=NULL)
                    {
                        count+=1;
                        printf("serial_no : %d\nName : %s \nContact : %s \nMail_id : %s\n",i,a[i].name,a[i].mobile_no,a[i].mailid);
                        flag=0;
                    }
                }
                if(count==1)
                {
                    for(int i=0;i<n1;i++)
                    {
                        char *ret=strstr(a[i].name,c);
                        if(ret!=NULL)
                        {
                            one=i;
                        }
                    
                    }
                }
                if(flag)
                {
                    pass=1;
                }
            }while(pass);
        }
        else if(n==2)
        {
            printf("By Mobile_no your searching !! \n");
            int pass=0;
            do{
                pass=0;
                char c[100];
                printf("Enter the valid Mobileno : ");
                scanf(" %[^\n]",c);
                int flag=1;
                for(int i=0;i<n1;i++)
                {
                    char *ret=strstr(a[i].mobile_no,c);
                    if(ret!=NULL)
                    {
                        one=i;
                        printf("serial_no : %d\nName : %s \nContact : %s \nMail_id : %s\n",i,a[i].name,a[i].mobile_no,a[i].mailid);
                        flag=0;
                    }
                    
                    
                }
                if(flag)
                {
                    pass=1;
                }
            }while(pass);
        }
        else if(n==3)
        {
            printf("By Mailid your searching !! \n");
            int pass=0;
            do{
                char c[100];
                printf("Enter the vaild Mailid : ");
                scanf(" %[^\n]",c);
                int flag=1;
                for(int i=0;i<n1;i++)
                {
                    char *ret=strstr(a[i].mailid,c);
                    if(ret!=NULL)
                    {
                        one=i;
                        printf("serial_no : %d\nName : %s \nContact : %s \nMail_id : %s\n",i,a[i].name,a[i].mobile_no,a[i].mailid);
                        flag=0;
                    }
                    
                }
                if(flag)
                {
                    pass=1;
                }
            }while(pass);
        }
        printf("Please choose correct option\n");
        getchar();
    }
    else
    {
        printf("Contact list is Empty ! PLease Add Contact \n");
    }
}
void editcontact(ab *a)
{
    if(n1>0)
    {
        printf("First Search the contact \n");
        searchcontact(a);
        int n;
        printf("Now Edit the Conatct !! \n");
        printf("1.Edit Name\n2.Edit contact\n3.Edit Emailid \n");
        printf("Choose option : ");
        scanf("%d",&n);
        if(n==1)
        {
            int s;
            char c[50];
            printf("Edit By Name !!! \n");
            if(count>1)
            {
                printf("Please Enter the Serial_no : ");
                scanf("%d",&s);
            }
            int flag=0;
            do{
                flag = 0;
                printf("Enter New Name : ");
                scanf(" %[^\n]",c);
                int i=0;
                while(c[i]!='\0')
                {
                    if(isdigit(c[i]))
                    {
                        printf("OOPs ? Must enter name in charachters \n");
                        flag = 1;
                        break;
                    }
                    i++;
                }
            }while(flag);
            if(count==1)
            {
                strcpy(a[one].name,c);
            }
            strcpy(a[s-1].name,c);
            printf("Sucessfully you entered name is Updated \n\n");
            
        }
        else if(n==2)
        {
            char c[50];
            printf("Edit By mobileno !!! \n");
            int flag1=0;
            do{
                flag1=0;
                printf("Enter your contact : ");
                scanf("%s",c);
                int n=strlen(c);
                if(n<10 || n>10)
                {
                    printf("OOPs !! Must Enter 10 digits \n");
                    flag1=1;
                }
                int i=0;
                while(c[i]!='\0')
                {
                    if(!(c[i]>=48 && c[i]<=57))
                    {
                        printf("OOPs !! Must enter contact in integers \n");
                        flag1=1;
                        break;
                    }
                    i++;
                }
                for(int i=0;c[i]!='\0';i++)
                {
                    if(!strcmp(c,a[i].mobile_no))
                    {
                        printf("OOPs !! Enter your Number must be Unique \n");
                        flag1=1;
                        break;
                    }
                }
            }while(flag1);
            strcpy(a[one].mobile_no,c);
            printf("Sucessfully you entered name is Updated \n\n");
            
        }
        else if(n==3)
        {
            char c[50];
            printf("Edit By Mailid !!! \n");
            int flag2=0;
            do{
                flag2=0;
                printf("Enter New  mail : ");
                scanf("%s",c);
                char str[]="@gmail.com";
                char *ret=strstr(c,str);
                if(ret==NULL)
                {
                    printf("OOPs !! You Entered mail is Wrong \n");
                    flag2=1;
                }
                for(int i=0;c[i]!='\0';i++)
                {
                    if(!(islower(c[i]) ||  c[i]=='@' || c[i]=='.' || isdigit(c[i])))
                    {
                        printf("OOPs !! must Eneter mail in Samll digits \n");
                        flag2=1;
                        break;
                    }
                }
                int count=0;
                for(int i=0;c[i]!='@';i++)
                {
                    if(c[i]>=97 && c[i]<=122){
                        count+=1;
                    }
                }
                if(count<1)
                {
                    printf("OOPs !! You Entered mail is Wrong \n");
                    flag2=1;
                }
                for(int i=0;c[i]!='\0';i++)
                {
                    if(!strcmp(c,a[i].mailid))
                    {
                        printf("OOPs !! Enter your Mail must be Unique \n");
                        flag2=1;
                        break;
                    }
                }

            }while(flag2);
            strcpy(a[one].mailid,c);
            printf("Sucessfully you entered name is Updated \n\n");
        }
        printf("Please choose correct option\n");
        getchar();
    }
    else
    {
        printf("Contact list is Empty ! PLease Add Contact \n");
    }

}
void deletecontact(ab *a)
{
    if(n1>0)
    {
        printf("First Search the contact Present in Address_Book !!! \n");
        printf("-------------------------------------------- \n");
        searchcontact(a);
        printf("Now Delete The Contact By choosing Option !! \n");
        printf("1.By name \n2.By Mobileno \n3.By Mailid \n");
        int n;
        printf("Choose the Option : ");
        scanf("%d",&n);
        if(n==1)
        {
            int s;
            char c[50];
            printf("By Name Delte the Contact !! \n");
            if(count>1)
            {
                printf("Please Enter the Serial no : ");
                scanf("%d",&s);
            }
            printf("Enter the Name : ");
            scanf(" %[^\n]",c);
            printf("Hey Buddy Successfully Delted your Entered Contact !!!");
            printf("\n");
            if(count==1)
            {
                for(int i=one;i<n1;i++)
                {
                    strcpy(a[i].name,a[i+1].name);
                    strcpy(a[i].mobile_no,a[i+1].mobile_no);
                    strcpy(a[i].mailid,a[i+1].mailid);
                }
            }
            else{
                for(int i=s;i<n1;i++)
                {
                    strcpy(a[i].name,a[i+1].name);
                    strcpy(a[i].mobile_no,a[i+1].mobile_no);
                    strcpy(a[i].mailid,a[i+1].mailid);
                }
            }
            n1-=1;

        }
        
        else if(n==2)
        {
            char c[50];
            printf("By Mobile_no Delte the Contact !! \n");
            printf("Enter the Mobile_no :");
            scanf(" %[^\n]",c);
            printf("Hey Buddy Successfully Delted your Entered Contact !!!");
            printf("\n");
            for(int i=one;i<n1;i++)
            {
                strcpy(a[i].name,a[i+1].name);
                strcpy(a[i].mobile_no,a[i+1].mobile_no);
                strcpy(a[i].mailid,a[i+1].mailid);
            }
            n1-=1;

        }
        else if(n==3)
        {
            int s;
            char c[50];
            printf("By Mailid Delte the Contact !! \n");
            printf("Enter the Mail_id : ");
            scanf(" %[^\n]",c);
            printf("Hey Buddy Successfully Delted your Enterd Contact !!! ");
            printf("\n");
            for(int i=one;i<n1;i++)
            {
                strcpy(a[i].name,a[i+1].name);
                strcpy(a[i].mobile_no,a[i+1].mobile_no);
                strcpy(a[i].mailid,a[i+1].mailid);
            }
            n1-=1;
        }
        printf("Please choose correct option\n");
        getchar();
    }
    else
    {
        printf("Contact list is Empty ! PLease Add Contact \n");
    }
}
void listcontact(ab *a){
    printf("----------------------------------------------------------------------------------\n");
    printf("%8s%16s%16s%25s \n","S.NO","Name","Mobile","Mail");
    for(int i=0;i<n1;i++)
    {
        printf("%8d%17s%17s%30s\n",i,a[i].name,a[i].mobile_no,a[i].mailid);
    }
    printf("----------------------------------------------------------------------------------");
    printf("\n");
}
void save_exit(ab *a) 
{
    FILE *fp = fopen("database.csv", "w");  
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "#%d#\n", n1);
    for (int i = 0; i < n1; i++) {
        fprintf(fp, "%s,%s,%s\n", a[i].name, a[i].mobile_no, a[i].mailid);
    }
    fclose(fp);
}


                         /************/// PROJECT COMPELETED /////************/