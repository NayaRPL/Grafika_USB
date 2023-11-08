#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void reshape(int width, int height);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Segitiga dan Persegi");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    // membuat titik
		glBegin(GL_POINTS);
	    glVertex3i(1, 4, 0);
	    glVertex3i(5, 8, 0);
	    glEnd();
	    glutSwapBuffers();
	    
	// mengambarkan garis 
		glBegin(GL_LINES);
	    glVertex3i(1, 4, 0);
	    glVertex3i(5, 8, 0);
	     glVertex3i(6, -8, 0);
	    glEnd();
    
	// mengambarkan segitiga 
		glBegin(GL_TRIANGLES);
		    glVertex3i(1, 4, 0);
		    glVertex3i(5, 8, 0);
		    glVertex3i(6, -8, 0);
	    glEnd();
	    
	// mengambarkan kotak 
		glBegin(GL_QUADS);
		    glVertex3i(-7, 4, 0);
		    glVertex3i(-5, 3, 0);
		    glVertex3i(7, -8, 0);
		    glVertex3i(2, 6, 0);
	    glEnd();
	    
	// mengambarkan sudut banyak
		glBegin(GL_QUADS);
		    glVertex3i(-8, 4, 0);
		    glVertex3i(-7, 4, 0);
		    glVertex3i(-5, 3, 0);
		    glVertex3i(7, -8, 0);
		    glVertex3i(2, 6, 0);
	    glEnd();
	    
	    
	    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
