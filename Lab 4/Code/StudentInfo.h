//StudentInfo.h - Header file for SEP101 lab 4, Student Information

//  Oct	11, 2022    Created      Arian.A
//  Oct 13, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A


//Avoid magic numbers
#define MAX_STR 32
#define NUM_SUBJECTS 6

//Define the subject structure
struct Subject {
    char name[MAX_STR+1];
    int mark;
};

//Define studentInfo structure, which includes subject structure
struct StudentInfo {
    char lastName [MAX_STR+1];
    int studentId;
    struct Subject subject[NUM_SUBJECTS];
};

//Prototypes of the functions declared in StudentInfo.c
void InitializeInfo(struct StudentInfo* student);
int MaximumMark(const struct Subject* subject);
int MinimumMark(const struct Subject* subject);
float AverageMark(struct Subject* subject, int len);
