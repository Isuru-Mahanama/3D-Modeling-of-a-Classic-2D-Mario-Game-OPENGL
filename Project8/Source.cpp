#include<iostream>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "models.h";
#include "textures.h"
#define PI 3.142857


//setup colors

const GLfloat blue[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat darkblue[4] = { 0.0f, 0.0f, 0.1f, 1.0f };
const GLfloat red[4] = { 1.0, 0.000, 0.000, 1.0 };
const GLfloat white[4] = { 1.000, 1, 1, 1.0 };
const GLfloat cream[4] = { 1.000, 0.627, 0.478 };
const GLfloat brownlight[4] = { 0.722, 0.525, 0.043 };
const GLfloat yellow[4] = { 0.90, 0.900, 0.000 };
const GLfloat brown[4] = { 0.502, 0.000, 0.000, 1.0 };
const GLfloat brown_b[4] = { 0.71, 0.44, 0.11, 1.0 };
const GLfloat lightbrown[4] = { 0.824, 0.706, 0.549, 1.0 };
const GLfloat black[4] = { 0, 0, 0, 1.0 };
const GLfloat ashBlue[4] = { 0.392, 0.584, 0.929, 1.0 };
const GLfloat steedBlue[4] = { 0.275, 0.510, 0.706, 1.0 };
const GLfloat powderBlue[4] = { 0.690, 0.878, 0.902, 1.0 };
const GLfloat dark_green[4] = { 0.000, 0.392, 0.000,1 };
const GLfloat treeGreen[] = { 0.0,0.1,0 };
const GLfloat spring_green[4] = { 0.196, 0.804, 0.196 ,1.0 };
const GLfloat green[4] = { 0.133, 0.545, 0.133,1.0 };
const GLfloat goldenyellow[4] = { 1.0f, 0.72f, 0.11f };
const GLfloat khaki[4] = { 0.941, 0.902, 0.549 ,1.0 };
const GLfloat teal[4] = { 0.000, 0.502, 0.502 ,1.0 };
const GLfloat pale[4] = { 0.686, 0.933, 0.933 ,1.0 };
const GLfloat lightSource[4] = { 1,0.8,1.0,1 };
const GLfloat white2[4] = { 1.0,1.0,1.0,1.0 };
const GLfloat orange_yellow[4] = { 1.000,0.3, 0.000 };
const GLfloat lightBlue[4] = { 0.1, 0.584, 0.929, 1.0 };
const GLfloat ashcolor[4] = { 0.698, 0.745, 0.71, 1.0 };
const GLfloat dark_brown[4] = { 0.4f, 0.26f, 0.13f, 1.0 };

//setting up camaras
bool useCamera1 = true;

//movement controllers
bool moveup = true;
bool moveforward = true;
bool marioController1 = true;

GLfloat marioMovement = 0;
GLfloat turn = 0;

GLfloat moveturn = 0;

GLfloat xRotated = 0;
GLfloat travel = 0;
GLfloat traveldown = 0;
GLfloat travelfront = 0;
GLfloat travelup = 0;
GLfloat travelleft = 0;
GLfloat sidemove = 0;
GLfloat movingBluEnimy = 0;
GLfloat travelside = 0;

GLfloat xtranslate = 0;
GLfloat ytranslate = 0;
GLfloat ytranslateR = 0;
//Animation
GLfloat animYRot = 0.0;

//variables to move the camera
GLfloat camX = 0.0;
GLfloat camY = 0.0;
GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;

//varibles to change the location looking at
GLfloat cenX = 0.0;
GLfloat cenY = 0.0;
GLfloat cenZ = 0.0;

GLfloat sceRY = 0.0;

//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

void init() {
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	 
	GLfloat globalAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	glEnable(GL_DEPTH_TEST);
	

	glEnable(GL_LIGHTING);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	glEnable(GL_NORMALIZE);

	loadExternalTextures();
}



void highWallY(GLfloat x, GLfloat y, GLfloat z, GLfloat len) {
	cube(x, y, z, len, 2, 2);
}


//drawing boxes-basic components

void drawBoxes() {
	glPushMatrix();
	highWallY(0, 0, 0, 2);
	glPopMatrix();
}

// drawing cylinder - basic component
void drawCyllicder() {
	
	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0.5, 0);
	gluCylinder(qobj, 0.3, 0.3, 1.5, 100, 100);
	glPopMatrix();
	

}

