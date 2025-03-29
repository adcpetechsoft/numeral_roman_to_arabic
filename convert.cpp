#define STR_SIZE 50

#define P_OK 0
#define P_ERR_VAL -10
#define P_ERR_NUM -20

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char num_roman[STR_SIZE];
int num_arabic;

int str_loc;

int convert_thousnad()
{
    int res;

    int i;

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

int convert_hundres()
{
    int res;

    int i;

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


// tens
int convert_tens()
{
    int res;

    int i;

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

// ones
int convert_ones()
{
    int res;

    int i;

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


int convert()
{
    int res;

    str_loc=0;
    num_arabic=0;

    convert_thousnad();
    convert_hundres();
    convert_tens();
    convert_ones();

    res=P_OK;
    
    return res;

}

int main(int argc, char *argv[])
{
    int x;

    char str01[STR_SIZE];

    x=1;

    if(argc>1)
    {
        while(x<argc)
        {
            snprintf(num_roman, sizeof(num_roman), "%s", argv[x]);
            if( convert() == P_OK )
            {
                printf("%i\n", num_arabic);
            }else
            {
                printf("ERROR: Improper Roman Numeral Input...\n");
            };

            x++;

        };


    }else
    {
        printf("ERROR: No ARG input... Input Roman Numeral to Cenvert as ARG...\n");
    };

    return 0;

};


