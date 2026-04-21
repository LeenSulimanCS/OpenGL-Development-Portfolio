#include<windows.h> 
#include<GL/glut.h> 
void DrawLine() { 
 glClear(GL_COLOR_BUFFER_BIT); 
 glEnable(GL_LINE_STIPPLE); //Determining the Line Type. 
 glLineWidth(5); 
 glLineStipple(1, 0XAAAA); //Factor and Pattern. 
 glBegin(GL_LINES); 
 glVertex2d(200, 400); 
 glVertex2d(500, 400); 
 glEnd(); 
 glDisable(GL_LINE_STIPPLE); //Disabling the Line Type. 
 glFlush(); 
} 
void Initial() { 
 glClearColor(1.0, 0.0, 0.0, 0.0); 
 glColor3f(1, 1, 1); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 gluOrtho2D(0, 600, 0, 800); 
} 
int main() { 
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutInitWindowSize(400, 400); 
 glutInitWindowPosition(0, 0); 
 glutCreateWindow("My White Stipple Line"); 
 Initial(); 
 glutDisplayFunc(DrawLine); 
 glutMainLoop(); 
 return 0; 
}