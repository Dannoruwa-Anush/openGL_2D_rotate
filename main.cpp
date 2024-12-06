#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

GLfloat d = 0; //Global variable (angle)

void myInit(){
    glClearColor(0,0,0,1); //R G B Transparency (background color)
    glColor3f(1,0,0); //set to RED (drawing color)
}

void mySpin(){
  d = d + 0.05;
  if(d > 360){
    d = 0;
  }
  glutPostRedisplay();
}

void drawSquare(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[]){
    glBegin(GL_POLYGON); //group data points as a single object
        glVertex2fv(V0); //data point 1
        glVertex2fv(V1); //data point 2
        glVertex2fv(V2); //data point 3
        glVertex2fv(V3); //data point 4
    glEnd();
}

void displayMe(void)
{
    GLfloat v[4][2] = {
                            {-0.5,  0.5},
                            { 0.5,  0.5},
                            { 0.5, -0.5},
                            {-0.5, -0.5},
                        };

    glClear(GL_COLOR_BUFFER_BIT); //clear the background

    //------[Start : rotation coordinates and angle]-------
    GLfloat rv[4][2]; //rotated vertex
    GLfloat r = d * 3.14/180; //angle in radius

    int i;
    for(i=0; i<4; i++){
       rv[i][0] =  v[i][0] * cos(r) - v[i][1] * sin(r);//x'
       rv[i][1] =  v[i][0] * sin(r) + v[i][1] * cos(r);//y'
    }
    //------[End : rotation coordinates and angle]---------
    drawSquare(rv[0], rv[1], rv[2], rv[3]);

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Basic OpenGL - 2D");
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //RGB | 2D
    myInit();

    glutDisplayFunc(displayMe);
    glutIdleFunc(mySpin); //Idle function
    glutMainLoop();
    return 0;
}
