//assignment 1
//Registration Number: E/16/377
//Name: I B S Vindula


#include <stdio.h>                          //header file


//global variable for storing binary converted value
char bin[70]; 



//functions
int ppower(int x, int y);                                                                                       //function for positive power
float npower(int x, int y);                                                                                     //function for taking negative power
int length(char input[]);                                                                                       //for taking length of an array
int stringcompare(char input1[],char input2[]);                                                                 //return 1 if the 2 strings are same
void stringcopy(char input1[],char input2[]);                                                                   //storing elements of input1 array to input 2 array
long long int stringtoint(char input[]);                                                                                  //converting character array to integer
int stringtointx(char input[]);                                                                                 //convert char array to 32bit integer
double stringtodouble(char input[]);                                                                            //converting a string to double
float stringtofloat(char input[]);                                                                              //converting a string to float
int hexvalidity(char input[]);                                                                                  //checking the characters of hex
void inttobinary(long long int x,char bin[]);                                                                   //converting an integer to binary
void hextobinarystore(int size,char input[],char bin[]);                                                        // converting integer to binary array
long long int binarytoint(char bin[]);                                                                          //converting binary array to an integer
void binarytohex(char bin[]);                                                                                   //printing hex value of binary array
void inttobinary64(long long int divident,char bin[]);                                                          //convert 64 bit integerto binary                                                                  

int main(int argc, char*argv[])                                                                                 //main function to get the input in command line
{
    //checking for the not possible errors
    if(stringcompare(argv[1],"-D") && stringcompare(argv[2],"-F")){
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 1;
    }
    if(stringcompare(argv[1],"-D")  && stringcompare(argv[2],"-I")){
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 1;
    }
    if(stringcompare(argv[1],"-I")  && stringcompare(argv[2],"-D")){
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 1;
    }
    if(stringcompare(argv[1],"-F")  && stringcompare(argv[2],"-D")){
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 1;
    }

    //error checking for wrong number of arguments
    if(argc != 4){
        fprintf(stderr,"ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <input>\n");
        return 1;
    }

    //error checking for wrong input arguments and convert all to binary
    if(stringcompare(argv[1],"-B" )){
        //code to wrong input size and format 
        int i;
        //for 32 bit binary
         if(length(argv[3])==32){
            for(i=0;i<32;i++){
                if( argv[3][i] == '0' || argv[3][i] == '1' ){
                }
                else{
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                    return 1;
                }
            }
            //if there is no errors copy the string to binary array
             stringcopy(argv[3],bin);
         }
        //for 64bit binary
         else if(length(argv[3])==64){
            for(i=0;i<64;i++){
                if( argv[3][i] == '0' || argv[3][i] == '1' ){
                }
                else{
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                    return 1;
                }
            }
                //copy string to array
             stringcopy(argv[3],bin);

         }
         //size error
         else{
            fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
        }

    }
    else if(stringcompare(argv[1],"-H")){
        //checking if the length is correct or not
        if(length(argv[3])==8){
            //checking the elements are correct and if not print the error
            if(hexvalidity(argv[3])==1){
                return 1;
            }
            else{
                   //converting for 8bit hexa decimal to binary
                hextobinarystore(8,argv[3],bin);
                   
                    }
                   } 
            
        //if there are 16 elements
        else if(length(argv[3])==16){
            //checking if the elements are valid
                if(hexvalidity(argv[3])==1){
                    return 1;
            }
                else{
                    //convert hex to a bin value
                    hextobinarystore(16,argv[3],bin);
            }

        }
        else{
            //printing errors if the input size is wrong
            fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
        }

    }
    else if(stringcompare(argv[1],"-I")){
        //if the input is an integer

            int i;                          //declaring variables
            //storing the string value to x after converting it intoa integer
            long long int x = stringtoint(argv[3]);
            //checking the size
            if(x >= - 2147483648  && x <= 2147483647){

            }
            //printing the error
            else{
                fprintf(stderr,"ERROR: The input size is wrong.\n");
                return 1;
            }
            //checking the elements
            for(i=0;argv[3][i]!='\0';i++){
                if(argv[3][i]>='0' && argv[3][i]<='9'){

                }
                //checking the negative value
                else if(argv[3][0]=='-'){

                }
                //if the elements are not valid
                else
                {
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                    return 1;
                }
            }
            //convert integer value to a binary value
            inttobinary(x,bin);


    }
    //if the integer type is single precision float
    else if(stringcompare(argv[1],"-F")){
        int k=0;                                                //initialising variables
        int i;
        //checking the inpits are correct
        for(i=0;i<length(argv[3]);i++){
            if(argv[3][i] >= '0' && argv[3][i]<='9'){
                //printf("e");

            }
            else if(argv[3][i]=='.'){
                k=k+1;
                if(k==2){
                    //print error if there are two dots
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                    return 1;
                }
            }
            else{
                //print error if there are no valid elements
                fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                return 1;
            }
        }
        }
        //if the input argument is doubleprecision float

    else if(stringcompare(argv[1],"-D")){
        int k=0;                                        //initialising variables
        int i;
        //checking for errors
        for(i=0;i<length(argv[3]);i++){
            if(argv[3][i] >= '0' && argv[3][i]<='9'){

            }
            else if(argv[3][i]=='.'){
                k=k+1;
                if(k==2){                                                           //print error if there are two dots
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                    return 1;
                }
            }
            else{                                                                   //print an error if there are invalid elements
                fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                return 1;
            }
}
    }
    else{
        //print error if the input argument is wrong
        fprintf(stderr,"ERROR: The input argument is wrong.\nPossible input arguments are -B, -H, -I, -F and -D.\n");
        return 1;
    }




    //error checking for wrong output arguments and convert all to binary
    if(stringcompare(argv[2],"-B" )){
        int i;
        //printing the binary value
        for(i=0;i<length(bin);i++){
            fprintf(stdout,"%c",bin[i]);
        }
        fprintf(stdout,"\n");
    }
    else if(stringcompare(argv[2],"-H")){  
        //printing the hexa value after converting binary to hex    
        binarytohex(bin);
    }
    
    else if(stringcompare(argv[2],"-I")){
        //if the length of the binary is 32 bit
        if(length(bin)==32){
             long long int x = binarytoint(bin);
             //printing the integer
             fprintf(stdout,"%I64lld\n",x);
    }

        
        else if(length(bin)==64){
            //if the binary is 64bit printin not possible error

            fprintf(stderr,"ERROR: This conversion is not possible.\n");
            return 1;
            }
            
        }
    else if(stringcompare(argv[2],"-F")){
        //if the output is float

    }
    else if(stringcompare(argv[2],"-D")){
        //if the output is double prec float

    }
    else{
        //printing output arg wrong error
        fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");
        return 1;
    }

return 0;                                               //return integer from main function
}