// drawing horizontal cylinder basic component
void drawhorizontalcylinder(double angle, int angleAxis, double baseRadius, double topRadius, double height) {
	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glPushMatrix();

	if (angleAxis == 1) {
		glRotatef(angle, 0, 1, 0);
	}

	if (angleAxis == 0) {
		glRotatef(angle, 1, 0, 0);
	}
	if (angleAxis == 2) {
		glRotatef(angle, 0, 0, 1);
	}


	glTranslatef(0, -1.3, 0);


	glColor3f(0.0, 0.0, 1.0);
	gluCylinder(qobj, baseRadius, topRadius, height, 100, 100);
	glPopMatrix();
}

//drawing circle - basic component

void drawCircle(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++)
	{
		double angle = 2 * PI / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

//drawong the hat of the mario

void drawHat() {

	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	const GLfloat red[4] = { 1.000, 0.000, 0.000, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0, 0, 2.5);
	gluCylinder(qobj, 0.5, 0.8, 0.5, 100, 100);
	glTranslatef(0, 0, 0.48);
	drawCircle(0.8);
	glPopMatrix();

}

//drawing the eyebrow of mario

void EyebrowMario(double radius) {
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawCircle(radius);
	glPopMatrix();
}

//drawing the mustache of mario

void mustache(double radius) {
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawCircle(radius);
	glPopMatrix();
}

void drawEyemario(double radius) {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glTranslatef(0.6, -0.26, 0);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();

	glPushMatrix();
	const GLfloat lightBlue[4] = { 0.000, 1.000, 1.000, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightBlue);
	glTranslatef(0.8, -0.26, 0);
	glutSolidSphere(0.13, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glTranslatef(0.95, -0.28, 0);
	glutSolidSphere(0.03, 20, 20);
	glPopMatrix();


}

void drawmariLeftBlueEye() {
	glPushMatrix();
	const GLfloat darkblue[4] = { 0.000, 0.000, 0.545, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, darkblue);
	glTranslatef(0.89, -0.3, 0.01);
	glutSolidSphere(0.075, 20, 20);
	glPopMatrix();
}

void drawRightEye() {
	glPushMatrix();
	const GLfloat darkblue[4] = { 0.000, 0.000, 0.545, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, darkblue);
	glTranslatef(0.89, -0.3, -0.01);
	glutSolidSphere(0.075, 20, 20);
	glPopMatrix();
}

void drawCoins() {

	glPushMatrix();
	glRotatef(xRotated, 0, 1, 0);
	glScalef(0.1, 0.5, 0.5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, goldenyellow);
	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void marioFace() {

	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	glTranslatef(0.6, -0.26, 0);
	glutSolidSphere(0.2f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	glTranslatef(0.2, -0.2, -0.15);
	glutSolidSphere(0.4f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	glTranslatef(0.2, -0.2, 0.15);
	glutSolidSphere(0.4f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	glutSolidSphere(0.6f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -0.2, 0);
	mustache(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -0.2, 0.1);
	mustache(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -0.2, -0.1);
	mustache(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.4, 0.2);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.4, -0.2);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.4, -0.1);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.4, 0.1);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.56, -0.35, 0.3);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.56, -0.35, -0.3);
	mustache(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25, 0.3, -0.15);
	drawEyemario(0.27);
	drawmariLeftBlueEye();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25, 0.3, 0.15);
	drawEyemario(0.27);
	drawRightEye();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45, 0.2, 0.2);
	EyebrowMario(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45, 0.2, -0.2);
	EyebrowMario(0.2);
	glPopMatrix();



}
void drawredtshirtmario() {


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glTranslatef(-1.4, 1.5, -0.7);
	drawhorizontalcylinder(90, 2, 0.4, 0.4, 1.5);
	glPopMatrix();

}
void pipline(double hightC, double baseradius, double topradius, double innerRT, double outerRT) {
	glPushMatrix();
	glTranslatef(7, 2, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	glutSolidTorus(innerRT, outerRT, 100, 100);
	glPopMatrix();
	drawhorizontalcylinder(90, 0, baseradius, topradius, hightC);
	glPopMatrix();
}


void drawRightHand() {

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glRotatef(45, 1, 1, 0);
	glRotatef(50, 0, 1, 0);
	glRotatef(20, 1, 0, 0);
	glTranslatef(-1.3, 1.4, -1);
	drawhorizontalcylinder(90, 2, 0.35, 0.2, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, 1.5, 0.7);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glTranslatef(1.2, 0.8, 0.65);
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();




}

void drawLeftHand() {


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glRotatef(45, -1, -1, 0);
	glRotatef(50, 0, -1, 0);
	glRotatef(20, -1, 0, 0);
	//glTranslatef(1.2, 0.8, 0.65);
	glTranslatef(-1.35, 1.45, -0.6);
	drawhorizontalcylinder(90, 2, 0.2, 0.35, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.135, 1.5, -0.7);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glTranslatef(1.2, 0.8, -0.65);
	glutSolidSphere(0.25, 100, 100);
	glPopMatrix();
}

void drawEarsmario() {
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 2, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	drawCircle(0.3);
	glPopMatrix();
}

void drawHairmario() {
	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.5, -0.1);
	glVertex3f(0, 0.5, 0.1);
	glVertex3f(0, -0.5, 0.1);
	glVertex3f(0, -0.5, -0.1);
	glEnd();
	glPopMatrix();
}

