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
const GLfloat brown_b[4] = { 0.71, 0.44, 0.11, 1.0 };
const GLfloat lightbrown[4] = { 0.824, 0.706, 0.549, 1.0 };
const GLfloat black[4] = { 0, 0, 0, 1.0 };
const GLfloat ashBlue[4] = { 0.392, 0.584, 0.929, 1.0 };
const GLfloat steedBlue[4] = { 0.275, 0.510, 0.706, 1.0 };
const GLfloat powderBlue[4] = { 0.690, 0.878, 0.902, 1.0 };
const GLfloat dark_green[4] = { 0.000, 0.392, 0.000,1 };
const GLfloat treeGreen[] = { 0,0.6,0 };
const GLfloat spring_green[4] = { 0.196, 0.804, 0.196 ,1.0 };
const GLfloat khaki[4] = { 0.941, 0.902, 0.549 ,1.0 };
const GLfloat teal[4] = { 0.000, 0.502, 0.502 ,1.0};
const GLfloat pale[4] = { 0.686, 0.933, 0.933 ,1.0 };
const GLfloat lightSource[4] = { 1,0.8,1.0,1 };
const GLfloat white2[4] = { 1.0,1.0,1.0,1.0 };
const GLfloat orange_yellow[4] = { 1.000,0.3, 0.000 };
const GLfloat lightBlue[4] = { 0.1, 0.584, 0.929, 1.0 };
const GLfloat ashcolor[4] = { 0.698, 0.745, 0.71, 1.0 };
bool useCamera1 = true;
bool eyelightning = false;
int redLight = 0;

GLfloat turn = 0;

GLfloat xRotated = 0;
GLfloat travel = 0;
GLfloat traveldown = 0;
GLfloat travelfront = 0;
GLfloat travelup = 0;
GLfloat travelleft = 0;
GLfloat sidemove = 0;

GLfloat travelside = 0;

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



GLfloat sceRY = 0.0;
//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

