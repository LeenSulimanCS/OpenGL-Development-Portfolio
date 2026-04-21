#include <GL/glut.h> 
float angle = 0.0f; 
float rotationSpeed = 1.0f; 
float rotX = 0.0f, rotY = 1.0f;  
void init() { 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    glEnable(GL_DEPTH_TEST);  
} 
void drawColoredCube() { 
    glBegin(GL_QUADS);  
 
    glColor3f(1.0f, 0.0f, 1.0f);  
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
 
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f); 
 
    glColor3f(0.0f, 0.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
 
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
 
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
 
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
 
    glEnd();  
} 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity(); 
    gluLookAt(0, 3, 5, 0, 0, 0, 0, 1, 0);
 glRotatef(angle, rotX, rotY, 0.0f); 
    drawColoredCube(); 
    glutSwapBuffers();  
} 
void idle() { 
    angle += rotationSpeed;  
    if (angle > 360) angle -= 360; 
    glutPostRedisplay(); 
} 
void specialKeys(int key, int x, int y) { 
    switch (key) { 
    case GLUT_KEY_UP: 
        rotationSpeed += 0.1f; 
        break; 
    case GLUT_KEY_DOWN: 
        if (rotationSpeed > 0.1f) rotationSpeed -= 0.1f; 
        break; 
    case GLUT_KEY_RIGHT: 
        rotX = 0.0f; 
        rotY = 1.0f; 
        break; 
    case GLUT_KEY_LEFT: 
        rotX = 1.0f; 
        rotY = 0.0f; 
        break; 
    } 
} 
void reshape(int w, int h) { 
    glViewport(0, 0, w, h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f); 
} 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600); 
    glutCreateWindow("animated 3D cube"); 
    init(); 
    glutDisplayFunc(display);  
    glutReshapeFunc(reshape);  
    glutSpecialFunc(specialKeys);  
    glutIdleFunc(idle);  
    glutMainLoop(); 
    return 0; 
} 