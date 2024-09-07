#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <bits/stdc++.h>

using namespace std;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
   glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
    glFlush();
}

void displayTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float n ) {
    if (n > 0) {
        float x12=(x1+x2)/2;
        float y12=(y1+y2)/2;
        float x13=(x1+x3)/2;
        float y13=(y1+y3)/2;
        float x23=(x2+x3)/2;
        float y23=(y2+y3)/2;
        
        displayTriangle(x1,y1,x12,y12,x13, y13,n-1);
        displayTriangle(x12,y12,x2,y2,x23, y23,n-1);
        displayTriangle(x13,y13,x23,y23,x3, y3,n-1);
    } else {
        drawTriangle(x1, y1, x2, y2, x3, y3);
    }
}

void displayCircle(float h,float k,float a,float b) {
    glBegin(GL_POINTS);      
    float x = 0, y = b;  
    float fx = 0, fy = 2 * a * a * b;  
    float p = (b * b) - (a * a * b) + (0.25 * a * a);  
    while(fx < fy) { 
         glVertex2f(h + x, k + y); 
         glVertex2f(h - x, k + y); 
         glVertex2f(h - x, k - y); 
         glVertex2f(h + x, k - y); 
        if(p < 0){ 
            fx = fx + 2 * b * b; 
            p = p + fx + b * b; 
            x++; 
        } 
        if(p >= 0){ 
            fx = fx + 2 * b * b; 
            x++; 
            y--; 
            fy = fy - 2 * a * a; 
            p = p + fx + b * b - fy; 
        } 
    } 
    p = (b * b) * (x + .5) * (x + .5) + (a * a) * (y - 1) * (y - 1) - (a * a) * (b * b); 
    while(y >= 0){  
        glVertex2f(h + x, k + y); 
        glVertex2f(h - x, k + y); 
        glVertex2f(h - x, k - y); 
        glVertex2f(h + x, k - y); 
        if(p >= 0){ 
            y--; 
            fy = fy - 2 * a * a; 
            p = p - fy + a * a; 
        } 
        if(p < 0){ 
            y--; 
            x++; 
            fy = fy - 2 * a * a; 
            fx = fx + 2 * b * b; 
            p = p + fx - fy + a * a; 
        } 
    } 
    glEnd(); 
}


float rectx1, recty1, rectx2, recty2, rectx3, recty3, rectx4, recty4;

void hor(float ax, float ay, float bx, float by) {
    float dx = bx - ax;
    float dy = by - ay;
    glBegin(GL_POINTS);
    glVertex2f(ax, ay);
    glEnd();
    float di = 2 * dy - dx;
    for (int i = 0; i < abs(dx); i++) {
        if (di < 0) {
            ax += 1;
            di = di + 2 * dy;
        } else {
            ax += 1;
            ay += 1;
            di = di + 2 * dy - 2 * dx;
        }
        glBegin(GL_POINTS);
        glVertex2f(ax, ay);
        glEnd();
    }
    glFlush();
}

void ver(float ax, float ay, float bx, float by) {
    float dx = bx - ax;
    float dy = by - ay;
    glBegin(GL_POINTS);
    glVertex2f(ax, ay);
    glEnd();
    float di = 2 * dx - dy;
    for (int i = 0; i < abs(dy); i++) {
        if (di < 0) {
            ay += 1;
            di = di + 2 * dx;
        } else {
            ax += 1;
            ay += 1;
            di = di + 2 * dx - 2 * dy;
        }
        glBegin(GL_POINTS);
        glVertex2f(ax, ay);
        glEnd();
    }
    glFlush();
}

void display(void) {
    hor(rectx1, recty1, rectx2, recty2);
    ver(rectx2, recty2, rectx3, recty3);
    hor(rectx4, recty4, rectx3, recty3);
    ver(rectx1, recty1, rectx4, recty4);
    
    float width = abs(rectx2 - rectx1), height = abs(recty4 - recty1);
    
    // calculating the dimension and midpoint of Elipse.
    // w formula = x1 (coordindate of one corner) + width / 2
    // h = y1 + width / 2
    
    float circleX = rectx1 + (width / 2);
    float circleY = recty1 + (height / 2);
    float majorAxis = width / 2;
    float minorAxis = height / 2; 
    
     displayCircle(circleX, circleY, majorAxis , minorAxis );
     
     // calculating the triangle points on the arch of the ellipse.
     // point 1 -> bottom left,  2 -> bottom right, 3 -> top.
     // increase from a point by percentage -> (percentage (0.20 for 20%) * height (or width)).
     
    float triangleX1 = rectx1 + (0.05 * width), triangleY1 = (recty1 + (height / 2)) - (0.2 * height);
    float triangleX2 = rectx2 - (0.05 * width), triangleY2 = (recty2 + (height / 2)) - (0.2 * height);
    float triangleX3 = rectx1 + (width / 2) , triangleY3 = recty4;
     
     displayTriangle( triangleX1, triangleY1, triangleX2, triangleY2, triangleX3, triangleY3, 2); 
    
     glFlush();
}

void init(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    printf("Input values:\n");
    scanf("%f %f %f %f %f %f %f %f", &rectx1, &recty1, &rectx2, &recty2, &rectx3, &recty3, &rectx4, &recty4);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrilateral Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

