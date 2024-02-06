#include "s21_string.h"
#include <stdio.h>
#include <math.h>
char* scanf_write_string(flagscanf* Flags, va_list arg, const char** source){

    while(**source==' '){
        (*source)++;
    }
    char* variable=va_arg(arg, char*);
    char buffer[300]="11";
    int wcount=0;//счетчик сколько раз мы записали, чтобы отмотать
    while(**source!=' '&&**source!='\0'&&width_check(*Flags)){ //пишем из source в буфер, а почему нельзя сразу писать в variable?
        variable[wcount]=**source;
        wcount++;
        (*source)++;
        if(Flags->width!=-1)Flags->width--;


    }

    variable[wcount]='\0';
    // while(wcount>=0){
    // variable[wcount]=buffer[wcount];//segfault
    //     wcount--;

    // }
   
    
        printf("\nBUFFER=%s\n", buffer);
        printf("VARIABLE=%s\n", variable);

    
    
return variable;

}

 int* scanf_write_decimal_octal_hex(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    //int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        if(**source!='\0'&&**source!=' '&&(is_octal ? **source<'8':1)){ //вообще ведь нельзя вставить if в while условие? только через ?
            if(**source>=0&&**source<=57&&is_int_f(**source)){
                if(**source=='0'&&*(*source+1)=='x'){ //priority of * highter than + but not highter than ++ seems like
                is_hex=1;(*source)=(*source)+2;}
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             while(**source!=' '&&**source!='\0'&&(is_octal ? **source<'8':1)&&(is_hex ? hex_check(source):1)&&(is_int ? is_int_f(**source):1)&&width_check(*Flags)){ //если не поставить последнее условие в скобки то оно считает все до ? условием, и оно никогда не выполняется, следовательно всегда 1
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                //count_reverse++;
                if(Flags->width!=-1)Flags->width--;
                //if(Flags->width!=-1)Flags->width--;

             }
            *pbuffer='\0';
             
            }
        }
//  while(count_reverse>0){ //отматываем source назад
// (*source)--;
// count_reverse--;
// pbuffer--;
// }
    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);
//long long result;
if(!Flags->failed){
    if(is_hex){
        // char* endptr;
        
        *result = hex_to_dex(buffer, 16, Flags, minus, source);
        // *variable_adress=result;
       
        //*variable_adress=hex_to_dex(buffer, 16, Flags, minus);
    }
    if(is_octal){
       *result=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *result=minus ? -1.0*buffer_integer:1*buffer_integer;
    }
}
    //  if(Flags->ll){ *(va_arg(arg, long long int *)) = (long long int)result;}
    //     else if(Flags->l){*(va_arg(arg, long int *)) = (long int)result;}
    //     else if(Flags->h){*(va_arg(arg, short int *))= (short int)result;}
    //     else{*(va_arg(arg, int*))=(int)result;}
       

}

int* scanf_write_int(flagscanf* Flags, va_list arg, const char** source, long double* result ){
    Flags->failed=1;
   // int* i=va_arg(arg, int*);// какое будет поведение у  va_arg  если тип аргумента не соответствует, например мы указываем int* а там лежит  char*
   // printf("VALUE OF INT I FROM MAIN=%d\n", *i);
    while(**source==' '||**source=='0')(*source)++;
    int i_i;
    char buffer[1000];
    int count=0;
    char* pbuffer=buffer;
    int is_int=0;//вырастет только если была запись в int
    if(**source=='\0'||**source==' '||(**source>=0&&**source<=57&&**source!=32)){ //это нужно чтобы не двигало курсор если мы пытаемся прочитать строку как d
    while(**source!='\0'&&**source!=' '){
        if(**source>=0&&**source<=57&&**source!=32){
            is_int=1; Flags->failed=0;
            while(**source!=' '&&**source!='\0'&&Flags->width>0){
                *pbuffer=**source;
                pbuffer++;
                (*source)++;
               count++;
               Flags->width--;
            }
            //if(Flags->width>0)buffer[Flags->width]='\0';
            
        i_i=atoi(buffer); //buffer почему-то остается в памяти, поэтому заводим счетчик count и зануляем buffer после atoi
        while(count>0){
            buffer[count]='\0';
            count--;
        }
        printf("WRITTEN INT=%d\n", i_i);
        
        break;}
        
       (*source)++;
        
    }
    }

    if(is_int)*result=i_i;
    
    //printf("INT WRITTEN TO MAIN VAR=%d\n", *i);

    
    //x=itoa(va_arg(arg, int), x, 10);
    
    
//return i;

}