void drawGround() {
	glPushMatrix();
	glTranslatef(-45, -40, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 9);
	glScalef(45, 45, 0.5);
	
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void drawSideWall() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void drawshoeMario() {
	drawhorizontalcylinder(90, 1, 0.3, 0.35, 0.4);
	glPushMatrix();
	glTranslatef(0, -1.2, 0);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -1.2, 0);
	glutSolidSphere(0.36, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -1.3, 0);
	glRotatef(90, 0, 1, 0);
	drawCircle(0.35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.3, 0);
	glRotatef(90, 0, 1, 0);
	drawCircle(0.3);
	glPopMatrix();

}

//complete mario character
void drawMario()
{

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glutSolidSphere(0.75f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.6, -0.7);
	glRotatef(10, 1, 0, 0);
	drawCyllicder();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0.4, -0.2);
	glRotatef(-10, 1, 0, 0);
	drawCyllicder();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 2.3, -0.3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 2.3, 0.3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0.6);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	drawshoeMario();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.6);
	glColor3f(1.0f, 1.0f, 1.0f);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	drawshoeMario();
	glPopMatrix();


	glPushMatrix();
	drawredtshirtmario();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.4, 0);
	marioFace();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-10, 0, 0, -1);
	glTranslatef(0.5, 0.19, 0);
	drawHat();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-20, 0, 0, -1);
	glTranslatef(0.4, -0.1, -2.8);
	drawCircle(0.8);

	glPopMatrix();
	glPushMatrix();
	drawRightHand();
	glPopMatrix();

	glPushMatrix();
	drawLeftHand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4.5, 0.5);
	glRotatef(180, 0, 0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cream);
	drawEarsmario();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4.5, -0.5);
	glRotatef(180, 0, 0, 1);
	drawEarsmario();
	glPopMatrix();

	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glTranslatef(1.15, 1, -0.4);
	drawHairmario();
	glPopMatrix();

	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glTranslatef(1.15, 1, 0.4);
	drawHairmario();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 1.3, 0.4);
	glRotatef(-90, 0, 1, 0);
	glRotatef(60, 0, 0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	drawCircle(0.15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 1.3, -0.4);
	glRotatef(-90, 0, 1, 0);
	glRotatef(60, 0, 0, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	drawCircle(0.15);
	glPopMatrix();


}
//drawing brown color enimy
void drawBrownEnimy() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	glTranslatef(0, 0.7, 0);
	glColor3f(0.502, 0.000, 0.000);
	glutSolidSphere(0.6, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -1.36);
	drawhorizontalcylinder(-90, 0, 1.5, 0.4, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -1.4);
	drawhorizontalcylinder(-90, 0, 0.4, 1, 0.5);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightbrown);
	glColor3f(0.824, 0.706, 0.549);
	glTranslatef(0, -1, -1);
	drawhorizontalcylinder(-90, 0, 0.4, 0.4, 1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	glColor3f(0.502, 0.000, 0.000);
	glTranslatef(-0.35, -1.1, 0.5);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
	glColor3f(0.502, 0.000, 0.000);
	glTranslatef(0.35, -1.1, 0.5);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0.35, -1.1, 0.5);
	glutSolidSphere(0.4, 40, 40);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.28, .7, 0.3);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.28, .7, 0.3);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 1.0, 0.6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glColor3f(0, 0, 0);
	glutSolidSphere(0.1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.0, 0.6);
	glColor3f(0, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glutSolidSphere(0.1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.35, 0.8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glRotatef(-90, 1, 0, 0);
	glColor3f(1, 1, 1);
	glutSolidCone(0.2, 0.3, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 0.35, 0.8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2, 0.3, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glColor3f(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -0.2, 0.4);
	drawCircle(1);
	glPopMatrix();

}
//creating blue color enimy
void drawBlueEnimey() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, powderBlue);
	glTranslatef(0, 0.7, 0);
	glutSolidSphere(1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, steedBlue);
	glTranslatef(0, 0.3, 0);
	glutSolidSphere(0.9, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.7, 1.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glRotatef(-90, 1, 0, 0);
	glutSolidSphere(0.20, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 0.7, 1.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glRotatef(-90, 1, 0, 0);
	glutSolidSphere(0.20, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(00, 0.2, .9);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2, 0.3, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.3, 0.8, 1.1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glutSolidSphere(0.15, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.8, 1.1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glutSolidSphere(0.15, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, lightbrown);
	glTranslatef(0, -1, -1);
	drawhorizontalcylinder(-90, 0, 0.4, 0.4, 1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, steedBlue);
	glTranslatef(-0.35, -1.1, 0.5);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, steedBlue);
	glTranslatef(0.35, -1.1, 0.5);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, powderBlue);
	glTranslatef(0.0, 1.0, 0.5);
	glutSolidSphere(0.6, 40, 40);
	glPopMatrix();



}

//draw Red color enimy
void drawRedEnemy() {


	glRotatef(-10, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 1.1, -1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	drawhorizontalcylinder(0, 0, 1., 1, 2);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(1, 0, 0);
	glutSolidSphere(1.2, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0, 1, 1);
	drawhorizontalcylinder(0, 0, 0.5, 0.5, 0.6);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0, 0, 1);
	glutSolidSphere(0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0, 0, 1.4);
	glutSolidSphere(0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0, -0.3, 1.6);
	glutSolidSphere(0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0.15, 0.2, 1.65);
	glutSolidSphere(0.2, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(-0.15, 0.2, 1.65);
	glutSolidSphere(0.2, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glColor3f(0, 0, 0);
	glTranslatef(-0.15, 0.29, 1.75);
	glutSolidSphere(0.1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
	glColor3f(0, 0, 0);
	glTranslatef(0.15, 0.29, 1.75);
	glutSolidSphere(0.1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0, 1.2, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(-0.7, 0.9, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0.7, 0.9, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(1.2, 0.2, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(75, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(-1.2, 0.2, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-75, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0, 1., 0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(30, 1, 0, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(-0.7, 0.7, 0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(20, 1, 0, 0);
	glRotatef(-40, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0.7, 0.7, 0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(20, 1, 0, 0);
	glRotatef(40, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0, 0.95, -0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-30, 1, 0, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(-0.7, 0.7, -0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-20, 1, 0, 0);
	glRotatef(-40, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glColor3f(1, 1, 1);
	glTranslatef(0.7, 0.7, -0.7);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-20, 1, 0, 0);
	glRotatef(40, 0, 1, 0);
	glutSolidCone(0.3, 0.5, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0.4, -1, 0.7);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(-0.4, -1, 0.7);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(-0.4, -1, -0.7);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(1, 1, 0);
	glTranslatef(0.4, -1, -0.7);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();

}

//creating steal boxes
void drawstealBoxes() {

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, -1, 0);
	drawBoxes();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, 0.8, 0);
	glScalef(1.2, 0.3, 1);
	drawBoxes();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

//drawing sky boxes
void drawskyBoxes() {
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 8);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_yellow);
	glTranslatef(0, -1, 0);
	drawBoxes();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_brown);
	glTranslatef(0, 0.8, 0);
	glScalef(1.2, 0.3, 1);
	drawBoxes();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

//creating the tree
void tree() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_brown);
	drawhorizontalcylinder(-90, 0, 2, 0.5, 5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, treeGreen);
	glTranslatef(0, 5, 0);
	glutSolidSphere(3, 100, 100);
	glTranslatef(2, 0, 0);
	glutSolidSphere(2, 100, 100);
	glTranslatef(-4, 0, 0);
	glutSolidSphere(2, 100, 100);
	glPopMatrix();
}

// drawing the steps
void drawsteps() {
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, sidemove - 0.5, -25);
	glScalef(12, 0.4, 5);
	glutSolidCube(1);
	glPopMatrix();



	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, 3, -39);
	glTranslatef(0, sidemove - 0.5, -25);
	glScalef(12, 0.4, 5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, 0, -sidemove - 0.5);
	glTranslatef(0, 5, -45);
	glScalef(12, 0.4, 5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	glTranslatef(0, 0, sidemove - 0.5);
	glTranslatef(0, 5, -50);
	glScalef(12, 0.4, 5);
	glutSolidCube(1);
	glPopMatrix();
}
//drawing the connector between two scenes
void drawSecondFreespace() {


	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ashcolor);
	glTranslatef(0, 30, -90);
	glRotatef(90, 1, 0, 0);

	glPushMatrix();
	glPushMatrix();
	glTranslatef(-6, -70, 0);
	glScalef(8 ,25, 8);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	drawBoxes();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();

	glPushMatrix();
	
	glTranslatef(0, -60, -4);
	glRotatef(90, -1, 0, 0);
	
	glScalef(3, 3, 6);
	glTranslatef(0, 0, movingBluEnimy);
	if (moveturn) {
		glRotatef(180, 0, 1, 0);
	}
	glRotatef(180, 0, 1, 0);
	drawBlueEnimey();
	glPopMatrix();


	glPushMatrix();

	glTranslatef(0, -73, -4);
	glRotatef(90, -1, 0, 0);

	glScalef(3, 3, 6);
	glTranslatef(0, 0, movingBluEnimy-0.2);
	if (moveturn) {
		glRotatef(180, 0, 1, 0);
	}
	glRotatef(180, 0, 1, 0);
	drawBlueEnimey();
	glPopMatrix();

	

	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

}

// drawing side walls
void drawSideWalls() {
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-11, 40, -29);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glScalef(5, 0.1, 37);
	glTranslatef(0, 1, 0);
	drawSideWall();
	glPopMatrix();
}
//drawing five coins inline
void drawFivecoins() {
	glPushMatrix();
	glTranslatef(5, 8, 5);
	drawCoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7, 8, 5);
	drawCoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 8, 5);
	drawCoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11, 8, 5);
	drawCoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13, 8, 5);
	drawCoins();
	glPopMatrix();
}

//drawing the first scene along with the connector
void drawScene() {

	glPushMatrix();
	drawSecondFreespace();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-30);
	drawsteps();
	glPopMatrix();


	drawSideWalls();
	

	glPushMatrix();
	glTranslatef(82,0,0);
	drawSideWalls();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 0, -454);
	glRotatef(90, 0, 1, 0);
	glScalef(12, 1, 1.1);
	drawSideWalls();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 0, -527);
	glRotatef(90, 0, 1, 0);
	glScalef(12, 1, 0.4);
	drawSideWalls();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-22, 0, -527);
	glRotatef(90, 0, 1, 0);
	glScalef(12, 1, 0.4);
	drawSideWalls();
	glPopMatrix();




	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	drawGround();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glScalef(3, 3, 3);
	glPushMatrix();
	glTranslatef(-5, 0.5, -15);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	drawBoxes();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5, 1.5, -15);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	drawBoxes();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5, 2.5, -15);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
	drawBoxes();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, ytranslateR, 0);
	glTranslatef(-12, 14.5, -42);
	glScalef(2.5, 2.5, 2.5);
	drawRedEnemy();
	glPopMatrix();

	glPushMatrix();
	glScalef(6, 6,6);
	glPushMatrix();
	glTranslatef(0, 0., 0);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, khaki);
	drawhorizontalcylinder(0, 0, 0.7, 0.2, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4., 1.4);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1, 3.6, 1.4);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.6, 3.3, 1.4);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1., 3.6, 1.5);
	glRotatef(100, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(1.6, 3.3, 1.5);
	glRotatef(100, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3.6, 0.3);
	glRotatef(55, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3.3, -0.3);
	glRotatef(55, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 3.6, 2.3);
	glRotatef(120, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3.3, 2.9);
	glRotatef(120, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	drawCircle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3., 0);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	drawhorizontalcylinder(0, 0, 2, 0.2, 1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//drawing coins as steps
	glPushMatrix();
	
	

	glPushMatrix();
	glTranslatef(30, 33, 3);
	glScalef(3, 3, 3);
	drawCoins();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(30, 30, -6);
	glScalef(3, 3, 3);
	drawCoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 24, -9);
	glScalef(3, 3, 3);
	drawCoins();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(30, 16, -14);
	glScalef(3, 3, 3);
	drawCoins();
	glPopMatrix();


	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glTranslatef(15, 5, -9);
	glScalef(2, 2, 2);
	pipline(4, 1.6, 1.6, 0.8, 1.6);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pale);
	glTranslatef(15, 12, -3);
	glScalef(2, 2, 2);
	pipline(8, 2, 2, 1, 2);
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glTranslatef(15, 20, 7);
	glScalef(2, 2, 2);
	pipline(12, 2.4, 2.4, 1.2, 2.4);
	glPopMatrix();


	//pipline which is alone
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glTranslatef(-45, 2, 23);
	glScalef(3, 4, 3);
	pipline(4, 1.6, 1.6, 0.8, 1.6);
	glPopMatrix();

	//drawmario on top of the pipline
	glPushMatrix();
	glTranslatef(-24, 15, 19);
	glTranslatef( 0, marioMovement-2, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(2.5, 2.5, 2.5);
	drawMario();
	glPopMatrix();
	
	glPushMatrix();

	

	glScalef(3, 3, 3);
	glPushMatrix();
	glTranslatef(-11, 3, -7);
	//drawCoins();

/*	glPushMatrix();
	glTranslatef(4, 2, 0);
	drawCoins();
	glPopMatrix();*/

  /*glPushMatrix();
	glTranslatef(4, 5, 4);
	drawCoins();
	glPopMatrix();
	*/

	// Five coins inline

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	drawFivecoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 3, 0);
	drawFivecoins();
	glPopMatrix();

	//

	glPushMatrix();
	glTranslatef(4, -0.5, -2);
	drawskyBoxes();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();
	glTranslatef(20, -0.5, -4);
	drawstealBoxes();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20, 2, -4);
	drawstealBoxes();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(3, 5, 4);
	drawskyBoxes();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 5, 4);
	drawskyBoxes();
	glTranslatef(0, 2.5, 0);
	glRotatef(90, 0, -1, 0);
	glTranslatef(0, 0, travel);
	glRotatef(90, 0, -1, 0);
	glTranslatef(travelup, -traveldown, travelfront);
	glTranslatef(0, 0, -travelleft);
	drawBrownEnimy();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.5, 2.5, 2.5);
	glPushMatrix();
	glTranslatef(0, 1.5, -12);
	glRotatef(xRotated, 0, 1, 0);
	drawBrownEnimy();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4.2, -12);
	glRotatef(90, 0, 1, 0);
	glRotatef(xRotated, 0, 1, 0);
	drawBrownEnimy();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 7.0, -12);
	glRotatef(180, 0, 1, 0);
	glRotatef(xRotated, 0, 1, 0);
	drawBrownEnimy();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 9.8, -12);
	glRotatef(270, 0, 1, 0);
	glRotatef(xRotated, 0, 1, 0);
	drawBrownEnimy();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 7, 0);
