# include <windows.h>
# include <stdlib.h>
# include <GL/glut.h>

float theta=0.0;

void drawPyramid(){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,10.f,0.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f);
    glRotatef(theta,0.0f,1.0f,0.0f);
    drawPyramid();

    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,2.0,10.0);
}

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
}

void myKeyboard(unsigned char key,int x,int y){
    if(key=='a'||key=='A')
        theta+=5.0;
    if(key=='s'||key=='S')
        theta-=5.0;
    if(key=='c'||key=='C')
        exit(0);
    if(theta>360)
        theta-=360;
    if(theta<0)
        theta+=360;
    glutPostRedisplay();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("金字塔------A 键：顺时针旋转，S键：逆时针旋转，C键：退出");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    init();
    glutMainLoop();
}
