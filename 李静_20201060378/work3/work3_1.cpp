  #include<Windows.h>
  #include <cmath>
  # include <stdlib.h>
  # include <stdio.h>
  #include <GL/glut.h>

  int xa,ya,xb,yb;


  void DrawLine() {
       int dx = xb - xa;
       int dy = yb - ya;
       int e = 0;
       glClear(GL_COLOR_BUFFER_BIT);
       glColor3f(1.0, 0.0, 0.0);//点的颜色
       glBegin(GL_POINTS);//以点的形式画图
       if (dx*dy > 0) { //k>0
           dx = abs(dx);
           dy = abs(dy);
           if (dx > dy) { //最大位移方向为x
               if (xa > xb) { //当最大位移方向的0值比1值大时，要交换点
                   int temp = 0;
                  temp = xa;
                  xa = xb;
                  xb = temp;
                  temp = ya;
                  ya = yb;
                  yb = temp;
               }
               e = -dx;
               int x = xa, y = ya;
               glVertex2i(x, y);
               while (x < xb) {
                   e += 2 * dy;
                   x++;
                   if (e > 0) {
                       y++;
                       e -= 2 * dx;
                   }
                   glVertex2i(x, y);
               }
               glEnd();glFlush();
           }
           else {//最大位移方向为y
               if (ya > yb) { //当最大位移方向的0值比1值大时，要交换点
                  int temp = 0;
                  temp = xa;
                  xa = xb;
                  xb = temp;
                  temp = ya;
                  ya = yb;
                  yb = temp;;
               }
               e = -dy;
               int x = xa, y = ya;
               glVertex2i(x, y);
               while (y < yb) {
                   e += 2 * dx;
                   y++;
                   if (e > 0) {
                       x++;
                       e -= 2 * dy;
                   }
                   glVertex2i(x, y);
               }
               glEnd();
               glFlush();
           }
       }
       else { //k<0
           if (abs(dx) > abs(dy)) {//最大位移方向为x
               dx = abs(dx);
               dy = -1*abs(dy);
               if (xa > xb) { //当最大位移方向的0值比1值大时，要交换点
                   int temp = 0;
                   temp = xa;
                   xa = xb;
                   xb = temp;
                  temp = ya;
                  ya = yb;
                  yb = temp;
               }
               e = -dx;
               int x = xa, y = ya;
               glVertex2i(x, y);
               while (x < xb) {
                   e -= 2 * dy;
                   x++;
                   if (e > 0) {
                       y--;
                       e -= 2 * dx;
                   }
                   glVertex2i(x, y);
               }
               glEnd();glFlush();
           }
           else {//最大位移方向为y
               dx = -1 * abs(dx);
               dy = abs(dy);
               if (ya > yb) { //当最大位移方向的0值比1值大时，要交换点
                   int temp = 0;
                   temp = xa;
                   xa = xb;
                   xb = temp;
                   temp = ya;
                   ya = yb;
                   yb = temp;
               }
               e = -dy;
               int x = xa, y = ya;
               glVertex2i(x, y);
               while (y < yb) {
                   e -= 2 * dx;
                   y++;
                   if (e > 0) {
                       x--;
                       e -= 2 * dy;
                   }
                   glVertex2i(x, y);
               }
               glEnd();glFlush();
           }
       }
}

int main(int argc, char** argv) {
       printf("依次输入xa,ya,xb,yb:");
       scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
       glutInit(&argc, argv);//glut初始化
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// 显示模式：双缓冲、RGBA
       glutInitWindowPosition(50, 100);
       glutInitWindowSize(400, 400);
       glutCreateWindow("Bresenham改进画直线段");
       glClearColor(1.0, 1.0, 1.0, 1.0);// 缓存清空后的颜色值
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();//恢复初始坐标系
       gluOrtho2D(-200, 200.0, -200, 200.0);
       glutDisplayFunc(DrawLine);
       // 通知开始GLUT的内部循环
       glutMainLoop();
       return 0;
}
