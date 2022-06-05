#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

int xs,ys,xe,ye;

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

void setPixel(GLint x,GLint y){
    glColor3f(0.7,0.3,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void lineBres(void){
    int dx=xe-xs;
    int dy=ye-ys;
    int p=2*dy-dx;
    int x,y;
    int twoDy=2*dy;
    int twoDyMinusDx=2*(dy-dx);
    if(xs>xe){
        x=xe;
        y=ye;
        xe=xs;
    }
    else{
        x=xs;
        y=ys;
    }
    setPixel(x,y);
    while(x<xe){
        x++;
        if(p<0){
            p=p+twoDy;
        }
        else{
            y++;
            p=p+twoDyMinusDx;
        }
        setPixel(x,y);
    }
}

int main(int argc,char **argv){
    printf("请输入点(x0,y0)的坐标(输入两个数，中间空格隔开,输入完毕回车):");
    scanf("%d%d",&xs,&ys);
    printf("请输入点(xEnd,yEnd)的坐标(输入两个数，中间空格隔开，输入完毕回车):");
    scanf("%d%d",&xe,&ye);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Bresenham算法画直线段");

    init();
    glutDisplayFunc(lineBres);
    glutMainLoop();
    return 0;
}