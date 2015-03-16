//
//  motor.cpp
//  Motor3D
//
//  Created by Rui Machado on 15/03/15.
//  Copyright (c) 2015 Rui Machado. All rights reserved.
//
#include "tinyxml\tinyxml.h"
#include "tinyxml\tinystr.h"
#include <GL/glut.h>
#include <fstream>
#include <string>
#include "motor.h"
using namespace std;
/*
void lerDesenha(const char* filename){
    
    float cx,cy,cz;
    FILE *f = fopen(filename, "r");
    if(f){
        glBegin(GL_TRIANGLES);
        while (fscanf(f, "%f %f %f\n", &cx, &cy, &cz)!=EOF){
            glVertex3f(cx, cy, cz);
			printf("%f %f %f\n", cx, cy, cz);

        }
        glEnd();
        fclose(f);
    }else
        printf("ERRO! Não fez load do ficheiro '%s'!\n",filename);
    
}
*/


void lerDesenha(const char* fich) {
    
    //declarar e abrir o ficheiro
    ifstream input_file(fich);
    
    if (!input_file) {
        //ocorreu um erro
        // return -1;
    }
    
    string line;
    float x, y, z;
    
    glBegin(GL_TRIANGLES);
	while (input_file >> x >> y >> z){
        glVertex3f(x, y, z);
        printf("%f %f %f\n", x, y, z);
    }
	glEnd();
}


void motor_XML(TiXmlNode* root){
    
    TiXmlNode *child;
    TiXmlAttribute * attr;
    const char* tag;
  
    for (child = root->FirstChild(); child; child=child->NextSibling()) {
        tag=child->Value();
        
        if (strcmp(tag, "modelo")==0) {
            attr=child->ToElement()->FirstAttribute();
            if (strcmp(attr->Name(), "ficheiro")==0) {
                lerDesenha(attr->Value());
            }    }
    }}