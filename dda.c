//Autor: José Armando Alarcón
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i((int)round(x), (int)round(y));
        printf("Point (%d, %d)\n", (int)round(x), (int)round(y));
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);

    // Dibuja todas las líneas ingresadas
    // Este es solo un ejemplo, podrías almacenar las coordenadas en una lista o arreglo para manejar múltiples líneas
    dda(2, 1, 8, 5);
    

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();

    return 0;
}




