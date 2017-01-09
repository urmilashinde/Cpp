//
//  main.cpp
//  String_operations
//
//  Created by Urmila shinde on 9/6/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>



void Reverse(char *str)
{
    size_t len;
    size_t k;
    len = strlen(str) - 1;
    k = len;
    char temp;
    
    for(int i=0; i<=len/2; i++)
    {
        temp = str[i];
        str[i] = str[k];
        str[k] = temp;
        k--;
    }

}

int atoi(char *str)
{
    int result = 0;
    
    for(int i=0; str[i] != '\0'; i++)
    {
        result = result*10 + str[i] - '0';
    }
    
    return result;
}


char* itoa(int num)
{
    char *result =new char[100];
    int temp = num;
    int len = 0;
    int k = len;
    
    printf("temp =  %d \n", temp);
    
    for( int i=0; temp>0; i++)
    {
        temp = temp/10;
        printf("temp =  %d \n", temp);
        len++;
    }
    
    printf("length of number is %d \n", len);
    
    k = len - 1;
    
    for(int j=0; num>0; j++)
    {
        result[k] = num % 10 + '0';
        num = num/10;
        k--;
        
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    
    char str[10] = "URMILA";
    
    for(auto charecter : str) {
        std::cout << charecter << std::endl;
        
    }
    
    char str2[10] = "1985";
    
    std::string mystr("Urmila");
    mystr.append("is awesome");
    std::cout << mystr << std::endl;
    
    int num = 2016;
    
    char a = '0';
    
    printf("char value is %d \n", a);
    
    printf("original string is %s \n", str);
    
    printf(" integer value of the string2 is %d \n", atoi(str2));
    
    printf(" alphabet value of the num is %s \n", itoa(num));

    
    printf("original string is %s \n", str);
    
    Reverse( str);
    
    printf("original string after reverse is %s \n", str);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}














std::string umang_itoa(int num){
    std::vector <char> result;
    char temp;
    
    for(int j=0; num>0; j++)
    {
        temp = static_cast<char> (num % 10 + '0');
        std::cout << temp;
        result.insert(result.begin()+j, temp);
        num = num/10;
        
    }
    std::cout << std::endl;
    return std::string(result.begin(), result.end());
    
    
    
    //UKP
    /*for(auto c : std::string(str)){
        result = result*10 + c - '0';
    }*/
}
