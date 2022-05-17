/*
    Copyright (c) 2022.04.14  AZABELL Developer
    ???Úº? ?Ò½??Úµ?                     Azabell source code
    C???? À¯?? ??Ã¼???? ???? ?Úµ?       C language-like object-oriented implementation code
    ?????? ????Ã³ : jeewoo19930315@gmail.com
    Developer Connect E-mail : jeewoo19930315@gmail.com
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//#include <malloc.h>
//#include <unistd.h>
#include <sys/types.h>
//#include <mysql.h>
#define CHOP(x) x[strlen(x) - 1] = ' '
#define FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE 9
#define     GET_NAME_MAX    9
const char NAME[] = "????_????_????_?Â±?_À¯??_????_????_??Å©_????";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// void const name print
void HyunA();
void Jiwoo();
void Juhyun();
void SungGyun();
void Urim();
void SeulGi();
void Seven();
void Tech();
void Soljin();
// void const School name print
void HyunA_S();
void Jiwoo_S();
void Juhyun_S();
void SungGyun_S();
void Urim_S();
void SeulGi_S();
void Seven_S();
void Tech_S();
void Soljin_S();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    À¯?? Å¬???? typedef ???? ????
*/
typedef struct MEMBER MEMBER;
typedef struct MAJOR MAJOR;
typedef struct PROGRAMMING PROGRAMMING;
typedef struct FOOD FOOD;
typedef struct MEMBER_NAME MEMBER_NAME;
typedef struct SCHOOL_NAME SCHOOL_NAME;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    ???Ó³? À¯??Å¬???? ???? ????
*/
void    NAME_SET_(struct MEMBER_NAME* select_name, int select_name_number);
int     NAME_GET_(const struct MEMBER_NAME* select_name);
void    SET_SCHOOL_NAME_(struct SCHOOL_NAME* select_school_name, int select_school_number);
int 	GET_SCHOOL_NAME_(const struct SCHOOL_NAME* select_school_name);
void    NAME_INIT(struct MEMBER* this);
void    SCHOOL_INIT(struct SCHOOL_NAME* this);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    ???? ?Þ¼??? ???? ???? ?Þ¼??? ???? ????
*/
void    PRINT_DATA_(const MEMBER* this);

/*
    PROGRAMMING, FOOD, MAJOR ???? ?Þ¼??? ???? ????
*/
void    PROGRAMMING_PRINT_DATA_(const PROGRAMMING* this);
void    FOOD_PRINT_DATA_(const FOOD* this);
void    MAJOR_PRINT_DATA_(const MAJOR* this);
/*
    MEMBER À¯?? Å¬???? ?Þ¼??? Setter, Getter ???? ????
*/
void    MEMBER_SET_(
    MEMBER* this,
    MEMBER_NAME* select_name,
    SCHOOL_NAME* select_school_name,
    const   int     HAKBUN,
    const   int     AGE,
    const   int     INIT_DATE,
    const   int     OUT_DATE
);
int     MEMBER_GET_(
    const MEMBER* this,
    MEMBER_NAME* select_name,
    SCHOOL_NAME* select_school_name
);

/*
    FOOD À¯?? Å¬???? ?Þ¼??? Setter, Getter ???? ????
*/
void    FOOD_SET_(
    struct  FOOD* this,
    const   int     BANANAS,
    const   int     BARBECUE,
    const   int     BARLEY,
    const   int     BLUEBERRIES,
    const   int     BREAD,
    const   int     BROCCOLI,
    const   int     BURGERS,
    const   int     CAKE,
    const   int     CHEESE,
    const   int     CHICKEN

);
int     FOOD_GET_(const FOOD* this);

/*
    PROGRAMMING À¯?? Å¬???? ?Þ¼??? Setter, Getter ???? ????
*/
void    PROGRAMMING_SET_(
    struct  PROGRAMMING* this,
    const   int             DATE,
    const   int             CLANG,
    const   int             PTYHON,
    const   int             R,
    const   int             JAVA,
    const   int             SECURITY,
    const   int             NODEJ,
    const   int             CPP,
    const   int             ASSEMBLY
);
int     PROGRAMMING_GET_(const PROGRAMMING* this);