//defining functions

//defining positive power
int ppower(int x, int y){
    //defining variables
int result=1;
int i=0;
//for positive power
if(y>0){
    for(i=0;i<y;i++){
        result=result*x;
    }
}
//returning the answer
return result;

}


//defining negative power function
float npower(int x, int y)
{
//defining variables
float result=1;
//for negative power
if(y<0){
        result=1/ppower(x,-y);
}
//return the result to a function
return result;
}


//defining length function
int length(char input[])
{
    //defining variables
int i=0;
//counting until the last element
for(i = 0; input[i] != '\0'; ++i){
    i++;
};
//return the value to the function
  return i;
}

//defining the string compare function
int stringcompare(char input1[],char input2[])
{
  if(length(input1)== length(input2)){
    for(int i=0;i<length(input1);i++){
        if(input1[i]==input2[i]){}
        else
            return 0;

    }
    //returning one because of the error
    return 1;
  }
  else
    return 0;
}

//defining the string copy function
void stringcopy(char input1[],char input2[])
{   //copy ine string to another string from element to element
    for(int i=0;i<length(input1);i++){
        input2[i]=input1[i];
    }
}

//define string to integer converting function
long long int stringtoint(char input[])
{
    //initialising variables
  int i, sign, move;
  long long int result;

  if (input[0] == '-') {                                        //for negative integers
    sign = -1;
  }

  if (sign == -1) {                                             //for moving the starting point
    move = 1;
  }
  else {
    move = 0;                                                               //not moving because positive
  }

  result = 0;

  //making the integer by removing aski value
  for (i = move; input[i]!= '\0'; i++) {
    result = result * 10 + input[i] - '0';
  }

  if (sign == -1) {
    result = -result;
  }

  return result;
}

//defining func stringtointx
int stringtointx(char input[]){
  int i, sign, move,result;

  if (input[0] == '-') {                                        //for negative integers
    sign = -1;
  }

  if (sign == -1) {                                             //for moving the starting point
    move = 1;
  }
  else {
    move = 0;                                                       //not moving for positive
  }

  result = 0;

  //making the integer by removing aski value
  for (i = move; input[i]!= '\0'; i++) {
    result = result * 10 + input[i] - '0';
  }

  if (sign == -1) {
    result = -result;
  }

  return result;
}

