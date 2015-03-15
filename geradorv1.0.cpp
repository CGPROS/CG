//
//  main.cpp
//  Gerador
//
//  Created by Rui Machado/Alexandre Mirra on 11/03/15.
//  Copyright (c) 2015 Rui Machado. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>


using namespace std;

ofstream outfile;

void plano(float altura, float lado, int camadas, int fatias, float z, int ori){

    int i;
    float l_const=lado/fatias, alt_const=altura/camadas,alt_ori=-altura/2,lado_ori=-lado/2;

	if (outfile.is_open() && outfile.good()) //verificamos se está tudo bem
	{
        switch (ori) {
            case 1:
                for(altura=alt_ori;camadas>0;camadas--){
                    i=0;
                    for(lado=lado_ori;i<fatias;i++){

            outfile << lado << " " << altura << " " << z  << endl;
			outfile << lado + l_const << " " << altura << " " << z  << endl;
			outfile << lado << " " << altura+alt_const << " " << z  << endl;
			//segundo triangulo
			outfile << lado+l_const << " " << altura << " " << z << endl;
			outfile << lado+l_const << " " << altura + alt_const<< " " << z<< endl;
			outfile << lado  << " " << altura + alt_const << " " << z << endl;
                        lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
        
            case 2:
            for(altura=alt_ori;camadas>0;camadas--){
                i=0;
                for(lado=lado_ori;i<fatias;i++){
                    
                outfile << lado << " " << altura << "." << z  << endl;
                outfile << lado << " " << altura+alt_const<< " " << z  << endl;
                outfile << lado+l_const << " " << altura << " " << z  << endl;
                    //segundo triangulo
                outfile << lado+l_const << " " << altura << " " << z << endl;
                outfile << lado << " " << altura + alt_const<< " " << z<< endl;
            outfile << lado+l_const  << " " << altura + alt_const << " " << z << endl;
                    lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
            case 3:
                for(altura=alt_ori;camadas>0;camadas--){
                    i=0;
                    for(lado=lado_ori;i<fatias;i++){
                        
                    outfile << z << " " << altura << " " << lado  << endl;
                    outfile << z << " " << altura+alt_const << " " << lado  << endl;
                    outfile << z << " " << altura << " " << lado+l_const  << endl;
                    //segundo triangulo
                outfile << z << " " << altura << " " << lado+l_const << endl;
                outfile << z << " " << altura + alt_const<< " " << lado<< endl;
            outfile << z  << " " << altura + alt_const << " " << lado+l_const << endl;
                        lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
            case 4:
                for(altura=alt_ori;camadas>0;camadas--){
                    i=0;
                    for(lado=lado_ori;i<fatias;i++){
                        
                    outfile << z << " " << altura << " " << lado  << endl;
                    outfile << z  << " " << altura << " " << lado+l_const  << endl;
                    outfile << z  << " " << altura+alt_const << " " << lado  << endl;
                        //segundo triangulo
                    outfile << z  << " " << altura << " " << lado+l_const << endl;
                outfile << z  << " " << altura + alt_const<< " " << lado+l_const<< endl;
                    outfile << z << " " << altura + alt_const << " " << lado << endl;
                        lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
            case 5:
                for(altura=alt_ori;camadas>0;camadas--){
                    i=0;
                    for(lado=lado_ori;i<fatias;i++){
                        
                        
                        outfile << altura << " " << z << " " << lado  << endl;
                        outfile << altura  << " " << z << " " << lado+l_const  << endl;
                        outfile << altura+alt_const  << " " << z << " " << lado  << endl;
                        //segundo triangulo
                        outfile << altura  << " " << z << " " << lado+l_const << endl;
                        outfile << altura + alt_const  << " " << z<< " " << lado+l_const<< endl;
                        outfile << altura+alt_const << " " << z << " " << lado << endl;
                        lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
            case 6:
                for(altura=alt_ori;camadas>0;camadas--){
                    i=0;
                    for(lado=lado_ori;i<fatias;i++){
                        
                        outfile << altura << " " << z << " " << lado  << endl;
                        outfile << altura+alt_const  << " " << z << " " << lado << endl;
                        outfile << altura  << " " << z << " " << lado+l_const  << endl;
                        //segundo triangulo
                        outfile << altura  << " " << z << " " << lado+l_const << endl;
                        outfile << altura + alt_const  << " " << z<< " " << lado<< endl;
                        outfile << altura+alt_const << " " << z << " " << lado+l_const << endl;
                        lado+=l_const;
                    }
                    altura+=alt_const;
                }
                break;
                
            default:
                break;

                   }

			outfile.close();
    }}

void paralelipipedo(float altura, float ladox, int ladoz, int camadas, float fatias){
    
    
    
    if (outfile.is_open() && outfile.good())
    {
        plano(altura, ladox, camadas, fatias, ladoz/2, 1);
        plano(altura, ladox, camadas, fatias, -ladoz/2, 2);
        
        plano(altura, ladoz, camadas, fatias, ladox/2, 3);
        plano(altura, ladoz, camadas, fatias, -ladox/2, 4);
        
        plano(ladox, ladoz, camadas, fatias, altura/2, 5);
        plano(ladox, ladoz, camadas, fatias, -altura/2, 6);
        outfile.close();
        
        
    }
    
    
}


/*
  




void esfera(float raio, float altura, float fatias){
 
	if (outfile.is_open() && outfile.good())
	{
		float alpha = 2 * 3.14 / fatias;

		outfile << "Circulo--ESFERA" << endl;
		for (int i = 0; i < fatias; i++){
			//criação circulo...duvidas
			outfile << sin(alpha + i)*raio << "." << altura / 2 << "." << cos(alpha + i)*raio << endl;
			
		}
		outfile.close();
	}
    

}


void cone(float raio, float altura, float fatias){
   
	if (outfile.is_open() && outfile.good())
	{
		float alpha = 2 * 3.14 / fatias;
		//Ponto Superior
		outfile << "Ponto Superior" << endl;
		outfile << 0 << "," << altura << "," << 0 << endl;
		outfile << "Circulo da base!"<< endl;
		for (int i = 0; i < fatias; i++){
			//criação base!! 
			outfile << sin(alpha + i)*raio << "." << 0 << "." << cos(alpha + i)*raio << endl;

		}
		
		outfile.close();
	}
    
}*/

int main(int argc, const char * argv[]) {
    
	
    
    if((strcmp("paralelipipedo",argv[1]))==0){
        
        if(argc==7){
        
        outfile.open("paralelipipedo.3d");
        float x = (float)atoi(argv[2]);
        float y = (float)atoi(argv[3]);
        float z = (float)atoi(argv[4]);
        int a = (int)atoi(argv[5]);
        int b  = (int)atoi(argv[6]);
        paralelipipedo(x,y,z,a,b);
        }
        else {printf ("Parametros incorrectos \n");}
        
    }
    
        
    /*
    if((strcmp("esfera",argv[1]))==0){
        
        outfile.open("esfera.3d");
		float x = (float)atoi(argv[2]);
		float y = (float)atoi(argv[3]);
		float z = (float)atoi(argv[4]);
        esfera(x,y,z);
        
    }
	if ((strcmp("cone", argv[1])) == 0){
		outfile.open("cone.3d");
		float x = (float)atoi(argv[2]);
		float y = (float)atoi(argv[3]);
		float z = (float)atoi(argv[4]);
		cone(x, y, z);

	}*/
    if((strcmp("plano",argv[1]))==0){
        outfile.open("plano.3d");
		float x = (float)atoi(argv[2]);
		float y = (float)atoi(argv[3]);
		int z = (int)atoi(argv[4]);
        int a = (int)atoi(argv[5]);
        float b  = (float)atoi(argv[6]);
       
        plano(x,y,z,a,0,b);
        
    }}
