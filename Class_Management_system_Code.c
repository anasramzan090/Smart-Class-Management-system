/* This Program is Writtten By____"MUHAMMAD ANAS RAMZAN"____anasramzan417@gmail.com____ */
/////////////////////////////////////////////////////////////////////////////////////////////////////
// This Program Manage The Student Academic Rocords As well As Student's Details Like Name/Adress etc.
/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Demands FromThe Instructor were...
This program should maintain academic record of the whole class. The user (teacher) should, first, select subject through a subject code, then program should give him an
option to either view the whole record of this subject or enter new marks. Whole record portion should display previously entered result of all students. Result should
include  Quiz 1 & 2 marks, Mid & Final exam marks, Total marks, and GPA. There should be a provision to edit old marks also. Each subject detail must be stored in
separate text file */
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Limitations Of this Program are, that It  can Manage The Rocord Upto 12 Subjects(2_Semesters) and It Can Store Data Of Only 500 Students.
// These Things Restrict the use This Program to a Limit.
/////////////////////////////////////////////////////////////////////////////////////////////////////
// This Project was Completed On 20_December_2021 at 9:00pm In UET Lahore.(By Muhammad Anas Ramzan.!)
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>   // standard input output Library Used In The Program...
#include <time.h>    // time Library Used In The Program...
#include <stdlib.h>  // Library Used In The Program...
#include <string.h>  // Library Used In The Program...
#include <conio.h>   // conditional Library Used In The Program...
#include <windows.h> // for color, Library Used In The Program...

struct student // STUDENT ACADEMIC RECORD STRUCTURE DECLARATION
{
   char name[20];
   char fname[20];
   char rollno[10];
   struct subject
   {
      float totalmark;
      float finalmark;
      float midmark;
      float quiz1mark;
      float quiz2mark;
      float gpamark;
   } cag, egd, ec, isl, ap, det, es, mp, edc, fots, cs, cp1, em, ed, vca, dld, qt, la, embs, mech, mechma, cp2, isl2;
} student;

struct studentdetails // STUDENT DETAILS STRUCTURE DECLARATION
{
   char sname[100];
   char fname[50];
   int cnic;
   int age;
   char adress[100];
   char gender[20];
   char rollnum[10];
   char section[20];
   int session;
};

// DECLARATION OF ALL THE FUNCTIONS USED IN THE PROGRAM.

void addstudentdetails();
void removestudentdetails();
void deletedetailsfile();
void noofdetails();
void displaydetails();
void opensubject();

// SEMESTER # 1...
void calculas();
void graphicsanddesign();
void electriccircuits();
void islamicandpakstudies();
void appliapphysics();

// Semester # 3...
void engineeringdynamics();
void vectorandcoplexanalysis();
void computerprograming();
void electricmachinery();
void digitallogicdesign();
void qurantranslation();

// Semester # 3...
void createqt();
void displayqt();
void appendqt();
void noofrecordqt();
void searchqt();
void updateqt();
void deleterecqt();

// Semester # 3...
void createcp();
void displaycp();
void appendcp();
void noofrecordcp();
void searchcp();
void updatecp();
void deletereccp();

// Semester # 3...
void createem();
void displayem();
void appendem();
void noofrecordem();
void searchem();
void updateem();
void deleterecem();

// Semester # 3...
void createed();
void displayed();
void appendvcad();
void noofrecorded();
void searched();
void updateed();
void deletereced();

// Semester # 3...
void createvca();
void Displayvca();
void appendvca();
void noofrecordvca();
void searchvca();
void updatevca();
void deleterecvca();

// Semester # 3...
void createdld();
void displaydld();
void appenddld();
void noofrecorddld();
void searchdld();
void updatedld();
void deleterecdld();

// SEMESTER # 1...
void createisl();
void displayisl();
void Appendisl();
void noofrecordisl();
void searchisl();
void updateisl();
void deketerecisl();

// SEMESTER # 1...
void createegd();
void displayegd();
void appendvcagd();
void noofrecordegd();
void searchegd();
void updateegd();
void deleterecegd();

// SEMESTER # 1...
void createec();
void displayec();
void appendec();
void noofrecordec();
void searchec();
void updateec();
void deleterecec();

// SEMESTER # 1...
void createap();
void displayap();
void appendap();
void noofrecordap();
void searchap();
void updateap();
void deleterecap();

// SEMESTER # 1...
void createcag();
void displaycag();
void appendcag();
void noofrecordcag();
void searchcag();
void updatecag();
void deletereccag();

void addstudentdetails() // FUNCTION DEFINITION TO ADD STUDENT DETAILS.
{
   FILE *fp;
   int a = 0;
   int b;
   int c = 500;
   printf("\nDetails of How many students do you want to add?  ");
   do
   {
      scanf("%d", &b);
      if (b > c || b <= 0)
      {
         printf("Invalid Entry...!!!");
         printf("Try again...!!!");
         printf("\nDetails of How many students do you want to add?  ");
      }

   } while (c <= b || b <= 0);

   struct studentdetails sd[500];
   printf("\nStart Adding The Details Of Students...!\n");
   fp = fopen("Detailsofstudents.txt", "wb");
   if (fp == NULL)
   {
      printf("\nErrror in Opening the File...!!!");
      exit(1);
   }
   for (a = 0; a < b; a++)
   {
      printf("\nEnter Name Of The Student:  ");
      fflush(stdin);
      gets(sd[a].sname);
      printf("\nEnter Father's Name Of The Student:  ");
      fflush(stdin);
      gets(sd[a].fname);
      printf("\nEnter National Identity Card Number OF The Student Without ( _ ) and ( Empty Spacec ):  ");
      fflush(stdin);
      scanf("%d", &sd[a].cnic);
      printf("\nEnter Age OF The Student:  ");
      fflush(stdin);
      scanf("%d", &sd[a].age);
      printf("\nGender OF The Student:  ");
      fflush(stdin);
      scanf("%s", sd[a].gender);
      printf("\nEnter Adress Of The Student:  ");
      fflush(stdin);
      gets(sd[a].adress);
      printf("\nEnter Roll_Number Of The Student:  ");
      fflush(stdin);
      gets(sd[a].rollnum);
      printf("\nEnter Section Of The Student:  ");
      fflush(stdin);
      gets(sd[a].section);
      printf("\nEnter Session Of The Student:  ");
      fflush(stdin);
      scanf("%d", &sd[a].session);
      printf("\n\n");
   }
   fwrite(sd, sizeof(struct studentdetails), b, fp);
   printf("Details of The students IS successfully Added...!\n\n\n");
   fclose(fp);
}

