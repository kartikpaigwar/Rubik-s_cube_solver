#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string.h>
#define l .45
#define m .45
#define n -.45
using namespace std;
//rgbyow
 float speed=2.0;
 char mv2[300];

int solve[300];
int lmv;
int i4=0;int i5=0;
int count=0;
int cl[54];
int clsw[54];
int solve1=0;
float r1,g1,b1;
static int rotation=0;
int rotationcomplete=0;
static GLfloat theta=0.0;
static GLint axis=0;
static GLfloat p=0.0,q=0.0,r=0.0;
static GLint inverse=0;
//static GLfloat angle=0.0;
double rotate_y=0; 
double rotate_x=0;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void display();
void specialKeys();
void output(float x, float y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
int rgbval(int i)///////////////////////////////////////////assigning rgb val to c
{int c;
c=cl[i-1];
return (c);}

void clswfi()/////////////////////////////////////////////colour swap for front
{int jfrt=0;
cl[2]=clsw[0];
cl[5]=clsw[1];
cl[8]=clsw[2];
cl[1]=clsw[3];
cl[4]=clsw[4];
cl[7]=clsw[5];
cl[0]=clsw[6];
cl[3]=clsw[7];
cl[6]=clsw[8];
cl[44]=clsw[29];
cl[43]=clsw[32];
cl[42]=clsw[35];
cl[9]=clsw[42];
cl[12]=clsw[43];
cl[15]=clsw[44];
cl[47]=clsw[9];
cl[46]=clsw[12];
cl[45]=clsw[15];
cl[29]=clsw[45];
cl[32]=clsw[46];
cl[35]=clsw[47];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}
void clswri()
{
int jfrt=0;
cl[11]=clsw[9];
cl[14]=clsw[10];
cl[17]=clsw[11];
cl[16]=clsw[14];
cl[15]=clsw[17];
cl[12]=clsw[16];
cl[9]=clsw[15];
cl[10]=clsw[12];
cl[38]=clsw[2];
cl[41]=clsw[5];
cl[44]=clsw[8];
cl[24]=clsw[38];
cl[21]=clsw[41];
cl[18]=clsw[44];
cl[53]=clsw[18];
cl[50]=clsw[21];
cl[47]=clsw[24];
cl[2]=clsw[47];
cl[5]=clsw[50];
cl[8]=clsw[53];

for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}
void clswui()
{
int jfrt=0;
cl[38]=clsw[36];
cl[41]=clsw[37];
cl[44]=clsw[38];
cl[43]=clsw[41];
cl[42]=clsw[44];
cl[39]=clsw[43];
cl[36]=clsw[42];
cl[37]=clsw[39];
cl[27]=clsw[0];
cl[28]=clsw[1];
cl[29]=clsw[2];
cl[18]=clsw[27];
cl[19]=clsw[28];
cl[20]=clsw[29];
cl[9]=clsw[18];
cl[10]=clsw[19];
cl[11]=clsw[20];
cl[0]=clsw[9];
cl[1]=clsw[10];
cl[2]=clsw[11];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}
void clswdi()
{
int jfrt=0;
cl[47]=clsw[45];
cl[50]=clsw[46];
cl[53]=clsw[47];
cl[52]=clsw[50];
cl[51]=clsw[53];
cl[48]=clsw[52];
cl[45]=clsw[51];
cl[46]=clsw[48];
cl[15]=clsw[6];
cl[16]=clsw[7];
cl[17]=clsw[8];
cl[24]=clsw[15];
cl[25]=clsw[16];
cl[26]=clsw[17];
cl[35]=clsw[24];
cl[34]=clsw[25];
cl[33]=clsw[26];
cl[6]=clsw[33];
cl[7]=clsw[34];
cl[8]=clsw[35];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}

void clswli()
{int jfrt=0;
cl[29]=clsw[27];
cl[32]=clsw[28];
cl[35]=clsw[29];
cl[34]=clsw[32];
cl[33]=clsw[35];
cl[30]=clsw[34];
cl[27]=clsw[33];
cl[28]=clsw[30];
cl[45]=clsw[0];
cl[48]=clsw[3];
cl[51]=clsw[6];
cl[26]=clsw[45];
cl[23]=clsw[48];
cl[20]=clsw[51];
cl[42]=clsw[20];
cl[39]=clsw[23];
cl[36]=clsw[26];
cl[0]=clsw[36];
cl[3]=clsw[39];
cl[6]=clsw[42];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}

void clswbi()
{int jfrt=0;
cl[20]=clsw[18];
cl[23]=clsw[19];
cl[26]=clsw[20];
cl[25]=clsw[23];
cl[24]=clsw[26];
cl[21]=clsw[25];
cl[18]=clsw[24];
cl[19]=clsw[21];
cl[36]=clsw[11];
cl[37]=clsw[14];
cl[38]=clsw[17];
cl[33]=clsw[36];
cl[30]=clsw[37];
cl[27]=clsw[38];
cl[51]=clsw[27];
cl[52]=clsw[30];
cl[53]=clsw[33];
cl[17]=clsw[51];
cl[14]=clsw[52];
cl[11]=clsw[53];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}
void clswf()/////////////////////////////////////////////colour swap for front F
{int jfrt=0;
cl[6]=clsw[0];
cl[3]=clsw[1];
cl[0]=clsw[2];
cl[7]=clsw[3];
cl[4]=clsw[4];
cl[1]=clsw[5];
cl[8]=clsw[6];
cl[5]=clsw[7];
cl[2]=clsw[8];
cl[35]=clsw[42];
cl[32]=clsw[43];
cl[29]=clsw[44];
cl[42]=clsw[9];
cl[43]=clsw[12];
cl[44]=clsw[15];
cl[15]=clsw[45];
cl[12]=clsw[46];
cl[9]=clsw[47];
cl[45]=clsw[29];
cl[46]=clsw[32];
cl[47]=clsw[35];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}
void clswr()
{
int jfrt=0;
cl[15]=clsw[9];
cl[12]=clsw[10];
cl[9]=clsw[11];
cl[16]=clsw[12];
cl[10]=clsw[14];
cl[17]=clsw[15];
cl[14]=clsw[16];
cl[11]=clsw[17];
cl[2]=clsw[38];
cl[5]=clsw[41];
cl[8]=clsw[44];
cl[47]=clsw[2];
cl[50]=clsw[5];
cl[53]=clsw[8];
cl[24]=clsw[47];
cl[21]=clsw[50];
cl[18]=clsw[53];
cl[38]=clsw[24];
cl[41]=clsw[21];
cl[44]=clsw[18];

for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}
void clswu()
{
int jfrt=0;
cl[42]=clsw[36];
cl[39]=clsw[37];
cl[36]=clsw[38];
cl[43]=clsw[39];
cl[37]=clsw[41];
cl[44]=clsw[42];
cl[41]=clsw[43];
cl[38]=clsw[44];
cl[27]=clsw[18];
cl[28]=clsw[19];
cl[29]=clsw[20];
cl[0]=clsw[27];
cl[1]=clsw[28];
cl[2]=clsw[29];
cl[9]=clsw[0];
cl[10]=clsw[1];
cl[11]=clsw[2];
cl[18]=clsw[9];
cl[19]=clsw[10];
cl[20]=clsw[11];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}
void clswd()
{
int jfrt=0;
cl[51]=clsw[45];
cl[52]=clsw[48];
cl[53]=clsw[51];
cl[50]=clsw[52];
cl[47]=clsw[53];
cl[46]=clsw[50];
cl[45]=clsw[47];
cl[48]=clsw[46];
cl[35]=clsw[8];
cl[34]=clsw[7];
cl[33]=clsw[6];
cl[26]=clsw[35];
cl[25]=clsw[34];
cl[24]=clsw[33];
cl[17]=clsw[26];
cl[16]=clsw[25];
cl[15]=clsw[24];
cl[8]=clsw[17];
cl[7]=clsw[16];
cl[6]=clsw[15];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}

}