/*
    MAJOR À¯?? Å¬???? ?Þ¼??? Setter, Getter ???? ????
*/
void    MAJOR_SET_(
    struct MAJOR* this,
    const   int     KoreanLanguageAndLiterature,    //???î±¹???Ð°?
    const   int     Philosophy,                     //Ã¶?Ð°?
    const   int     Archeology,                     //?????Ð°?
    const   int     LibraryAndInformationScience,   //????Á¤???Ð°?
    const   int     CommerceAndTrade,               //?????Ð°?
    const   int     Administration,                 //??Á¤?Ð°?
    const   int     PoliticalScienceAndDiplomacy,   //Á¤Ä¡?Ü±??Ð°?
    const   int     MechanicalEngineering,          //????????
    const   int     ElectronicEngineering,          //???Ú°???
    const   int     Architecure,                    //??????
    const   int     Physics,                        //??????
    const   int     Chemistry,                      //È­??
    const   int     Biology                        //??????
);
int     MAJOR_GET_(const MAJOR* this);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    MEMBER_NAME À¯?? Å¬???? À¯?? new ?????? ????
*/
MEMBER_NAME* new_name(
    int select_name_number
);

/*
    SCHOOL_NAME À¯?? Å¬???? À¯?? new ?????? ????
*/
SCHOOL_NAME* new_school(
    int select_school_number
);

/*
    MEMBER À¯?? Å¬???? À¯?? new ?????? ????
*/
MEMBER* new_member(
    int HAKBUN_,
    MEMBER_NAME* member_name_,
    SCHOOL_NAME* select_school_number_,
    int AGE_,
    int INIT_DATE_,
    int OUT_DATE_
);

/*
    ?Ò¸??? ???æ¼±??
*/
void    DELETE_MEMBER(MEMBER* member_delete_ptr);

/*
    FOOD À¯?? new ?????? ???? ????
*/
FOOD* new_food(
    int     BANANAS_,
    int     BARBECUE_,
    int     BARLEY_,
    int     BLUEBERRIES_,
    int     BREAD_,
    int     BROCCOLI_,
    int     BURGERS_,
    int     CAKE_,
    int     CHEESE_,
    int     CHICKEN_
);
/*
    ?Ò¸??? ???æ¼±??
*/
void    DELETE_FOOD(FOOD* food_delete_ptr);

/*
    PROGRAMMING À¯?? new ?????? ???? ????
*/
PROGRAMMING* new_programming(
    int     DATE_,
    int     CLANG_,
    int     PTYHON_,
    int     R_,
    int     JAVA_,
    int     SECURITY_,
    int     NODEJ_,
    int     CPP_,
    int     ASSEMBLY_
);
/*
    ?Ò¸??? ???æ¼±??
*/
void    DELETE_PROGRAMMING(PROGRAMMING* programming_delete_ptr);

/*
    MAJOR À¯?? new ?????? ???? ????
*/
MAJOR* new_major(
    int     KoreanLanguageAndLiterature_,    //???î±¹???Ð°?
    int     Philosophy_,                     //Ã¶?Ð°?
    int     Archeology_,                     //?????Ð°?
    int     LibraryAndInformationScience_,   //????Á¤???Ð°?
    int     CommerceAndTrade_,               //?????Ð°?
    int     Administration_,                 //??Á¤?Ð°?
    int     PoliticalScienceAndDiplomacy_,   //Á¤Ä¡?Ü±??Ð°?
    int     MechanicalEngineering_,          //????????
    int     ElectronicEngineering_,          //???Ú°???
    int     Architecure_,                    //??????
    int     Physics_,                        //??????
    int     Chemistry_,                      //È­??
    int     Biology_                         //??????
);
/*
    ?Ò¸??? ???æ¼±??
*/
void    DELETE_MAJOR(MAJOR* major_delete_ptr);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    MEMBER À¯??Å¬???? ???? ?Ô¼?
*/

typedef struct MEMBER {
    struct MEMBER* this;
    struct MEMBER_NAME* member_name;
    struct SCHOOL_NAME* school_name;

    struct MEMBER_NAME {
        struct MEMBER* this;
        int     select_name_number_;
        MEMBER_NAME* member_name;

        void    (*SET_NAME)(struct MEMBER_NAME* select_name, int select_name_number);
        int     (*GET_NAME)(const struct MEMBER_NAME* select_name);

        void    (*NAMEINIT)(MEMBER* name_init);
    } MEMBER_NAME;

    struct SCHOOL_NAME {
        struct MEMBER* this;
        int     select_school_number_;
        SCHOOL_NAME* school_name;

        void    (*SET_SCHOOL_NAME)(struct SCHOOL_NAME* select_school_name, int select_school_number);
        int     (*GET_SCHOOL_NAME)(const struct SCHOOL_NAME* select_school_name);

        void    (*SCHOOLINIT)(MEMBER* school_init);
    } SCHOOL_NAME;

    int     HAKBUN_;
    int     AGE_;
    int     INIT_DATE_;
    int     OUT_DATE_;

    void    (*PRINT_DATA)(const MEMBER* this, const MEMBER_NAME* select_name, const SCHOOL_NAME* select_school_name);
    void    (*MEMBER_SET)
        (
            struct MEMBER* this,
            struct MEMBER_NAME* select_name,
            struct SCHOOL_NAME* select_school_name,
            const   int     HAKBUN,
            const   int     AGE,
            const   int     INIT_DATE,
            const   int     OUT_DATE
            );
    int  (*MEMBER_GET)(const struct MEMBER* this, MEMBER_NAME* select_name, SCHOOL_NAME* select_school_name);
    /*
        void    NAME_INIT(struct MEMBER* this)
        void    SCHOOL_INIT(struct SCHOOL_NAME* this)
    */
} MEMBER;

