//
//  View.c
//  GLUTStroke
//
//  Created by Laura del Pino Díaz on 1/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"



void Init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void ReshapeSize(int ancho, int alto){
    
    float dx = gl_width;
    float dy = gl_height;
    
    dx *= (float)ancho / (float)w_width;
    dy *= (float)alto / (float)w_height;
    
    glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_near, gl_far); // espacio de trabajo
    glutPostRedisplay();
}


void Display(){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angle, 0, 0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glRectf(-0.5, -0.5, 0.5, 0.5);
    glFlush();
    
    glutSwapBuffers();
}

void Timer(int v){
    if (rotating) {
        angle += angle_perstep*sense;
        if(angle > 360.0) angle -=360.0;
        if(angle < -360.0) angle +=360.0;
        glutPostRedisplay();
    }
    glutTimerFunc(1000/steps_persecond, Timer, v);
}

void Mouse(int button, int state, int x, int y){

    if(state != GLUT_DOWN) return;
    
    switch (button) {
        case GLUT_LEFT_BUTTON:
            rotating = GL_TRUE;
            sense = 1;
            break;
            
        case GLUT_RIGHT_BUTTON:
            rotating = GL_TRUE;
            sense = -1;
            break;
        case GLUT_MIDDLE_BUTTON:
            rotating = GL_FALSE;
            break;
    }

}