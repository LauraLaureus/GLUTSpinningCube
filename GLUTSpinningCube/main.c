//
//  main.c
//  GLUTStroke
//
//  Created by Laura del Pino Díaz on 1/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//
#include "View.h"

int win1;
int menu1,menu2,menu3;

int w_width = 500,w_height = 500;
float gl_width = 2.0,gl_height = 2.0,gl_near = -1.0,gl_far =5.0;
GLboolean  rotating = GL_FALSE;
int angle_perstep = 1,steps_persecond =50;
float sense =1.0;
GLfloat angle = 0.0;



int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutCreateWindow("OpenGL Practica 3_3  Laura del Pino Díaz");
    Init();
    glutDisplayFunc(Display); // define la funcion de rendering
    glutReshapeFunc(ReshapeSize);
    glutTimerFunc(100, Timer, 0);
    glutMouseFunc(Mouse);
    
   
    glutMainLoop();
    
    return 0;
}

