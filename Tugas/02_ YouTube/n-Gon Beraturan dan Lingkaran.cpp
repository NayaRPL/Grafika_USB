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
    
//    
//    // Menggambar strip dengan GL_LINE_STRIP
//    glBegin(GL_LINE_STRIP);
//        glVertex2i(20,10);
//        glVertex2i(50,10);
//        glVertex2i(20,80);
//        glVertex2i(50,80); // Menghubungkan kembali ke titik awal untuk membentuk strip
//    glEnd();
    
//     glBegin(GL_LINE_LOOP);
//        glVertex2i(20,10);
//        glVertex2i(50,10);
//        glVertex2i(20,80);
//        glVertex2i(50,80); 
//    glEnd();

//  menggunakan manual
//	glBegin(GL_LINE_LOOP);
////		    glVertex2f(40 * cos(2*3.14 * 1/6),40*sin(2*3.14 * 1/6));
////		    glVertex2f(40 * cos(2*3.14 * 2/6),40*sin(2*3.14 * 2/6));
////			glVertex2f(40 * cos(2*3.14 * 3/6),40*sin(2*3.14 * 3/6));
////			glVertex2f(40 * cos(2*3.14 * 4/6),40*sin(2*3.14 * 4/6));
////			glVertex2f(40 * cos(2*3.14 * 5/6),40*sin(2*3.14 * 5/6));
////			glVertex2f(40 * cos(2*3.14 * 6/6),40*sin(2*3.14 * 6/6));
//			ngon(6,10,0,40,180);
//    glEnd();

// menggunakan fungsi


    glBegin(GL_LINE_LOOP);
    ngon(8, 0, 0, 60, 45); // Menggambar heksagon dengan radius 40 dan pusat (0,0)
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
