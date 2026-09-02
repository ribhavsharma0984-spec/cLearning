#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slotpicker(int *, int *);
void classAssigner(int (*array1)[7], int *);
int subjectPicker(int *);

//timetable maker
/*
math = 1
physics = 2
c = 3
english = 4
chemistry = 5
*/

int main()
{
    int i, j;
    int (*pnt)[7] ;


    srand(time(NULL));
    int timetable[5][7] = {0};
    int classLeft[5] = {4, 3, 4, 2, 2};  


    
    pnt = &timetable[0];
    classAssigner(&timetable[0], &classLeft[0]);

    printf("timetable :\nmath = 1\nphysics = 2\nc = 3\nenglish = 4\nchemistry = 5\n\n\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 7; j++)
        {
            printf("%d ", *(*(pnt + i)+ j));
        }
        printf("\n");
    }

    printf("\nClasses pending : \n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", classLeft[i]);
    }


}

void classAssigner(int (*array1)[7], int *classDecrement)
{
    int classes;
    int row, col;
    int *p;
    int count = 0;
    

    do
    {
        slotpicker(&row, &col);
        classes = subjectPicker(classDecrement);
       
        if(*(*(array1 + row) + col) == 0)
        {
            if(*(classDecrement  + (classes - 1)) > 0)
            {
                *(*(array1 + row) + col) = classes;
                (*(classDecrement  + (classes - 1)))--;
                count++;
            }
        }
        
    }while (count < 15);
    
}

void slotpicker(int *i, int *j)
{
    *i = rand()%5; //row
    *j = rand()%7;  //column 

}

int subjectPicker(int *classleft)
{
    int subject;
    subject = rand()%5 + 1;
    return subject;

}
