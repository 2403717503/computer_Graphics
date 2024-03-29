# Sutherland多边形裁剪和三维几何变换实验报告

## 学号：20201060378

## 实验目的
1. 掌握Sutherland多边形裁剪的原理
2. 掌握三维几何变换的原理
3. 熟悉三维几何变换矩阵

## 实验内容
使用opengl,给定多边形顶点，和裁剪窗口，对多边形进行裁剪
使用opengl，给定一个三维图形对它进行平移和旋转操作

## 输入数据
work9.cpp输入的多边形顶点坐标：(-300, -100),(-300, 150), (-100, 150),(100, 100),(100, 0),(0, -100),(-300, -100)

## 实现的功能
work9.cpp实现将给定的顶点连接成多边形，并用给定窗口对其进行裁剪，保留窗口内的部分，去掉窗口外的部分的功能
work9_1.cpp实现将给定的三维体，通过按键a,d,w,s,q,e实现左右上下外里平移0.1，按键j,l实现y轴旋转10度，按键i,k实现x轴旋转10度，按键u,o实现z轴旋转10度的功能

## 实验功能
多边形裁剪的图
![多边形裁剪的图](https://github.com/2403717503/computer_Graphics/raw/main/9.PNG)
三维体原图
![三维体原图](https://github.com/2403717503/computer_Graphics/raw/main/9.1.png)
三维体平移后的图
![平移后的图](https://github.com/2403717503/computer_Graphics/raw/main/9.2.png)
三维体旋转后的图
![旋转后的图](https://github.com/2403717503/computer_Graphics/raw/main/9.3.png)