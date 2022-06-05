#include <windows.h>
#include <stdio.h>
# include <math.h>
#include <GL/glut.h>
#define pi 3.14

typedef struct point{
    double x;
    double y;
    double z;
}Point;
Point point[]={{0,0,1},{25,25,1},{40,90,1}};
int selection;

void init (void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

void translation(){  //平移
    double a[3][3]={{1,0,0},{0,1,0},{30,20,1}};
    for(int i=0;i<3;i++){
        point[i].x=point[i].x*a[0][0]+point[i].y*a[1][0]+point[i].z*a[2][0];
        point[i].y=point[i].x*a[0][1]+point[i].y*a[1][1]+point[i].z*a[2][1];
        point[i].z=1;
    }
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2f(point[i].x,point[i].y);
    }
    glEnd();
    glFlush();
}

void scale(){//比例
    double a[3][3]={{2,0,0},{0,1.5,0},{0,0,1}};
    for(int i=0;i<3;i++){
        point[i].x=point[i].x*a[0][0]+point[i].y*a[1][0]+point[i].z*a[2][0];
        point[i].y=point[i].x*a[0][1]+point[i].y*a[1][1]+point[i].z*a[2][1];
        point[i].z=1;
    }
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2f(point[i].x,point[i].y);
    }
    glEnd();
    glFlush();
}

void transForm(){//对称
    double a[3][3]={{0,1,0},{1,0,0},{0,0,1}};
    for(int i=0;i<3;i++){
        point[i].x=point[i].x*a[0][0]+point[i].y*a[1][0]+point[i].z*a[2][0];
        point[i].y=point[i].x*a[0][1]+point[i].y*a[1][1]+point[i].z*a[2][1];
        point[i].z=1;
    }
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2f(point[i].x,point[i].y);
    }
    glEnd();
    glFlush();
}

void Rotate(){//旋转
    double a[3][3]={{cos(-pi/6),sin(-pi/6),0},{-(sin(-pi/6)),cos(-pi/6),0},{0,0,1}};
    for(int i=0;i<3;i++){
        point[i].x=point[i].x*a[0][0]+point[i].y*a[1][0]+point[i].z*a[2][0];
        point[i].y=point[i].x*a[0][1]+point[i].y*a[1][1]+point[i].z*a[2][1];
        point[i].z=1;
    }
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2f(point[i].x,point[i].y);
    }
    glEnd();
    glFlush();
}

void draw(){
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2f(point[i].x,point[i].y);
    }
    glEnd();
    glFlush();
}

void display_translation(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.6,0.4,0.0);
    draw();

    glColor3f(0.0,0.4,0.2);
    translation();
}

void display_transForm(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.6,0.4,0.0);
    draw();

    glColor3f(0.0,0.4,0.2);
    transForm();
}


void display_scale(){
     glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.6,0.4,0.0);
    draw();

    glColor3f(0.0,0.4,0.2);
    scale();
}

void display_Rotate(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.6,0.4,0.0);
    draw();

    glColor3f(0.0,0.4,0.2);
    Rotate();
}



int main(int argc,char **argv){
     printf("1.平移    2.缩放    3.对称  4.旋转  \n请输入要执行的操作(输入每个操作前的数字）：");
    scanf("%d",&selection);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
   switch(selection){
    case 1:
        glutCreateWindow("平移后的图");
         init();
         glutDisplayFunc(display_translation);
          glutMainLoop();
        break;
    case 2:
         glutCreateWindow("缩放后的图");
          init();
        glutDisplayFunc(display_scale);
          glutMainLoop();
        break;
    case 3:
         glutCreateWindow("对称后的图");
          init();
        glutDisplayFunc(display_transForm);
          glutMainLoop();
        break;
    case 4:
        glutCreateWindow("旋转后的图");
          init();
        glutDisplayFunc(display_Rotate);
          glutMainLoop();
    }
    return 0;
}