void clswl()
{int jfrt=0;
cl[33]=clsw[27];
cl[30]=clsw[28];
cl[27]=clsw[29];
cl[34]=clsw[30];
cl[28]=clsw[32];
cl[35]=clsw[33];
cl[32]=clsw[34];
cl[29]=clsw[35];
cl[26]=clsw[36];
cl[23]=clsw[39];
cl[20]=clsw[42];
cl[51]=clsw[20];
cl[48]=clsw[23];
cl[45]=clsw[26];
cl[6]=clsw[51];
cl[3]=clsw[48];
cl[0]=clsw[45];
cl[42]=clsw[6];
cl[39]=clsw[3];
cl[36]=clsw[0];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}

void clswb()
{int jfrt=0;
cl[24]=clsw[18];
cl[25]=clsw[21];
cl[26]=clsw[24];
cl[23]=clsw[25];
cl[20]=clsw[26];
cl[19]=clsw[23];
cl[18]=clsw[20];
cl[21]=clsw[19];
cl[11]=clsw[36];
cl[14]=clsw[37];
cl[17]=clsw[38];
cl[53]=clsw[11];
cl[52]=clsw[14];
cl[51]=clsw[17];
cl[33]=clsw[53];
cl[30]=clsw[52];
cl[27]=clsw[51];
cl[36]=clsw[33];
cl[37]=clsw[30];
cl[38]=clsw[27];
for(jfrt=0;jfrt<54;jfrt++)
{clsw[jfrt]=cl[jfrt];}
}
void zzero(int i,float a)   /////////////////////////////////////////////////z planes
{int c;
if (i<=54){
c=rgbval(i);/////////////////////////////////////////////////////////////////calling rgb function to give value to c
if(c==1)
{r1=1;g1=0;b1=0;}
if(c==2)
{r1=0;g1=1;b1=0;}
if(c==3)
{r1=1;g1=0.5;b1=0;}
if(c==4)
{r1=0;g1=0;b1=1;}
if(c==5)
{r1=1;g1=01;b1=0;}
if(c==6)
{r1=1;g1=1;b1=1;}}
else{r1=0.5;g1=0.5;b1=0.5;}
//Red F1
if (i==1 || i==21 || i==101|| i==201){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0-l, 0.9-m, -a-n);     				  
glVertex3f( 0-l, 0.6-m, -a-n);      
glVertex3f( 0.3-l, 0.6-m, -a-n);      
glVertex3f( 0.3-l, 0.9-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0-l, 0.9-m, -a-n);     				  
glVertex3f( 0-l, 0.6-m, -a-n);      
glVertex3f( 0.3-l, 0.6-m, -a-n);      
glVertex3f( 0.3-l, 0.9-m, -a-n);
glEnd();}

