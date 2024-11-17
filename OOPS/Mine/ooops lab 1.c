#include<stdio.h>

struct stud {
   char name[30];
   int rollno;
   int marks[6];
};

float avg(struct stud s) {
   int tmarks = 0;
   for (int i = 0; i < 6; i++) {
      tmarks += s.marks[i];
   }
   return (float)tmarks / 6;  
}

float classavg(struct stud s[], int n) {
   float sum = 0;
   for (int i = 0; i < n; i++) {
      sum += avg(s[i]);
   }
   return sum / n;  
}

int main() {
   int x;
   printf("Enter no. of students: ");
   scanf("%d", &x);

   struct stud s[x];  

   for (int i = 0; i < x; i++) {
      printf("Enter the name of the student: ");
      scanf("%s", s[i].name);
      printf("Enter the roll no. of the student: ");
      scanf("%d", &s[i].rollno);  

      for (int j = 0; j < 6; j++) {
         printf("Enter the marks of the student in subject %d: ", j + 1);
         scanf("%d", &s[i].marks[j]);  
      }
   }

   printf("Student name    Roll no.    Aggregated marks\n");
   for (int k = 0; k < x; k++) {
      printf("%s    %d     %.2f\n", s[k].name, s[k].rollno, avg(s[k]));  
   }

   printf("Class average: %.2f\n", classavg(s, x));  

   return 0;
}

