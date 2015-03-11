//
//  main.cpp
//  Gerador
//
//  Created by Rui Machado on 11/03/15.
//  Copyright (c) 2015 Rui Machado. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ofstream outfile;
void paralelipipedo(float comp, float altura, float largura){
    
   
   
    if (outfile.is_open() && outfile.good()) //verificamos se está tudo bem
    {
        outfile << comp << "." << altura << "." << largura << endl;
        outfile.close();
    }
    
    
}

void plano(float comp, float altura, float largura){


    

}


void esfera(float comp, float altura, float largura){
 
    

}


void cone(float comp, float altura, float largura){
   
    
}

int main(int argc, const char * argv[]) {
    
    
    if(strcmp("paralelipipedo",argv[2])){
        
        outfile.open("paralelipipedo.3d");
        float x = atoi(argv[3]);
        float y = atoi(argv[4]);
        float z = atoi(argv[5]);
        paralelipipedo(x,y,z);
        
    }else
    
    if(strcmp("esfera",argv[2])){
        
        outfile.open("esfera.3d");
        float x = atoi(argv[3]);
        float y = atoi(argv[4]);
        float z = atoi(argv[5]);
        esfera(x,y,z);
        
    }else
    if(strcmp("cone",argv[2])){
        outfile.open("cone.3d");
        float x = atoi(argv[3]);
        float y = atoi(argv[4]);
        float z = atoi(argv[5]);
        cone(x,y,z);
        
    }else
    if(strcmp("plano",argv[2])){
        outfile.open("plano.3d");
        float x = atoi(argv[3]);
        float y = atoi(argv[4]);
        float z = atoi(argv[5]);
        plano(x,y,z);
        
    }



    
    
    return 0;
}