void sscanf_write_o(va_list arg, const char** source, flagscanf* Flags, long double* result){
     Flags->failed=1;
    int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        while(**source!='\0'&&**source!=' '&&is_int_f(**source)){
            if(**source>=0&&**source<=57&&is_int_f(**source)){
               
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             
             while(**source!=' '&&**source!='\0'&&is_int_f(**source)){
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                count_reverse++;
                //count++;

             }
            *pbuffer='\0';
//тут была сега если вставить отмотку сюда, то идет бесконечный цикл и pbuffer растет вплоть до segfault
             
            }
      
        }
              while(count_reverse>0){ //отматываем source назад
(*source)--;
count_reverse--;
pbuffer--;
}

    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);

    if(is_hex){
        // char* endptr;
        
        // long int result = strtol(buffer, &endptr, 16);
        // *variable_adress=result;
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_octal){
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    

}

void sscanf_write_e(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    float* variable_address=va_arg(arg, float*);
    float buffer_float;
    
    while(**source==' ')(*source)++;
    char buffer[10000];
    char* pbuffer=buffer;
    number_type type={0};
    // int minus=0;
    if(**source>=0&&**source<=57&&**source!=32){
        Flags->failed=0;
        // if(**source=='-')minus=1;
        while(**source!='\0'&&**source!=' '){
            if(**source=='0'&&*(*source+1)=='x'){
                type.is_hex=1; (*source)=(*source)+2;}//skip 0x to number
            
            if(**source=='0'&&is_int_f(*(*source)+1)){
                type.is_octal=1;(*source)++;
            }
            for(int i=1;*(*source+i)!=32;i++){ //тут если вместо 32 поставить ' ' почему то выкидывает из цикла на одну итерацию позже
                if(*(*source+i)=='e'||*(*source+i)=='E'){
                type.is_scientific=1;printf("is scientific\n");
                
                }
            }
            if(!type.is_hex&&!type.is_octal&&!type.is_scientific)type.is_int=1;
            while(**source!=32){
                *pbuffer=**source;
                (*source)++;
                pbuffer++;
            }
            *pbuffer='\0';
    }
        }
        int integer_from_string=atoi(buffer);
    if(type.is_scientific)
    *variable_address=scientific_to_float(buffer); 
    else{
    *variable_address=a_to_float(buffer);}
    if(Flags->failed==1){
        if((s21_strncmp(*source, "inf", 3)==0) ||
        (s21_strncmp(*source, "INF", 3)==0) ||
        (s21_strncmp(*source, "Inf", 3)==0) ||
        (s21_strncmp(*source, "inF", 3)==0) ||
        (s21_strncmp(*source, "InF", 3)==0) ||
        (s21_strncmp(*source, "iNF", 3)==0))
        {
            *variable_address=INFINITY;
            Flags->failed=0;
            *source += 3;
        }
    if((s21_strncmp(*source, "nan", 3)==0) ||
        (s21_strncmp(*source, "NAN", 3)==0) ||
        (s21_strncmp(*source, "NaN", 3)==0) ||
        (s21_strncmp(*source, "Nan", 3)==0) ||
        (s21_strncmp(*source, "naN", 3)==0) ||
        (s21_strncmp(*source, "nAN", 3)==0) )
        {
            *variable_address=NAN;
            Flags->failed=0;
            *source += 3;
        }    

    } 
    
            
    }

void set_params(flagscanf *Flags, const char **format) {
  width_function(format,  &(Flags->width));
  if (Flags->width == 0) {
    Flags->width = -1;
    Flags->failed = 0;
  }

  
}

void width_function(const char **format, int *width) {
   while (**format <= 57 && **format >= 48) {
    *width = *width * 10 + (**format - '0');
    (*format)++;

    
  }

  }



int is_int_f(char c){
    int x=0;
    if(c>=0&&c<=57&&c!=32)
    x=1;
    return x;
}

