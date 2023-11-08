#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>>

void init(void);
void display(void);
void reshape(int width, int height);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Segitiga, Persegi, dan Strip");
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
    gluOrtho2D(-200.0, 200.0, -200.0, 100.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle) {
    double angle, angleInc;
    int k;

    if (n < 3) return;
    angle = rotAngle * 3.14 / 180;
    angleInc = 2 * 3.14 / n;

    // titik pertama
    glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

    // titik berikutnya
    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    

// 	perulangan untuk membuat lingkaran 
	for(int a=60 ; a>=30 ; a-=10){
		
	    glBegin(GL_LINE_LOOP);		 
				ngon(500,0,0,a,45);
	    glEnd();
	}

// 
//// untuk penuruanan segi 
	int segi = 6;
	for(int a=60 ; a>=30 ; a-=10){
		
	    glBegin(GL_LINE_LOOP);		 
				ngon(segi,0,0,a,45);
				segi--;
	    glEnd();
	}


// 	perulangan untuk membuat percangan 
	int segi = 6;
	for(int a=60 ; a>=30 ; a-=10){	
		if(segi %2 == 0){
			glBegin(GL_LINE_LOOP);	
				glColor3f(1.0,0.0,0.0);	 
				ngon(segi,0,0,a,45);
	        glEnd();
		}else{
			glBegin(GL_LINE_LOOP);
				glColor3f(0.0,0.0,1.0)	; 		 
				ngon(segi,0,0,a,45);
	        glEnd();
		}
	   	segi --;
	}

//  menggunakan array untuk mengambar
	int data [3][2] = {{0,-40},{0,40},{80,80}};
	glBegin(GL_LINE_LOOP);
		for(int s=0; s<3; s++){
			glColor3f(1.0,0.0,1.0);
			glVertex2i(data[s][0], data[s][1]);
		}
	glEnd();

    
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
