/* Dan Gray
cs4410 HW #3
10-22-14 */

#include "Windows.h"
#include <gl/GL.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

 double horizAngle = 0.0;	//Viewing angle
 double vertAngle = 0.0;	//Viewing angle
 double limbAngle = 0.0; //Walking angle
 bool walk = false;	//For walking

void drawRobot(){
	//head
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0.0);
	glutSolidSphere(.25, 20, 20);
	glPopMatrix();

	//Hair
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 1.05, -0.10);
	glScaled(1.2, 0.5, 0.9);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	//eyes
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(0.11, 1.1, 0.15);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.11, 1.1, 0.15);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.12, 1.12, 0.2);
	glutSolidSphere(.03, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.12, 1.12, 0.2);
	glutSolidSphere(.03, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.121, 1.125, 0.222);
	glutSolidSphere(.01, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.121, 1.125, 0.222);
	glutSolidSphere(.01, 20, 20);
	glPopMatrix();
	//Makeup
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslated(0.12, 1.135, 0.084);
	glScaled(0.90, 2.8, 3.5);
	glutSolidSphere(.02, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.12, 1.135, 0.084);
	glScaled(0.90, 2.8, 3.5);
	glutSolidSphere(.02, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.12, 1.05, 0.15);
	glScaled(0.90, 2.8, 3.5);
	glutSolidSphere(.02, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.12, 1.05, 0.15);
	glScaled(0.90, 2.8, 3.5);
	glutSolidSphere(.02, 20, 20);
	glPopMatrix();

	//collar
	for(int i = 0; i <= 180; i+=20){
		glColor3f(0.0, 0.60, 1.0);	
		glPushMatrix();
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.75, 0.13);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 4.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.75, 0.13);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 4.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}
	for(int i = 10; i < 180; i+=20){
		glColor3f(1.0, 0.0, 1.0);	
		glPushMatrix();
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.75, 0.13);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 4.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.75, 0.13);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 4.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}

	//mouth
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.92, 0.180);
	glScaled(2.0, 0.60, 1.0);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.92, 0.190);
	glRotated(20, 1.0, 0.0, 0.0);
	glScaled(2.04, 0.65, 0.6);
	glutSolidSphere(.07, 20, 20);
	glPopMatrix();

	//nose
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 1.02, 0.29);
	glScaled(0.80, 0.80, 1.0);
	glutSolidSphere(.06, 20, 20);
	glPopMatrix();

	//body
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.40, 0.0);
	glScaled(1.0, 1.5, 0.30);
	glutSolidCube(.50);
	glPopMatrix();

	//buttons
	glColor3f(1.0, 0.50, 0.0);
	glPushMatrix();
	glTranslated(0.0, 0.68, 0.05);
	glutSolidSphere(0.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.0, 0.53, 0.05);
	glutSolidSphere(0.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.0, 0.38, 0.05);
	glutSolidSphere(0.07, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.0, 0.23, 0.05);
	glutSolidSphere(0.07, 20, 20);
	glPopMatrix();
}
//Draw left arm
void leftArm(){
	glColor3f(1.0, 0.0, 1.0);	
	glPushMatrix();
	glTranslated(-0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);	
	glPushMatrix();
	glTranslated(-0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//Hand collar
	for(int i = 0; i <= 180; i+=20){
		glColor3f(0.0, 0.60, 1.0);	
		glPushMatrix();
		glTranslated(-0.30, 0.23, 0.0);
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.30, 0.23, 0.0);
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}
	for(int i = 10; i <= 180; i+=20){
		glColor3f(1.0, 0.0, 1.0);	
		glPushMatrix();
		glTranslated(-0.30, 0.23, 0.0);
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.30, 0.23, 0.0);
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}
	//hand
	glColor3f(1.0, 1.0, 1.0);	
	glPushMatrix();
	glTranslated(-0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();

}
//Draw right arm
void rightArm(){
	glColor3f(1.0, 0.0, 1.0);	
	glPushMatrix();
	glTranslated(0.30, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glColor3f(0.0, 0.60, 1.0);	
	glPushMatrix();
	glTranslated(0.270, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.33, 0.50, 0.0);
	glScaled(0.07, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//Hand collar
	for(int i = 0; i <= 180; i+=20){
		glColor3f(0.0, 0.60, 1.0);	
		glPushMatrix();
		glTranslated(0.30, 0.23, 0.0);
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.30, 0.23, 0.0);
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}
	for(int i = 10; i <= 180; i+=20){
		glColor3f(1.0, 0.0, 1.0);	
		glPushMatrix();
		glTranslated(0.30, 0.23, 0.0);
		glRotated(-i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.30, 0.23, 0.0);
		glRotated(i, 0.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 0.05);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(1.0, 2.0, 1.0);
		glutSolidSphere(.02, 20, 20);
		glPopMatrix();
	}
	//hand
	glColor3f(1.0, 1.0, 1.0);	
	glPushMatrix();
	glTranslated(0.30, 0.17, 0.0);
	glScaled(0.80, 1.0, 1.0);
	glutSolidSphere(.08, 20, 20);
	glPopMatrix();
}
//Draw left leg
void leftLeg(){
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();	
	glTranslated(-0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//shoe
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(-0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
}
//Draw right leg
void rightLeg(){
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();	
	glTranslated(0.20, -0.220, 0.0);
	glScaled(0.20, 1.0, 0.20);
	glutSolidCube(.50);
	glPopMatrix();
	//shoe
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(0.20, -0.50, 0.15);
	glScaled(1.0, 0.60, 1.50);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.20, -0.485, 0.0);
	glScaled(1.0, 0.65, 1.0);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
}


void myInit(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0*(64/48.0), 2.0*(64/48.0), -2.0, 2.0, 0.1, 100.0); //left, right, bottom, top, near, far Parallel Projection
	glViewport(0, 0, 800, 640);

	//set properties of the surface material
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f}; // 
	GLfloat mat_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat mat_shininess[] = {50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light_position[] = {2.0f, 2.0f, 3.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

}
//If nothing else happening, do walking motion
void Walk (void)
{
	static float mf = 0.05;	//limb movement factor
 
	limbAngle += mf;
 
	if(limbAngle >  30.0){
		mf = -0.70;
	}
	if(limbAngle < -30.0){
		mf =  0.70;
	}
	glutPostRedisplay ();
}


void myDisplay(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.50, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(walk == true){
	//Rotating around Robot
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	drawRobot();
	glPopMatrix();
	//Left arm walking movement
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	glTranslated(-0.30, 1.0, 0.0);
	glRotated(limbAngle, 1.0, 0.0, 0.0f);
	glTranslated(0.30, -1.0, 0.0);
	leftArm();
	glPopMatrix();
	//Right arm walking movement
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	glTranslated(0.30, 1.0, 0.0);
	glRotated(-limbAngle, 1.0, 0.0, 0.0f);
	glTranslated(-0.30, -1.0, 0.0);
	rightArm();
	glPopMatrix();
	//Left leg walking movement
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	glRotated(-limbAngle, 1.0, 0.0, 0.0f);
	leftLeg();
	glPopMatrix();
	//Right leg walking movement
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	glRotated(limbAngle, 1.0, 0.0, 0.0f);
	rightLeg();
	glPopMatrix();
	}
	else if(walk == false){
	//Rotating around Robot and no Walking
	glPushMatrix();
	glRotated(vertAngle, 1.0, 0.0, 0.0f);
	glRotated(horizAngle, 0.0, 1.0, 0.0f);
	drawRobot();
	leftArm();
	rightArm();
	leftLeg();
	rightLeg();
	glPopMatrix();
	}

	/*Each new picture is drawn in the invisible buffer, and when the drawing is
	complete the display switches to it.*/
	glutSwapBuffers();
}



void myKeyboard(unsigned char key, int x, int y){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static double zoomFactor = 1.0;	//Zooming in/out 
	static double zoomFactor2 = 1.0;

	switch (key)
    {
    case 's':
		if(walk == false){
			walk = true;
		}
		else if(walk == true){
			walk = false;
		}
	break;
	case 'z':
		zoomFactor -= 0.02;
		zoomFactor2 += 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800*zoomFactor, 640*zoomFactor);
	break;
	case 'Z':
		zoomFactor += 0.02;
		zoomFactor2 -= 7.7;
		glViewport(1.0 * zoomFactor2, 1.0 * zoomFactor2, 800*zoomFactor, 640*zoomFactor);
	break;
	case 'd':
		vertAngle = 0.0;
		horizAngle = 0.0;
		walk = false;
	break;
    case 'e':
		exit(0);			// exit
    }
	
	/*sets a flag so that when the mainloop is ready it will call the real "display" callback once per mainloop iteration*/
	glutPostRedisplay();		//refresh the display, redraw the image now
}

void arrowKeyPress(int key, int x, int y){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(key){
	case GLUT_KEY_RIGHT:
		horizAngle += 2;
	break;
	case GLUT_KEY_LEFT:
		horizAngle -= 2;
	break;
	case GLUT_KEY_UP:
		vertAngle -= 2;
	break;
	case GLUT_KEY_DOWN:
		vertAngle += 2;
	break;
    }

    glutPostRedisplay();		// redraw the image now
}


void main(int argc, char **argv){

	glutInit(&argc, argv);  //OpenGL utility kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //double buffering for animation
	glutInitWindowSize(800, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Give me your candy Kid!!!");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(Walk);		//Ongoing walking function for when nothing else happening

	glutKeyboardFunc(myKeyboard);	//myKeyboard will handle normal keys
	glutSpecialFunc(arrowKeyPress);	//arrowKeyPress will handle special keys

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable (GL_COLOR_MATERIAL);	//Material color match vertex color specified

	myInit();
	glutMainLoop();
}