int dec_convert(int input, int base){
    int power=0;
    int dec=0;

    while(input>0){
    dec=dec+(input%10)*s21_pow(base, power);
    input=input/10;
    power++;}
    return dec;
}



    float scientific_to_float(char* string){
    char pre_dot[1000000];//тут был stack smashing если маленькие размеры массивов
    float pre_dot_float;
    char post_dot[1000000]="000000";
    float post_dot_float;
    char exponent[1000000];
    int count=0;
    while(*string!='.'){
        pre_dot[count]=*(string);
        string++;
        count++;

    }
    pre_dot[count]='\0';
    count=0;
    string++;
    while(*string!='e'&&*string!='E'){
        post_dot[count]=*string;
        string++;count++;
    }
    post_dot[count]='\0';
    count=0;
    while(*string!='+'&&*string!='-'){
        *(string++);
    }

    while(*string!=' '){
        exponent[count]=*(string);
        count++;string++;
    }
    exponent[count]='\0';
 int i=0; //количество знаков, заводим для знака после точки
 pre_dot_float=(float)char_to_dec(&i, pre_dot);
 i=0;
 post_dot_float=(float)char_to_dec(&i, post_dot);
 while(i>0){
    post_dot_float /=10;
    i--;

 }
 float return_this=pre_dot_float+post_dot_float;
 return_this=exponent_f(exponent, return_this);


    

    // printf("\n\n post_dot_float=%f", pre_dot_float);
    // printf("\n\n post_dot_float=%f", post_dot_float);
    // printf("\n\npredot=%s\n\n", pre_dot);
    // printf("\n\npostdot=%s\n\n", post_dot);
    // printf("\n\nexponent=%s\n\n", exponent);
    return return_this;

   }

   long double char_to_dec(int* i, char str[]){
    long double result = 0.0;
    while(*str>=48&&*str<=57) {//0 to 9
    (*i)++;
    result *= 10;
    result += *str-'0';
    str++;
      }
       return result;
  }

  long double exponent_f(char exp[], float pre_plus_post){
    int is_negative=0; 
    float return_this;
    if(*exp=='-'){
            is_negative=1; }  
            exp++;
    
if(!is_negative){
    printf("AAAAA%lf", (((float)atoi(exp))*10));
return_this=pre_plus_post*s21_pow(10, (float)atoi(exp));

};
printf("\n\nEXPONENTED=%f\n\n", return_this);
return return_this;
  }

 long long int hex_to_dex(char str[], int base, flagscanf *param, int minus, const char** source) {
  long long int result = 0x0;
 // param->failed = 1;
  char *start_str = str;
  long long int sign = minus ? -1.0:1;
  
    //  base = 16;
  
  


    
  
int break_=0;
  while (((*str >= 48 && *str <= 57) || (*str >= 65 && *str <= 70) ||
          (*str >= 97 && *str <= 102))&&break_==0 ) {
    if (*str >= 48 && *str <= 55) {
      result = (*str - '0') + result * base;
      str++;
      (*source)++;
      
    } else if ((*str >= 56 && *str <= 57) && (base != 8)) {
      result = (*str - '0') + result * base;
      str++;
      (*source)++;
     
    } else if ((*str >= 65 && *str <= 70) && (base != 8) && (base != 10)) {
      result = (*str - 55) + result * base;
      str++;
      (*source)++;
    } else if ((*str >= 97 && *str <= 102) && (base != 8) && (base != 10)) {
      result = (*str - 87) + result * base;
      str++;
      (*source)++;
    }
    else{break_=1;}
    
   // param->failed = 0;
  }
//   if (param->failed == 1) *str = *start_str;
  return result * sign;
} 

int convert_to_dec(int input, int base, int minus){
    int power=0;
    int dec=0;
    
    while(input>0){
    dec=dec+(input%10)*pow(base, power);
    input=input/10;
    power++;}
    return minus ? dec*-1.0:dec;
}



float a_to_float(char* string){
    char pre_dot[10000];
    float pre_dot_float;
    char post_dot[10000]="000000";
    float post_dot_float;
    char exponent[10000];
    long long int sign=set_sign(string);
    int count=0;
    while(*string!='.'){
        pre_dot[count]=*(string);
        string++;
        count++;

    }
    pre_dot[count]='\0';
    count=0;
    string++;
    while(*string!=' '&&*string!='\0'&&is_int_f(*string)){
        post_dot[count]=*string;
        string++;count++;
    }
    post_dot[count]='\0';
    count=0;
    

    
    
 int i=0; //количество знаков, заводим для знака после точки
 pre_dot_float=(float)char_to_dec(&i, pre_dot);
 i=0;
 post_dot_float=(float)char_to_dec(&i, post_dot);
 while(i>0){
    post_dot_float /=10;
    i--;

 }
 float return_this=pre_dot_float+post_dot_float;
 
    return return_this*sign;

   }

 long int set_sign(char *str) {
  long int sign = 1;
  if (*str == '+') {
    str++;
  } else if (*str == '-') {
    sign = -1.0;
    str++;
    
  }
  return sign;
} 

int s21_sscanf(const char* source, const char *format, ...){
va_list args;

flagscanf sscan_Flags={{0}, 0};

va_start(args, format);
// char* s=va_arg(args, char*);
// printf("STRING FROM MAIN=%s\n", s);
// int* x=va_arg(args, int*);
// printf("INT X IN MAIN=%d\n", *x);
char* tmp;
flagscanf Flagscanf={{0}, 0};
while(*format!='\0'&&*source!='\0'){
    printf("here?\n");
    while(*format==*source&&*format!='%'){
      format++; source++;
    }
    if(*format=='%'&&Flagscanf.failed==0){
        format++;
        Flagscanf.width=0;
        set_params(&Flagscanf, &format);
        printf("test");
        //Flagscanf=scanfparser_flags(&format); // заполняем от ' ' до 0 почему не растет указатель я разименовываю 1 раз, значит должен расти формат
        scanfparser_spec(format, &Flagscanf); // заполняем спецификаторы например d или s
        //Flagscanf=scanfparser(format);
        scanf_concat_type(&Flagscanf, args, &source); //возвращаем то, что мы пишем в переменную,
        //va_arg(args,char*);
        printf("tmp=%s\n", tmp);
        //как вообще подставить в функцию имя переменной когда оно само переменная?
        //strcat(, tmp);
        //move_str=strlen(tmp);

        
    }
    format++;


}
printf("Flagscanf:\nbase.integer=%d\nbase.string=%d\nfplus=%d\n", Flagscanf.base.integer, Flagscanf.base.string, Flagscanf.fplus);
//printf("Flagscanf:\nbase->integer=%d\n", Flagscanf.base.integer);
}

