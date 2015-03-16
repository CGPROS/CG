//
//  main.cpp
//  Motor3D
//
//  Created by Rui Machado on 15/03/15.
//  Copyright (c) 2015 Rui Machado. All rights reserved.
//

#include <iostream>
#include "motor.h"
#include <GL/glut.h>

//Inicializaçoes Principais
TiXmlNode *cena=NULL;
int tipo_camera=0;


void changeSize(int w, int h){
    
    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;
    
    // compute window's aspect ratio
    float ratio = w * 1.0 / h;
    
    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();
    
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    
    // Set perspective
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    
    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}



int angx=0;
float coordx=0.0;
float coordy=0.0;
void renderScene(void) {
    
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // set the camera
    glLoadIdentity();
    
    /*if (tipo_camera==1)
        modo_explorador();
    else
        if (tipo_camera==2)
            modo_fps();
        else{*/
    
        gluLookAt(0.0,3.0,5.0,
                      0.0, 0.0, 0.0,
                      0.0f, 1.0f, 0.0f);
    
    
    
    // pÙr instruÁıes de desenho aqui
    glRotatef((GLfloat) angx, 0.0,1.0,0.0);
    glTranslatef((GLfloat) coordx, 0.0,0.0);
    glTranslatef((GLfloat) 0.0, coordy,0.0);
    glColor3f(0.0, 0.0,0.7f);
    motor_XML(cena);
    
    
    // End of frame
    glutSwapBuffers();
}



void tecla_normal(unsigned char key, int x,int y){
    
    if(key== 'r'){
        
        angx=(angx + 5)%360;
        
        
    }
    if(key=='l'){
        angx=(angx - 5)%360;
    }
	glutPostRedisplay();
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
	glutPostRedisplay();
    
}

//  
void front_menu(int op){
    switch (op) {
        case 1:
            glPolygonMode(GL_FRONT,GL_POINT);
            break;
        case 2:
            glPolygonMode(GL_FRONT,GL_LINE);
            break;
        case 3:
            glPolygonMode(GL_FRONT,GL_FILL);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    
    TiXmlDocument doc;
	TiXmlElement *root = NULL;
    
    if(argc!=2){
        printf("ERRO!! Número de argumentos errado, falta XML de input!\n");
        return 1;
    }
    
    
    if(doc.LoadFile(argv[1])){
		root = doc.RootElement();
		cena = root->FirstChild("cena");
        
        
        if (cena) {
            // inicializaÁ„o
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
            glutInitWindowPosition(100, 100);
            glutInitWindowSize(800, 800);
            glutCreateWindow("BananaCorp®");
            
            
            // pÙr registo de funÁıes aqui
            glutDisplayFunc(renderScene);
            glutReshapeFunc(changeSize);
            
            // funções do teclado e rato
            
            glutKeyboardFunc(tecla_normal);
            glutSpecialFunc(tecla_especial);
            
            
            
            
            //MENU
            glutCreateMenu(front_menu);
            glutAddMenuEntry("GL POINT",1);
            glutAddMenuEntry("GL LINE",2);
            glutAddMenuEntry("GL FILL",3);
          //  glutAddMenuEntry("Modo Explorador",4);
           // glutAddMenuEntry("Modo FPS",5);
            
            glutAttachMenu(GLUT_RIGHT_BUTTON);
            
            // alguns settings para OpenGL
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glClearColor(0.0f,0.0f,0.0f,0.0f);
            
            glPolygonMode(GL_FRONT, GL_LINE);
            
            // entrar no ciclo do GLUT
            glutMainLoop();
            
        }
        else
            printf("Falhou!! Sem tag 'cena' no XML!\n");
    }
    else
        printf("Falhou!! Não fez load do ficheiro!\n");
    
    return 0;
    
}