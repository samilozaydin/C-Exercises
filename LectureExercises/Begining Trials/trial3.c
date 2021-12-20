#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Age;
    char Name[12];
    float Weight;
    int RollNumber;

} sStudentInfo;

int main(int argc, char *argv[])
{
    //create an array of structure;
    sStudentInfo RamInfo[2] = {0};

    //Create pointer to the structure
    sStudentInfo *psInfo = NULL;

    int iSizeofStructure = 0;

    //Assign the address of array to the pointer
    psInfo = RamInfo;

    // Subtract the pointer
    iSizeofStructure = (char *)(psInfo + 1) - (char *)(psInfo);

    printf("Size of structure  =  %d\n\n", iSizeofStructure);
}