//Red F2
if (i==2 || i==20|| i==102|| i==202){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .3-l, 0.9-m, -a-n);     				  
glVertex3f( .3-l, 0.6-m, -a-n);      
glVertex3f( 0.6-l, 0.6-m, -a-n);      
glVertex3f( 0.6-l, 0.9-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .3-l, 0.9-m, -a-n);     				  
glVertex3f( .3-l, 0.6-m, -a-n);      
glVertex3f( 0.6-l, 0.6-m, -a-n);      
glVertex3f( 0.6-l, 0.9-m, -a-n);
glEnd();} 
//Red F3
if (i==3 || i==19|| i==103|| i==203){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .6-l, 0.9-m, -a-n);     				  
glVertex3f( .6-l, 0.6-m, -a-n);      
glVertex3f( 0.9-l, 0.6-m, -a-n);      
glVertex3f( 0.9-l, 0.9-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .6-l, 0.9-m, -a-n);     				  
glVertex3f( .6-l, 0.6-m, -a-n);      
glVertex3f( 0.9-l, 0.6-m, -a-n);      
glVertex3f( 0.9-l, 0.9-m, -a-n);
glEnd();}


//Red F4
if (i==4 || i==24|| i==104|| i==204){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0-l, 0.6-m, -a-n);     				  
glVertex3f( 0-l, 0.3-m, -a-n);      
glVertex3f( 0.3-l, 0.3-m, -a-n);      
glVertex3f( 0.3-l, 0.6-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0-l, 0.6-m, -a-n);     				  
glVertex3f( 0-l, 0.3-m, -a-n);      
glVertex3f( 0.3-l, 0.3-m, -a-n);      
glVertex3f( 0.3-l, 0.6-m, -a-n);
glEnd();}

//Red F5
if (i==5 || i==23|| i==105|| i==205){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .3-l, 0.6-m, -a-n);     				  
glVertex3f( .3-l, 0.3-m, -a-n);      
glVertex3f( 0.6-l, 0.3-m, -a-n);      
glVertex3f( 0.6-l, 0.6-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .3-l, 0.6-m, -a-n);     				  
glVertex3f( .3-l, 0.3-m, -a-n);      
glVertex3f( 0.6-l, 0.3-m, -a-n);      
glVertex3f( 0.6-l, 0.6-m, -a-n);
glEnd();}
 //Red F6
if (i==6 || i==22|| i==106|| i==206){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .6-l, 0.6-m, -a-n);     				  
glVertex3f( .6-l, 0.3-m, -a-n);      
glVertex3f( 0.9-l, 0.3-m, -a-n);      
glVertex3f( 0.9-l, 0.6-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .6-l, 0.6-m, -a-n);     				  
glVertex3f( .6-l, 0.3-m, -a-n);      
glVertex3f( 0.9-l, 0.3-m, -a-n);      
glVertex3f( 0.9-l, 0.6-m, -a-n);
glEnd();}
//Red F7
if (i==7 || i==27|| i==107|| i==207){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0-l, 0.3-m, -a-n);     				  
glVertex3f( 0-l, 0.0-m, -a-n);      
glVertex3f( 0.3-l, 0.0-m, -a-n);      
glVertex3f( 0.3-l, 0.3-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0-l, 0.3-m, -a-n);     				  
glVertex3f( 0-l, 0.0-m, -a-n);      
glVertex3f( 0.3-l, 0.0-m, -a-n);      
glVertex3f( 0.3-l, 0.3-m, -a-n);
glEnd();}

//Red F8
if (i==8 || i==26|| i==108|| i==208){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .3-l, 0.3-m, -a-n);     				  
glVertex3f( .3-l, 0.0-m, -a-n);      
glVertex3f( 0.6-l, 0.0-m, -a-n);      
glVertex3f( 0.6-l, 0.3-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .3-l, 0.3-m, -a-n);     				  
glVertex3f( .3-l, 0.0-m, -a-n);      
glVertex3f( 0.6-l, 0.0-m, -a-n);      
glVertex3f( 0.6-l, 0.3-m, -a-n);
glEnd();}

//Red F9
if (i==9 || i==25|| i==109|| i==209){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( .6-l, 0.3-m, -a-n);     				  
glVertex3f( .6-l, 0.0-m, -a-n);      
glVertex3f( 0.9-l, 0.0-m, -a-n);      
glVertex3f( 0.9-l, 0.3-m, -a-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( .6-l, 0.3-m, -a-n);     				  
glVertex3f( .6-l, 0.0-m, -a-n);      
glVertex3f( 0.9-l, 0.0-m, -a-n);      
glVertex3f( 0.9-l, 0.3-m, -a-n);
glEnd();}
}