//	glTranslatef(8, 0, 0);
	glRotatef(xRotated - 100, 0, -1, 0);
	glTranslatef(17, ytranslateR - 0.9, 0);
	glScalef(2.5, 2.5, 2.5);
	drawRedEnemy();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 0.9, 20);
	glScalef(1.5, 2.4, 1);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.9, 20);
	glTranslatef(11, 0, 0);
	glScalef(0.6, 2, 0.8);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 0, 18);
	glTranslatef(15, 0, 0);
	glScalef(3, 6, 3);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.9, 20);
	glTranslatef(11, 4, 0);
	glScalef(1.6, 2, 1);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.9, 20);
	glTranslatef(14, 0, 0);
	glScalef(1, 2, 1);
	tree();
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0, 10, 18);
	drawCoins();
	glPopMatrix();


}

// drawing the second scene
void secondLargearea() {
	glPushMatrix();
	//floor
	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
//	glTranslatef(-45, -40, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glScalef(15, 15, 1);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//drawBoxes();
	

	//sidewall
	glPushMatrix();
	glTranslatef(0, 0, 0);
//	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glScalef(15, 15, 1);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//sidewall
	// //sidewall
	glPushMatrix();
	glTranslatef(0, 0, 32);
	glRotatef(90, 0, 1, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glScalef(15, 15, 1);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//drawBoxes();

	//sidewall
	glPushMatrix();
	glTranslatef(28, 0, 30);
	glRotatef(90, 0, 1, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glScalef(15, 15, 1);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//sidewall
	glPushMatrix();
	glTranslatef(0, 0, 30);
	//	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	glScalef(15, 15, 1);
	//drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	//other floor
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -30);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);
	glScalef(15, 15, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
	drawBoxes();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 3, 5);
	glScalef(4, 4, 4);
	drawskyBoxes();
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(6, 3, 5);
	glScalef(4, 4, 4);
	drawskyBoxes();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1, 3, 5);
	glScalef(4, 4, 4);
	drawskyBoxes();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 8, 8);
	glRotatef(90, 1, 0, 0);
	glScalef(4, 4, 4);
	drawstealBoxes();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9, -10, -8);
	glScalef(2.7, 2.7, 2.7);
	drawFivecoins();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9, -6, -8);
	glScalef(2.7, 2.7, 2.7);
	drawFivecoins();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-9, -2, -8);
	glScalef(2.7, 2.7, 2.7);
	drawFivecoins();
	glPopMatrix();

	

	glPopMatrix();

	glPushMatrix();
	glTranslatef(13, 5, 72);
	glScalef(0.3, 0.3, 0.3);
	drawSecondFreespace();
	glPopMatrix();

}

