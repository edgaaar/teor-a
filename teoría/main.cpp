//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

CFiguras f;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat azul[] = { 0.0, 0.0, 1.0 };
GLfloat blanco[] = { 1.0, 1.0, 1.0 };
GLfloat verde[] = { 0.0, 1.0, 0.0 };
GLfloat rojo[] = { 1.0, 0.0, 0.0 };
GLfloat negro[] = { 0.0, 0.0, 0.0 };
GLfloat amarillo[] = { 1.0, 1.0, 0.0 };
GLfloat posicion[] = { 0.0, 0.0, 10.0, 1.0 };
GLfloat posicion2[] = { 0.0, 10.0, 0.0, 1.0 };

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture asfalto;
CTexture tree;
CTexture tree2;
CTexture edi;
CTexture pasto;
CTexture borde;
CTexture ama;
CTexture frente;
CTexture lateral;
CTexture superior;

CFiguras sky;

void arbol(CTexture textura)
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, textura.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	//glLightfv(GL_LIGHT1, GL_AMBIENT, blanco);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, blanco);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, blanco);
	glLightfv(GL_LIGHT1, GL_POSITION, posicion);

	glLightfv(GL_LIGHT2, GL_AMBIENT, blanco);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, blanco);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, blanco);
	glLightfv(GL_LIGHT2, GL_POSITION, posicion2);


	//glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	asfalto.LoadTGA("asp.tga");
	asfalto.BuildGLTexture();
	asfalto.ReleaseImage();

	tree.LoadTGA("ar1.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	tree2.LoadTGA("ar2.tga");
	tree2.BuildGLTexture();
	tree2.ReleaseImage();

	edi.LoadTGA("edi1.tga");
	edi.BuildGLTexture();
	edi.ReleaseImage();

	pasto.LoadTGA("pas1.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	borde.LoadTGA("mad1.tga");
	borde.BuildGLTexture();
	borde.ReleaseImage();

	ama.LoadTGA("am.tga");
	ama.BuildGLTexture();
	ama.ReleaseImage();

	frente.LoadTGA("fren.tga");
	frente.BuildGLTexture();
	frente.ReleaseImage();

	lateral.LoadTGA("lat.tga");
	lateral.BuildGLTexture();
	lateral.ReleaseImage();

	superior.LoadTGA("sup.tga");
	superior.BuildGLTexture();
	superior.ReleaseImage();
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);
	objCamera.Move_Camera(-20);
	objCamera.UpDown_Camera(3);
	g_lookupdown = 13.0f;
	//objCamera.Position_Camera(-10, 15, 50, -10, 0, 0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glEnable(GL_LIGHTING);
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				//glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				//glMaterialfv(GL_FRONT, GL_DIFFUSE, rojo);
				sky.skybox(300.0, 300.0, 300.0,text1.GLindex);
				//glEnable(GL_LIGHTING);
				glColor3f(1.0,0.0,0.0);
			glPopMatrix();

			glBegin(GL_LINES);
				glColor3f(1.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(100.0, 0.0, 0.0);
				glColor3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 100.0, 0.0);
				glColor3f(0.0, 0.0, 1.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 100.0);
				glColor3f(1.0, 0.0, 0.0);
			glEnd();

			glPushMatrix();//asfalto
				glTranslatef(0, -2.5, 10);
				f.prisma(1, 120, 122,asfalto.GLindex,asfalto.GLindex);
			glPopMatrix();
			//�rbol frente 1
			glPushMatrix();
				glTranslatef(-45, 0, 35);
				glScalef(0.4, 1.0, 0.4);
				arbol(tree);
			glPopMatrix();
			//�rbol frente 2
			glPushMatrix();
				glTranslatef(45, 0, 35);
				glScalef(0.3, 1.0, 0.3);
				arbol(tree);
			glPopMatrix();
			//�rbol atr�s 1
			glPushMatrix();
				glTranslatef(-20, 0, -33);
				glScalef(0.4, 1.0, 0.4);
				arbol(tree2);
			glPopMatrix();
			//�rbol atr�s 2
			glPushMatrix();
				glTranslatef(20, 0, -33);
				glScalef(0.4, 1.0, 0.4);
				arbol(tree2);
			glPopMatrix();
			//edificio der
			glPushMatrix();
				glTranslatef(20.25, 27 + 1, 0);
				f.prisma(54, 27, 27, edi.GLindex, 0);
			glPopMatrix();
			//edificio izq
			glPushMatrix();
				glTranslatef(-20.25, 27 + 1, 0);
				f.prisma(54, 27, 27, edi.GLindex,0);
			glPopMatrix();
			//vest�bulo
			glPushMatrix();
				glTranslatef(0, 5.25 + 1, 6.75);
				f.prisma(10.5, 13.5, 13.5, ama.GLindex,ama.GLindex);
			glPopMatrix();

			//base circular dcha
			glPushMatrix();
				glScalef(0.7, 1, 0.5);
				glTranslatef(14.5, -2.1, 27);
				//glRotatef(14.03, 1, 0, 0);
				f.cilindro(33.75, 3, 50,0.5,pasto.GLindex,borde.GLindex, true);
			glPopMatrix();

			//base circular izq
			glPushMatrix();
				glScalef(0.7, 1, 0.5);
				glTranslatef(-14.5, 0.9, 27);
				glRotatef(180, 0, 0, 1);
				f.cilindro(33.75, 3, 50, 0.5, pasto.GLindex, borde.GLindex, true);
			glPopMatrix();

			//base cuadrangular
			glPushMatrix();
				glTranslatef(0, -0.5, 0);
				//glRotatef(14.03, 1, 0, 0);
				f.prisma(3, 67.5, 27, false, false, borde.GLindex);
			glPopMatrix();


			

/////////////////////--------JARDINERAS------------////////////////////////
				//jardinera 1
				glPushMatrix();
				glTranslatef(7, 0, 5);
				glScalef(0.9, 1, 1.2);
					//pico jardinera
					glPushMatrix();
						glTranslatef(45, -0.5, -25);
						glRotatef(90, 0, 1, 0);
						f.prisma_t(3, 10, 10, borde.GLindex, pasto.GLindex);
					glPopMatrix();
					//rect�ngulo jardinera
					glPushMatrix();
						glTranslatef(45, -0.5, -10);
						f.prisma(3, 10, 20, borde.GLindex, pasto.GLindex);
					glPopMatrix();
				glPopMatrix();

				//jardinera 2
				glPushMatrix();
					glTranslatef(0, 0, 6);
					glScalef(1, 1, 1.3);

					//Semic�rculo
					glPushMatrix();
						glTranslatef(15, -2.01, -30);
						glRotatef(90, 0, -1, 0);
						f.cilindro(5, 3, 35, 1, true, true, pasto.GLindex, borde.GLindex);
					glPopMatrix();

					//pico jardinera
					glPushMatrix();
						glTranslatef(40, -0.5, -30);
						glRotatef(90, 0, -1, 0);
						f.prisma_t(3, 10, 10, borde.GLindex, pasto.GLindex);
					glPopMatrix();

					//rect�ngulo jardinera
					glPushMatrix();
						glTranslatef(25, -0.5, -30);
						glRotatef(90, 0, 1, 0);
						f.prisma(3, 10, 20, borde.GLindex, pasto.GLindex);
					glPopMatrix();
				glPopMatrix();

				//jardinera peque�a
				glPushMatrix();
					glTranslatef(6.75, -2,60);
					glRotatef(270, 1, 0, 0);
					f.jard_p(1.5, 1.5, 3, borde.GLindex, pasto.GLindex);
				glPopMatrix();

				//jardinera grande
				glPushMatrix();
					glTranslatef(35, -2, 45);
					glRotatef(270, 1, 0, 0);
					f.jard_g(5, 4, 3, borde.GLindex, pasto.GLindex);
				glPopMatrix();

				////////JARDINERAS LADO IZQUIERDO/////////////////

				glPushMatrix();
				glTranslatef(-0, -1.0, 0);
				glRotatef(180, 0, 0, 1);
					//jardinera 1
					glPushMatrix();
					glTranslatef(7, 0, 5);
					glScalef(0.9, 1, 1.2);
					//pico jardinera
					glPushMatrix();
					glTranslatef(45, -0.5, -25);
					glRotatef(90, 0, 1, 0);
					f.prisma_t(3, 10, 10, borde.GLindex, pasto.GLindex);
					glPopMatrix();
					//rect�ngulo jardinera
					glPushMatrix();
					glTranslatef(45, -0.5, -10);
					f.prisma(3, 10, 20, borde.GLindex, pasto.GLindex);
					glPopMatrix();
					glPopMatrix();

					//jardinera 2
					glPushMatrix();
					glTranslatef(0, 0, 6);
					glScalef(1, 1, 1.3);

					//Semic�rculo
					glPushMatrix();
					glTranslatef(15, -2.01, -30);
					glRotatef(90, 0, -1, 0);
					f.cilindro(5, 3, 35, 1, true, true, pasto.GLindex, borde.GLindex);
					glPopMatrix();

					//pico jardinera
					glPushMatrix();
					glTranslatef(40, -0.5, -30);
					glRotatef(90, 0, -1, 0);
					f.prisma_t(3, 10, 10, borde.GLindex, pasto.GLindex);
					glPopMatrix();

					//rect�ngulo jardinera
					glPushMatrix();
					glTranslatef(25, -0.5, -30);
					glRotatef(90, 0, 1, 0);
					f.prisma(3, 10, 20, borde.GLindex, pasto.GLindex);
					glPopMatrix();
					glPopMatrix();

					//jardinera peque�a
					glPushMatrix();
					glTranslatef(6.75, -2, 60);
					glRotatef(270, 1, 0, 0);
					f.jard_p(1.5, 1.5, 3, borde.GLindex, pasto.GLindex);
					glPopMatrix();

					//jardinera grande
					glPushMatrix();
					glTranslatef(35, -2, 45);
					glRotatef(270, 1, 0, 0);
					f.jard_g(5, 4, 3, borde.GLindex, pasto.GLindex);
					glPopMatrix();
				glPopMatrix();
///////////////////////////////////////////////////////////////////////////

			//salida
			glPushMatrix();
				glTranslatef(0, 4 + 1, -8.5 + 6.75);
				f.prisma(8.0, 13.5, 3.5, ama.GLindex,ama.GLindex);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, -3, 0);
				//explanada salida
				glPushMatrix();
					glTranslatef(0, 1.5 + 1,-6.75 -8.5 + 6.75);
					f.prisma(3.0, 13.5, 10, asfalto.GLindex,asfalto.GLindex);
				glPopMatrix();
				//escalon1
				glPushMatrix();
					glTranslatef(0, 0.375 + 1, -9 -6.75 - 8.5 + 6.75);
					f.prisma(0.6, 13.5, 8, asfalto.GLindex, asfalto.GLindex);
				glPopMatrix();
				//escalon2
				glPushMatrix();
					glTranslatef(0, 0.975 + 1,2 -9 - 6.75 - 8.5 + 6.75);
					f.prisma(0.6, 13.5, 8, asfalto.GLindex, asfalto.GLindex);
				glPopMatrix();
				//escalon3
				glPushMatrix();
					glTranslatef(0, 1.575 + 1,4 -9 - 6.75 - 8.5 + 6.75);
					f.prisma(0.6, 13.5, 8, asfalto.GLindex, asfalto.GLindex);
				glPopMatrix();
				//escalon4
				glPushMatrix();
					glTranslatef(0, 2.175 + 1,6 -9 - 6.75 - 8.5 + 6.75);
					f.prisma(0.6, 13.5, 8, asfalto.GLindex, asfalto.GLindex);
				glPopMatrix();
			glPopMatrix();
			/*glPushMatrix();
				//glTranslatef(0.0, 8.0, 0.0);
				glMaterialfv(GL_FRONT, GL_AMBIENT, negro);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, blanco);
				//glMaterialfv(GL_FRONT, GL_SPECULAR, blanco);
				//glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
				f_luis.esfera(4.0, 20, 20, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(8.0, 0.0, 0.0);
				glMaterialfv(GL_FRONT, GL_AMBIENT, negro);
				//glMaterialfv(GL_FRONT, GL_DIFFUSE, blanco);
				//glMaterialfv(GL_FRONT, GL_SPECULAR, blanco);
				//glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
				f_luis.cilindro(3.0, 3.0, 30, 0);
			glPopMatrix();*/

		glPopMatrix(); 
		//entrada
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1f);
		glPushMatrix();
		glTranslatef(0, 4.6, 6.5 + 15.4);
		f.prisma_ent(13.5, 20, 17, frente.GLindex, lateral.GLindex, superior.GLindex);
		glPopMatrix();
		//glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 550.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto de Computaci�n Gr�fica"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