void xzero(int i,float a)                                       //x planes
{int c;
if (i<=54){
c=rgbval(i);
if(c==1)
{r1=1;g1=0;b1=0;}
if(c==2)
{r1=0;g1=1;b1=0;}
if(c==3)
{r1=1;g1=0.5;b1=0;}
if(c==4)
{r1=0;g1=0;b1=1;}
if(c==5)
{r1=1;g1=01;b1=0;}
if(c==6)
{r1=1;g1=1;b1=1;}}
else{r1=0.5;g1=0.5;b1=0.5;}
//Green F10
if (i==10 || i==30|| i==110|| i==210){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.9-m, -0.9-n);     				  
glVertex3f( a-l, 0.6-m, -0.9-n);      
glVertex3f( a-l, 0.6-m, -0.6-n);      
glVertex3f( a-l, 0.9-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.9-m, -0.9-n);     				  
glVertex3f( a-l, 0.6-m, -0.9-n);      
glVertex3f( a-l, 0.6-m, -0.6-n);      
glVertex3f( a-l, 0.9-m, -0.6-n);
glEnd();}
//Green F11
if (i==11 || i==29|| i==111|| i==211){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.9-m, -0.6-n);     				  
glVertex3f( a-l, 0.6-m, -0.6-n);      
glVertex3f( a-l, 0.6-m, -0.3-n);      
glVertex3f( a-l, 0.9-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.9-m, -0.6-n);     				  
glVertex3f( a-l, 0.6-m, -0.6-n);      
glVertex3f( a-l, 0.6-m, -0.3-n);      
glVertex3f( a-l, 0.9-m, -0.3-n);
glEnd();}
//Green F12
if (i==12 || i==28|| i==112|| i==212){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.9-m, -0.3-n);     				  
glVertex3f( a-l, 0.6-m, -0.3-n);      
glVertex3f( a-l, 0.6-m, -0-n);      
glVertex3f( a-l, 0.9-m, -0-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.9-m, -0.3-n);     				  
glVertex3f( a-l, 0.6-m, -0.3-n);      
glVertex3f( a-l, 0.6-m, -0-n);      
glVertex3f( a-l, 0.9-m, -0-n);
glEnd();}
//Green F13
if (i==13 || i==33|| i==113|| i==213){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.6-m, -0.9-n);     				  
glVertex3f( a-l, 0.3-m, -0.9-n);      
glVertex3f( a-l, 0.3-m, -0.6-n);      
glVertex3f( a-l, 0.6-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.6-m, -0.9-n);     				  
glVertex3f( a-l, 0.3-m, -0.9-n);      
glVertex3f( a-l, 0.3-m, -0.6-n);      
glVertex3f( a-l, 0.6-m, -0.6-n);
glEnd();}
//Green F14
if (i==14 || i==32|| i==114|| i==214){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.6-m, -0.6-n);     				  
glVertex3f( a-l, 0.3-m, -0.6-n);      
glVertex3f( a-l, 0.3-m, -0.3-n);      
glVertex3f( a-l, 0.6-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.6-m, -0.6-n);     				  
glVertex3f( a-l, 0.3-m, -0.6-n);      
glVertex3f( a-l, 0.3-m, -0.3-n);      
glVertex3f( a-l, 0.6-m, -0.3-n);
glEnd();}
//Green F15
if (i==15 || i==31|| i==115|| i==215){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.6-m, -0.3-n);     				  
glVertex3f( a-l, 0.3-m, -0.3-n);      
glVertex3f( a-l, 0.3-m, -0-n);      
glVertex3f( a-l, 0.6-m, -0-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.6-m, -0.3-n);     				  
glVertex3f( a-l, 0.3-m, -0.3-n);      
glVertex3f( a-l, 0.3-m, -0-n);      
glVertex3f( a-l, 0.6-m, -0-n);
glEnd();}
//Green F16
if (i==16 || i==36|| i==116|| i==216){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.3-m, -0.9-n);     				  
glVertex3f( a-l, 0.0-m, -0.9-n);      
glVertex3f( a-l, 0.0-m, -0.6-n);      
glVertex3f( a-l, 0.3-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.3-m, -0.9-n);     				  
glVertex3f( a-l, 0.0-m, -0.9-n);      
glVertex3f( a-l, 0.0-m, -0.6-n);      
glVertex3f( a-l, 0.3-m, -0.6-n);
glEnd();}
//Green F17
if (i==17 || i==35|| i==117|| i==217){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.3-m, -0.6-n);     				  
glVertex3f( a-l, 0.0-m, -0.6-n);      
glVertex3f( a-l, 0.0-m, -0.3-n);      
glVertex3f( a-l, 0.3-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.3-m, -0.6-n);     				  
glVertex3f( a-l, 0.0-m, -0.6-n);      
glVertex3f( a-l, 0.0-m, -0.3-n);      
glVertex3f( a-l, 0.3-m, -0.3-n);
glEnd();}
//Green F18
if (i==18 || i==34|| i==118|| i==218){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( a-l, 0.3-m, -0.3-n);     				  
glVertex3f( a-l, 0.-m, -0.3-n);      
glVertex3f( a-l, 0.-m, -0-n);      
glVertex3f( a-l, 0.3-m, -0-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( a-l, 0.3-m, -0.3-n);     				  
glVertex3f( a-l, 0.-m, -0.3-n);      
glVertex3f( a-l, 0.-m, -0-n);      
glVertex3f( a-l, 0.3-m, -0-n);
glEnd();}
}
void yzero(int i,float a)                                       //y planes
{int c;
if (i<=54){
c=rgbval(i);
if(c==1)
{r1=1;g1=0;b1=0;}
if(c==2)
{r1=0;g1=1;b1=0;}
if(c==3)
{r1=1;g1=0.5;b1=0;}
if(c==4)
{r1=0;g1=0;b1=1;}
if(c==5)
{r1=1;g1=01;b1=0;}
if(c==6)
{r1=1;g1=1;b1=1;}}
else{r1=0.5;g1=0.5;b1=0.5;}
//Yellow 37
if (i==37 || i==52|| i==137|| i==237){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.-l, a-m, -0.3-n);     				  
glVertex3f( 0.-l, a-m, -0-n);      
glVertex3f( .3-l, a-m, -0-n);      
glVertex3f( .3-l, a-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.-l, a-m, -0.3-n);     				  
glVertex3f( 0.-l, a-m, -0-n);      
glVertex3f( .3-l, a-m, -0-n);      
glVertex3f( .3-l, a-m, -0.3-n);
glEnd();}