/*
    À¯?? ???? Å¬???? new ?????? ???? ????
*/
MEMBER_NAME* new_name(
    int     select_name_number
)
{
    MEMBER_NAME* temp = (MEMBER_NAME*)malloc(sizeof(MEMBER_NAME));

    temp->select_name_number_ = select_name_number;

    // ?Ô¼? ??????
    temp->select_name_number_ = temp;
    temp->NAMEINIT = NAME_INIT;
    // temp -> SET_NAME = NAME_SET_;
    // temp -> GET_NAME = NAME_GET_;

    return temp;
}

/*
    À¯?? ???? Å¬???? new ?????? ???? ????
*/
SCHOOL_NAME* new_school(
    int     select_school_number
)
{
    SCHOOL_NAME* temp = (SCHOOL_NAME*)malloc(sizeof(SCHOOL_NAME));

    temp->select_school_number_ = select_school_number;

    // ?Ô¼? ??????
    temp->select_school_number_ = temp;
    temp->SCHOOLINIT = SCHOOL_INIT;
    // temp -> SET_SCHOOL_NAME = SET_SCHOOL_NAME_;
    // temp -> GET_SCHOOL_NAME = GET_SCHOOL_NAME_;

    return temp;
}

void    MEMBER_SET_(
    MEMBER* this,
    MEMBER_NAME* select_name,
    SCHOOL_NAME* select_school_name,
    const   int     HAKBUN,
    const   int     AGE,
    const   int     INIT_DATE,
    const   int     OUT_DATE
)
{
    select_name->select_name_number_;
    select_school_name->select_school_number_;
    this->HAKBUN_;
    this->AGE_;
    this->INIT_DATE_;
    this->OUT_DATE_;
}

int     MEMBER_GET_(const MEMBER* this, MEMBER_NAME* select_name, SCHOOL_NAME* select_school_name)
{
    return
        select_name->select_name_number_,
        select_school_name->select_school_number_,
        this->HAKBUN_,
        this->AGE_,
        this->INIT_DATE_,
        this->OUT_DATE_;
}

void    NAME_INIT(struct MEMBER* this)
{
    this->MEMBER_NAME.SET_NAME = NAME_SET_;
    this->MEMBER_NAME.GET_NAME = NAME_GET_;
}
void    SCHOOL_INIT(struct SCHOOL_NAME* this)
{
    this->SET_SCHOOL_NAME = SET_SCHOOL_NAME_;
    this->GET_SCHOOL_NAME = GET_SCHOOL_NAME_;
}

MEMBER* new_member(int HAKBUN, MEMBER_NAME* member_name, SCHOOL_NAME* school_name, int AGE, int INIT_DATE, int OUT_DATE)
{
    MEMBER* temp = (MEMBER*)malloc(sizeof(MEMBER));


    temp->HAKBUN_ = HAKBUN;
    // temp->MEMBER_NAME.SET_NAME = NAME_SET_;
    // temp->MEMBER_NAME.GET_NAME = NAME_GET_;
    // temp->SCHOOL_NAME.SET_SCHOOL_NAME = SET_SCHOOL_NAME_;
    // temp->SCHOOL_NAME.GET_SCHOOL_NAME = GET_SCHOOL_NAME_;
    temp->MEMBER_NAME.NAMEINIT = NAME_INIT;
    temp->SCHOOL_NAME.SCHOOLINIT = SCHOOL_INIT;
    temp->AGE_ = AGE;
    temp->INIT_DATE_ = INIT_DATE;
    temp->OUT_DATE_ = OUT_DATE;

    // ?Ô¼? ??????
    temp -> this = temp;
    temp->PRINT_DATA = PRINT_DATA_;
    // temp->MEMBER_SET = MEMBER_SET_;
    // temp->MEMBER_GET = MEMBER_GET_;
    temp->MEMBER_NAME.GET_NAME = NAME_GET_;
    temp->SCHOOL_NAME.GET_SCHOOL_NAME = GET_SCHOOL_NAME_;

    return temp;
}

