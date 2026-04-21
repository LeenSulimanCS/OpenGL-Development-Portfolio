#include<windows.h> 
#include<GL/glut.h> 
void Quad() { 
 glClear(GL_COLOR_BUFFER_BIT); 
 glLineWidth(10);   
 glBegin(GL_QUADS); 
 glColor3f(1.0, 0.5, 0.0);         
 glVertex2f(200, 200); 
 glVertex2f(200, 600); 
 glVertex2f(600, 600); 
 glVertex2f(600, 200); 
 glEnd(); 
 glFlush(); 
} 
void Initial() { 
 glClearColor(1, 1, 1, 0); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 gluOrtho2D(0, 700, 0, 800); 
} 
int main() { 
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutInitWindowSize(400, 400); 
 glutInitWindowPosition(0, 0); 
 glutCreateWindow("My Orange Square”"); 
 Initial(); 
 glutDisplayFunc(Quad); 
 glutMainLoop(); 
 return 0; 
}