//Yellow 38
if (i==38 || i==53|| i==138|| i==238){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.3-l, a-m, -0.3-n);     				  
glVertex3f( 0.3-l, a-m, -0-n);      
glVertex3f( .6-l, a-m, -0-n);      
glVertex3f( .6-l, a-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.3-l, a-m, -0.3-n);     				  
glVertex3f( 0.3-l, a-m, -0-n);      
glVertex3f( .6-l, a-m, -0-n);      
glVertex3f( .6-l, a-m, -0.3-n);
glEnd();}

//Yellow 39
if (i==39 || i==54|| i==139|| i==239){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.6-l, a-m, -0.3-n);     				  
glVertex3f( 0.6-l, a-m, -0-n);      
glVertex3f( .9-l, a-m, -0-n);      
glVertex3f( .9-l, a-m, -0.3-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.6-l, a-m, -0.3-n);     				  
glVertex3f( 0.6-l, a-m, -0-n);      
glVertex3f( .9-l, a-m, -0-n);      
glVertex3f( .9-l, a-m, -0.3-n);
glEnd();}

//Yellow 40
if (i==40 || i==49|| i==140|| i==240){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.-l, a-m, -0.6-n);     				  
glVertex3f( 0.-l, a-m, -0.3-n);      
glVertex3f( .3-l, a-m, -0.3-n);      
glVertex3f( .3-l, a-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.-l, a-m, -0.6-n);     				  
glVertex3f( 0.-l, a-m, -0.3-n);      
glVertex3f( .3-l, a-m, -0.3-n);      
glVertex3f( .3-l, a-m, -0.6-n);
glEnd();}

//Yellow 41
if (i==41 || i==50|| i==141|| i==241){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.3-l, a-m, -0.6-n);     				  
glVertex3f( 0.3-l, a-m, -0.3-n);      
glVertex3f( .6-l, a-m, -0.3-n);      
glVertex3f( .6-l, a-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.3-l, a-m, -0.6-n);     				  
glVertex3f( 0.3-l, a-m, -0.3-n);      
glVertex3f( .6-l, a-m, -0.3-n);      
glVertex3f( .6-l, a-m, -0.6-n);
glEnd();}

//Yellow 42
if (i==42 || i==51|| i==142|| i==242){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.6-l, a-m, -0.6-n);     				  
glVertex3f( 0.6-l, a-m, -0.3-n);      
glVertex3f( .9-l, a-m, -0.3-n);      
glVertex3f( .9-l, a-m, -0.6-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.6-l, a-m, -0.6-n);     				  
glVertex3f( 0.6-l, a-m, -0.3-n);      
glVertex3f( .9-l, a-m, -0.3-n);      
glVertex3f( .9-l, a-m, -0.6-n);
glEnd();}

//Yellow 43
if (i==43 || i==46|| i==143|| i==243){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.-l, a-m, -0.9-n);     				  
glVertex3f( 0.-l, a-m, -0.6-n);      
glVertex3f( .3-l, a-m, -0.6-n);      
glVertex3f( .3-l, a-m, -0.9-n);
glEnd();
glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.-l, a-m, -0.9-n);     				  
glVertex3f( 0.-l, a-m, -0.6-n);      
glVertex3f( .3-l, a-m, -0.6-n);      
glVertex3f( .3-l, a-m, -0.9-n);
glEnd();}

//Yellow 44
if (i==44 || i==47|| i==144|| i==244){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.3-l, a-m, -0.9-n);     				  
glVertex3f( 0.3-l, a-m, -0.6-n);      
glVertex3f( .6-l, a-m, -0.6-n);      
glVertex3f( .6-l, a-m, -0.9-n);
glEnd();glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.3-l, a-m, -0.9-n);     				  
glVertex3f( 0.3-l, a-m, -0.6-n);      
glVertex3f( .6-l, a-m, -0.6-n);      
glVertex3f( .6-l, a-m, -0.9-n);
glEnd();}