void init() {
    glClearColor(0.500, 0.527, 0.3,1.0f);

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

void drawCoins() {

    glPushMatrix();
    glRotatef(xRotated, 0, 1, 0);
    glScalef(0.2, 1, 1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glutSolidSphere(1,100,100);
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
    glPushMatrix();
    glScalef(45, 45, 0.5);
    glutSolidCube(1);
    glPopMatrix();
}

void drawSideWall() {
    glBegin(GL_POLYGON);
    glVertex3f(-25, 20, 0);
    glVertex3f(25, 20, 0);
    glVertex3f(25, -20, 0);
    glVertex3f(-25, -20, 0);
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
void drawskyBoxes() {
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, orange_yellow);
    drawBoxes();
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glTranslatef(0, 0.8, 0);
    glScalef(1.2, 0.3, 1);
    drawBoxes();
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

void tree() {
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
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

void drawsteps() {
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
    glTranslatef(0, sidemove-0.5, -25);
    glScalef(12, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
    glTranslatef(0, -3, -32);
    glTranslatef(sidemove - 0.5, 0, -25);
    glScalef(12, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
    glTranslatef(0, 3, -39);
    glTranslatef(0, sidemove - 0.5, -25);
    glScalef(12, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
    glTranslatef(0, 0,- sidemove - 0.5);
    glTranslatef(0, 4, -45);
    glScalef(12, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_b);
    glTranslatef(0, 0, sidemove - 0.5);
    glTranslatef(0, 5, -50);
    glScalef(12, 0.2, 3);
    glutSolidCube(1);
    glPopMatrix();
}

void drawSecondFreespace() {

  
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ashcolor);
    glTranslatef(0, 30, -90);
    glRotatef(90, 1, 0, 0);

    glPushMatrix();
    glRotatef(sceRY, 0.0, 0.0, 1.0);
    drawCircle(20);
   
    glPushMatrix();
    glTranslatef(0, 0, -4);
    glRotatef(90, -1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glScalef(3,3, 3);
    drawBlueEnimey();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    
}
void drawSky() {
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glScalef(10,4, 12);
    glTranslatef(0, 7.5, 0);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ashBlue);
    glScalef(8, 4, 11);
    glTranslatef(0, 8, 0);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ashBlue);
    glScalef(8, 4, 11);
    glTranslatef(0, 7.5, 0.5);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glScalef(9, 4, 11);
    glTranslatef(0,7.5, 0.5);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
}
void drawScene() {
   
    glPushMatrix();
    drawSecondFreespace();
    glPopMatrix();

    glPushMatrix();
    drawsteps();
    glPopMatrix();
     
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-3, -1, 20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.1, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix(); 


     glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-3, -1, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.1, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix(); 

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-3, -1, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.1, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, -1, 0, 0);
    glTranslatef(-3, -12.5, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.1, 0.4, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, -1, 0, 0);
    glTranslatef(-3, 12, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.1, 0.4, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, -1, 0, 0);
    glTranslatef(-8, -12.5, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.02, 0.4, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, -1, 0, 0);
    glTranslatef(-8, 12, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.02, 0.4, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();
  

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, -1, 0, 0);
    glTranslatef(-8, -1, 20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.02, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-8, -1, 20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.02, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-8, -1, -20);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);
    glScalef(0.02, 1, 1);
    glTranslatef(0, 1, 0);
    drawSideWall();
    glPopMatrix();

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
    glScalef(3, 3, 3);
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
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
    glTranslatef(3, 0, -7);
    glScalef(2, 2, 2);
    pipline(2, 0.8, 0.8, 0.4, 0.8);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pale);
    glTranslatef(3, 4, -1);
    glScalef(2, 2, 2);
    pipline(4, 1, 1, 0.5, 1);
    glPopMatrix();


    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teal);
    glTranslatef(3, 8, 5);
    glScalef(2, 2, 2);
    pipline(6, 1.2, 1.2, 0.6, 1.2);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glColor3f(1, 0.1, 0);
    glTranslatef(-15,8,5);
    drawCoins();
  //  glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0, 0);
    drawCoins();
    glPushMatrix();
    glTranslatef(4, 2, 0);
    drawCoins();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 5, 4);
    drawCoins();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5, 3, 3);
    drawCoins();
    glPopMatrix();

   
    glPushMatrix();
    glTranslatef(4, 0, -2);
    drawskyBoxes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,5,-8);
    drawskyBoxes();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(3, 5, 4);
    drawskyBoxes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 5, 4);
    drawskyBoxes();
    glTranslatef(0,2.5,0);
    glRotatef(90,0,-1,0);
    glTranslatef(0, 0, travel);
    glRotatef(90, 0, -1, 0);
    glTranslatef(travelup, -traveldown, travelfront);
    glTranslatef(0,0, -travelleft);
    drawBrownEnimy();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 1.2, 1.2);
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
    glTranslatef(-8, 7, 0);
    glTranslatef(8, 0, 0);
    glRotatef(xRotated-100,0,-1,0);
    glTranslatef(17, ytranslateR-0.9, 0);
    drawRedEnemy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1,15);
    glScalef(0.5, 1.2, 0.5);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, 15);
    glTranslatef(3,0,0);
    glScalef(0.2, 1, 0.3);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, 15);
    glTranslatef(3, 0, 0);
    glScalef(0.8, 3, 0.3);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, 15);
    glTranslatef(3, 4, 0);
    glScalef(0.8, 1, 0.3);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, 15);
    glTranslatef(6, 0, 0);
    glScalef(0.4, 1, 0.3);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 0.8);
    drawSky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 3, 3);
    glScalef(0.5, 0.5, 0.5);
    drawSky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, -10);
    glScalef(0.5, 0.5, 0.5);
    drawSky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2, 6);
    drawCoins();
    glPopMatrix();

   
}

