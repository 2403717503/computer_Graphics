#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>

 struct point{
    float x;
    float y;
}vertices [4]={{250,50},{550,150},{550,400},{250,250}};

typedef struct XET{
    float x;
    float dx;
    float yMax;
    struct XET *next;
}AET,NET;


void PolyScan(){
    int max_y=0;
    int len=4;
    AET *pAET=(AET *)malloc(sizeof(AET));
    NET *pNET[800];
    for(int i=0;i<len;i++){
            if(vertices[i].y>max_y){
                max_y=vertices[i].y;
            }
    }
    pAET->next=NULL;
    for(int i=0;i<=max_y;i++){
        pNET[i]=(NET *)malloc(sizeof(NET));
        pNET[i]->next=NULL;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4,0.6,0.2);
    glBegin(GL_POINTS);
    for(int i=0;i<=max_y;i++){
        for(int j=0;j<len;j++){
            if(i==vertices[j].y){
                if(vertices[(j-1+len)%len].y>vertices[j].y){
                    NET *p=(NET *)malloc(sizeof(NET));
                    p->x=vertices[j].x;
                    p->yMax=vertices[(j-1+len)%len].y;
                    float DX=vertices[(j-1+len)%len].x-vertices[j].x;
                    float DY=vertices[(j-1+len)%len].y-vertices[j].y;
                    p->dx=DX/DY;
                    p->next=pNET[i]->next;
                    pNET[i]->next=p;
                }
                if(vertices[(j+1+len)%len].y>vertices[j].y){
                    NET *p=(NET *)malloc(sizeof(NET));
                    p->x=vertices[j].x;
                    p->yMax=vertices[(j+1+len)%len].y;
                    float DX=vertices[(j+1+len)%len].x-vertices[j].x;
                    float DY=vertices[(j+1+len)%len].y-vertices[j].y;
                    p->dx=DX/DY;
                    p->next=pNET[i]->next;
                    pNET[i]->next=p;
                }
            }
        }
    }
    for(int i=0;i<=max_y;i++){
        NET *p=pAET->next;
        while(p){
            p->x=p->x+p->dx;
            p=p->next;
        }
        AET *tq=pAET;
        p=pAET->next;
        tq->next=NULL;
        while(p){
            while(tq->next!=NULL&&tq->next->x<=p->x){
                tq=tq->next;
            }
            NET *t=p->next;
            p->next=tq->next;
            tq->next=p;
            p=t;
            tq=pAET;
        }
       AET *q=pAET;
        p=q->next;
        while(p){
            if(p->yMax==i){
                q->next=p->next;
                delete p;
                p=q->next;
            }else{
                q=q->next;
                p=q->next;
            }
        }
        p=pNET[i]->next;
        q=pAET;
        while(p){
            while(q->next&&p->x>=q->next->x){
                q=q->next;
            }
            NET *t=p->next;
            p->next=q->next;
            q->next=p;
            p=t;
            q=pAET;
        }
        p=pAET->next;
        while(p&&p->next!=NULL){
            for(float j=p->x;j<=p->next->x;j++){
                glVertex2i(j,i);
            }
            p=p->next->next;
        }
    }
    glEnd();
    glFlush();
}

void Init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,600.0,0.0,450.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2);
    glPointSize(1);
    glBegin(GL_POINTS);
    PolyScan();
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("X射线扫描算法");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
