#include "03_for.h"

int main()
{
    srand(time(NULL));

    struct PersonInfoStru   personOuterObj[7];
    struct Select           outerObj[4];

    int selectChoice_OutputValue;

    for (int i = 0; i < 4; i += 1)
    {
        for (int j = 0; j < 7; j += 1)
        {
            selectChoice_OutputValue = rand() % 4;
            PersionInfo_Init(&personOuterObj[j]);
            personOuterObj[j].Select_Person_Info = rand() % 7;
            personOuterObj[j].PERSON_SET(&personOuterObj[j], personOuterObj[j].Select_Person_Info);
            personOuterObj[j].PERSON_GET(&personOuterObj[j]);
            outerObj[i].input_Method_Value = selectChoice_OutputValue;
            init(&outerObj[i]);
            outerObj[i].SET(&outerObj[i], outerObj[i].input_Method_Value);
            outerObj[i].GET(&outerObj[i]);
        }
        printf("---\n");
    }
}