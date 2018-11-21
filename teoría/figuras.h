//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	//void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void cilindro(float radio, float altura, int resolucion, float parte, boolean tapa, boolean base, GLuint text_tap, GLuint text_lat);
	void cilindro(float radio, float altura, int resolucion, float parte, GLuint text_tap, GLuint text_lat, boolean entrada);
	//void cilindro(float radio, float altura, int resolucion, float parte, boolean tapa, boolean base, GLuint text);
	//void cilindro(float radio, float altura, int resolucion, float parte, boolean tapa, GLuint text);
	//void cilindro(float radio, float altura, int resolucion, float parte, GLuint text);
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	//void prisma (float altura, float largo, float profundidad, GLuint text);
	void prisma(float altura, float largo, float profundidad, GLuint text_lat, GLuint text_sup);
	void prisma_ent(float altura, float largo, float profundidad, GLuint text_fre, GLuint text_lat, GLuint text_sup);
	void prisma_ent(float altura, float largo, float profundidad, GLuint text_lat, GLuint text_sup);
	void jard_g(float altura, float largo, float profundidad, GLuint text, GLuint text2);
	//void jard_g(float altura, float largo, float profundidad, GLuint text);
	//void jard_p(float altura, float largo, float profundidad, GLuint text);
	void jard_p(float altura, float largo, float profundidad, GLuint text, GLuint text2);
	void prisma_t(float altura, float largo, float profundidad, GLuint text_lat, GLuint text_sup);
	//void prisma_t(float altura, float largo, float profundidad, GLuint text);
	//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void prisma(float altura, float largo, float profundidad, boolean tapa, boolean base, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);


};