//Yellow 45
if (i==45 || i==48|| i==145|| i==245){
glBegin(GL_POLYGON);
glColor3f(  r1,  g1,  b1 );
glVertex3f( 0.6-l, a-m, -0.9-n);     				  
glVertex3f( 0.6-l, a-m, -0.6-n);      
glVertex3f( .9-l, a-m, -0.6-n);      
glVertex3f( .9-l, a-m, -0.9-n);
glEnd();glLineWidth(3.0);
glColor3f(.0, .0, 0.);
glBegin(GL_LINE_LOOP);
glVertex3f( 0.6-l, a-m, -0.9-n);     				  
glVertex3f( 0.6-l, a-m, -0.6-n);      
glVertex3f( .9-l, a-m, -0.6-n);      
glVertex3f( .9-l, a-m, -0.9-n);
glEnd();}

}

////////////////////////////////////////////////////////////////////////CUBES
void cube1(){
zzero(1,0.9);zzero(101,0.6);
yzero(43,0.9);yzero(143,0.6);
xzero(30,0);xzero(210,0.3);}
void cube2(){
zzero(2,0.9);zzero(102,0.6);
yzero(44,0.9);yzero(144,0.6);
xzero(210,0.3);xzero(110,0.6);}
void cube3(){
zzero(3,0.9);zzero(103,0.6);
yzero(45,0.9);yzero(145,0.6);
xzero(110,0.6);xzero(10,0.9);}
void cube4(){
zzero(4,0.9);zzero(104,0.6);
yzero(143,0.6);yzero(243,0.3);
xzero(33,0);xzero(213,0.3);}
void cube5(){
zzero(5,0.9);zzero(105,0.6);
yzero(144,0.6);yzero(244,0.3);
xzero(213,0.3);xzero(113,0.6);}
void cube6(){
zzero(6,0.9);zzero(106,0.6);
yzero(145,0.6);yzero(245,0.3);
xzero(113,0.6);xzero(13,0.9);}
void cube7(){
zzero(7,0.9);zzero(107,0.6);
yzero(243,0.3);yzero(46,0);
xzero(36,0);xzero(216,0.3);}
void cube8(){
zzero(8,0.9);zzero(108,0.6);
yzero(244,0.3);yzero(47,0);
xzero(216,0.3);xzero(116,0.6);}
void cube9(){
zzero(9,0.9);zzero(109,0.6);
yzero(245,0.3);yzero(48,0);
xzero(116,0.6);xzero(16,0.9);}
void cube10(){
zzero(101,0.6);zzero(201,0.3);
yzero(40,0.9);yzero(140,0.6);
xzero(29,0);xzero(211,0.3);}
void cube11(){
zzero(102,0.6);zzero(202,0.3);
yzero(41,0.9);yzero(141,0.6);
xzero(211,0.3);xzero(111,0.6);}
void cube12(){
zzero(103,0.6);zzero(203,0.3);
yzero(42,0.9);yzero(142,0.6);
xzero(111,0.6);xzero(11,0.9);}
void cube13(){
zzero(104,0.6);zzero(204,0.3);
yzero(140,0.6);yzero(240,0.3);
xzero(32,0);xzero(214,0.3);}
void cube14(){
zzero(105,0.6);zzero(205,0.3);
yzero(141,0.6);yzero(241,0.3);
xzero(214,0.3);xzero(114,0.6);}
void cube15(){
zzero(106,0.6);zzero(206,0.3);
yzero(142,0.6);yzero(242,0.3);
xzero(114,0.6);xzero(14,0.9);}
void cube16(){
zzero(107,0.6);zzero(207,0.3);
yzero(240,0.3);yzero(49,0);
xzero(35,0);xzero(217,0.3);}
void cube17(){
zzero(108,0.6);zzero(208,0.3);
yzero(241,0.3);yzero(50,0);
xzero(217,0.3);xzero(117,0.6);}
void cube18(){
zzero(109,0.6);zzero(209,0.3);
yzero(242,0.3);yzero(51,0);
xzero(117,0.6);xzero(17,0.9);}
void cube19(){
zzero(201,0.3);zzero(21,0);
yzero(37,0.9);yzero(137,0.6);
xzero(28,0);xzero(212,0.3);}
void cube20(){
zzero(202,0.3);zzero(20,0);
yzero(38,0.9);yzero(138,0.6);
xzero(212,0.3);xzero(112,0.6);}
void cube21(){
zzero(203,0.3);zzero(19,0);
yzero(39,0.9);yzero(139,0.6);
xzero(112,0.6);xzero(12,0.9);}
void cube22(){
zzero(204,0.3);zzero(24,0);
yzero(137,0.6);yzero(237,0.3);
xzero(31,0);xzero(215,0.3);}
void cube23(){
zzero(205,0.3);zzero(23,0);
yzero(138,0.6);yzero(238,0.3);
xzero(215,0.3);xzero(115,0.6);}
void cube24(){
zzero(206,0.3);zzero(22,0);
yzero(139,0.6);yzero(239,0.3);
xzero(115,0.6);xzero(15,0.9);}
void cube25(){
zzero(207,0.3);zzero(27,0);
yzero(237,0.3);yzero(52,0);
xzero(34,0);xzero(218,0.3);}
void cube26(){
zzero(208,0.3);zzero(26,0);
yzero(238,0.3);yzero(53,0);
xzero(218,0.3);xzero(118,0.6);}
void cube27(){
zzero(209,0.3);zzero(25,0);
yzero(239,0.3);yzero(54,0);
xzero(118,0.6);xzero(18,0.9);}
void display()
{	int i1;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		usleep(2000);

		glLoadIdentity();
       
		glRotatef( rotate_x, 1.0, 0.0, 0.0 );

		glRotatef( rotate_y, 0.0, 1.0, 0.0 );



		if(rotation==0){
				cube1();cube2();cube3();cube4();cube5();cube6();cube7();cube8();cube9();cube10();cube11();cube12();cube13();cube14();cube15();cube16();cube17();cube18();cube19();cube20();cube21();cube22();cube23();cube24();cube25();cube26();cube27();
         	               }

if(rotation==1)
{cube10();cube11();cube12();cube13();cube14();cube15();cube16();cube17();cube18();cube19();cube20();cube21();cube22();cube23();cube24();cube25();cube26();cube27();
if(inverse==1){glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Front Inverted");
    glRotatef(theta,0,0,1.0);
    if(i4==0)
 system("xdotool key b");
             
cube1();cube2();cube3();cube4();cube5();cube6();cube7();cube8();cube9();
}
else if (inverse==0){
         glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Front");
        glRotatef(-theta,0,0,1.0);
         if(i4==0)
 system("xdotool key b");
cube1();cube2();cube3();cube4();cube5();cube6();cube7();cube8();cube9();
}
}
if(rotation==2)
{cube1();cube2();cube4();cube5();cube7();cube8();cube10();cube11();cube13();cube14();cube16();cube17();cube19();cube20();cube22();cube23();cube25();cube26();
if(inverse==1){
 glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Right Inverted");
         glRotatef(-theta,1.0,0,0);
         if(i4==0)
 system("xdotool key b");
cube3();cube6();cube9();cube12();cube15();cube18();cube21();cube24();cube27();usleep(1000);
}
else if (inverse==0){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Right");
       glRotatef(theta,1.0,0,0);
       if(i4==0)
 system("xdotool key b");
cube3();cube6();cube9();cube12();cube15();cube18();cube21();cube24();cube27();usleep(1000);
}
}
if(rotation==3)
{cube4();cube5();cube6();cube7();cube8();cube9();cube13();cube14();cube15();cube16();cube17();cube18();cube22();cube23();cube24();cube25();cube26();cube27();

if(inverse==1){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Upper Inverted");
        glRotatef(-theta,0,1.0,0);
        if(i4==0)
 system("xdotool key b");
cube1();cube2();cube3();cube10();cube11();cube12();cube19();cube20();cube21();
}
else if (inverse==0){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Upper");
        glRotatef(theta,0,1.0,0);
        if(i4==0)
 system("xdotool key b");
cube1();cube2();cube3();cube10();cube11();cube12();cube19();cube20();cube21();
}
}

if(rotation==4)
{cube1();cube2();cube3();cube4();cube5();cube6();cube10();cube11();cube12();cube13();cube14();cube15();cube19();cube20();cube21();cube22();cube23();cube24();

if(inverse==1){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Down Inverted");
        glRotatef(theta,0,1.0,0);
        if(i4==0)
 system("xdotool key b");
cube7();cube8();cube9();cube16();cube17();cube18();cube25();cube26();cube27();
}
else if (inverse==0){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Down");
        glRotatef(-theta,0,1.0,0);
        if(i4==0)
 system("xdotool key b");
cube7();cube8();cube9();cube16();cube17();cube18();cube25();cube26();cube27();
}
}

if(rotation==5)
{cube2();cube3();cube5();cube6();cube8();cube9();cube11();cube12();cube14();cube15();cube17();cube18();cube20();cube21();cube23();cube24();cube26();cube27();

if(inverse==1){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Left Inverted");
        glRotatef(theta,1.0,0,0);
        if(i4==0)
 system("xdotool key b");
cube1();cube4();cube7();cube10();cube13();cube16();cube19();cube22();cube25();
}
else if (inverse==0){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Left");
        glRotatef(-theta,1.0,0,0);
        if(i4==0)
 system("xdotool key b");
cube1();cube4();cube7();cube10();cube13();cube16();cube19();cube22();cube25();
}
}

if(rotation==6)
{cube1();cube4();cube7();cube10();cube13();cube16();cube2();cube3();cube5();cube6();cube8();cube9();cube11();cube12();cube14();cube15();cube17();cube18();

if(inverse==1){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Back Inverted");
        glRotatef(-theta,0,0,1.0);
        if(i4==0)
 system("xdotool key b");
cube19();cube22();cube25();cube20();cube21();cube23();cube24();cube26();cube27();
}
else if (inverse==0){ glColor3f(0.7,0.7,0.7);
        output(-0.0,0.9,"Back");
        glRotatef(theta,0,0,1.0);
        if(i4==0)
 system("xdotool key b");
cube19();cube22();cube25();cube20();cube21();cube23();cube24();cube26();cube27();
}
}

glFlush();
glutSwapBuffers();
}


