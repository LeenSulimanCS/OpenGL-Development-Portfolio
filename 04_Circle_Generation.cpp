#include<windows.h> 
#include<GL/glut.h> 
#include<math.h> 
void Circle() { 
 GLfloat xi, yi, theta = 0; 
 GLfloat x_c = 0, y_c = 0, r = 0.8; 
 int COUNT; 
 glClear(GL_COLOR_BUFFER_BIT); 
 for (COUNT = 1; COUNT <= 10000; COUNT++) { 
  theta = theta + 0.001; 
  xi = x_c + r * cos(theta); 
  yi = y_c + r * sin(theta); 
  glBegin(GL_POINTS); 
  glVertex2f(xi, yi); 
  glEnd(); 
 } 
 glFlush(); 
} 
void Initial() { 
 glClearColor(1.0, 1.0, 0, 1.0); 
 glColor3f(0, 0, 1); 
 glPointSize(16.0); 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
} 
int main() { 
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
 glutInitWindowSize(400, 400); 
 glutInitWindowPosition(0, 0); 
 glutCreateWindow("My Circle"); 
 Initial(); 
 glutDisplayFunc(Circle); 
 glutMainLoop(); 
 return 0; 
}