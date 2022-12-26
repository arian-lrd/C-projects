//StudentInfo.c - Function definitions for SEP101 lab 4, Student Information

//  Oct	11, 2022    Created      Arian.A
//  Oct 13, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A



#include <stdbool.h>
#include "StudentInfo.h"

//initialize the student information
void InitializeInfo(struct StudentInfo* student){
    student->lastName[0] = '\0';
    student->studentId = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        student->subject[i].name[0] = '\0';
        student->subject[i].mark = 0;
    }
}

//Calculate the average mark
float AverageMark(struct Subject* subject, int len){
    int runningTotal = 0;
    float averageMark;
    int rtrnVal = 0;
    for (int i = 0; i < NUM_SUBJECTS && rtrnVal !=-1 ; i++)
    {
        if(subject[i].mark == 0) {
            rtrnVal = -1;
        }
        else{
            runningTotal += subject[i].mark;
        }
    }
    averageMark = (float)runningTotal / (float)len;
    return averageMark;
}

//Find the index of the maximum grade(This is simpler than returning the maximum grade's value)
int MaximumMark(const struct Subject* subject){
    int maximumMark = 0;
    int maxIndex = 0;
    int rtrnVal = 0;
    for (int i = 0; i < NUM_SUBJECTS && rtrnVal != -1; i++)
    {
        if (subject[i].mark == 0) {
            rtrnVal = -1;
        }
        else if (subject[i].mark > maximumMark) {
            maximumMark = subject[i].mark;
            maxIndex = i;
        }
    }
    return maxIndex;   
}

//Find the index of the minimum grade(This is simpler than returning the minimum grade's value)
int MinimumMark(const struct Subject* subject) {
    int minimumMark = 100;
    int minIndex = 0;
    int rtrnVal = 0;
    for (int i = 0; i < NUM_SUBJECTS && rtrnVal != -1; i++)
    {
        if (subject[i].mark == 0) {
            rtrnVal = -1;
        }
        else if (subject[i].mark < minimumMark) {
            minimumMark = subject[i].mark;
            minIndex = i;
        }
    }
    return minIndex; 
}
/*
struct Subject {
    char name[MAX_STR+1];
    int mark;
};

struct StudentInfo {
    char lastName [MAX_STR+1];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};
*/