// drawing the full scene
void drawFinalScene() {
	glPushMatrix();
	
    glTranslatef(0, 0, -700);
	glScalef(10, 6, 10);
	glTranslatef(-14,-14,-14);
	secondLargearea();
	glPopMatrix();

	//Draw a grid on the xz plane

	glPushMatrix();
	//drawMario();
	glPopMatrix();
	// drawRedEnemy();
	 //drawBlueEnimey();
	glPushMatrix();


	glRotatef(xRotated, 0, -1, 0);
	glTranslatef(40, 10.5, 6.5);
	
	glPushMatrix();
	glScalef(6.5, 6.5, 6.5);
	drawBrownEnimy();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glScalef(2.5, 2.5, 2.5);
	drawScene();
	glPopMatrix();
	//  drawGrid();
}

// Enable the light sources
void enabling() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
}

// enabling the light source two
void whitelighsource() {
	GLfloat L_Ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat L_Diffuse[] = { 1.0, 0.7, 0.7, 1.0 };
	GLfloat L_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat L_SpotDirection[] = { 0.0, -1.0, 0.0 };
	GLfloat light_position[] = { 3.0, 3.0, 0.0, 1.0 };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, L_SpotDirection);
}

//Enabling light source one
void enableLighSourceforFirstScene() {
	enabling();
	glEnable(GL_LIGHT0);
	GLfloat position[] = { 0.0,5.0,0.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	// Set attenuation parameters
	GLfloat constantAttenuation = 1.0;
	GLfloat linearAttenuation = 0.0;
	GLfloat quadraticAttenuation = 0.00001;
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constantAttenuation);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);


	// Set the cutoff distance for the light source
	GLfloat cutoffDistance = 10.0;
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0);

	// Set the direction of the light source
	GLfloat direction[] = { 0.0, -1.0, 0.0 };
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
}