void    DELETE_MEMBER(MEMBER* member_delete_ptr)
{
    free(member_delete_ptr);
}

///////////////////////////////////////////////////////////////////////

/*
    FOOD À¯??Å¬???? ???? ?Ô¼?
*/

typedef struct FOOD {
    MEMBER Member;
    struct FOOD* this;

    int     BANANAS_;
    int     BARBECUE_;
    int     BARLEY_;
    int     BLUEBERRIES_;
    int     BREAD_;
    int     BROCCOLI_;
    int     BURGERS_;
    int     CAKE_;
    int     CHEESE_;
    int     CHICKEN_;

    void    (*FOOD_SET)
        (
            struct  FOOD* this,
            const   int     BANANAS,
            const   int     BARBECUE,
            const   int     BARLEY,
            const   int     BLUEBERRIES,
            const   int     BREAD,
            const   int     BROCCOLI,
            const   int     BURGERS,
            const   int     CAKE,
            const   int     CHEESE,
            const   int     CHICKEN
            );
    int     (*FOOD_GET)(const struct FOOD* this);
    void    (*FOOD_PRINT_DATA)(const FOOD* this);
} FOOD;

void FOOD_SET_(
    FOOD* this,
    const int BANANAS,
    const int BARBECUE,
    const int BARLEY,
    const int BLUEBERRIES,
    const int BREAD,
    const int BROCCOLI,
    const int BURGERS,
    const int CAKE,
    const int CHEESE,
    const int CHICKEN
)
{
    this->BANANAS_ = BANANAS;
    this->BARBECUE_ = BARBECUE;
    this->BARLEY_ = BARLEY;
    this->BLUEBERRIES_ = BLUEBERRIES;
    this->BREAD_ = BREAD;
    this->BROCCOLI_ = BROCCOLI;
    this->BURGERS_ = BURGERS;
    this->CAKE_ = CAKE;
    this->CHEESE_ = CHEESE;
    this->CHICKEN_ = CHICKEN;
}

int FOOD_GET_(const FOOD* this)
{
    return
        this->BANANAS_,
        this->BARBECUE_,
        this->BARLEY_,
        this->BLUEBERRIES_,
        this->BREAD_,
        this->BROCCOLI_;
    this->BURGERS_,
        this->CAKE_,
        this->CHEESE_,
        this->CHICKEN_;
}

void    DELETE_FOOD(FOOD* food_delete_ptr)
{
    free(food_delete_ptr);
}

