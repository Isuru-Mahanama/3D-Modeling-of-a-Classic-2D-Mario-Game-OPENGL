#include<iostream>
#include<GL/glut.h>
#include "models.h"


void cube(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {

	glPushMatrix();
	glTranslatef(x, y, z);


	glNormal3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);

	//TOP
	glTexCoord2f(0.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, h, 0);
	glEnd();

	//BOTTOM
	glNormal3f(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, 0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, 0, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 0, l);
	glEnd();


	// FRONT
	glNormal3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, l);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, 0, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h, l);
	glEnd();



	//// BACK
	glNormal3f(-1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w, h, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, 0, 0);
	glEnd();



	// LEFT
	glNormal3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(0, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h, 0);
	glEnd();

	//RIGHT
	glNormal3f(0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	//glColor3f(0.0, 0.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(w, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, h, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, 0, l);
	glEnd();

	glPopMatrix();
}