// enabling light source three for second scene
void enableLighSourceforSecondScene() {
	enabling();
	glEnable(GL_LIGHT2);
	GLfloat position[] = { 0.0,15.0,-150.0,1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, position);
	GLfloat diffuse[] = { 1.0, 1.0, 0.0, 1.0 }; // white light
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
	GLfloat specular[] = { 1.0, 1.0, 0.0, 1.0 }; // white specular light
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular);


	// Set attenuation parameters
	GLfloat constantAttenuation = 1.0;
	GLfloat linearAttenuation = 0.0;
	GLfloat quadraticAttenuation = 0.00001;
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, constantAttenuation);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);


	// Set the cutoff distance for the light source
	GLfloat cutoffDistance = 10.0;
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.0);

	// Set the direction of the light source
	GLfloat direction[] = { 0.0, 1.0, 0.0 };
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
}

//Display function
void display() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (useCamera1) {

		// Use camera 1
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	
		glTranslatef(0.0f, 0.0f, objZ);
		glPushMatrix();
		gluLookAt(-14.5 + camX,30 + camY, 13.5 + camZ,- 14+cenX, 30+cenY, 0+cenZ, 0, 1.0, 0);
	
		glRotatef(sceY, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, sceZ);
		glTranslatef(0.0, sceRY, 0);
		glTranslatef(sceX, 0, 0);

		drawFinalScene();
		glPopMatrix();
	}

	else{
		
		//side veiw
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(45.0f, 0.0f, objZ);
		glPushMatrix();
	
		gluLookAt(-155 + camX, 82 + camY, 150 + camZ, 0 + cenX, 10 + cenY, 0 + cenZ, 0, 1.0, 0);
	
		glRotatef(sceY, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, sceZ);
		glTranslatef(0.0, sceRY, 0);
		glTranslatef(sceX, 0, 0);

		drawFinalScene();
		glPopMatrix();

	}




	glutSwapBuffers();

}