void spincube()
{   theta+=0.5+speed;
	 if(theta==360.0)
	theta-=360.0;
	if(theta>=90.0)
	{      
		rotationcomplete=1;
	glutIdleFunc(NULL);
        if(rotation==1&&inverse==0){
        clswfi();
       }
        if(rotation==1&&inverse==1){
         clswfi(); clswfi(); clswfi();}
         //clswf();}
         if(rotation==2&&inverse==0)
        clswri();
        if(rotation==2&&inverse==1){
        clswri();clswri();clswri();}
        // clswr();}
          if(rotation==3&&inverse==0)
        clswui();
        if(rotation==3&&inverse==1){
         clswui(); clswui(); clswui();}
         //clswu();}
        if(rotation==4&&inverse==0){
        clswd();clswd();clswd();}
        if(rotation==4&&inverse==1){
        //clswdi();clswdi();clswdi();}
         clswd();}
        if(rotation==5&&inverse==0)
        clswli();
        if(rotation==5&&inverse==1){
       clswli();clswli();clswli();}
       // clswl();}
        if(rotation==6&&inverse==0)
        clswbi();
        if(rotation==6&&inverse==1){
        clswbi();clswbi();clswbi();}
        //clswb();}
        rotation=0;
        theta=0;
}

glutPostRedisplay();
}
static void keyboard(unsigned char key,int x,int y)
{
   if(key=='b')
      {
        
          
         
  
         if(rotationcomplete==1)
  {
           rotationcomplete=0;


        switch(mv2[i5])
        {
   
        case '1' :
        
	
          rotation=1;
          

           
		  inverse=1;
                  solve[++count]=1;
                  
		  glutIdleFunc(spincube);
              
                
                  i5++;
                  
            break;
       case '2':
                  rotation=1;
		  inverse=0;
                  solve[++count]=-1;
                  
		  glutIdleFunc(spincube);
                  
                
                  i5++;
                  
                  
                  
              
            break;
                  
         case '3':
	                
          rotation=2;
           
		  inverse=1;
             	  solve[++count]=2;
		  glutIdleFunc(spincube);
                 
                 i5++;
             break ;
           
           case '4' :
               rotation=2;
		  inverse=0;
             	  solve[++count]=-2;
		  glutIdleFunc(spincube);
                 
                 i5++;
              
              
           break;  
           
           case '5':

		  rotation=3;
           
		  inverse=1;
             	  solve[++count]=3;
		  glutIdleFunc(spincube);
                 
                 i5++;
             break ; 

           case '6':
                 
                  rotation=3;
		  inverse=0;
             	  solve[++count]=-3;
		  glutIdleFunc(spincube);
                 
                 i5++;
            break ;  

            case '7': 
 
                  rotation=4;
           
		  inverse=1;
             	  solve[++count]=4;
		  glutIdleFunc(spincube);
                 
                 i5++;
             break ;

            case '8':
     
                  rotation=4;
		  inverse=0;
             	  solve[++count]=-4;
		  glutIdleFunc(spincube);
                 
                 i5++;
                 break ;

           case '9':
                 
                  rotation=5;
           
		  inverse=1;
             	  solve[++count]=5;
		  glutIdleFunc(spincube);
                 
                 i5++;
             break ;
           
           case 'z':

                  rotation=5;
		  inverse=0;
             	  solve[++count]=-5;
		  glutIdleFunc(spincube);
                 
                 i5++;
                 break ;

           case 'x':

                rotation=6;
           
		  inverse=1;
             	  solve[++count]=6;
		  glutIdleFunc(spincube);
                 
                 i5++;
             break ;

           case 'c':
               
                 rotation=6;
		  inverse=0;
             	  solve[++count]=-6;
		  glutIdleFunc(spincube);
                 
                 i5++;
                 break ;
            
             case '\0' :
             
                  rotation=0;
	}
       
	}
	}


if(key=='p'){speed=speed+1;}
if(key=='l'){speed=speed-1;}

}
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 10;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 10;
  else if (key ==GLUT_KEY_UP)
    rotate_x += 10;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 10;
 
  //  Request display update
  glutPostRedisplay();
 
}