flagscanf scanfparser_flags(const char** format){
    //(*format)++;
    flagscanf Flags={0};
    
    while(**format==' '||**format=='-'||**format=='+'||**format=='#'||**format=='0'){
        switch(**format){
            case' ':
            Flags.fspace=1;
            break;
            case'-':
            Flags.fminus=1;
            break;
            case'+':
            Flags.fplus=1;
            break;
            case'#':
            Flags.fsharp=1;
            break;
            case'0':
            Flags.fzero=1;
            break;
        }
        (*format)++;
    }
    return Flags;

}

 void scanfparser_spec(const char *format, flagscanf* Flags){
        
        //format++;
        while(*format!='\0'&&*format!='%'&&*format!=' '){
            printf("here?:82");
        switch(*format){
           // case'[':
                // logic parsing regular
                //Flags->regular == NULL;
               // break;
            case 'h':
            Flags->h=1;
            format++;
            break;   
            case 'l':
            if(Flags->l==1){
                Flags->ll=1;
            }
            else{
            Flags->l=1;}
                
            format++;//странно что здесь отрабатывает нормально сдвиг
            break;
            case 'L':
            Flags->L=1;
            format++;
            break;
            default:
                Flags->base = parser(&format, Flags->base); 
        }
    //format++;


    }
       }    

 
   void scanf_concat_type(flagscanf* Flags, va_list arg, const char** source){
    void* add_this=malloc(10000);
    
    long double* result=calloc(1, sizeof(long double));
    if(Flags->base.integer==1){
       add_this=(void*)scanf_write_int(Flags, arg, source, result);
    }
    if(Flags->base.string==1){
        add_this=scanf_write_string(Flags, arg, source);
    }
    if(Flags->base.decimal_octal_hex==1||Flags->base.p){
        add_this=(void*)scanf_write_decimal_octal_hex(arg, source, Flags, result);
        // printf("ADDTHIS=%d\n", *((int*)add_this)); interesting segfault 
    }
    if(Flags->base.e==1){
        sscanf_write_e(arg, source, Flags, result);
    }
    if(Flags->base.o==1){
        sscanf_write_o(arg, source, Flags, result);
    }
    if(!Flags->base.string&&!Flags->base.e&&!Flags->base.o&&!Flags->failed){
     if(Flags->ll){ 
        *(va_arg(arg, long long int *)) = (long long int)*result;}
        else if(Flags->l){*(va_arg(arg, long int *)) = (long int)*result;}
        else if(Flags->h){*(va_arg(arg, short int *))= (short int)*result;}
        else{*(va_arg(arg, int*))=(int)*result;}}
    //     else{
    //       int* x=va_arg(arg, int*);
    //       printf("test");}
    //       }
    // // if(Flags->base.e)
    // {*(va_arg(arg, float*))=(float)*result;}    

   
    //return (void*)add_this; //мы допишем это в str вместо %d
   } 

   flags    parser(const char **format, flags Flags){
        //flags Flags={0};
        //(*format)++;
        while(**format=='d'||**format=='s'||**format=='i'||**format=='e'||**format=='o'||**format=='E'||**format=='g'||**format=='G'||**format=='f'){
           printf("here?:parser163");
    //           case 'e':
    // case 'E':
    // case 'g':
    // case 'G':
    // case 'f':
        switch(**format){
            
        case 'd':
            Flags.integer=1;
            Flags.move_format=2;
            break;
        case 's':
            Flags.string=1;
            Flags.move_format=2;
            break;  
        case 'i':
            Flags.decimal_octal_hex=1;
            break;   
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        case 'f':
            Flags.e=1;
            break; 
        case 'o':
            Flags.o=1;        
        default:
            break;  }
            
            (*format)++;
    }
    return Flags;


    }

    int width_check(flagscanf Flags){
      int is_true=0;
      if(Flags.width>0||Flags.width==-1)is_true=1;
      return is_true;
    }

int hex_check(const char** str){
  int is_true=0;
  if((**str >= 48 && **str <= 57) || (**str >= 65 && **str <= 70) ||
          (**str >= 97 && **str <= 102))is_true=1;
          return is_true;
}

