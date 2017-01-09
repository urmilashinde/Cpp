//
//  main.cpp
//  Bit_Manipulation
//
//  Created by Urmila shinde on 9/8/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>

#define SET_BIT(reg, pos)((1<<pos) | reg)

#define CLEAR_BIT(reg, pos)((~(1<<pos)) & reg)

#define TOGGLE_BIT(reg, pos) ((1<<pos) ^ reg)

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int Reg = 0x80;
    
    printf("original reg value is %4x \n", Reg);
    
  //  Reg = (1 << 2) | Reg;
    
    
    Reg = SET_BIT(Reg, 2);
    printf("reg value after setting 3rd bit is %4x \n",  Reg);
    
    printf("original reg value is %4x \n", Reg);
    
    // Reg = ~(1 << 2) & Reg;
    
    Reg = CLEAR_BIT(Reg, 2);
    printf("reg value after clearing 3rd bit is %4x \n", Reg);
    
    
    printf("original reg value is %4x \n", Reg);
    
    Reg = TOGGLE_BIT(Reg, 7);
    printf("reg value after toggling 7th bit is %4x \n", Reg);
    Reg = TOGGLE_BIT(Reg, 0);
    printf("reg value after toggling 0th bit is %4x \n", Reg);
    
    printf("original reg value is %4x \n", Reg);
    
    
    return 0;
}
