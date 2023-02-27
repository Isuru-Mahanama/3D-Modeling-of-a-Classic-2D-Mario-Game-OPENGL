#include <GL/glut.h>  
#include <math.h>
#define PI 3.142857



const GLfloat blue[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat red[4] = { 1.0, 0.000, 0.000, 1.0 };
const GLfloat white[4] = { 1.000, 1, 1, 1.0 };
const GLfloat cream[4] = { 1.000, 0.627, 0.478 };
const GLfloat brownlight[4] = { 0.722, 0.525, 0.043 };
const GLfloat yellow[4] = { 1.000, 1.000, 0.000 };
const GLfloat brown[4] = { 0.502, 0.000, 0.000, 1.0 };
const GLfloat lightbrown[4] = { 0.824, 0.706, 0.549, 1.0 };
const GLfloat black[4] = { 0, 0, 0, 1.0 };
const GLfloat ashBlue[4] = { 0.392, 0.584, 0.929, 1.0 };
const GLfloat steedBlue[4] = { 0.275, 0.510, 0.706, 1.0 };
const GLfloat powderBlue[4] = { 0.690, 0.878, 0.902, 1.0 };
const GLfloat dark_green[4] = { 0.000, 0.392, 0.000,1 };
const GLfloat spring_green[4] = { 0.196, 0.804, 0.196 ,1.0 };
const GLfloat khaki[4] = { 0.941, 0.902, 0.549 ,1.0 };
const GLfloat teal[4] = { 0.000, 0.502, 0.502 ,1.0};
const GLfloat pale[4] = { 0.686, 0.933, 0.933 ,1.0 };

GLfloat xRotated = 0;
GLfloat radius = 0.5;
GLfloat xtranslate = 0;
GLfloat ytranslate =0;
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

//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //For lightning and shading
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    //glShadeModel(GL_SMOOTH); // this is default, you may not set it
    glEnable(GL_NORMALIZE);

}

void drawBoxes() {
    glPushMatrix();
    glutSolidCube(2);
    glPopMatrix();
}

void drawCyllicder() {
    //  glBegin(GL_POLYGON);
    GLUquadric* qobj;
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0.5, 0);
    gluCylinder(qobj, 0.3, 0.3, 1.5, 100, 100);
    glPopMatrix();
    //  glEnd();

}
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

void EyebrowMario(double radius) {
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    drawCircle(radius);
    glPopMatrix();
}

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
    glTranslatef(7, 2,0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, -1.5, 0);
    glutSolidTorus(innerRT, outerRT, 100, 100);
    glPopMatrix();
    drawhorizontalcylinder(90,0,baseradius,topradius,hightC);
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
    glBegin(GL_POLYGON);
    glVertex3f(-10,20,0);
    glVertex3f(10,20,0);
    glVertex3f(10,-20,0);
    glVertex3f(-10,-20,0);
    glEnd();
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

void drawBrownEnimy() {
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glTranslatef(0, 0.7, 0);
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
    glTranslatef(0, -1, -1);
    drawhorizontalcylinder(-90, 0, 0.4, 0.4, 1);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glTranslatef(-0.35, -1.1, 0.5);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glTranslatef(0.35, -1.1, 0.5);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0.35, -1.1, 0.5);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.28, .7, 0.3);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.28, .7, 0.3);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 1.0, 0.6);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    glutSolidSphere(0.1, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 1.0, 0.6);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    glutSolidSphere(0.1, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.35, 0.8);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.2, 0.3, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0.35, 0.8);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.2, 0.3, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, -0.2, 0.4);
    drawCircle(1);
    glPopMatrix();

}

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



void drawGrid() {
    GLfloat step = 1.0f;
    GLint line;

    glBegin(GL_POLYGON);
    for (line = -40; line <= 40; line += step) {
        glVertex3f(line, -0.4, 40);
        glVertex3f(line, -0.4, -40);

        glVertex3f(40, -0.4, line);
        glVertex3f(-40, -0.4, line);
    }

    glEnd();
}