void drawFinalScene() {


    //Draw a grid on the xz plane
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    glColor3f(1, 1, 1);
    glPopMatrix();

    //draw the three axes


    //snowman
    glPushMatrix();
    //drawMario();
    glPopMatrix();
    // drawRedEnemy();
     //drawBlueEnimey();
    glPushMatrix();

    // glTranslatef(x + cos(i) * radius, 0, z + sin(i) * radius);
    glRotatef(xRotated, 0, -1, 0);
    glTranslatef(1.5, 4.5, 1.5);
    //  glRotatef(xRotated, 0, 1, 0);
    glTranslatef(20, 0, 0);
    glPushMatrix();
    glScalef(2.5, 2.5, 2.5);
    drawBrownEnimy();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(2.5, 2.5, 2.5);
    drawScene();
    glPopMatrix();
    //  drawGrid();
}
void enabling() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
}
void glEnableEyesLightinig() {
    GLfloat light_position[] = { 0.f, 10.0f, 0.0f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.f, 0.f, 1.0f };
    GLfloat spot_direction[] = { 0.0f, -1.0f, 0.0f };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_POINT, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
  //  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,0.0000000000001f);

    glPushMatrix();
    glTranslatef(-0.3, 1.0, 0.6);
    glColor3f(0.5f, 0.5f, 0.5f);
    glutSolidSphere(0.1, 40, 40);
    glPopMatrix();
   
}
void forbavkground() {
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat light_position[] = { 0.0, 0.0, 5.0, 1.0 };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
}
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
void display() {

   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    if (useCamera1) {
     
        // Use camera 1
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
      //  enableLighSourceforFirstScene();
        glTranslatef(0.0f, 0.0f, objZ);
        glPushMatrix();
        gluLookAt( 0+camX , 130+camY , 2.5 + camZ, 0, 0, 0, 0, 1.0, 0);
    //    gluLookAt(25.0, 25.0 + camY, 0.0, 7.0, -8.0, 0.0, 0.0, 1.0, 0.0);
        glRotatef(sceRY, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, sceZ);
        glTranslatef(0.0, sceY, 0);
        glTranslatef(sceX, 0, 0);
        drawFinalScene();
        glPopMatrix();
    }
    else {
        // Use camera 2
     
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
     //  enableLighSourceforFirstScene();
        glTranslatef(0.0f, 0.0f, objZ);
        glPushMatrix();
    //   gluLookAt(-12.5 + camX, 5.5 + camY, 2.5 + camZ, 0, 0, 0, 0, 1.0, 0);
    //   gluLookAt(0.0, 90.0 + camY, -200.0, 0.0, -100.0, 300.0, 0.0, 1.0, 0.0);
      //  gluLookAt(-10.0, 5.0 + camY, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
         gluLookAt( 0+camX, 10.0+camY , +50.0+camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
       // glTranslatef(0,0,-100);
       
        glRotatef(sceRY, 0.0, 1.0, 0.0);
     //    glTranslatef(0, -30, 90);
          glTranslatef(0.0, 0.0, sceZ);
          glTranslatef(0.0, sceY, 0);
          glTranslatef(sceX, 0, 0);

         drawFinalScene();
         glPopMatrix();
         // Extract the translation components
       
         // Print out the translated coordinates
       
    }
   
  
   

    glutSwapBuffers();

}


//Animation timer function
void timer(int x) {

   // skyrotate += 0.1;
    
    /*if (xRotated == 360.0)
        xRotated = 0.0;
    else
        xRotated += 2.0;*/
    travel += 0.5;
    if (travel == 1) {
        turn += 0.5;
     //   travel = 0;
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

    if (sidemove != 25) {
        sidemove += 1;
    }
    if (sidemove == 25) {
        for (int i = 0; i < 25; i++) {
            sidemove--;
        }
    }
    glutPostRedisplay();

    glutTimerFunc(60.0, timer, 1);
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        camZ -= 1;

    if (key == GLUT_KEY_DOWN)
        camZ += 1;

    if (key == GLUT_KEY_RIGHT)
        sceRY += 1;

    if (key == GLUT_KEY_LEFT)
        sceRY -= 1;
       

    if (key == GLUT_KEY_F1)
        objZ -= 1;

    if (key == GLUT_KEY_F2)
        objZ += 1;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'l')
        camX += 1;

    if (key == 'r')
        camX -= 1;
    if (key == 'f')
        sceZ += 1;

    if (key == 'b')
        sceZ -= 1;
    if (key == 'u')
       camY += 1;
    if (key == 'd')
        camY -= 1;

    if (key == 'x')
        sceX += 1;
    if (key == 'y')
        sceX -= 1;
    if (key == '1')
        useCamera1 = true;
    if (key == '2')
        useCamera1 = false;

    if (key == '!')
        enableLighSourceforFirstScene();
    if (key == 'e')
        glEnableEyesLightinig();
       
    glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
  //  gluPerspective(150.0, aspect_ratio, 1.0, 100.0);
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);

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