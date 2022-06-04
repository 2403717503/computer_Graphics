#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

static int xa,ya,xb,yb;

inline int round(const float a){
    return (int)(a+0.5);
}

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}


void setPixel(GLint x,GLint y){
    glColor3f(0.8,0.1,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}


void lineDDA(){
    float xIncrement,yIncrement;
    float steps;
    float x=xa;
    float y=ya;
    int dx=xb-xa;
    int dy=yb-ya;
    if(fabs(dx)>fabs(dy)){
         steps=fabs(dx);
    }
    else{
         steps=fabs(dy);
    }
    xIncrement=(float)(dx)/(float)(steps);
    yIncrement=(float)(dy)/(float)(steps);

    setPixel(round(x),round(y));
    for(int k=0;k<steps;k++){
        x=x+xIncrement;
        y=y+yIncrement;
        setPixel(round(x),round(y));
    }
}

int main(int argc,char **argv){
    printf("请输入点(x0,y0)的坐标(输入两个数，中间空格隔开,输入完毕回车):");
    scanf("%d%d",&xa,&ya);
    printf("请输入点(x1,y1)的坐标(输入两个数，中间空格隔开，输入完毕回车):");
    scanf("%d%d",&xb,&yb);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("DDA算法画直线段");

    init();
    glutDisplayFunc(lineDDA);
    glutMainLoop();
    return 0;
}
