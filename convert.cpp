/*
    Roman to  Arabic program
    Convert Roman to HinduArabic Numeral
    Submitted to  https://code.golf/roman-to-arabic#cpp

    Created by: amd
*/


// ---------------------------------
// Preprocessor Declaration
#define STR_SIZE 50

#define P_OK 0
#define P_ERR_VAL -10
#define P_ERR_NUM -20

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ---------------------------------
// Global Varibles

char num_roman[STR_SIZE];
int num_arabic;

int str_loc;

// *********************************
// convert_thousnad method
int convert_thousnad()
{
    // --------------------------
    // variable Declaration
    int res;

    int i;

    // --------------------------
    // Actual Function

    // Scan for 1000 to 3000 values
    if(num_roman[str_loc]=='M' && num_roman[str_loc] != '\0')
    {
        // 1000 to 3000
        i=0;
        while(num_roman[str_loc]=='M' && i<3 && num_roman[str_loc] != '\0')
        {
            num_arabic+=1000;
            str_loc++;
        };

    };

    res=P_OK;

    return res;

};


// *********************************
// convert_hundres method
int convert_hundres()
{
    // ----------------------------
    // variable declaration
    int res;

    int i;

    // ----------------------------
    // Actual Function
    
    // for 500 to 800
    if(num_roman[str_loc]=='D')
    {
        num_arabic+=500;
        str_loc++;
        i=0;
        while(num_roman[str_loc]=='C' && i<3 && num_roman[str_loc] != '\0')
        {
            num_arabic+=100;
            str_loc++;
            i++;
        };

    }else
    if(num_roman[str_loc]=='C')
    {

        // for 100-300
        if(num_roman[str_loc]=='C' && num_roman[str_loc+1] != 'D' && 
            num_roman[str_loc+1] != 'M' && num_roman[str_loc]!='\0')
        {
            i=0;
            while(num_roman[str_loc]=='C' && i<3 && num_roman[str_loc] != '\0')
            {
                num_arabic+=100;
                str_loc++;
                i++;
            };
    
        };
        
        
        // 900
        if(num_roman[str_loc+1]=='M' && num_roman[str_loc]!='\0')
        {
            num_arabic+=900;
            str_loc++;
            str_loc++;
        };

        // 400
        if(num_roman[str_loc+1]=='D' && num_roman[str_loc]!='\0')
        {
            num_arabic+=400;
            str_loc++;
            str_loc++;
        };

    };
    
    res=P_OK;

    return res;

};


// *********************************
// convert_tens method
int convert_tens()
{
    // ---------------------------
    // Variable  declaration
    int res;

    int i;


    // ----------------------------
    // Actual funciton

    // for 50 to 80
    if(num_roman[str_loc]=='L' && num_roman[str_loc] != '\0')
    {
        num_arabic+=50;
        str_loc++;
        i=0;
        while(num_roman[str_loc]=='X' && i<3 && num_roman[str_loc] != '\0')
        {
            num_arabic+=10;
            str_loc++;
            i++;
        };
   
    };

    // for 90, 40 and 10-30
    if(num_roman[str_loc]=='X' && num_roman[str_loc]!='\0')
    {
        // for 10 to 30
        if(num_roman[str_loc]=='X' && num_roman[str_loc+1] != 'L' && 
            num_roman[str_loc+1] != 'C' && num_roman[str_loc]!='\0')
            {
        
                // 10 to 30
                i=0;
                while(num_roman[str_loc]=='X' && i<3 && num_roman[str_loc] != '\0')
                {
                    num_arabic+=10;
                    str_loc++;
                    i++;
                };
            };

        // 90
        if(num_roman[str_loc+1]=='C' && num_roman[str_loc]!='\0')
        {
            num_arabic+=90;
            str_loc++;
            str_loc++;
        };

        // 40        
        if(num_roman[str_loc+1]=='L' && num_roman[str_loc]!='\0')
        {
            num_arabic+=40;
            str_loc++;
            str_loc++;
        };

    };

 
    res=P_OK;

    return res;

};

// *********************************
// convert_ones method
int convert_ones()
{
    
    // -----------------------------
    // Variable  Declaration
    int res;

    int i;


    // -----------------------------
    // Actual Funciton
    
    // for 5 to 8
    if(num_roman[str_loc]=='V' && num_roman[str_loc] != '\0')
    {
        num_arabic+=5;
        str_loc++;
        i=0;
        while(num_roman[str_loc]=='I' && i<3 && num_roman[str_loc] != '\0')
        {
            num_arabic+=1;
            str_loc++;
            i++;
        };

    };

    // for 9, 4 and 1-3
    if(num_roman[str_loc]=='I' && num_roman[str_loc]!='\0')
    {

        // for 1 to 3
        if(num_roman[str_loc]=='I' && num_roman[str_loc+1] != 'X' && 
            num_roman[str_loc+1] != 'V' && num_roman[str_loc]!='\0')
        {
            i=0;
            while(num_roman[str_loc]=='I' && i<3 && num_roman[str_loc] != '\0')
            {
                num_arabic+=1;
                str_loc++;
                i++;
            };
    
        };

        // 90
        if(num_roman[str_loc+1]=='X' && num_roman[str_loc]!='\0')
        {
            num_arabic+=9;
            str_loc++;
            str_loc++;
        };

        // 40        
        if(num_roman[str_loc+1]=='V' && num_roman[str_loc]!='\0')
        {
            num_arabic+=4;
            str_loc++;
            str_loc++;
        };

    };

    res=P_OK;

    return res;

};

// *********************************
// convert method
int convert()
{
    // ----------------------------
    // Variable Declaration
    int res;

    // ---------------------------
    // Actual Function

    str_loc=0;
    num_arabic=0;

    convert_thousnad();
    convert_hundres();
    convert_tens();
    convert_ones();

    res=P_OK;
    
    return res;

}

// *********************************
// ---------------------------------
// Progran  Entry Point
// ---------------------------------
// *********************************
int main(int argc, char *argv[])
{
    // ----------------------------
    // Variable  Declaration
    int x;

    char str01[STR_SIZE];

    
    // ----------------------------
    // Actual function

    // initialized var for loping test
    x=1;

    // check the ARG present
    if(argc>1)
    {
        // scanning all the varibles to  convert
        while(x<argc)
        {
            // call the convert function then display
            snprintf(num_roman, sizeof(num_roman), "%s", argv[x]);
            if( convert() == P_OK )
            {
                // Display if Sucessfull
                printf("%i\n", num_arabic);
            }else
            {
                // Print if Error
                printf("ERROR: Improper Roman Numeral Input...\n");
            };

            x++;

        };


    }else
    {
        // Print if no ARG
        printf("ERROR: No ARG input... Input Roman Numeral to Cenvert as ARG...\n");
    };

    return 0;

};
