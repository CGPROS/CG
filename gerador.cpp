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
    
   
   
    if (outfile.is_open() && outfile.good()) 
    {
        outfile << comp << "." << altura << "." << largura << endl;
        outfile.close();
    }
    
    
}

void plano(float comp, float altura, float largura){


    if (outfile.is_open() && outfile.good()) 
    {
        outfile << comp << "." << altura << "." << largura << endl;
        outfile.close();
    }
    

}


void esfera(float comp, float altura, float largura){
 
     if (outfile.is_open() && outfile.good()) 
    {
        outfile << comp << "." << altura << "." << largura << endl;
        outfile.close();
    }
    

}


void cone(float comp, float altura, float largura){
   
     if (outfile.is_open() && outfile.good()) 
    {
        outfile << comp << "." << altura << "." << largura << endl;
        outfile.close();
    }
    
}

int main(int argc, const char * argv[]) {
    
 
    
    if((strcmp("paralelipipedo",argv[1]))==0){
        
        outfile.open("paralelipipedo.3d");
        float x = atoi(argv[2]);
        float y = atoi(argv[3]);
        float z = atoi(argv[4]);
        paralelipipedo(x,y,z);
        
    }
    
    if((strcmp("esfera",argv[1]))==0){
        
        outfile.open("esfera.3d");
        float x = atoi(argv[2]);
        float y = atoi(argv[3]);
        float z = atoi(argv[4]);
        esfera(x,y,z);
        
    }
    if((strcmp("cone",argv[1]))==0){
        outfile.open("cone.3d");
        float x = atoi(argv[2]);
        float y = atoi(argv[3]);
        float z = atoi(argv[4]);
        cone(x,y,z);
        
    }
    if((strcmp("plano",argv[1]))==0){
        outfile.open("plano.3d");
        float x = atoi(argv[2]);
        float y = atoi(argv[3]);
        float z = atoi(argv[4]);
        plano(x,y,z);
        
    }



    
    
    return 0;
}