//Animation timer function
void timer(int x) {


	travel += 0.5;
	if (travel == 1) {
		turn += 0.5;
	
	}

	if (travel == 3) {
		travelfront += 0.5;
		traveldown += 0.5;

		travelside += 0.1;
		travel = 0;
	}
	if (travelside == 1) {
		travelside = 0;
	}

	if (traveldown == 5.5) {
		traveldown = 0;
		travelfront = 0;
		travelup += 1;
		travelleft += 2;
	}
	if (travelup == 2) {
		travelleft = 0;
		travelup = 0;
	}
	xRotated += 6;

	if (ytranslateR != 7) {
		ytranslateR += 1;
	}
	if (ytranslateR == 7) {
		for (int i = 0; i < 6; i++) {
			ytranslateR--;
		}
	}

	//movement of the steps

	if (moveup) {
		sidemove += 1;
	}
	if (sidemove == 25) {
		moveup = false;
	}
	if (!moveup) {
		sidemove -= 1;
	}
	if (sidemove == 0) {
		moveup = true;
	}

	// movement of blue color enimy

	if (moveforward) {
		movingBluEnimy += 0.5;
	}
	if (movingBluEnimy == 6) {
		moveforward = false;
		moveturn = false;
	}
	if (!moveforward) {
		movingBluEnimy -= 0.5;
	}
	if (movingBluEnimy == 1) {
		moveforward = true;
		moveturn = true;
	}


	//movement of the mario
	if (marioController1) {
		marioMovement += 1;
	}
	if (marioMovement == 4) {
		marioController1 = false;
	}
	if (!marioController1) {
		marioMovement -= 1;
	}
	if (marioMovement == -15) {
		marioController1 = true;
	}


	glutPostRedisplay();

	glutTimerFunc(60.0, timer, 1);
}

