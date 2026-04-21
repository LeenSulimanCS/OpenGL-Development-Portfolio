#include<windows.h> 
#include<GL/glut.h> 
void draw() 
{ 
 glClear(GL_COLOR_BUFFER_BIT); 
 glPointSize(12); 
 glBegin(GL_POINTS); 
 glVertex2d(200, 200); 
 glEnd(); 
 glFlush(); 
} 
void Initial() { 
 glClearColor(1.0, 0.0, 0.0, 0.0); 
 glColor3f(0.0, 0.0, 1.0); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 gluOrtho2D(0, 600, 0, 800); 
} 
int main() { 
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutInitWindowSize(400, 400); 
 glutInitWindowPosition(0, 0); 
 glutCreateWindow("My Blue Point"); 
 Initial(); 
 glutDisplayFunc(draw); 
 glutMainLoop(); 
 return 0; 
} 