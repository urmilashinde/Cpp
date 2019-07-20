//
//  main.cpp
//  Matrix
//
//  Created by Urmila shinde on 11/19/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>

// current number = max_rw * index_rw + index_col

void populateMatrix(int *matrix, int max_rw, int max_col)
{
    for(int i=0; i<max_rw; i++)
    {
        for(int j=0; j<max_col; j++)
        {
            matrix[(max_rw*i)+j]=1;
        }
    }
    
    matrix[(max_rw*0)+2] = 3;
    matrix[(max_rw*4)+2] = 3;
    matrix[(max_rw*2)+0] = 2;
    matrix[(max_rw*2)+4] = 2;
    
}

void printMatrix(int *matrix, int max_rw, int max_col)
{
    std::cout <<"============================" << std::endl;
    for(int i = 0; i<max_rw; i++)
    {
        for(int j=0; j<max_col; j++)
        {
            std::cout << matrix[(max_col*i)+j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout <<"============================" << std::endl;
}

/*
void rotate_90(int *matrix, int max_rw, int max_col)
{
    int n = max_rw;
    
    for(int layer=0; layer<n/2; layer++)
    {
        int first = layer;
        int last = n-1-layer;
        
        for(int i=first; i<last; i++)
        {
            int offset = i-first;
            
            //save top
            int top = matrix[first][i];
        }
    }
}
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int matrix[5][5];
    int max_rw = 5;
    int max_col = 5;
    
    
    
    populateMatrix(&matrix[0][0], max_rw, max_col);
    
    printMatrix(&matrix[0][0], max_rw, max_col);
    
    std::cout << std::endl;
    
    //rotate_90(&matrix[0][0], max_rw, max_col);
    
    int n = max_rw;
    
    for(int layer=0; layer<n/2; layer++)
    {
        int first = layer;
        int last = n-1-layer;
        
        std::cout << "First\t" << "Last\t" << "i\t" << "offset\t"<< std::endl;
        
        for(int i=first; i<last; i++)
        {
            int offset = i-first;
            std::cout << first <<"\t"<< last <<"\t" << i <<"\t" << offset<< std::endl;
            
            //save top
            int top = matrix[first][i];
            
            //left to top
            matrix[first][i] = matrix[last-offset][first];
            
            //bottom to left
            matrix[last-offset][first] = matrix[last][last-offset];
            
            //top to right
            matrix[i][last] = top;
            
        }
        
        printMatrix(&matrix[0][0], max_rw, max_col);
    }

     printMatrix(&matrix[0][0], max_rw, max_col);
    
    return 0;
}
