//
//  main.cpp
//  map
//
//  Created by Urmila shinde on 9/12/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::map< std::string, int> mymap;
    
    mymap["Urmila"] = 100;
    mymap["Umang"] = 200;
    
    
    std::cout<<"My map contents are:"<<std::endl;
    
    std::map<std::string, int>::iterator it = mymap.begin();
    
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        std::cout<< it->first << " => "<< it->second << std::endl;
    }
    
    //=========================================================================
    
    char str[] = "urmila shindeeeeeee uuuuu llllll";
    
    std::cout<<" the string is %s \n"<< str;
    
    std::map<char, int>map1;
    
    //std::map<char, int>::iterator it1 = map1.begin();
    auto it1 = map1.begin();
    auto end = map1.end();
    
    for(char c: str) {
        
        //std::cout << c << std::endl;
        
        it1 = map1.find(c);
        if(it1 != end) //char found..increase count
        {
            (it1->second)++;
        }
        else // char not found.. create a map entry.
        {
            map1[c] = 1;
        }
    }
    
    std::cout<<" printing map char and count \n" << std::endl;
    
    for(it1=map1.begin(); it1!=map1.end(); it1++)
    {
        std::cout << it1->first<< "   " << it1->second << std::endl;
    }
    
    return 0;
}
