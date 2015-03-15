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
#define _USE_MATH_DEFINES // for C++..
#include <cmath>


using namespace std;

ofstream outfile;
void paralelipipedo(float comp, float altura, float largura){
    
   
   
    if (outfile.is_open() && outfile.good()) 
    {
		//Nao se pode invocar funçao plano em vez de definir pontos outra vez??? tentei e deu erro .

		//plano horizontal Base (ZoX)
		outfile << "plano horizontal Base (ZoX)"<< endl;
		outfile << comp / 2 << "." << altura << "." << largura / 2 << endl;
		outfile << comp / 2 << "." << altura << "." << -largura / 2 << endl;
		outfile << -comp / 2 << "," << altura << "," << largura / 2 << endl;
		//segundo triangulo
		outfile << -comp / 2 << "," << altura << "," << largura / 2 << endl;
		outfile << comp / 2 << "." << altura << "." << -largura / 2 << endl;
		outfile << -comp / 2 << "." << altura << "." << -largura / 2 << endl;

		//plano vertical Base (ZoY)
		outfile << "plano vertical Base (ZoY)" << endl;
		outfile << comp << "," << -altura / 2 << "," << -largura / 2 << endl;
		outfile << comp << "." << altura / 2 << "." << -largura / 2 << endl;
		outfile << comp << "." << -altura / 2 << "." << +largura / 2 << endl;
		//segundotriangulo
		outfile << comp << "," << -altura / 2 << "," << largura / 2 << endl;
		outfile << comp << "." << altura / 2 << "." << -largura / 2 << endl;
		outfile << comp << "." << altura / 2 << "." << largura / 2 << endl;
		
		//plano frente base (XoY)
		outfile << "plano frente base (XoY)" << endl;
		outfile << -comp / 2 << "," << -altura / 2 << "," << largura << endl;
		outfile << comp / 2 << "." << -altura / 2 << "." << largura << endl;
		outfile << comp / 2 << "." << altura / 2 << "." << largura << endl;
		//segundotriangulo
		outfile << -comp / 2 << "," << -altura / 2 << "," << largura << endl;
		outfile << comp / 2 << "." << altura / 2 << "." << largura << endl;
		outfile << -comp / 2 << "." << altura / 2 << "." << largura << endl;

		outfile.close();
		

    }
    
    
}

void plano(float comp, float altura, float largura){



	if (outfile.is_open() && outfile.good()) //verificamos se está tudo bem
	{
		if (altura == 0){ //plano ZoX
			outfile << "Plano ZoX" << endl;
			outfile << comp / 2 << "." << altura << "." << largura / 2 << endl;
			outfile << comp / 2 << "." << altura << "." << -largura / 2 << endl;
			outfile << -comp / 2 << "," << altura << "," << largura / 2 << endl;
			//segundo triangulo
			outfile << -comp / 2 << "," << altura << "," << largura / 2 << endl;
			outfile << comp / 2 << "." << altura << "." << -largura / 2 << endl;
			outfile << -comp / 2 << "." << altura << "." << -largura / 2 << endl;

			outfile.close();
		}
		if (comp == 0){ //plano ZoY
			outfile << "Plano ZoY" << endl;
			outfile << comp << "," << -altura / 2 << "," << -largura / 2 << endl;
			outfile << comp << "." << altura / 2 << "." << -largura / 2 << endl;
			outfile << comp << "." << -altura / 2 << "." << +largura / 2 << endl;
			//segundotriangulo
			outfile << comp << "," << -altura / 2 << "," << largura / 2 << endl;
			outfile << comp << "." << altura / 2 << "." << -largura / 2 << endl;
			outfile << comp << "." << altura / 2 << "." << largura / 2 << endl;

			outfile.close();
		}
		if (largura == 0){ //plano XoY
			outfile << "Plano XoY" << endl;
			outfile << -comp / 2 << "," << -altura / 2 << "," << largura << endl;
			outfile << comp / 2 << "." << -altura / 2 << "." << largura << endl;
			outfile << comp / 2 << "." << altura / 2 << "." << largura << endl;
			//segundotriangulo
			outfile << -comp / 2 << "," << -altura / 2 << "," << largura << endl;
			outfile << comp / 2 << "." << altura / 2 << "." << largura << endl;
			outfile << -comp / 2 << "." << altura / 2 << "." << largura << endl;

			outfile.close();
		}
	}
}
    

  




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
    
}

int main(int argc, const char * argv[]) {
    
	
    
    if((strcmp("paralelipipedo",argv[1]))==0){
        
        outfile.open("paralelipipedo.3d");
        float x = (float)atoi(argv[2]);
		float y = (float)atoi(argv[3]);
		float z = (float)atoi(argv[4]);
        paralelipipedo(x,y,z);
        
    }
    
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

	}
    if((strcmp("plano",argv[1]))==0){
        outfile.open("plano.3d");
		float x = (float)atoi(argv[2]);
		float y = (float)atoi(argv[3]);
		float z = (float)atoi(argv[4]);
        plano(x,y,z);
        
    }
}