FOOD* new_food(
    int     BANANAS,
    int     BARBECUE,
    int     BARLEY,
    int     BLUEBERRIES,
    int     BREAD,
    int     BROCCOLI,
    int     BURGERS,
    int     CAKE,
    int     CHEESE,
    int     CHICKEN
)
{
    FOOD* temp = (FOOD*)malloc(sizeof(FOOD));

    temp->BANANAS_ = BANANAS;
    temp->BARBECUE_ = BARBECUE;
    temp->BARLEY_ = BARLEY;
    temp->BLUEBERRIES_ = BLUEBERRIES;
    temp->BREAD_ = BREAD;
    temp->BROCCOLI_ = BROCCOLI;
    temp->BURGERS_ = BURGERS;
    temp->CAKE_ = CAKE;
    temp->CHEESE_ = CHEESE;
    temp->CHICKEN_ = CHICKEN;

    // ?Ô¼? ??????
    temp -> this = temp;
    temp->FOOD_PRINT_DATA = FOOD_PRINT_DATA_;
    temp->FOOD_SET = FOOD_SET_;
    temp->FOOD_GET = FOOD_GET_;

    return temp;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/*
    PROGRAMMING À¯??Å¬???? ???? ?Ô¼?
*/

typedef struct PROGRAMMING {
    MEMBER Member;
    struct PROGRAMMING* this;

    int     DATE_;
    int     CLANG_;
    int     PTYHON_;
    int     R_;
    int     JAVA_;
    int     SECURITY_;
    int     NODEJ_;
    int     CPP_;
    int     ASSEMBLY_;

    void    (*PROGRAMMING_SET)
        (
            struct  PROGRAMMING* this,
            const   int             DATE,
            const   int             CLANG,
            const   int             PTYHON,
            const   int             R,
            const   int              JAVA,
            const   int             SECURITY,
            const   int             NODEJ,
            const   int             CPP,
            const   int             ASSEMBLY
            );
    int     (*PROGRAMMING_GET)(const struct PROGRAMMING* this);
    void    (*PROGRAMMING_PRINT_DATA)(const PROGRAMMING* this);
} PROGRAMMING;

PROGRAMMING* new_programming(
    int DATE,
    int CLANG,
    int PTYHON,
    int R,
    int JAVA,
    int SECURITY,
    int NODEJ,
    int CPP,
    int ASSEMBLY
)
{
    PROGRAMMING* temp = (PROGRAMMING*)malloc(sizeof(PROGRAMMING));

    temp->DATE_ = DATE;
    temp->CLANG_ = CLANG;
    temp->PTYHON_ = PTYHON;
    temp->R_ = R;
    temp->JAVA_ = JAVA;
    temp->SECURITY_ = SECURITY;
    temp->NODEJ_ = NODEJ;
    temp->CPP_ = CPP;
    temp->ASSEMBLY_ = ASSEMBLY;

    // ?Ô¼? ??????
    temp->this = temp;
    temp->PROGRAMMING_PRINT_DATA = PROGRAMMING_PRINT_DATA_;
    temp->PROGRAMMING_SET = PROGRAMMING_SET_;
    temp->PROGRAMMING_GET = PROGRAMMING_GET_;

    return temp;
}

void PROGRAMMING_SET_(
    PROGRAMMING* this,
    const int DATE,
    const int CLANG,
    const int PTYHON,
    const int R,
    const int JAVA,
    const int SECURITY,
    const int NODEJ,
    const int CPP,
    const int ASSEMBLY
)
{
    this->DATE_ = DATE;
    this->CLANG_ = CLANG;
    this->PTYHON_ = PTYHON;
    this->R_ = R;
    this->JAVA_ = JAVA;
    this->SECURITY_ = SECURITY;
    this->NODEJ_ = NODEJ;
    this->CPP_ = CPP;
    this->ASSEMBLY_ = ASSEMBLY;
}

int     PROGRAMMING_GET_(const PROGRAMMING* this)
{
    this->DATE_,
        this->CLANG_,
        this->PTYHON_,
        this->R_,
        this->JAVA_,
        this->SECURITY_,
        this->NODEJ_,
        this->CPP_,
        this->ASSEMBLY_;
}

void    DELETE_PROGRAMMING(PROGRAMMING* programming_delete_ptr)
{
    free(programming_delete_ptr);
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/*
    MAJOR À¯??Å¬???? ???? ?Ô¼?
*/

typedef struct MAJOR {
    MEMBER Member;
    struct PROGRAMMING* this;

    int     KoreanLanguageAndLiterature_;    //???î±¹???Ð°?
    int     Philosophy_;                     //Ã¶?Ð°?
    int     Archeology_;                     //?????Ð°?
    int     LibraryAndInformationScience_;   //????Á¤???Ð°?
    int     CommerceAndTrade_;               //?????Ð°?
    int     Administration_;                 //??Á¤?Ð°?
    int     PoliticalScienceAndDiplomacy_;   //Á¤Ä¡?Ü±??Ð°?
    int     MechanicalEngineering_;          //????????
    int     ElectronicEngineering_;          //???Ú°???
    int     Architecure_;                    //??????
    int     Physics_;                        //??????
    int     Chemistry_;                      //È­??
    int     Biology_;                        //??????
    void    (*MAJOR_SET)
        (
            struct MAJOR* this,
            const   int     KoreanLanguageAndLiterature,    //???î±¹???Ð°?
            const   int     Philosophy,                     //Ã¶?Ð°?
            const   int     Archeology,                     //?????Ð°?
            const   int     LibraryAndInformationScience,   //????Á¤???Ð°?
            const   int     CommerceAndTrade,               //?????Ð°?
            const   int     Administration,                 //??Á¤?Ð°?
            const   int     PoliticalScienceAndDiplomacy,   //Á¤Ä¡?Ü±??Ð°?
            const   int     MechanicalEngineering,          //????????
            const   int     ElectronicEngineering,          //???Ú°???
            const   int     Architecure,                    //??????
            const   int     Physics,                        //??????
            const   int     Chemistry,                      //È­??
            const   int     Biology                        //??????
            );
    int     (*MAJOR_GET)(const struct MAJOR* this);
    void    (*MAJOR_PRINT_DATA)(const MAJOR* this);
} MAJOR;

void MAJOR_SET_(
    MAJOR* this,
    const int KoreanLanguageAndLiterature,
    const int Philosophy,
    const int Archeology,
    const int LibraryAndInformationScience,
    const int CommerceAndTrade,
    const int Administration,
    const int PoliticalScienceAndDiplomacy,
    const int MechanicalEngineering,
    const int ElectronicEngineering,
    const int Architecure,
    const int Physics,
    const int Chemistry,
    const int Biology
)
{
    this->KoreanLanguageAndLiterature_ = KoreanLanguageAndLiterature;
    this->Philosophy_ = Philosophy;
    this->Archeology_ = Archeology;
    this->LibraryAndInformationScience_ = LibraryAndInformationScience;
    this->CommerceAndTrade_ = CommerceAndTrade;
    this->Administration_ = Administration;
    this->PoliticalScienceAndDiplomacy_ = PoliticalScienceAndDiplomacy;
    this->MechanicalEngineering_ = MechanicalEngineering;
    this->ElectronicEngineering_ = ElectronicEngineering;
    this->Architecure_ = Architecure;
    this->Physics_ = Physics;
    this->Chemistry_ = Chemistry;
    this->Biology_ = Biology;
}

int     MAJOR_GET_(const MAJOR* this)
{
    return
        this->KoreanLanguageAndLiterature_,
        this->Philosophy_,
        this->Archeology_,
        this->LibraryAndInformationScience_,
        this->CommerceAndTrade_,
        this->Administration_,
        this->PoliticalScienceAndDiplomacy_,
        this->MechanicalEngineering_,
        this->ElectronicEngineering_,
        this->Architecure_,
        this->Physics_,
        this->Chemistry_,
        this->Biology_;
}

MAJOR* new_major(
    int     KoreanLanguageAndLiterature,    //???î±¹???Ð°?
    int     Philosophy,                     //Ã¶?Ð°?
    int     Archeology,                     //?????Ð°?
    int     LibraryAndInformationScience,   //????Á¤???Ð°?
    int     CommerceAndTrade,               //?????Ð°?
    int     Administration,                 //??Á¤?Ð°?
    int     PoliticalScienceAndDiplomacy,   //Á¤Ä¡?Ü±??Ð°?
    int     MechanicalEngineering,          //????????
    int     ElectronicEngineering,          //???Ú°???
    int     Architecure,                    //??????
    int     Physics,                        //??????
    int     Chemistry,                      //È­??
    int     Biology                         //??????
)
{
    MAJOR* temp = (MAJOR*)malloc(sizeof(MAJOR));

    temp->KoreanLanguageAndLiterature_ = KoreanLanguageAndLiterature;
    temp->Philosophy_ = Philosophy;
    temp->Archeology_ = Archeology;
    temp->LibraryAndInformationScience_ = LibraryAndInformationScience;
    temp->CommerceAndTrade_ = CommerceAndTrade;
    temp->Administration_ = Administration;
    temp->PoliticalScienceAndDiplomacy_ = PoliticalScienceAndDiplomacy;
    temp->MechanicalEngineering_ = MechanicalEngineering;
    temp->ElectronicEngineering_ = ElectronicEngineering;
    temp->Architecure_ = Architecure;
    temp->Physics_ = Physics;
    temp->Chemistry_ = Chemistry;
    temp->Biology_ = Biology;

    // ?Ô¼? ?????? 
    temp -> this = temp;
    temp->MAJOR_PRINT_DATA = MAJOR_PRINT_DATA_;
    temp->MAJOR_SET = MAJOR_SET_;
    temp->MAJOR_GET = MAJOR_GET_;

    return temp;
}

void    DELETE_MAJOR(MAJOR* major_delete_ptr)
{
    free(major_delete_ptr);
}

//--------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------
void    PRINT_DATA_(const MEMBER* this)
{
    printf("?Ð»? ?Ð¹? : %d, ???? : %d, ???? ??Â¥ : %d, Á¹????Á¤??Â¥ : %d\n",
        this->HAKBUN_,
        this->AGE_, this->INIT_DATE_, this->OUT_DATE_);
}

void    PROGRAMMING_PRINT_DATA_(const PROGRAMMING* this)
{
    int result = this->CLANG_ + this->PTYHON_ + this->R_ + this->JAVA_ + this->SECURITY_ + this->NODEJ_ + this->CPP_ + this->ASSEMBLY_;
    printf("???Ð³âµµ : %d, C???? Á¡?? : %d, Python Á¡?? : %d, R Á¡?? :%d, JAVA Á¡?? :%d, ????Á¡?? : %d, node Á¡?? : %d, c++Á¡?? : %d, ???Àºí¸® Á¡?? %d, ???? ???? : %.2f\n\n",
        this->DATE_, this->CLANG_, this->PTYHON_, this->R_, this->JAVA_, this->SECURITY_, this->NODEJ_, this->CPP_, this->ASSEMBLY_, (float)result / 8);
}

void    FOOD_PRINT_DATA_(const FOOD* this)
{
    int result = this->BANANAS_ + this->BARBECUE_ + this->BARLEY_ + this->BLUEBERRIES_ + this->BREAD_ + this->BROCCOLI_ + this->BURGERS_ + this->CAKE_ + this->CHEESE_ + this->CHICKEN_;
    printf("BANANAS : %d, BARBECUE : %d, BARLEY : %d, BLUEBERRIES : %d, BREAD : %d, BROCCOLI : %d, BURGERS : %d, CAKE : %d, CHEESE : %d, CHICKEN : %d, SUM : %d\n\n",
        this->BANANAS_, this->BARBECUE_, this->BARLEY_, this->BLUEBERRIES_, this->BREAD_, this->BROCCOLI_, this->BURGERS_, this->CAKE_, this->CHEESE_, this->CHICKEN_, result);
}

void    MAJOR_PRINT_DATA_(const MAJOR* this)
{
    int result = this->KoreanLanguageAndLiterature_ + this->Philosophy_ + this->Archeology_ + this->LibraryAndInformationScience_ + this->CommerceAndTrade_ +
        this->Administration_ + this->PoliticalScienceAndDiplomacy_ + this->MechanicalEngineering_ +
        this->ElectronicEngineering_ + this->Architecure_ + this->Physics_ + this->Chemistry_ + this->Biology_;

    printf("KoreanLanguageAndLiterature : %d, Philosophy : %d, Archeology : %d, LibraryAndInformationScience : %d, CommerceAndTrade : %d, Administration : %d, PoliticalScienceAndDiplomacy : %d, MechanicalEngineering : %d,  ElectronicEngineering : %d, Architecure : %d ,Physics : %d, Chemistry : %d , Biology : %d, result =  %d \n\n",
        this->KoreanLanguageAndLiterature_, this->Philosophy_, this->Archeology_, this->LibraryAndInformationScience_, this->CommerceAndTrade_,
        this->Administration_, this->PoliticalScienceAndDiplomacy_, this->MechanicalEngineering_,
        this->ElectronicEngineering_, this->Architecure_, this->Physics_, this->Chemistry_, this->Biology_, result);

}

void 	SET_SCHOOL_NAME_(struct SCHOOL_NAME* select_school_name, int select_school_number)
{
    select_school_name->select_school_number_ = select_school_number;
}

int 	GET_SCHOOL_NAME_(const struct SCHOOL_NAME* select_school_name)
{
    void (*SCHOOL[FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE])() = {
    &HyunA, &Jiwoo, &Juhyun, &SungGyun, &Urim, &SeulGi, &Seven, &Tech, &Soljin
    };
    (SCHOOL[select_school_name->select_school_number_]()
        );
}


void     NAME_SET_(struct MEMBER_NAME* member_ptr, int select_name_number)
{
    member_ptr->select_name_number_ = select_name_number;
}

int     NAME_GET_(const struct MEMBER_NAME* select_name)
{
    void (*NAME[FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE])() = {
        &HyunA_S, &Jiwoo_S, &Juhyun_S, &SungGyun_S, &Urim_S, &SeulGi_S, &Seven_S, &Tech_S, &Soljin_S
    };
    (NAME[select_name->select_name_number_]()
        );
}

//--------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------

//const char NAME[] = "????_????_????_?Â±?_À¯??_????_????_??Å©_????";
void HyunA() { for (int i = 0; i < 4; i += 1) { printf("%c", NAME[i]); } }
void Jiwoo() { for (int i = 5; i < 9; i += 1) { printf("%c", NAME[i]); } }
void Juhyun() { for (int i = 10; i < 14; i += 1) { printf("%c", NAME[i]); } }
void SungGyun() { for (int i = 15; i < 19; i += 1) { printf("%c", NAME[i]); } }
void Urim() { for (int i = 20; i < 24; i += 1) { printf("%c", NAME[i]); } }
void SeulGi() { for (int i = 25; i < 29; i += 1) { printf("%c", NAME[i]); } }
void Seven() { for (int i = 30; i < 34; i += 1) { printf("%c", NAME[i]); } }
void Tech() { for (int i = 35; i < 39; i += 1) { printf("%c", NAME[i]); } }
void Soljin() { for (int i = 40; i < 45; i += 1) { printf("%c", NAME[i]); } }

// SCHOOL NAME
/*
    ?Ì¸??? ?Ð±??? ?????Ï°? ???Àµ??? ??Á¤??
*/
void HyunA_S() { HyunA();  printf("\t?Ñ±?????Á¾???Ð±?\n"); }
void Jiwoo_S() { Jiwoo(); printf("\tÄ«?Ì½?Æ®\n"); }
void Juhyun_S() { Juhyun(); printf("\t???????Ð°????Ð±?\n"); }
void SungGyun_S() { SungGyun(); printf("\t???????Ð±?\n"); }
void Urim_S() { Urim(); printf("\t???Å¿??Ú´??Ð±?\n"); }
void SeulGi_S() { SeulGi(); printf("\t???ç·¿???Ð±?\n"); }
void Seven_S() { Seven(); printf("\t???????Ð±?\n"); }
void Tech_S() { Tech(); printf("\t??????Å©\n"); }
void Soljin_S() { Soljin(); printf("\t???????Ð±?\n"); }

int main()
{
    // ???? ?×½?Æ®?? ???? È®?? ?Þ¼??? ??????
    puts("?? ?Þ¼????? ???Ì¸? ???? ??????..");

    // ?Î¸? À¯?? Å¬???? MEMBER?? ???Óµ? Å¬???? ???? ????
    MEMBER_NAME nameOuterObj;
    SCHOOL_NAME schoolOuterObj;

    // À¯?? ?Ú½? Å¬???? ?Ô¼? ?????? ?Î¼? ??È¯ ?? ????
    //nameOuterObj.select_name_number_ = 2;
    printf("??È¯?? ?Ô¼????????? ?Î¼???À» ?Ô·??Ï½Ã¿? : ");
    scanf("%d", &nameOuterObj.select_name_number_);

    // ?Î¸? À¯?? Å¬???? MEMBER?? ???Óµ? ?Ú½? Å¬???? new ?????? È£??
    MEMBER_NAME* nameObj = new_name(&nameOuterObj.select_name_number_);
    SCHOOL_NAME* schoolObj = new_school(&schoolOuterObj.select_school_number_);

    // MEMBER ?Î¸? Å¬???? ?????? È£?? , ?Ú½? Å¬???? nameObj, schoolObj?? ?Ýµ??? ?????Ø¾? ?Î¸? Å¬???? ?Þ¼??å°¡ È£???? ??.
    MEMBER* memOuterObj = new_member(3081, nameObj, schoolObj, 30, 20140201, 20190301);

    // ?Ú½? Å¬?????? ?????? È£??, ?Ì¸??? ?Ð±? ?Ì¸??? ???Ã¿? ?????? ?Çµ??? ?????Ú¸? ???æ¿¡?? ?????Øµ?.
    NAME_INIT(nameObj);
    NAME_SET_(nameObj, nameOuterObj.select_name_number_);
    NAME_GET_(nameObj);

    // ???? À¯????À¸?? ????(??????) -- ???Ï´? ???? ??À» ?Ö¾??Ö¸? ?È´?. ?Ç´?, ?Ý´??? scanf?Ô¼??? ?Ô·Â¹Þ°? ?Ï°? ??Á¶Ã¼?? ?Ï³? ?? ?????Ù´??? ?Ï¸?
    // È¿????À¸?? ??Ã¼??À» ?Ú·á±¸Á¶?? ?Ù·? ?? ??À½.
    (*memOuterObj).HAKBUN_ = 2187;

    /*
        MEMBER ???? ?Þ¼??? ????, À§???? ????À¸?? ?????Øµ? ?Ú½? Å¬?????? ???î¼­ ??Á®?Í¾??Ñ´?.
    */
    (*memOuterObj).PRINT_DATA(memOuterObj, nameObj, schoolObj);

    // ???? ???? ?? -- new?????Ú¿? ????À» ?Ø¼? ????À» ?? ?? ??????, ?Æ·??? ???? ????Ã³?? ??Á¦???? ???? ???? ?????Ïµ??? ????.
    /*
        (*memOuterObj).AGE_ = 30;
        (*memOuterObj).INIT_DATE_ = 20140201;
        (*memOuterObj).OUT_DATE_ = 20190301;
    */


    /* ???? ???? */
    // PROGRAMMING ?Þ¼??å¿¡ ???? ?????? È£??
    PROGRAMMING* programOuterObj = new_programming(20200221, 20, 20, 20, 20, 20, 20, 20, 20);
    (*programOuterObj).PROGRAMMING_PRINT_DATA(programOuterObj);
    // FOOD ?Þ¼??å¿¡ ???? ?????? È£??
    FOOD* foodOuterObj = new_food(30, 30, 30, 30, 30, 30, 30, 30, 30, 30);
    (*foodOuterObj).FOOD_PRINT_DATA(foodOuterObj);
    // MAJOR ?Þ¼??å¿¡ ???? ?????? È£??
    MAJOR* majorOuterObj = new_major(40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40);
    (*majorOuterObj).MAJOR_PRINT_DATA(majorOuterObj);

    exit(0);
}