void drawRedEnemy() {

    glPushMatrix();
    glRotatef(-10, 1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 1.1, -1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    drawhorizontalcylinder(0, 0, 1., 1, 2);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
    glutSolidSphere(1.2, 40, 40);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0, 1, 1);
    drawhorizontalcylinder(0, 0, 0.5, 0.5, 0.6);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0, 0, 1.4);
    glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0, -0.3, 1.6);
    glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0.15, 0.2, 1.65);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(-0.15, 0.2, 1.65);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    glTranslatef(-0.15, 0.29, 1.75);
    glutSolidSphere(0.1, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
    glTranslatef(0.15, 0.29, 1.75);
    glutSolidSphere(0.1, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0, 1.2, 0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(-0.7, 0.9, 0);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-30, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0.7, 0.9, 0);
    glRotatef(-90, 1, 0, 0);
    glRotatef(30, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(1.2, 0.2, 0);
    glRotatef(-90, 1, 0, 0);
    glRotatef(75, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(-1.2, 0.2, 0);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-75, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0, 1., 0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(30, 1, 0, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(-0.7, 0.7, 0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(20, 1, 0, 0);
    glRotatef(-40, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0.7, 0.7, 0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(20, 1, 0, 0);
    glRotatef(40, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0, 0.95, -0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-30, 1, 0, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(-0.7, 0.7, -0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-20, 1, 0, 0);
    glRotatef(-40, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glTranslatef(0.7, 0.7, -0.7);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-20, 1, 0, 0);
    glRotatef(40, 0, 1, 0);
    glutSolidCone(0.3, 0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0.4, -1, 0.7);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(-0.4, -1, 0.7);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(-0.4, -1, -0.7);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0.4, -1, -0.7);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();
}
void drawAxes() {

    glBegin(GL_LINES);

    glLineWidth(10);


    const GLfloat red[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-200, 0, 0);
    glVertex3f(200, 0, 0);



    const GLfloat green[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -200, 0);
    glVertex3f(0, 200, 0);


    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -200);
    glVertex3f(0, 0, 200);

    glEnd();
}

void drawScene() {
     
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_green);
    drawGround();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8, 0.5, -18);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, spring_green);
    drawBoxes();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-8, 1.5, -18);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, spring_green);
    drawBoxes();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-8, 2.5, -18);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, spring_green);
    drawBoxes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,ytranslateR,0);
    glTranslatef(-8, 4.5, -18);
    drawRedEnemy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0., 0);
    glRotatef(-90, 1, 0, 0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, khaki);
    drawhorizontalcylinder(0,0,0.7,0.2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4., 1.4);
    glRotatef(-90, 1, 0, 0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,white);
    glutSolidSphere(0.3,40,40);
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

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
    pipline(2, 0.8, 0.8, 0.4, 0.8);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pale);
    glTranslatef(0, 0, 2);
    pipline(4, 1, 1, 0.5, 1);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
    glTranslatef(0, 0, 3);
    pipline(6, 1.2, 1.2, 0.6, 1.2);
    glPopMatrix();

}
void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glEnable(GL_LIGHT0);
    GLfloat position[] = { 2.0,2.0,2.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    /* set light intensities */
    GLfloat white2[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white2);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);


    ///////
    //Translate the scene along the z axis
    glTranslatef(0.0f, 0.0f, objZ);
    glPushMatrix();
    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0, 2.0 + camY, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(sceY, 0.0, 1.0, 0.0);

    //Draw a grid on the xz plane
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glColor3f(1, 1, 1);
    glPopMatrix();

    //draw the three axes

    drawAxes();

    //snowman
    glPushMatrix();
    //drawMario();
    glPopMatrix();
    // drawRedEnemy();
     //drawBlueEnimey();
    glPushMatrix();
    
   // glTranslatef(x + cos(i) * radius, 0, z + sin(i) * radius);
    glRotatef(xRotated, 0, 1, 0);
    glTranslatef(2.5, 1.5, 0.5);
    glRotatef(xRotated, 0, 1, 0);
     drawBrownEnimy();
     glPopMatrix();
  
    drawScene();
    //  drawGrid();
    glPopMatrix();

    glutSwapBuffers();

}

//Animation timer function
void timer(int x) {

   
    
    /*if (xRotated == 360.0)
        xRotated = 0.0;
    else
        xRotated += 2.0;*/
    
    xRotated += 1;

    if (ytranslateR != 7) {
        ytranslateR += 1;
    }
    if (ytranslateR == 7) {
        for (int i = 0; i < 6; i++) {
            ytranslateR--;
        }
    }
    glutPostRedisplay();

    glutTimerFunc(60.0, timer, 1);
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        camY += 1;

    if (key == GLUT_KEY_DOWN)
        camY -= 1;

    if (key == GLUT_KEY_RIGHT)
        sceY += 1;

    if (key == GLUT_KEY_LEFT)
        sceY -= 1;

    if (key == GLUT_KEY_F1)
        objZ -= 1;

    if (key == GLUT_KEY_F2)
        objZ += 1;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'l')
        objY += 1;

    if (key == 'r')
        objY -= 1;

    glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

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

    glutTimerFunc(200, timer,0);
    init();
    glutMainLoop();


    return 0;
}