void noofdetails() // FUNCTION DEFINITION TO CHECK NO STUDENTS ADDED IN THE DETAILS LIST.
{
   struct studentdetails s1;
   FILE *fp;
   fp = fopen("Detailsofstudents.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(struct studentdetails);
   printf("\n\nNo of Students Whose details are Saved = %d\n\n", n);
   fclose(fp);
}

void removestudentdetails() // FUNCTION DEFINITION TO REMOVE THE DETAILS OF A STUDENT.
{
   int j, found = 0;
   char rno[10];
   struct studentdetails s1;
   FILE *fp, *fp1;
   fp = fopen("Detailsofstudents.txt", "r");
   fp1 = fopen("tempremove.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Details you want To Delete: ");
   scanf("%d", &rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct studentdetails), 1, fp))
   {
      if (strcmp(s1.rollnum, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct studentdetails), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tempremove.txt", "r");
      fp = fopen("Detailsofstudents.txt", "w");

      while (fread(&s1, sizeof(struct studentdetails), 1, fp1))
      {
         fwrite(&s1, sizeof(struct studentdetails), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nDetails Of This Students Have Been Removed Successfuly...!\n");
   }
   else
   {
      printf("\nDetails Of Student With this Roll_No are Not Found...!!!\n\n");
   }
   fclose(fp);
}

void deletedetailsfile() // FUNCTION DEFINITON TO DELETE THE FILE OF DETAILS OF STUDENTS.
{

   if (remove("Detailsofstudents.txt") == 0)
   {
      printf("\nDetails Of All The Students Has Been Deleted successfully:  \n\n\n");
   }
   else
   {
      printf("\nNO File Is Available...!!!\n");
   }
}

void displaydetails() // FUNCTION DEFINITION TO DISPLAY THE DETAILS OF THE STUDENTS.
{
   int j;
   struct studentdetails s1;
   FILE *fp;
   fp = fopen("Detailsofstudents.txt", "r");
   while (fread(&s1, sizeof(struct studentdetails), 1, fp))
   {
      printf("\nSaved Details OF %s is Shown  Below...!\n", s1.sname);

      printf("\nFather Name Of %s Is %s", s1.sname, s1.fname);
      printf("\nCNIC Of %s Is %d", s1.sname, s1.cnic);
      printf("\nAge Of %s Is %d", s1.sname, s1.age);
      printf("\nGender Of student is %s", s1.gender);
      printf("\nAdress Of %s Is %s", s1.sname, s1.adress);
      printf("\nRoll_No Of %s Is %s", s1.sname, s1.rollnum);
      printf("\nSection Of %s Is %s", s1.sname, s1.section);
      printf("\nSession Of %s Is %d", s1.sname, s1.session);
      printf("\n\n");
   }
   fclose(fp);
}

void opensubject() // FUNCTION DEFINITIN TO OPEN THE SUBJECTS RECORD BOOK
{
   char usercode[10];
   char edcode[10] = "MCT211";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char vcacode[10] = "MA129";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char cpcode[10] = "MCT242";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char emcode[10] = "MCT223";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char dldcode[10] = "MCT241"; // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char qtcode[10] = "QT201";   // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char apcode[10] = "PHY118";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char cagcode[10] = "MA113";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char egdcode[10] = "MCT111"; // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char eccode[10] = "MCT121";  // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.
   char islcode[10] = "ISL101"; // SUBJECT CODE OF SUBJECT FROM MECHATRONICS ENGINEERING SEMESTER.

   printf("\nEnter The Code Of Subject That You are Intending to Open. ");
   printf("\n\n\t\t\t__NOTE__\n\nSubject Code Should be In Capital Letters e.g:- MCT242...");
   printf("\n\nEnter The Code Of Subject:  ");
   scanf("%s", &usercode);

   if (strcmp(cpcode, usercode) == 0)
   {
      computerprograming();
   }

   if (strcmp(emcode, usercode) == 0)
   {
      electricmachinery();
   }

   if (strcmp(dldcode, usercode) == 0)
   {
      digitallogicdesign();
   }

   if (strcmp(edcode, usercode) == 0)
   {
      engineeringdynamics();
   }

   if (strcmp(vcacode, usercode) == 0)
   {
      vectorandcoplexanalysis();
   }

   if (strcmp(qtcode, usercode) == 0)
   {
      qurantranslation();
   }

   if (strcmp(egdcode, usercode) == 0)
   {
      graphicsanddesign();
   }

   if (strcmp(eccode, usercode) == 0)
   {
      electriccircuits();
   }

   if (strcmp(apcode, usercode) == 0)
   {
      appliapphysics();
   }

   if (strcmp(cagcode, usercode) == 0)
   {
      calculas();
   }

   if (strcmp(islcode, usercode) == 0)
   {
      islamicandpakstudies();
   }
}
// FUNCTIONS DEFINITION TO CREATE NEW RECORD OF QURAN TANLSATION
void createqt()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal Marks Of Subject are 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("qt.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.totalmark);
         if (stu[i].qt.totalmark > to || stu[i].qt.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (to < stu[i].qt.totalmark || stu[i].qt.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.finalmark);
         if (stu[i].qt.finalmark > fi || stu[i].qt.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (fi < stu[i].qt.finalmark || stu[i].qt.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.midmark);
         if (stu[i].qt.midmark > mi || stu[i].qt.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (mi < stu[i].qt.midmark || stu[i].qt.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.quiz1mark);
         if (stu[i].qt.quiz1mark > q1 || stu[i].qt.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (q1 < stu[i].qt.quiz1mark || stu[i].qt.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.quiz2mark);
         if (stu[i].qt.quiz2mark > q2 || stu[i].qt.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (q2 < stu[i].qt.quiz2mark || stu[i].qt.quiz2mark < 0);
      printf("\nEnter GPA of The Student in QURAN TRANSLATION_2:  ");
      do
      {
         scanf("%f", &stu[i].qt.gpamark);
         if (stu[i].qt.gpamark > gp || stu[i].qt.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
         }
      } while (gp < stu[i].qt.gpamark || stu[i].qt.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION TO DISPLAY PREVIOUS RECORD OF QURAN TANLSATION
void displayqt()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savqt In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("qt.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In QURAN TRANSLATION_2 is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.qt.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.qt.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.qt.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.qt.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.qt.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.qt.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION TO APPEND IN THE PREVIOUS RECORD OF QURAN TANLSATION
void appendqt()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of QURAN TRANSLATION_2?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("qt.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.totalmark);
            if (s[i].qt.totalmark > to || s[i].qt.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (to < s[i].qt.totalmark || s[i].qt.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.finalmark);
            if (s[i].qt.finalmark > fi || s[i].qt.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (fi < s[i].qt.finalmark || s[i].qt.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.midmark);
            if (s[i].qt.midmark > mi || s[i].qt.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (mi < s[i].qt.midmark || s[i].qt.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.quiz1mark);
            if (s[i].qt.quiz1mark > q1 || s[i].qt.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (q1 < s[i].qt.quiz1mark || s[i].qt.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.quiz2mark);
            if (s[i].qt.quiz2mark > q2 || s[i].qt.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (q2 < s[i].qt.quiz2mark || s[i].qt.quiz2mark < 0);
         printf("\nEnter GPA of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s[i].qt.gpamark);
            if (s[i].qt.gpamark > gp || s[i].qt.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (gp < s[i].qt.gpamark || s[i].qt.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been Appended Successfuly...!\n");
}
// FUNCTIONS DEFINITION TO CHECK NO OF STUDENTS IN THE RECORD OF QURAN TANLSATION
void noofrecordqt()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("qt.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}
// FUNCTIONS DEFINITION TO SEARCH IN RECORD OF QURAN TANLSATION
void searchqt()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("qt.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of QURAN TRANSLATION_2:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In QURAN TRANSLATION_2 Has been Displayqt Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.qt.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.qt.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.qt.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.qt.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.qt.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.qt.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION TO UPDATE PREVOUS RECORD OF QURAN TANLSATION
void updateqt()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("qt.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.totalmark);
            if (s1.qt.totalmark > to || s1.qt.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (to < s1.qt.totalmark || s1.qt.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.finalmark);
            if (s1.qt.finalmark > fi || s1.qt.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (fi < s1.qt.finalmark || s1.qt.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.midmark);
            if (s1.qt.midmark > mi || s1.qt.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (mi < s1.qt.midmark || s1.qt.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.quiz1mark);
            if (s1.qt.quiz1mark > q1 || s1.qt.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in QURAN TRANSLATION_2:  ");
            }

         } while (q1 < s1.qt.quiz1mark || s1.qt.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.quiz2mark);
            if (s1.qt.quiz2mark > q2 || s1.qt.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (q2 < s1.qt.quiz2mark || s1.qt.quiz2mark < 0);
         printf("\nEnter GPA of The Student in QURAN TRANSLATION_2:  ");
         do
         {
            scanf("%f", &s1.qt.gpamark);
            if (s1.qt.gpamark > gp || s1.qt.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in QURAN TRANSLATION_2:  ");
            }
         } while (gp < s1.qt.gpamark || s1.qt.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("qt.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}
// FUNCTIONS DEFINITION TO DELETE RECORD OF QURAN TANLSATION
void deleterecqt()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("qt.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("qt.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Dleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION TO CREATE NEW RECORD OF COMPUTER_PROGRAMING_1
void createcp()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Sbject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("cp1.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.totalmark);
         if (stu[i].cp1.totalmark > to || stu[i].cp1.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
         }
      } while (to < stu[i].cp1.totalmark || stu[i].cp1.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.finalmark);
         if (stu[i].cp1.finalmark > fi || stu[i].cp1.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
         }
      } while (fi < stu[i].cp1.finalmark || stu[i].cp1.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.midmark);
         if (stu[i].cp1.midmark > mi || stu[i].cp1.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
         }
      } while (mi < stu[i].cp1.midmark || stu[i].cp1.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.quiz1mark);
         if (stu[i].cp1.quiz1mark > q1 || stu[i].cp1.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
         }
      } while (q1 < stu[i].cp1.quiz1mark || stu[i].cp1.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.quiz2mark);
         if (stu[i].cp1.quiz2mark > q2 || stu[i].cp1.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
         }
      } while (q2 < stu[i].cp1.quiz2mark || stu[i].cp1.quiz2mark < 0);
      printf("\nEnter GPA of The Student in Computer_Programing_1:  ");
      do
      {
         scanf("%f", &stu[i].cp1.gpamark);
         if (stu[i].cp1.gpamark > gp || stu[i].cp1.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
         }
      } while (gp < stu[i].cp1.gpamark || stu[i].cp1.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION TO DISPLAY RECORD OF COMPUTER_PROGRAMING_1
void displaycp()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Saved In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("cp1.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In Computer_Programing_1 is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cp1.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cp1.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cp1.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cp1.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cp1.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.cp1.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}
// FUNCTION DEFINITION TO APPEND NEW RECORD OF COMPUTER_PROGRAMING_1
void appendcp()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of Computer_Programing_1?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("cp1.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.totalmark);
            if (s[i].cp1.totalmark > to || s[i].cp1.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
            }
         } while (to < s[i].cp1.totalmark || s[i].cp1.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.finalmark);
            if (s[i].cp1.finalmark > fi || s[i].cp1.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
            }
         } while (fi < s[i].cp1.finalmark || s[i].cp1.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.midmark);
            if (s[i].cp1.midmark > mi || s[i].cp1.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
            }
         } while (mi < s[i].cp1.midmark || s[i].cp1.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.quiz1mark);
            if (s[i].cp1.quiz1mark > q1 || s[i].cp1.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
            }
         } while (q1 < s[i].cp1.quiz1mark || s[i].cp1.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.quiz2mark);
            if (s[i].cp1.quiz2mark > q2 || s[i].cp1.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
            }
         } while (q2 < s[i].cp1.quiz2mark || s[i].cp1.quiz2mark < 0);
         printf("\nEnter GPA of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s[i].cp1.gpamark);
            if (s[i].cp1.gpamark > gp || s[i].cp1.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
            }
         } while (gp < s[i].cp1.gpamark || s[i].cp1.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appended Successfuly...!\n");
}
// FUNCTIONS DEFINITION TO SEARCH NO OF STUDENTS IN THE RECORD OF COMPUTER_PROGRAMING_1
void noofrecordcp()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("cp1.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}
// FUNCTIONS DEFINITION TO SEARCH RESULT OF A STUDENT RECORD OF COMPUTER_PROGRAMING_1
void searchcp()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("cp1.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of Computer_Programing_1:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In Computer_Programing_1 Has been Displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.cp1.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.cp1.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.cp1.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.cp1.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.cp1.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.cp1.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}
// FUNCTION DEFINITION TO UPDATE RESULT OF A STUDENT RECORD OF COMPUTER_PROGRAMING_1
void updatecp()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("cp1.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.totalmark);
            if (s1.cp1.totalmark > to || s1.cp1.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in Computer_Programing_1:  ");
            }
         } while (to < s1.cp1.totalmark || s1.cp1.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.finalmark);
            if (s1.cp1.finalmark > fi || s1.cp1.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in Computer_Programing_1:  ");
            }
         } while (fi < s1.cp1.finalmark || s1.cp1.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.midmark);
            if (s1.cp1.midmark > mi || s1.cp1.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in Computer_Programing_1:  ");
            }
         } while (mi < s1.cp1.midmark || s1.cp1.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.quiz1mark);
            if (s1.cp1.quiz1mark > q1 || s1.cp1.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in Computer_Programing_1:  ");
            }

         } while (q1 < s1.cp1.quiz1mark || s1.cp1.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.quiz2mark);
            if (s1.cp1.quiz2mark > q2 || s1.cp1.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
            }
         } while (q2 < s1.cp1.quiz2mark || s1.cp1.quiz2mark < 0);
         printf("\nEnter GPA of The Student in Computer_Programing_1:  ");
         do
         {
            scanf("%f", &s1.cp1.gpamark);
            if (s1.cp1.gpamark > gp || s1.cp1.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in Computer_Programing_1:  ");
            }
         } while (gp < s1.cp1.gpamark || s1.cp1.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("cp1.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}
// FUNCTIONS DEFINITION TO DELETE RESULT OF A STUDENT RECORD OF COMPUTER_PROGRAMING_1
void deletereccp()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("cp1.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("cp1.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Dleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// NOW FURTHER FUNCTIONS DEFINITION IS SAME AS FOR THE ABOVE GIVEN TWO SUBJECTS.

// FUNCTIONS DEFINITION OF DLD
void createdld()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Sbject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("dld.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.totalmark);
         if (stu[i].dld.totalmark > to || stu[i].dld.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (to < stu[i].dld.totalmark || stu[i].dld.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.finalmark);
         if (stu[i].dld.finalmark > fi || stu[i].dld.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (fi < stu[i].dld.finalmark || stu[i].dld.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.midmark);
         if (stu[i].dld.midmark > mi || stu[i].dld.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (mi < stu[i].dld.midmark || stu[i].dld.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.quiz1mark);
         if (stu[i].dld.quiz1mark > q1 || stu[i].dld.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (q1 < stu[i].dld.quiz1mark || stu[i].dld.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.quiz2mark);
         if (stu[i].dld.quiz2mark > q2 || stu[i].dld.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (q2 < stu[i].dld.quiz2mark || stu[i].dld.quiz2mark < 0);
      printf("\nEnter GPA of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].dld.gpamark);
         if (stu[i].dld.gpamark > gp || stu[i].dld.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         }
      } while (gp < stu[i].dld.gpamark || stu[i].dld.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displaydld()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Saved In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("dld.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In DIGITAL LOGIC DESIGN AND CIRCUITS is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.dld.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.dld.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.dld.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.dld.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.dld.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.dld.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appenddld()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of DIGITAL LOGIC DESIGN AND CIRCUITS?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("dld.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.totalmark);
            if (s[i].dld.totalmark > to || s[i].dld.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (to < s[i].dld.totalmark || s[i].dld.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.finalmark);
            if (s[i].dld.finalmark > fi || s[i].dld.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (fi < s[i].dld.finalmark || s[i].dld.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.midmark);
            if (s[i].dld.midmark > mi || s[i].dld.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (mi < s[i].dld.midmark || s[i].dld.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.quiz1mark);
            if (s[i].dld.quiz1mark > q1 || s[i].dld.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (q1 < s[i].dld.quiz1mark || s[i].dld.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.quiz2mark);
            if (s[i].dld.quiz2mark > q2 || s[i].dld.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (q2 < s[i].dld.quiz2mark || s[i].dld.quiz2mark < 0);
         printf("\nEnter GPA of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].dld.gpamark);
            if (s[i].dld.gpamark > gp || s[i].dld.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (gp < s[i].dld.gpamark || s[i].dld.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appendvcad Successfuly...!\n");
}

void noofrecorddld()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("dld.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchdld()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("dld.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In DIGITAL LOGIC DESIGN AND CIRCUITS Has been Displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.dld.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.dld.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.dld.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.dld.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.dld.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.dld.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updatedld()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("dld.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.totalmark);
            if (s1.dld.totalmark > to || s1.dld.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (to < s1.dld.totalmark || s1.dld.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.finalmark);
            if (s1.dld.finalmark > fi || s1.dld.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (fi < s1.dld.finalmark || s1.dld.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.midmark);
            if (s1.dld.midmark > mi || s1.dld.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (mi < s1.dld.midmark || s1.dld.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.quiz1mark);
            if (s1.dld.quiz1mark > q1 || s1.dld.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }

         } while (q1 < s1.dld.quiz1mark || s1.dld.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.quiz2mark);
            if (s1.dld.quiz2mark > q2 || s1.dld.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (q2 < s1.dld.quiz2mark || s1.dld.quiz2mark < 0);
         printf("\nEnter GPA of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.dld.gpamark);
            if (s1.dld.gpamark > gp || s1.dld.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in DIGITAL LOGIC DESIGN AND CIRCUITS:  ");
            }
         } while (gp < s1.dld.gpamark || s1.dld.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("dld.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecdld()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("dld.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("dld.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Has Been Deleted...!\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION OF ENGINEERING DYNAMICS.
void createed()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ed.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.totalmark);
         if (stu[i].ed.totalmark > to || stu[i].ed.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (to < stu[i].ed.totalmark || stu[i].ed.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.finalmark);
         if (stu[i].ed.finalmark > fi || stu[i].ed.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (fi < stu[i].ed.finalmark || stu[i].ed.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.midmark);
         if (stu[i].ed.midmark > mi || stu[i].ed.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (mi < stu[i].ed.midmark || stu[i].ed.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.quiz1mark);
         if (stu[i].ed.quiz1mark > q1 || stu[i].ed.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (q1 < stu[i].ed.quiz1mark || stu[i].ed.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.quiz2mark);
         if (stu[i].ed.quiz2mark > q2 || stu[i].ed.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (q2 < stu[i].ed.quiz2mark || stu[i].ed.quiz2mark < 0);
      printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
      do
      {
         scanf("%f", &stu[i].ed.gpamark);
         if (stu[i].ed.gpamark > gp || stu[i].ed.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
         }
      } while (gp < stu[i].ed.gpamark || stu[i].ed.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displayed()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Saved In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("ed.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In ENGINEERING DYNAMICS is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ed.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ed.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ed.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ed.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ed.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.ed.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendvcad()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of ENGINEERING DYNAMICS?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ed.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.totalmark);
            if (s[i].ed.totalmark > to || s[i].ed.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (to < s[i].ed.totalmark || s[i].ed.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.finalmark);
            if (s[i].ed.finalmark > fi || s[i].ed.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (fi < s[i].ed.finalmark || s[i].ed.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.midmark);
            if (s[i].ed.midmark > mi || s[i].ed.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (mi < s[i].ed.midmark || s[i].ed.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.quiz1mark);
            if (s[i].ed.quiz1mark > q1 || s[i].ed.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (q1 < s[i].ed.quiz1mark || s[i].ed.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.quiz2mark);
            if (s[i].ed.quiz2mark > q2 || s[i].ed.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (q2 < s[i].ed.quiz2mark || s[i].ed.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s[i].ed.gpamark);
            if (s[i].ed.gpamark > gp || s[i].ed.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (gp < s[i].ed.gpamark || s[i].ed.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appended Successfuly...!\n");
}

void noofrecorded()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("ed.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searched()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("ed.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of ENGINEERING DYNAMICS:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In ENGINEERING DYNAMICS Has been Displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.ed.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ed.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ed.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.ed.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.ed.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.ed.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateed()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ed.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.totalmark);
            if (s1.ed.totalmark > to || s1.ed.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (to < s1.ed.totalmark || s1.ed.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.finalmark);
            if (s1.ed.finalmark > fi || s1.ed.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (fi < s1.ed.finalmark || s1.ed.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.midmark);
            if (s1.ed.midmark > mi || s1.ed.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (mi < s1.ed.midmark || s1.ed.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.quiz1mark);
            if (s1.ed.quiz1mark > q1 || s1.ed.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING DYNAMICS:  ");
            }

         } while (q1 < s1.ed.quiz1mark || s1.ed.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.quiz2mark);
            if (s1.ed.quiz2mark > q2 || s1.ed.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (q2 < s1.ed.quiz2mark || s1.ed.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
         do
         {
            scanf("%f", &s1.ed.gpamark);
            if (s1.ed.gpamark > gp || s1.ed.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ENGINEERING DYNAMICS:  ");
            }
         } while (gp < s1.ed.gpamark || s1.ed.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("ed.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deletereced()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ed.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("ed.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION OF ELECTRIC MACHINERY.
void createem()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("em.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.totalmark);
         if (stu[i].em.totalmark > to || stu[i].em.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (to < stu[i].em.totalmark || stu[i].em.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.finalmark);
         if (stu[i].em.finalmark > fi || stu[i].em.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (fi < stu[i].em.finalmark || stu[i].em.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.midmark);
         if (stu[i].em.midmark > mi || stu[i].em.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (mi < stu[i].em.midmark || stu[i].em.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.quiz1mark);
         if (stu[i].em.quiz1mark > q1 || stu[i].em.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (q1 < stu[i].em.quiz1mark || stu[i].em.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.quiz2mark);
         if (stu[i].em.quiz2mark > q2 || stu[i].em.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (q2 < stu[i].em.quiz2mark || stu[i].em.quiz2mark < 0);
      printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
      do
      {
         scanf("%f", &stu[i].em.gpamark);
         if (stu[i].em.gpamark > gp || stu[i].em.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
         }
      } while (gp < stu[i].em.gpamark || stu[i].em.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displayem()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savem In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("em.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In ELECTRIC MACHINERY is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.em.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.em.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.em.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.em.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.em.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.em.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendem()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of ELECTRIC MACHINERY?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("em.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.totalmark);
            if (s[i].em.totalmark > to || s[i].em.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (to < s[i].em.totalmark || s[i].em.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.finalmark);
            if (s[i].em.finalmark > fi || s[i].em.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (fi < s[i].em.finalmark || s[i].em.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.midmark);
            if (s[i].em.midmark > mi || s[i].em.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (mi < s[i].em.midmark || s[i].em.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.quiz1mark);
            if (s[i].em.quiz1mark > q1 || s[i].em.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (q1 < s[i].em.quiz1mark || s[i].em.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.quiz2mark);
            if (s[i].em.quiz2mark > q2 || s[i].em.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (q2 < s[i].em.quiz2mark || s[i].em.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s[i].em.gpamark);
            if (s[i].em.gpamark > gp || s[i].em.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (gp < s[i].em.gpamark || s[i].em.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appended Successfuly...!\n");
}

void noofrecordem()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("em.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchem()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("em.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of ELECTRIC MACHINERY:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In ELECTRIC MACHINERY Has been Displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.em.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.em.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.em.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.em.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.em.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.em.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateem()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("em.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.totalmark);
            if (s1.em.totalmark > to || s1.em.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (to < s1.em.totalmark || s1.em.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.finalmark);
            if (s1.em.finalmark > fi || s1.em.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (fi < s1.em.finalmark || s1.em.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.midmark);
            if (s1.em.midmark > mi || s1.em.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (mi < s1.em.midmark || s1.em.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.quiz1mark);
            if (s1.em.quiz1mark > q1 || s1.em.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC MACHINERY:  ");
            }

         } while (q1 < s1.em.quiz1mark || s1.em.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.quiz2mark);
            if (s1.em.quiz2mark > q2 || s1.em.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (q2 < s1.em.quiz2mark || s1.em.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
         do
         {
            scanf("%f", &s1.em.gpamark);
            if (s1.em.gpamark > gp || s1.em.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ELECTRIC MACHINERY:  ");
            }
         } while (gp < s1.em.gpamark || s1.em.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("em.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecem()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("em.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("em.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("Record Has Been Deleted...!");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITIONS OF VECTOR AND COMPLEX ANALYSIS
void createvca()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("vca.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.totalmark);
         if (stu[i].vca.totalmark > to || stu[i].vca.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (to < stu[i].vca.totalmark || stu[i].vca.totalmark < 0);
      printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.finalmark);
         if (stu[i].vca.finalmark > fi || stu[i].vca.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (fi < stu[i].vca.finalmark || stu[i].vca.finalmark < 0);
      printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.midmark);
         if (stu[i].vca.midmark > mi || stu[i].vca.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (mi < stu[i].vca.midmark || stu[i].vca.midmark < 0);
      printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.quiz1mark);
         if (stu[i].vca.quiz1mark > q1 || stu[i].vca.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (q1 < stu[i].vca.quiz1mark || stu[i].vca.quiz1mark < 0);
      printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.quiz2mark);
         if (stu[i].vca.quiz2mark > q2 || stu[i].vca.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (q2 < stu[i].vca.quiz2mark || stu[i].vca.quiz2mark < 0);
      printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
      do
      {
         scanf("%f", &stu[i].vca.gpamark);
         if (stu[i].vca.gpamark > gp || stu[i].vca.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         }
      } while (gp < stu[i].vca.gpamark || stu[i].vca.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void Displayvca()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savvca In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("vca.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of obtained Marks of %s %s In VECTOR AND COMPLEX ANALYSIS is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.vca.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.vca.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.vca.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.vca.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.vca.quiz2mark);
         printf("\nobtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.vca.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendvca()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of VECTOR AND COMPLEX ANALYSIS?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("vca.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.totalmark);
            if (s[i].vca.totalmark > to || s[i].vca.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (to < s[i].vca.totalmark || s[i].vca.totalmark < 0);
         printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.finalmark);
            if (s[i].vca.finalmark > fi || s[i].vca.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (fi < s[i].vca.finalmark || s[i].vca.finalmark < 0);
         printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.midmark);
            if (s[i].vca.midmark > mi || s[i].vca.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (mi < s[i].vca.midmark || s[i].vca.midmark < 0);
         printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.quiz1mark);
            if (s[i].vca.quiz1mark > q1 || s[i].vca.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (q1 < s[i].vca.quiz1mark || s[i].vca.quiz1mark < 0);
         printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.quiz2mark);
            if (s[i].vca.quiz2mark > q2 || s[i].vca.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (q2 < s[i].vca.quiz2mark || s[i].vca.quiz2mark < 0);
         printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s[i].vca.gpamark);
            if (s[i].vca.gpamark > gp || s[i].vca.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (gp < s[i].vca.gpamark || s[i].vca.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appended Successfuly...!\n");
}

void noofrecordvca()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("vca.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchvca()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("vca.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of VECTOR AND COMPLEX ANALYSIS:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of obtained Marks of %s %s In VECTOR AND COMPLEX ANALYSIS Has been Displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.vca.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.vca.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.vca.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.vca.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.vca.quiz2mark);
            printf("\nobtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.vca.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updatevca()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("vca.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.totalmark);
            if (s1.vca.totalmark > to || s1.vca.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total obtained Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (to < s1.vca.totalmark || s1.vca.totalmark < 0);
         printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.finalmark);
            if (s1.vca.finalmark > fi || s1.vca.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Final_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (fi < s1.vca.finalmark || s1.vca.finalmark < 0);
         printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.midmark);
            if (s1.vca.midmark > mi || s1.vca.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Mid_Term Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (mi < s1.vca.midmark || s1.vca.midmark < 0);
         printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.quiz1mark);
            if (s1.vca.quiz1mark > q1 || s1.vca.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Quiz_1 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }

         } while (q1 < s1.vca.quiz1mark || s1.vca.quiz1mark < 0);
         printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.quiz2mark);
            if (s1.vca.quiz2mark > q2 || s1.vca.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter obtained Quiz_2 Marks of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (q2 < s1.vca.quiz2mark || s1.vca.quiz2mark < 0);
         printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
         do
         {
            scanf("%f", &s1.vca.gpamark);
            if (s1.vca.gpamark > gp || s1.vca.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in VECTOR AND COMPLEX ANALYSIS:  ");
            }
         } while (gp < s1.vca.gpamark || s1.vca.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("vca.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecvca()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("vca.txt", "r");
   fp1 = fopen("temp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("temp.txt", "r");
      fp = fopen("vca.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("Record Has Been Deleted...!");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITIONS OF ENGINEERING DYNAMICS SUBJECT
void engineeringdynamics()
{
   int ch;
   do
   {
      printf("\nWelcom To the ENGINEERING DYNAMICS RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of ENGINEERING DYNAMICS...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of ENGINEERING DYNAMICS...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of ENGINEERING DYNAMICS...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of ENGINEERING DYNAMICS...Then Press 4");
      printf("\nIF You Want To Search In Record Of ENGINEERING DYNAMICS...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of ENGINEERING DYNAMICS...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of ENGINEERING DYNAMICS...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createed();
         break;
      case 2:
         displayed();
         break;
      case 3:
         appendvcad();
         break;
      case 4:
         noofrecorded;
         break;
      case 5:
         searched();
         break;
      case 6:
         updateed();
         break;
      case 7:
         deletereced();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF VECTOR AND COMPLEX ANALYSIS SUBJECT
void vectorandcoplexanalysis()
{
   int ch;
   do
   {
      printf("\nWelcom To the VECTOR AND COMPLEX ANALYSIS RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 4");
      printf("\nIF You Want To Search In Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of VECTOR AND COMPLEX ANALYSIS...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createvca();
         break;
      case 2:
         Displayvca();
         break;
      case 3:
         appendvca();
         break;
      case 4:
         noofrecordvca;
         break;
      case 5:
         searchvca();
         break;
      case 6:
         updatevca();
         break;
      case 7:
         deleterecvca();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF  Computer_Programing_1 SUBJECT
void computerprograming()
{
   int ch;
   do
   {
      printf("\nWelcom To the Computer_Programing_1 RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of Computer_Programing_1...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of Computer_Programing_1...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of Computer_Programing_1...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of Computer_Programing_1...Then Press 4");
      printf("\nIF You Want To Search In Record Of Computer_Programing_1...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of Computer_Programing_1...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of Computer_Programing_1...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createcp();
         break;
      case 2:
         displaycp();
         break;
      case 3:
         appendcp();
         break;
      case 4:
         noofrecordcp();
         break;
      case 5:
         searchcp();
         break;
      case 6:
         updatecp();
         break;
      case 7:
         deletereccp();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF  ELECTRIC MACHINERY SUBJECT
void electricmachinery()
{
   int ch;
   do
   {
      printf("\nWelcom To the ELECTRIC MACHINERY RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of ELECTRIC MACHINERY...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of ELECTRIC MACHINERY...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of ELECTRIC MACHINERY...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of ELECTRIC MACHINERY...Then Press 4");
      printf("\nIF You Want To Search In Record Of ELECTRIC MACHINERY...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of ELECTRIC MACHINERY...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of ELECTRIC MACHINERY...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createem();
         break;
      case 2:
         displayem();
         break;
      case 3:
         appendem();
         break;
      case 4:
         noofrecordem;
         break;
      case 5:
         searchem();
         break;
      case 6:
         updateem();
         break;
      case 7:
         deleterecem();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF  DIGITAL LOGIC DESIGN AND CIRCUITS SUBJECT
void digitallogicdesign()
{
   int ch;
   do
   {
      printf("\nWelcom To the DIGITAL LOGIC DESIGN AND CIRCUITS RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 4");
      printf("\nIF You Want To Search In Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of DIGITAL LOGIC DESIGN AND CIRCUITS...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createdld();
         break;
      case 2:
         displaydld();
         break;
      case 3:
         appenddld();
         break;
      case 4:
         noofrecorddld;
         break;
      case 5:
         searchdld();
         break;
      case 6:
         updatedld();
         break;
      case 7:
         deleterecdld();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF  QURAN TRANSLATION_2 SUBJECT
void qurantranslation()
{
   int ch;
   do
   {
      printf("\nWelcom To the QURAN TRANSLATION_2 RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of QURAN TRANSLATION_2...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of QURAN TRANSLATION_2...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of QURAN TRANSLATION_2...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of QURAN TRANSLATION_2...Then Press 4");
      printf("\nIF You Want To Search In Record Of QURAN TRANSLATION_2...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of QURAN TRANSLATION_2...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of QURAN TRANSLATION_2...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createqt();
         break;
      case 2:
         displayqt();
         break;
      case 3:
         appendqt();
         break;
      case 4:
         noofrecordqt;
         break;
      case 5:
         searchqt();
         break;
      case 6:
         updateqt();
         break;
      case 7:
         deleterecqt();
         break;
      }
   } while (ch != 0);
}
// FUNCTIONS DEFINITIONS OF ISLAMIYAT AND PAKISTAN STUDIES
void createisl()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("isl.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.totalmark);
         if (stu[i].isl.totalmark > to || stu[i].isl.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (to < stu[i].isl.totalmark || stu[i].isl.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.finalmark);
         if (stu[i].isl.finalmark > fi || stu[i].isl.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (fi < stu[i].isl.finalmark || stu[i].isl.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.midmark);
         if (stu[i].isl.midmark > mi || stu[i].isl.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (mi < stu[i].isl.midmark || stu[i].isl.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.quiz1mark);
         if (stu[i].isl.quiz1mark > q1 || stu[i].isl.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (q1 < stu[i].isl.quiz1mark || stu[i].isl.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.quiz2mark);
         if (stu[i].isl.quiz2mark > q2 || stu[i].isl.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (q2 < stu[i].isl.quiz2mark || stu[i].isl.quiz2mark < 0);
      printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
      do
      {
         scanf("%f", &stu[i].isl.gpamark);
         if (stu[i].isl.gpamark > gp || stu[i].isl.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         }
      } while (gp < stu[i].isl.gpamark || stu[i].isl.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\nRecord Has Been Added Successfuly...!");
      printf("\n\n");
   }
   fclose(fp);
}

void displayisl()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savisl In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("isl.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In ISLAMIYAT AND PAKISTAN STUDIES is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.isl.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.isl.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.isl.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.isl.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.isl.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.isl.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void Appendisl()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of ISLAMIYAT AND PAKISTAN STUDIES?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("isl.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.totalmark);
            if (s[i].isl.totalmark > to || s[i].isl.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (to < s[i].isl.totalmark || s[i].isl.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.finalmark);
            if (s[i].isl.finalmark > fi || s[i].isl.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (fi < s[i].isl.finalmark || s[i].isl.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.midmark);
            if (s[i].isl.midmark > mi || s[i].isl.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (mi < s[i].isl.midmark || s[i].isl.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.quiz1mark);
            if (s[i].isl.quiz1mark > q1 || s[i].isl.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (q1 < s[i].isl.quiz1mark || s[i].isl.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.quiz2mark);
            if (s[i].isl.quiz2mark > q2 || s[i].isl.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (q2 < s[i].isl.quiz2mark || s[i].isl.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s[i].isl.gpamark);
            if (s[i].isl.gpamark > gp || s[i].isl.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (gp < s[i].isl.gpamark || s[i].isl.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been Appended Successfuly...!\n");
}

void noofrecordisl()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("isl.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchisl()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("isl.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of ISLAMIYAT AND PAKISTAN STUDIES:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In ISLAMIYAT AND PAKISTAN STUDIES Has been Displayisl Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.isl.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.isl.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.isl.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.isl.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.isl.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.isl.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateisl()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("isl.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.totalmark);
            if (s1.isl.totalmark > to || s1.isl.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (to < s1.isl.totalmark || s1.isl.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.finalmark);
            if (s1.isl.finalmark > fi || s1.isl.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (fi < s1.isl.finalmark || s1.isl.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.midmark);
            if (s1.isl.midmark > mi || s1.isl.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (mi < s1.isl.midmark || s1.isl.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.quiz1mark);
            if (s1.isl.quiz1mark > q1 || s1.isl.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }

         } while (q1 < s1.isl.quiz1mark || s1.isl.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.quiz2mark);
            if (s1.isl.quiz2mark > q2 || s1.isl.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (q2 < s1.isl.quiz2mark || s1.isl.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
         do
         {
            scanf("%f", &s1.isl.gpamark);
            if (s1.isl.gpamark > gp || s1.isl.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ISLAMIYAT AND PAKISTAN STUDIES:  ");
            }
         } while (gp < s1.isl.gpamark || s1.isl.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("isl.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updatisl Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecisl()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("isl.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("isl.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION OF ENGINEERING GRAPHICS
void createegd()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Sbject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("egd.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.totalmark);
         if (stu[i].egd.totalmark > to || stu[i].egd.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (to < stu[i].egd.totalmark || stu[i].egd.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.finalmark);
         if (stu[i].egd.finalmark > fi || stu[i].egd.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (fi < stu[i].egd.finalmark || stu[i].egd.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.midmark);
         if (stu[i].egd.midmark > mi || stu[i].egd.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (mi < stu[i].egd.midmark || stu[i].egd.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.quiz1mark);
         if (stu[i].egd.quiz1mark > q1 || stu[i].egd.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (q1 < stu[i].egd.quiz1mark || stu[i].egd.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.quiz2mark);
         if (stu[i].egd.quiz2mark > q2 || stu[i].egd.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (q2 < stu[i].egd.quiz2mark || stu[i].egd.quiz2mark < 0);
      printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
      do
      {
         scanf("%f", &stu[i].egd.gpamark);
         if (stu[i].egd.gpamark > gp || stu[i].egd.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         }
      } while (gp < stu[i].egd.gpamark || stu[i].egd.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displayegd()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savap In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("egd.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In ENGINEERING GRAPHICS AND DRAWING is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.egd.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.egd.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.egd.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.egd.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.egd.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.egd.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendvcagd()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of ENGINEERING GRAPHICS AND DRAWING?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("egd.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.totalmark);
            if (s[i].egd.totalmark > to || s[i].egd.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (to < s[i].egd.totalmark || s[i].egd.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.finalmark);
            if (s[i].egd.finalmark > fi || s[i].egd.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (fi < s[i].egd.finalmark || s[i].egd.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.midmark);
            if (s[i].egd.midmark > mi || s[i].egd.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (mi < s[i].egd.midmark || s[i].egd.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.quiz1mark);
            if (s[i].egd.quiz1mark > q1 || s[i].egd.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (q1 < s[i].egd.quiz1mark || s[i].egd.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.quiz2mark);
            if (s[i].egd.quiz2mark > q2 || s[i].egd.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (q2 < s[i].egd.quiz2mark || s[i].egd.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s[i].egd.gpamark);
            if (s[i].egd.gpamark > gp || s[i].egd.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (gp < s[i].egd.gpamark || s[i].egd.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been Appended Successfuly...!\n");
}

void noofrecordegd()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("egd.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchegd()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("egd.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of ENGINEERING GRAPHICS AND DRAWING:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In ENGINEERING GRAPHICS AND DRAWING Has been displayap Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.egd.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.egd.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.egd.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.egd.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.egd.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.egd.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateegd()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("egd.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.totalmark);
            if (s1.egd.totalmark > to || s1.egd.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (to < s1.egd.totalmark || s1.egd.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.finalmark);
            if (s1.egd.finalmark > fi || s1.egd.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (fi < s1.egd.finalmark || s1.egd.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.midmark);
            if (s1.egd.midmark > mi || s1.egd.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (mi < s1.egd.midmark || s1.egd.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.quiz1mark);
            if (s1.egd.quiz1mark > q1 || s1.egd.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }

         } while (q1 < s1.egd.quiz1mark || s1.egd.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.quiz2mark);
            if (s1.egd.quiz2mark > q2 || s1.egd.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (q2 < s1.egd.quiz2mark || s1.egd.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
         do
         {
            scanf("%f", &s1.egd.gpamark);
            if (s1.egd.gpamark > gp || s1.egd.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ENGINEERING GRAPHICS AND DRAWING:  ");
            }
         } while (gp < s1.egd.gpamark || s1.egd.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("egd.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecegd()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("egd.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("egd.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deletap Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION FOR APPLIED PHYSICS.
void createap()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ap.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.totalmark);
         if (stu[i].ap.totalmark > to || stu[i].ap.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
         }
      } while (to < stu[i].ap.totalmark || stu[i].ap.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.finalmark);
         if (stu[i].ap.finalmark > fi || stu[i].ap.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
         }
      } while (fi < stu[i].ap.finalmark || stu[i].ap.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.midmark);
         if (stu[i].ap.midmark > mi || stu[i].ap.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
         }
      } while (mi < stu[i].ap.midmark || stu[i].ap.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.quiz1mark);
         if (stu[i].ap.quiz1mark > q1 || stu[i].ap.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
         }
      } while (q1 < stu[i].ap.quiz1mark || stu[i].ap.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.quiz2mark);
         if (stu[i].ap.quiz2mark > q2 || stu[i].ap.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
         }
      } while (q2 < stu[i].ap.quiz2mark || stu[i].ap.quiz2mark < 0);
      printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
      do
      {
         scanf("%f", &stu[i].ap.gpamark);
         if (stu[i].ap.gpamark > gp || stu[i].ap.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
         }
      } while (gp < stu[i].ap.gpamark || stu[i].ap.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displayap()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savap In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("ap.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In APPLIED PHYSICS is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ap.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ap.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ap.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ap.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ap.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.ap.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendap()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of APPLIED PHYSICS?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ap.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.totalmark);
            if (s[i].ap.totalmark > to || s[i].ap.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (to < s[i].ap.totalmark || s[i].ap.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.finalmark);
            if (s[i].ap.finalmark > fi || s[i].ap.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (fi < s[i].ap.finalmark || s[i].ap.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.midmark);
            if (s[i].ap.midmark > mi || s[i].ap.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (mi < s[i].ap.midmark || s[i].ap.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.quiz1mark);
            if (s[i].ap.quiz1mark > q1 || s[i].ap.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (q1 < s[i].ap.quiz1mark || s[i].ap.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.quiz2mark);
            if (s[i].ap.quiz2mark > q2 || s[i].ap.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (q2 < s[i].ap.quiz2mark || s[i].ap.quiz2mark < 0);
         printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s[i].ap.gpamark);
            if (s[i].ap.gpamark > gp || s[i].ap.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
            }
         } while (gp < s[i].ap.gpamark || s[i].ap.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been Appended Successfuly...!\n");
}

void noofrecordap()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("ap.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchap()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("ap.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of APPLIED PHYSICS:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In APPLIED PHYSICS Has been displayed Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.ap.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ap.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ap.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.ap.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.ap.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.ap.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateap()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ap.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.totalmark);
            if (s1.ap.totalmark > to || s1.ap.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (to < s1.ap.totalmark || s1.ap.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.finalmark);
            if (s1.ap.finalmark > fi || s1.ap.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (fi < s1.ap.finalmark || s1.ap.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.midmark);
            if (s1.ap.midmark > mi || s1.ap.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (mi < s1.ap.midmark || s1.ap.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.quiz1mark);
            if (s1.ap.quiz1mark > q1 || s1.ap.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in APPLIED PHYSICS:  ");
            }

         } while (q1 < s1.ap.quiz1mark || s1.ap.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.quiz2mark);
            if (s1.ap.quiz2mark > q2 || s1.ap.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in APPLIED PHYSICS:  ");
            }
         } while (q2 < s1.ap.quiz2mark || s1.ap.quiz2mark < 0);
         printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
         do
         {
            scanf("%f", &s1.ap.gpamark);
            if (s1.ap.gpamark > gp || s1.ap.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in APPLIED PHYSICS:  ");
            }
         } while (gp < s1.ap.gpamark || s1.ap.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("ap.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecap()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ap.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("ap.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITONS FOR ELECTRIC CIRCUITS
void createec()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ec.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.totalmark);
         if (stu[i].ec.totalmark > to || stu[i].ec.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (to < stu[i].ec.totalmark || stu[i].ec.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.finalmark);
         if (stu[i].ec.finalmark > fi || stu[i].ec.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (fi < stu[i].ec.finalmark || stu[i].ec.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.midmark);
         if (stu[i].ec.midmark > mi || stu[i].ec.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (mi < stu[i].ec.midmark || stu[i].ec.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.quiz1mark);
         if (stu[i].ec.quiz1mark > q1 || stu[i].ec.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (q1 < stu[i].ec.quiz1mark || stu[i].ec.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.quiz2mark);
         if (stu[i].ec.quiz2mark > q2 || stu[i].ec.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (q2 < stu[i].ec.quiz2mark || stu[i].ec.quiz2mark < 0);
      printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
      do
      {
         scanf("%f", &stu[i].ec.gpamark);
         if (stu[i].ec.gpamark > gp || stu[i].ec.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
         }
      } while (gp < stu[i].ec.gpamark || stu[i].ec.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displayec()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Saved In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("ec.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In ELECTRIC CIRCUITS is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ec.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ec.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ec.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ec.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.ec.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.ec.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendec()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of ELECTRIC CIRCUITS?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("ec.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.totalmark);
            if (s[i].ec.totalmark > to || s[i].ec.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (to < s[i].ec.totalmark || s[i].ec.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.finalmark);
            if (s[i].ec.finalmark > fi || s[i].ec.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (fi < s[i].ec.finalmark || s[i].ec.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.midmark);
            if (s[i].ec.midmark > mi || s[i].ec.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (mi < s[i].ec.midmark || s[i].ec.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.quiz1mark);
            if (s[i].ec.quiz1mark > q1 || s[i].ec.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (q1 < s[i].ec.quiz1mark || s[i].ec.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.quiz2mark);
            if (s[i].ec.quiz2mark > q2 || s[i].ec.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (q2 < s[i].ec.quiz2mark || s[i].ec.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s[i].ec.gpamark);
            if (s[i].ec.gpamark > gp || s[i].ec.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (gp < s[i].ec.gpamark || s[i].ec.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been appended Successfuly...!\n");
}

void noofrecordec()
{
   printf("========================================== Your Intention Is To See Add Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("ec.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchec()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("ec.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of ELECTRIC CIRCUITS:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In ELECTRIC CIRCUITS Has been displayap Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.ec.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ec.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.ec.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.ec.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.ec.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.ec.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updateec()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ec.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.totalmark);
            if (s1.ec.totalmark > to || s1.ec.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (to < s1.ec.totalmark || s1.ec.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.finalmark);
            if (s1.ec.finalmark > fi || s1.ec.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (fi < s1.ec.finalmark || s1.ec.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.midmark);
            if (s1.ec.midmark > mi || s1.ec.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (mi < s1.ec.midmark || s1.ec.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.quiz1mark);
            if (s1.ec.quiz1mark > q1 || s1.ec.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in ELECTRIC CIRCUITS:  ");
            }

         } while (q1 < s1.ec.quiz1mark || s1.ec.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.quiz2mark);
            if (s1.ec.quiz2mark > q2 || s1.ec.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (q2 < s1.ec.quiz2mark || s1.ec.quiz2mark < 0);
         printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
         do
         {
            scanf("%f", &s1.ec.gpamark);
            if (s1.ec.gpamark > gp || s1.ec.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in ELECTRIC CIRCUITS:  ");
            }
         } while (gp < s1.ec.gpamark || s1.ec.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("ec.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deleterecec()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("ec.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("ec.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deletaed Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// FUNCTIONS DEFINITION OF CALCULAS AND ANALYTICAL GEOMETRY
void createcag()
{
   printf("========================================== Your Intention Is To Add The Record Of Students In The File ==========================================\n\n");
   struct student *stu;
   FILE *fp;
   int n, i, j;
   int k = 500;
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("\nResult of How Many Students do you want to add?  ");
   do
   {
      scanf("%d", &n);
      if (n > k || n < 0)
      {
         printf("\nInvalid Entry...!!!");
         printf("\nTry again...!!!");
         printf("\nResult of How Many Students do you want to add?  ");
      }
   } while (k <= n || n <= 0);
   printf("\n\nStart Adding The Result Of The Students...!\n");
   printf("\n__________NOTE__________\n\nTotal MArks Of Subject Is 100\nTotal Marks Of Final_Term are 40\nTotal Marks Of Mid_Term are 40\nQuiz_1 Marks are 15\nQuiz_2 Marks are 15\nMaximum Grade Point Average Is 4\n\n");
   stu = (struct student *)calloc(n, sizeof(student));
   fp = fopen("cag.txt", "w");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student: ");
      scanf("%s %s", &stu[i].name, &stu[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student: ");
      scanf("%s", &stu[i].rollno);
      printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.totalmark);
         if (stu[i].cag.totalmark > to || stu[i].cag.totalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (to < stu[i].cag.totalmark || stu[i].cag.totalmark < 0);
      printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.finalmark);
         if (stu[i].cag.finalmark > fi || stu[i].cag.finalmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (fi < stu[i].cag.finalmark || stu[i].cag.finalmark < 0);
      printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.midmark);
         if (stu[i].cag.midmark > mi || stu[i].cag.midmark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (mi < stu[i].cag.midmark || stu[i].cag.midmark < 0);
      printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.quiz1mark);
         if (stu[i].cag.quiz1mark > q1 || stu[i].cag.quiz1mark < 0)
         {

            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (q1 < stu[i].cag.quiz1mark || stu[i].cag.quiz1mark < 0);
      printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.quiz2mark);
         if (stu[i].cag.quiz2mark > q2 || stu[i].cag.quiz2mark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (q2 < stu[i].cag.quiz2mark || stu[i].cag.quiz2mark < 0);
      printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
      do
      {
         scanf("%f", &stu[i].cag.gpamark);
         if (stu[i].cag.gpamark > gp || stu[i].cag.gpamark < 0)
         {
            printf("\nInvalid Entry...!!!\nTry again...!!!");
            printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         }
      } while (gp < stu[i].cag.gpamark || stu[i].cag.gpamark < 0);
      fwrite(&stu[i], sizeof(student), 1, fp);
      printf("\n Record Has Been Added Successfuly");
      printf("\n\n");
   }
   fclose(fp);
}

void displaycag()
{
   printf("========================================== Your Intention Is To Display The Previous Record Of Students Savcag In The File ==========================================\n\n");
   int j;
   struct student s1;
   FILE *fp;
   fp = fopen("cag.txt", "r");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      printf("\nRecord Of Obtained Marks of %s %s In CALCULAS AND ANALYTICAL GEOMETRY is Shown  Below...!\n", s1.name, s1.fname);
      for (j = 0; j < 1; j++)
      {
         printf("\nTotal Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cag.totalmark);
         printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cag.finalmark);
         printf("\nMid_Term Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cag.midmark);
         printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cag.quiz1mark);
         printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", s1.rollno, s1.cag.quiz2mark);
         printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", s1.rollno, s1.cag.gpamark);
         printf("\n\n");
      }
   }
   fclose(fp);
}

void appendcag()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Append New The Record Of Students In The File ==========================================\n\n");
   struct student *s;
   FILE *fp;
   int n, i, j;
   printf("\nResult of How Many Students do you want to Append In The Previous List Of CALCULAS AND ANALYTICAL GEOMETRY?  ");
   scanf("%d", &n);
   s = (struct student *)calloc(n, sizeof(student));
   fp = fopen("cag.txt", "a");
   for (i = 0; i < n; i++)
   {
      printf("\nEnter Name Of The Student:  ");
      scanf("%s %s", &s[i].name, &s[i].fname);
      fflush(stdin);
      printf("\nEnter Roll No Of The Student:  ");
      scanf("%s", &s[i].rollno);
      for (j = 0; j < 1; j++)
      {
         printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.totalmark);
            if (s[i].cag.totalmark > to || s[i].cag.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (to < s[i].cag.totalmark || s[i].cag.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.finalmark);
            if (s[i].cag.finalmark > fi || s[i].cag.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (fi < s[i].cag.finalmark || s[i].cag.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.midmark);
            if (s[i].cag.midmark > mi || s[i].cag.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (mi < s[i].cag.midmark || s[i].cag.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.quiz1mark);
            if (s[i].cag.quiz1mark > q1 || s[i].cag.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (q1 < s[i].cag.quiz1mark || s[i].cag.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.quiz2mark);
            if (s[i].cag.quiz2mark > q2 || s[i].cag.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (q2 < s[i].cag.quiz2mark || s[i].cag.quiz2mark < 0);
         printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s[i].cag.gpamark);
            if (s[i].cag.gpamark > gp || s[i].cag.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (gp < s[i].cag.gpamark || s[i].cag.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s[i], sizeof(student), 1, fp);
   }
   fclose(fp);
   printf("\nNew Record Has Been Appended Successfuly...!\n");
}

void noofrecordcag()
{
   printf("========================================== Your Intention Is To See Added Of Students In The File ==========================================\n\n");
   struct student s1;
   FILE *fp;
   fp = fopen("cag.txt", "r");
   fseek(fp, 0, SEEK_END);
   int n = ftell(fp) / sizeof(student);
   printf("\n\n Number Of Students Added in The Record File are = %d", n);
   printf("\n\n");
   fclose(fp);
}

void searchcag()
{
   printf("========================================== Your Intention Is To See The Record Of A Single Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp;
   fp = fopen("cag.txt", "r");
   printf("\nEnter Roll_NO Of the Student to Search His/Her Result Of CALCULAS AND ANALYTICAL GEOMETRY:  ");
   scanf("%s", rno);
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         printf("\nRecord Of Obtained Marks of %s %s In CALCULAS AND ANALYTICAL GEOMETRY Has been Displaycag Below...!\n\n", s1.name, s1.fname);
         for (j = 0; j < 1; j++)
         {
            printf("\nTotal Marks Of The Roll_NO %s are %0.2f", rno, s1.cag.totalmark);
            printf("\nFinal_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.cag.finalmark);
            printf("\nMoid_Term Marks Of The Roll_NO %s are %0.2f", rno, s1.cag.midmark);
            printf("\nQuiz_1 Marks Of The Roll_NO %s are %0.2f", rno, s1.cag.quiz1mark);
            printf("\nQuiz_2 Marks Of The Roll_NO %s are %0.2f", rno, s1.cag.quiz2mark);
            printf("\nObtained GPA Of The Roll_NO %s is %0.2f\n\n", rno, s1.cag.gpamark);
            printf("\n\n");
         }
      }
   }
   if (!found)
   {
      printf("\nRecord Was Not Found...!!!\n");
   }
   fclose(fp);
}

void updatecag()
{
   int to = 100;
   int fi = 40;
   int mi = 30;
   int q1 = 15;
   int q2 = 15;
   int gp = 4;
   printf("========================================== Your Intention Is To Update The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("cag.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO Of the Student Whose Record You want to update:  ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
         fflush(stdin);
         printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.totalmark);
            if (s1.cag.totalmark > to || s1.cag.totalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Total Obtained Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (to < s1.cag.totalmark || s1.cag.totalmark < 0);
         printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.finalmark);
            if (s1.cag.finalmark > fi || s1.cag.finalmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Final_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (fi < s1.cag.finalmark || s1.cag.finalmark < 0);
         printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.midmark);
            if (s1.cag.midmark > mi || s1.cag.midmark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Mid_Term Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (mi < s1.cag.midmark || s1.cag.midmark < 0);
         printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.quiz1mark);
            if (s1.cag.quiz1mark > q1 || s1.cag.quiz1mark < 0)
            {

               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_1 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }

         } while (q1 < s1.cag.quiz1mark || s1.cag.quiz1mark < 0);
         printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.quiz2mark);
            if (s1.cag.quiz2mark > q2 || s1.cag.quiz2mark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter Obtained Quiz_2 Marks of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (q2 < s1.cag.quiz2mark || s1.cag.quiz2mark < 0);
         printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
         do
         {
            scanf("%f", &s1.cag.gpamark);
            if (s1.cag.gpamark > gp || s1.cag.gpamark < 0)
            {
               printf("\nInvalid Entry...!!!\nTry again...!!!");
               printf("\nEnter GPA of The Student in CALCULAS AND ANALYTICAL GEOMETRY:  ");
            }
         } while (gp < s1.cag.gpamark || s1.cag.gpamark < 0);
         printf("\n\n");
      }
      fwrite(&s1, sizeof(student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("cag.txt", "w");
      while (fread(&s1, sizeof(student), 1, fp1))
      {
         fwrite(&s1, sizeof(student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord of the Student %s Has Been Updated Successfully...!!!", s1.rollno);
      printf("\n\n");
   }
   else
   {
      printf("Error,Record Not Found...!!!\n\n");
   }
}

void deletereccag()
{
   printf("========================================== Your Intention Is To Delete The Record Of Student In The File ==========================================\n\n");
   int j, found = 0;
   char rno[10];
   struct student s1;
   FILE *fp, *fp1;
   fp = fopen("cag.txt", "r");
   fp1 = fopen("tecp.txt", "w");
   printf("\nEnter Roll_NO of the Student Whose Record you want To Delete: ");
   scanf("%s", rno);
   printf("\n\n");
   while (fread(&s1, sizeof(struct student), 1, fp))
   {
      if (strcmp(s1.rollno, rno) == 0)
      {
         found = 1;
      }
      else
         fwrite(&s1, sizeof(struct student), 1, fp1);
   }
   fclose(fp);
   fclose(fp1);
   if (found)
   {
      fp1 = fopen("tecp.txt", "r");
      fp = fopen("cag.txt", "w");
      while (fread(&s1, sizeof(struct student), 1, fp1))
      {
         fwrite(&s1, sizeof(struct student), 1, fp);
      }
      fclose(fp);
      fclose(fp1);
      printf("\nRecord Of The student Has Been Deleted Successfully\n");
   }
   else
   {
      printf("Record Not Found...!!!\n\n");
   }
   fclose(fp);
}
// function definiton of applied physics subjects
void appliapphysics()
{
   int ch;
   do
   {
      printf("\nWelcom To the APPLIED PHYSICS RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of APPLIED PHYSICS...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of APPLIED PHYSICS...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of APPLIED PHYSICS...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of APPLIED PHYSICS...Then Press 4");
      printf("\nIF You Want To Search In Record Of APPLIED PHYSICS...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of APPLIED PHYSICS...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of APPLIED PHYSICS...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createap();
         break;
      case 2:
         displayap();
         break;
      case 3:
         appendap();
         break;
      case 4:
         noofrecordap;
         break;
      case 5:
         searchap();
         break;
      case 6:
         updateap();
         break;
      case 7:
         deleterecap();
         break;
      }
   } while (ch != 0);
}
// function definiton of CALCULAS AND ANALYTICAL GEOMETRY subjects
void calculas()
{
   int ch;
   do
   {
      printf("\nWelcom To the CALCULAS AND ANALYTICAL GEOMETRY RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 4");
      printf("\nIF You Want To Search In Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of CALCULAS AND ANALYTICAL GEOMETRY...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createcag();
         break;
      case 2:
         displaycag();
         break;
      case 3:
         appendcag();
         break;
      case 4:
         noofrecordcag;
         break;
      case 5:
         searchcag();
         break;
      case 6:
         updatecag();
         break;
      case 7:
         deletereccag();
         break;
      }
   } while (ch != 0);
}
// function definiton of ENGINEERING GRAPHICS AND DRAWING  subjects
void graphicsanddesign()
{
   int ch;
   do
   {
      printf("\nWelcom To the ENGINEERING GRAPHICS AND DRAWING RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 4");
      printf("\nIF You Want To Search In Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of ENGINEERING GRAPHICS AND DRAWING...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createegd();
         break;
      case 2:
         displayegd();
         break;
      case 3:
         appendvcagd();
         break;
      case 4:
         noofrecordegd();
         break;
      case 5:
         searchegd();
         break;
      case 6:
         updateegd();
         break;
      case 7:
         deleterecegd();
         break;
      }
   } while (ch != 0);
}
// function definiton of ELECTRIC CIRCUITS subjects
void electriccircuits()
{
   int ch;
   do
   {
      printf("\nWelcom To the ELECTRIC CIRCUITS RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of ELECTRIC CIRCUITS...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of ELECTRIC CIRCUITS...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of ELECTRIC CIRCUITS...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of ELECTRIC CIRCUITS...Then Press 4");
      printf("\nIF You Want To Search In Record Of ELECTRIC CIRCUITS...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of ELECTRIC CIRCUITS...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of ELECTRIC CIRCUITS...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createec();
         break;
      case 2:
         displayap();
         break;
      case 3:
         appendec();
         break;
      case 4:
         noofrecordec;
         break;
      case 5:
         searchec();
         break;
      case 6:
         updateec();
         break;
      case 7:
         deleterecec();
         break;
      }
   } while (ch != 0);
}
// function definiton of ISLAMIYAT AND PAKISTAN STUDIES subjects
void islamicandpakstudies()
{
   int ch;
   do
   {
      printf("\nWelcom To the ISLAMIYAT AND PAKISTAN STUDIES RECORD BOOK\n");
      printf("\nIF You Want To Create a New Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 1");
      printf("\nIF You Want To Display The Previous Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 2");
      printf("\nIF You Want To Append New Marks in Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 3");
      printf("\nIF You Want To Find Out The Number of Students Added in Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 4");
      printf("\nIF You Want To Search In Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 5");
      printf("\nIF You Want To Update The Previous Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 6");
      printf("\nIF You Want To Delete The Previous Record Of ISLAMIYAT AND PAKISTAN STUDIES...Then Press 7");
      printf("\nIF You Want To Exit...Then Press 0");
      printf("\n\n\tEnter Your Intention: ");
      scanf("%d", &ch);
      switch (ch)
      {
      case 1:
         createisl();
         break;
      case 2:
         displayisl();
         break;
      case 3:
         Appendisl();
         break;
      case 4:
         noofrecordisl;
         break;
      case 5:
         searchisl();
         break;
      case 6:
         updateisl();
         break;
      case 7:
         deleterecisl();
         break;
      }
   } while (ch != 0);
}
// MAIN FUNCTION.
int main()
{
   system("color 7");
   int intention = 0;
   time_t t; // not a primitive datatype
   time(&t);
   printf("\n====================================================================================================================================================");
   printf("\n\t\t\t\t\t This Program Started at(Day/Date/Time/Year): %s", ctime(&t)); // To Display Day/Date/Time/Year when the Program started Running.
   printf("====================================================================================================================================================\n");
   printf("\n\t\t\t\t\t\t\t\t  Greetings...!\n");
   printf("\n\t\t\t\t\t\t\t\t Welcome to the \n\t\t\t\t\t\t\t   Academic Record Management\n\t\t\t\t\t\t\t\t   System...!");
   printf("\n\n====================================================================================================================================================");
   printf("\n\t\t\t\t\tSelect your Intention From The Choices Given Below...\n");
   printf("====================================================================================================================================================");
   do
   {
      printf("\n\n\t\t\t\t\t\t\t   _____NOTE_____\n\t\t\t\t\tPlease Follow The Instructions While Working With Program.\n\t\t\t\t\tPressing Ivalid Key May Result In Crash The Program.!\n\n");
      printf("\n\t\t\t\t\tDo you want to Add New Student's Details?...Then Press 1\n");
      printf("\t\t\t\t\tDo you want to Remove Previous Details of a Student?...Then Press 2\n");
      printf("\t\t\t\t\tDo you want to Delete Details Of All The students?...Then Press 3\n");
      printf("\t\t\t\t\tDo you want to Check Number of Students Whose Details Are available?...Then Press 4\n");
      printf("\t\t\t\t\tDo you want to Display the Saved Details of Students?...Then Press 5\n");
      printf("\t\t\t\t\tDo you want to Open Record of a Subject?...Then Press 6\n");
      printf("\t\t\t\t\tDo you want to Close the Program?...Then Press 0\n\n\n");
      printf("\t\t\t\t\tPress Any Key from 1_2_3_4_5_6_0: ");
      scanf("%d", &intention); // Taking intention of the user.
      printf("\n\n");
      if (intention == 1)
      {
         addstudentdetails();
      }
      if (intention == 2)
      {
         removestudentdetails();
      }
      if (intention == 3)
      {
         deletedetailsfile();
      }
      if (intention == 4)
      {
         noofdetails();
      }
      if (intention == 5)
      {
         displaydetails();
      }
      if (intention == 6)
      {
         opensubject();
      }
   } while (intention != 0);
   return 0;
}
// END OF THE PROGRAM...!!!