//defining a function to convert string to double
double stringtodouble(char input[]){
    int j=0;                                                                //declaring variables
    double result2 = 0 ;

    while(input[j] != '.'){
        j++;
    }

    char input1[j];
    int i=0;

    for(i=0;i<j;i++){
        input1[i]=input[i];                                             //copying array to array
    }

    long long int result1=0;
    for(i=0;i<=j;i++){
        result1=10*result1 + input1[i] - '0' ;                                          //getting integer value by the loop
    }
    double t=0.1;

    for(i=j+1;i<length(input);i++){


            result2 = result2 + t * (input[i] - '0');                                               //getting decimal value by loop
            t=t*0.1;
    }
    //printf("%lf",result); //for testing
    return (double)result1 + result2;                                                           //returning the total value

}

//defining the function string to double
float stringtofloat(char input[]){
    int j=0;                                                                            //declaring variables
    float result2 = 0 ;

    while(input[j] != '.'){                                                     //count upto dec point
        j++;
    }

    char input1[j];                                                                         //declaring variables
    int i=0;

    for(i=0;i<j;i++){
        input1[i]=input[i];                                                                 //copyingfrom one array to another array
        //printf("%c",input1[i]);
    }
    int result1=0;
    for(i=0;i<j;i++){
        result1=10*result1 + input1[i] - '0' ;                                                          //getting the integer value
    }
    //printf("result1: %d\n",result1);
    //return (double)result1;      //for error checking
    float t=0.1;

    for(i=j+1;i<length(input);i++){


            result2 = result2 + t * (input[i] - '0');                                                           //getting the decimal value
            t=t*0.1;
    }
    //printf("%f",result); //for testing
    return result1 + result2;                                                                                           //returning the totalvalue
}


//defining function for checking the validity of hexadecimal
int hexvalidity(char input[]){
    int i;
    for(i=0;input[i]!='\0';i++){
        if(input[i]<='9' && input[i] >= '0'){

        }
        else if(input[i]<=70 && input[i] >= 65) {

        }
        else{
            //input format error if there are invalid 
            fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
            return 1;
        }
    }
    return 0;
}

//defining an array to convert an integer to binary array
void inttobinary(long long int divident,char bin[]){
    //declaring variables
    int j,remainder;
    int k=31;
    //for positive initigers
    if(divident>0){
        for(j=0;j<32;j++){
            //printf("rdivident: %d\n",divident);
            remainder=divident%2;
            //printf("remainder: %d\n",remainder);
            divident=divident/2;
            
            if(remainder==0){
             bin[k]='0';                                //storint 0 in the array
             //printf("0");
        }

        else if(remainder==1){
             bin[k]='1';                                            //
            // printf("1");
        }
        k--;
    }
}

        else if(divident<0){                                        //if the integer is negative
        divident=-divident;
        for(j=0;j<32;j++){
            //printf("rdivident: %d\n",divident);
            remainder=divident%2;
            //printf("remainder: %d\n",remainder);
            divident=divident/2;
            
            if(remainder==0){
             bin[k]='1';                                                //circulatingthe value to get 2s compliments
             //printf("0");
        }

        else if(remainder==1){
             bin[k]='0';                                                                     //circulatingthe value to get 2s compliments
            // printf("1");
        }
        k--;

    }
        //to add 1 bit to binary value
        for(j=31;j>=0;j--){
            if(bin[j]=='1'){
                bin[j]='0';
            }
            else{
                bin[j]='1';
                break;
            }
        }
}
// to convert 0 to binary
    else if(divident==0){
        for(j=0;j<32;j++){
            bin[j]='0';
        }

    }
}


//defining an array to convert an 64 bit integer to binary array
void inttobinary64(long long int divident,char bin[]){
    int j,remainder;
    int k=63;
    if(divident>0){                                             //for positive integers
        for(j=0;j<64;j++){
            //printf("rdivident: %d\n",divident);
            remainder=divident%2;
            //printf("remainder: %d\n",remainder);
            divident=divident/2;
            
            if(remainder==0){                                       //storing values in bin array
             bin[k]='0';
             //printf("0");
        }

        else if(remainder==1){
             bin[k]='1';
            // printf("1");
        }
        k--;
    }
}

        else if(divident<0){                                    //for negative integers
        divident=-divident;
        for(j=0;j<64;j++){
            //printf("rdivident: %d\n",divident);
            remainder=divident%2;
            //printf("remainder: %d\n",remainder);
            divident=divident/2;
            
            if(remainder==0){
             bin[k]='1';                                                    //storing inverted bin values
             //printf("0");
        }

        else if(remainder==1){
             bin[k]='0';
            // printf("1");
        }
        k--;

    }

        for(j=63;j>=0;j--){                                         //add 1bit to get 2s compliment
            if(bin[j]=='1'){
                bin[j]='0';
            }
            else{
                bin[j]='1';
                break;
            }
        }
}
    else if(divident==0){                                               //converting 0 to binary
        for(j=0;j<64;j++){
            bin[j]='0';
        }

    }
}

