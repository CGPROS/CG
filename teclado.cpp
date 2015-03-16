//
//  teclado.cpp
//  Motor3D
//
//  Created by Rui Machado on 16/03/15.
//  Copyright (c) 2015 Rui Machado. All rights reserved.
//

#include "teclado.h"
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
int angx=0;
float coordx = 0;
float coordy = 0;


void tecla_normal(unsigned char key, int x,int y){

    if(key== 'r'){
    
        angx=(angx + 5)%360;
        
        
    }
    if(key=='l'){
        angx=(angx - 5)%360;
    }

}



void tecla_especial(int tecla,int x, int y){

    if(tecla== GLUT_KEY_UP){
        
        coordy=coordy+0.5;
        
    }
    if(tecla==GLUT_KEY_DOWN){
      coordy=coordy-0.5;
    }
    if(tecla==GLUT_KEY_LEFT){
        coordx=coordx-0.5;
    }
    if(tecla== GLUT_KEY_RIGHT){
        
        coordx=coordx+0.5;
        
    }

    
}


