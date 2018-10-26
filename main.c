#include <stdio.h>
#include <stdlib.h>
struct date_of{
int day,mon,year;
}date;
struct resturant{
int id,salary;
long long int phone;
char fname[33],lname[33],address[33];
struct date_of date;
}details;
void insert()
{
 FILE *fp;
 fp = fopen("Record.bat", "a");
 printf("Enter the employee id   :");
 scanf("%d", &details.id);
 printf("Enter the First Name      :");
 scanf("%s]", &details.fname);
 printf("Enter the Last Name      :");
 scanf("%s", &details.lname);
 printf("Enter the address      :");
 scanf("%s", &details.address);
 printf("Enter salary     :");
 scanf("%d",&details.salary);
 printf("Enter phone Number   :");
 scanf("%lli",&details.phone);
 printf("Date of join");
 scanf("%d%d%d",&details.date.day,&details.date.mon,&details.date.year);
 fwrite(&details, sizeof(details), 1, fp);
 fclose(fp);
}
void dis()
{
 FILE *fp1;
 fp1 = fopen("Record.bat", "r");
 while (fread(&details, sizeof(details), 1, fp1))
 printf("  id: %d\n\tFirst name: %s\t\n\tLast name: %s\t\n\tAddress: %s\t\n\tSalary: %d\t\n\tPhone: %lli\t\n\tDate: %d-%d-%d\n\n\n",details.id,details.fname,details.lname,details.address,details.salary,details.phone,details.date.day,details.date.mon,details.date.year);
 fclose(fp1);
 getche();
}
void search()
{
    int id;
    printf("enter a id to search:   ");
    scanf("%d",&id);
    FILE *fp1;
    fp1 = fopen("Record.bat", "r");
    while (fread(&details, sizeof(details), 1, fp1))
    {
        if(details.id == id)
        {
        printf("  id: %d\n\tFirst name: %s\t\n\tLast name: %s\t\n\tAddress: %s\t\n\tSalary: %d\t\n\tPhone: %lli\t\n\tDate: %d-%d-%d\n\n\n",details.id,details.fname,details.lname,details.address,details.salary,details.phone,details.date.day,details.date.mon,details.date.year);
        }
    }
    fclose(fp1);
    getche();
}
void copy_dis()
{
    char name[22];
    printf("Name the file you want to display: ");
    scanf("%s",name);
    FILE *fp1;
    fp1 = fopen(name, "r");
    while (fread(&details, sizeof(details), 1, fp1))
    printf("  id: %d\n\tFirst name: %s\t\n\tLast name: %s\t\n\tAddress: %s\t\n\tSalary: %d\t\n\tPhone: %lli\t\n\tDate: %d-%d-%d\n\n\n",details.id,details.fname,details.lname,details.address,details.salary,details.phone,details.date.day,details.date.mon,details.date.year);
    fclose(fp1);
    getche();
}
void copy()
{
    char name[22];
    printf("Name the file you want to copy: ");
    scanf("%s",name);
    FILE *fpt,*fpt1;
    fpt = fopen("Record.bat","r");
    fpt1 = fopen(name,"w");
    while (fread(&details, sizeof(details), 1, fpt))
    {
        fwrite(&details, sizeof(details), 1, fpt1);
    }
    printf("copied successful");
    fclose(fpt);
    fclose(fpt1);
    getche();
}
void delete()
{
    int id;
    printf("Enter id of a record you want to delete: ");
    scanf("%d",&id);
    FILE *fpt,*fpt1;
    fpt = fopen("Record.bat","r");
    fpt1 = fopen("Esewa.bat","w");
    while (fread(&details, sizeof(details), 1, fpt))
    {
        if(id!=details.id)
        {
            fwrite(&details, sizeof(details), 1, fpt1);
        }else{
                printf("Delete successful");
                break;
        }
    }
    fclose(fpt);
    fclose(fpt1);
    remove("Record.bat");
    rename("Esewa.bat","Record.bat");
    getche();
}
int main()
{
int c, emp;
char a;
   do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. COPY\n\t6. DISPLAY COPIED FILE");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:

    insert();
   break;
  case 2:
   dis();
   break;
  case 3:
   search();
   break;
  case 4:
   delete();
   break;
  case 5:
   copy();
   break;
  case 6:
    copy_dis();
   break;
  case 7:

    break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);


}