/*void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	glOrtho(-10.0,10.0,-10.0*(GLfloat)h/(GLfloat)w, 10.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
	glOrtho(-10.0*(GLfloat)w/(GLfloat)h, 10.0*(GLfloat)w/(GLfloat)h,-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}*/

void draw(int argc, char** argv,int* cl1,char* mv1)
{int i1;
/*
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (500, 500);
glutCreateWindow ("RUBIK'S CUBE");
//glutReshapeFunc (myreshape);
glEnable(GL_DEPTH_TEST);
glutIdleFunc(spincube);
glutKeyboardFunc(keyboard);
glutDisplayFunc (display);
glutSpecialFunc(specialKeys);*/
//  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
//for(i1=0;i1<54;i1++)
//{printf("enter color code:");
//scanf("%d",&cl[i1]);
//}
 lmv=strlen(mv1);
for(i1=0;i1<300;i1++){
mv2[i1]='0';}

for(i1=0;i1<lmv;i1++){
mv2[i1]=mv1[i1];}

for(i1=0;i1<54;i1++)
{cl[i1]=cl1[i1];
clsw[i1]=cl[i1];}




  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Rubik's Cube");
  
  

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
glutIdleFunc(spincube);
  glutKeyboardFunc(keyboard);

  glutDisplayFunc(display);

  glutSpecialFunc(specialKeys);
  glutIdleFunc(spincube);
  glutKeyboardFunc(keyboard);
  system("xdotool key Left");
   system("xdotool key Left");
 system("xdotool key Left");
 system("xdotool key Left");
  system("xdotool key Down");
 system("xdotool key Down");
 system("xdotool key Down");
 

  
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  


}