//defining function
void hextobinarystore(int size,char input[],char bin[]){
    //converting for size bit hexa decimal
    int i;
           for(i=0;i<size;i++){
            if(input[i]=='0'){
                bin[4*i]='0';
                bin[4*i+1]='0';
                bin[4*i+2]='0';
                bin[4*i+3]='0';
                }
                else if(input[i]=='1'){
                bin[4*i]='0';
                bin[4*i+1]='0';
                bin[4*i+2]='0';
                bin[4*i+3]='1';
                }
                else if(input[i]=='2'){
                bin[4*i]='0';
                bin[4*i+1]='0';
                bin[4*i+2]='1';
                bin[4*i+3]='0';
                }
                else if(input[i]=='3'){
                bin[4*i]='0';
                bin[4*i+1]='0';
                bin[4*i+2]='1';
                bin[4*i+3]='1';
                }
                else if(input[i]=='4'){
                bin[4*i]='0';
                bin[4*i+1]='1';
                bin[4*i+2]='0';
                bin[4*i+3]='0';
                }
                else if(input[i]=='5'){
                bin[4*i]='0';
                bin[4*i+1]='1';
                bin[4*i+2]='0';
                bin[4*i+3]='1';
                }
                else if(input[i]=='6'){
                bin[4*i]='0';
                bin[4*i+1]='1';
                bin[4*i+2]='1';
                bin[4*i+3]='0';
                }
                else if(input[i]=='7'){
                bin[4*i]='0';
                bin[4*i+1]='1';
                bin[4*i+2]='1';
                bin[4*i+3]='1';
                }
                else if(input[i]=='8'){
                bin[4*i]='1';
                bin[4*i+1]='0';
                bin[4*i+2]='0';
                bin[4*i+3]='0';
                }
                else if(input[i]=='9'){
                bin[4*i]='1';
                bin[4*i+1]='0';
                bin[4*i+2]='0';
                bin[4*i+3]='1';
                }
                else if(input[i]=='A'){
                bin[4*i]='1';
                bin[4*i+1]='0';
                bin[4*i+2]='1';
                bin[4*i+3]='0';
                }
                else if(input[i]=='B'){
                bin[4*i]='1';
                bin[4*i+1]='0';
                bin[4*i+2]='1';
                bin[4*i+3]='1';
                }
                else if(input[i]=='C'){
                bin[4*i]='1';
                bin[4*i+1]='1';
                bin[4*i+2]='0';
                bin[4*i+3]='0';
                }
                else if(input[i]=='D'){
                bin[4*i]='1';
                bin[4*i+1]='1';
                bin[4*i+2]='0';
                bin[4*i+3]='1';
                }
                else if(input[i]=='E'){
                bin[4*i]='1';
                bin[4*i+1]='1';
                bin[4*i+2]='1';
                bin[4*i+3]='0';
                }
                else if(input[i]=='F'){
                bin[4*i]='1';
                bin[4*i+1]='1';
                bin[4*i+2]='1';
                bin[4*i+3]='1';
                }
            }
}

//converting binary to integer
//can convert 2s compliment binary too
long long int binarytoint(char bin[]){
    int y=length(bin);
    long long int x=0;
    int i,k;
    k=0;
    if(y==32){
        for(i=31;i>=0;i--){
            if(bin[i]=='1'){
                x=x+ppower(2,k);                                                    //getting by gettig twos power
            }
            k++;

        }
    }
    return x; 

}


//binary to hex : defining the function
void binarytohex(char bin[]){
    int x = length(bin);                                                                //declaring variables
    int i,j;
    fprintf(stdout,"0x");                                                                   //printing the first part of hex

    for(i=0;i<x/4;i++){
        int k=3;
        int result=0;
        for(j=4*i;j<4*i+4;j++){                                                     //getting the integer value from 4bit to 4bit
            if(bin[j]=='1'){
                result=result+ppower(2,k);
            }
            k--;
        }
        if(result>=0 && result<=9){
            fprintf(stdout,"%d",result);
        }
        else if(result==10){
            fprintf(stdout,"A");
        }
        else if(result==11){
            fprintf(stdout,"B");
        }
        else if(result==12){
            fprintf(stdout,"C");
        }
        else if(result==13){
            fprintf(stdout,"D");
        }
        else if(result==14){
            fprintf(stdout,"E");
        }
        else if(result==15){
            fprintf(stdout,"F");
        }
    }
    fprintf(stdout,"\n");                                           //printing new line
}