void keyboardSpecial(int key, int x, int y) {

	//camra movemnts along with the z axis
	if (key == GLUT_KEY_UP)
		camZ -= 5;

	if (key == GLUT_KEY_DOWN)
		camZ += 5;

	//scene goes up and down
	if (key == GLUT_KEY_RIGHT)
		sceY += 5;

	if (key == GLUT_KEY_LEFT)
		sceY -= 5;


	if (key == GLUT_KEY_F1)
		objZ -= 3;

	if (key == GLUT_KEY_F2)
		objZ += 3;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	//camra movemnts along with the x axis
	if (key == 'l')
		camX += 3;

	if (key == 'r')
		camX -= 3;
	//scene goes along with z axis
	if (key == 'f')
		sceZ += 8;

	if (key == 'b')
		sceZ -= 8;

	//camra movemnts along with the y axis
	if (key == 'd')
		sceRY += 5;
	if (key == 'u')
		sceRY -= 5;
	//scene moves along with x axis
	if (key == 'x')
		sceX += 5;
	if (key == 'y')
		sceX -= 5;
	if (key == 'v')
		useCamera1 = true;

	if (key == 'z')
			useCamera1 = false;
	  
	


	if (key == '1')
		enableLighSourceforFirstScene();
	if (key == '!')
		glDisable(GL_LIGHT0);
	if (key == '2')
		whitelighsource();
	if (key == '@')
		glDisable(GL_LIGHT1);
	if (key == '3')
		enableLighSourceforSecondScene();
	if (key == '#')
		glDisable(GL_LIGHT2);
	if (key == '6')
		sceRY += 1;
	
	//Changing the place where camra is looking at

	//looking right side
	if (key == 'g')
		cenX += 3;
	//looking up
	if (key == 'h')
		cenY += 3;
	// looking towards z axis
	if (key == 'j')
		cenZ += 3;
	//looking left side
	if (key == 'G')
		cenX -= 3;
	//looking down
	if (key == 'H')
		cenY -= 3;
	// looking towards minse z axis
	if (key == 'J')
		cenZ -= 3;
	glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 10000.0);


}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	// keyboard function activation
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);

	glutTimerFunc(200, timer, 0);
	init();
	glutMainLoop();


	return 0;
}