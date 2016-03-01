//
//  View.h
//  GLUTStroke
//
//  Created by Laura del Pino Díaz on 1/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#ifndef View_h
#define View_h

#include <stdio.h>
#include <GLUT/glut.h>

#endif /* View_h */
#ifndef GLOBAL_VARS
extern GLboolean rotating;
extern int visualiza,w_width,w_height,steps_persecond,angle_perstep;
extern float gl_width,gl_height,gl_near,gl_far,sense;
extern GLfloat angle;
#endif

extern void Mouse(int button,int state, int x, int y);
extern void Timer(int value);
extern void Display();
extern void Init();
extern void ReshapeSize();