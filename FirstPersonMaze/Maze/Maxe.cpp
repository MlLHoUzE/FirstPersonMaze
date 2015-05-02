#include "Texture.h"
#include<GL/glut.h>
/*
				BY MAX MCCRAW AND RYAN HAMMOND

*/

#define checkImageWidth 64		//set up for textures
#define checkImageHeight 64		//set up for textures
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];	//set up for textures

static GLuint texName;

int playerX = 1.0;
int playerY = 1.0;

int lookX = 0.0;
int lookY = -1.0;
float cameraX, cameraY;
Texture wallTexture;	//unique texture name
Texture floorTexture;	//unique texture name 2
Texture startTexture;
Texture exitTexture;

int maze[10][10] = 
{ 
{1,1,1,1,1,1,1,1,1,1},
{1,2,0,0,0,0,0,1,3,1},
{1,1,1,1,0,1,0,0,0,1},
{1,0,0,0,0,1,1,1,0,1},
{1,0,1,0,1,1,2,1,0,1},
{1,0,1,0,1,1,0,1,0,1},
{1,0,1,0,0,1,0,1,0,1},
{1,0,1,1,0,1,0,1,0,1},
{1,4,1,1,2,1,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

void init()
{
	glClearColor(0.5, 0.0, 0.5, 0.0);
	//glShadeModel(); // GL_FLAT || GL_SMOOTH

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 4)
			{
				playerX = j;
				playerY = i;
			}
		}
	}
}
void firstTexture()	//load first texture
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &wallTexture.texID);

	glBindTexture(GL_TEXTURE_2D, wallTexture.texID);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, wallTexture.bpp / 8, wallTexture.width, wallTexture.height, 0, wallTexture.type, GL_UNSIGNED_BYTE, wallTexture.imageData);
}

void secondTexture()	//load first texture
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &floorTexture.texID);

	glBindTexture(GL_TEXTURE_2D, floorTexture.texID);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, floorTexture.bpp / 8, floorTexture.width, floorTexture.height, 0, floorTexture.type, GL_UNSIGNED_BYTE, floorTexture.imageData);
}

void thirdTexture()	//load first texture
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &startTexture.texID);

	glBindTexture(GL_TEXTURE_2D, startTexture.texID);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, startTexture.bpp / 8, startTexture.width, startTexture.height, 0, startTexture.type, GL_UNSIGNED_BYTE, startTexture.imageData);
}

void fourthTexture()	//load first texture
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &exitTexture.texID);

	glBindTexture(GL_TEXTURE_2D, exitTexture.texID);



	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, exitTexture.bpp / 8, exitTexture.width, exitTexture.height, 0, exitTexture.type, GL_UNSIGNED_BYTE, exitTexture.imageData);
}
void drawCube(float x, float y)
{
	firstTexture();
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x, y, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x, y + 1, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x + 1, y + 1, 0.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x + 1, y, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x, y, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x, y + 1, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x + 1, y + 1, 1.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x + 1, y, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x, y, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x + 1, y, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x + 1, y, 1.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x, y, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x, y + 1, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x + 1, y + 1, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x + 1, y + 1, 1.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x, y + 1, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x + 1, y, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x + 1, y + 1, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x + 1, y + 1, 1.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x + 1, y, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(x, y, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(x, y + 1, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(x, y + 1, 1.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(x, y, 1.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat ambient_color[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat diffuse_color[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 2.0, 1.0 };
	GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	//glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);


	// lookX
	// lookY

	//gluLookAt(playerX-1.0, playerY-1.0, 5.0, playerX, playerY, 0.0, 0.0, 1.0, 0.0);
	if (lookX == 0)
	{
		cameraX = playerX + 0.5;

		if (lookY > 0)
			cameraY = playerY;
		else
			cameraY = playerY + 1;
	}
	else if (lookY == 0)
	{
		cameraY = playerY + 0.5;

		if (lookX > 0)
			cameraX = playerX;
		else
			cameraX = playerX + 1.0;
	}

	gluLookAt(cameraX, cameraY, 0.5, cameraX + lookX, cameraY + lookY, 0.5, 0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	secondTexture();
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord3f(10.0, 0.0, 0.0); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord3f(10.0, 10.0, 0.0); glVertex3f(10.0, 10.0, 0.0);
	glTexCoord3f(0.0, 10.0, 0.0); glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 1)
			{
				glColor3f(1.0, 1.0, 1.0);
				drawCube(j, i);
				/*
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(j,i,0.0);
				glVertex3f(j+1,i,0.0);
				glVertex3f(j+1,i+1,0.0);
				glVertex3f(j,i+1,0.0);
				glEnd();
				*/
			}
			else if (maze[i][j] == 2)
			{
				glColor3f(1.0, 1.0, 0.0);
				glPushMatrix();
				glTranslatef(j + 0.5, i + 0.5, 0.5);
				glutSolidSphere(0.25, 25, 25);
				glPopMatrix();

				/*
				glColor3f(1.0, 1.0, 0.0);
				glBegin(GL_QUADS);
				glVertex3f(j, i, 0.0);
				glVertex3f(j + 1, i, 0.0);
				glVertex3f(j + 1, i + 1, 0.0);
				glVertex3f(j, i + 1, 0.0);
				glEnd();
				*/
			}
			else if (maze[i][j] == 3)
			{
				glColor3f(0.0, 1.0, 1.0);
				fourthTexture();
				glPushMatrix();
				glTranslatef(j, i, 0.0);
				glBegin(GL_QUADS);
				glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.01);
				glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(0.0, 1.0, 0.01);
				glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.0, 1.0, 0.01);
				glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.01);
				glEnd();
				glPopMatrix();
				/*
				glColor3f(0.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex3f(j, i, 0.0);
				glVertex3f(j + 1, i, 0.0);
				glVertex3f(j + 1, i + 1, 0.0);
				glVertex3f(j, i + 1, 0.0);
				glEnd();
				*/
			}
			else if (maze[i][j] == 4)
			{
				glColor3f(0.0, 1.0, 0.0);
				thirdTexture();
				glPushMatrix();
				glTranslatef(j, i, 0.0);
				glBegin(GL_QUADS);
				glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 0.01);
				glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.01);
				glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 1.0, 0.01);
				glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 0.01);
				glEnd();
				glPopMatrix();
				/*
				glColor3f(0.0, 1.0, 0.0);
				glBegin(GL_QUADS);
				glVertex3f(j, i, 0.0);
				glVertex3f(j + 1, i, 0.0);
				glVertex3f(j + 1, i + 1, 0.0);
				glVertex3f(j, i + 1, 0.0);
				glEnd();
				*/
			}
		}
	}


	//glColor3f(0.0, 0.0, 1.0);
	//drawCube(playerX, playerY);
	/*
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(playerX, playerY, 0.0);
	glVertex3f(playerX + 1, playerY, 0.0);
	glVertex3f(playerX + 1, playerY + 1, 0.0);
	glVertex3f(playerX, playerY + 1, 0.0);
	glEnd();
	*/

	


	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); // GL_PROJECTION || GL_MODELVIEW
	glLoadIdentity();
	glFrustum(-0.5, 0.5, -0.5, 0.5, 0.9, 10);
}

void keyboard(unsigned char key, int x, int y)
{

	if(key == 'w' || key == 'W')
	{
		if(lookX != 0)
		{
			if(maze[playerY][playerX + lookX] != 1 && maze[playerY][playerX + lookX] != 2)
			{
				playerX += lookX;
			}
		}
		else if(lookY != 0)
		{
			if (maze[playerY + lookY][playerX] != 1 && maze[playerY + lookY][playerX] != 2)
			{
				playerY += lookY;
			}
		}
	}
	else if(key == 'a' || key == 'A')
	{
		if( lookX == 1 )
		{
			lookX = 0;
			lookY = 1;
		}
		else if(lookX == -1)
		{
			lookX = 0;
			lookY = -1;
		}
		else if(lookY == 1)
		{
			lookY = 0;
			lookX = -1;
		}
		else if(lookY == -1)
		{
			lookY = 0;
			lookX = 1;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if( lookX == 1 )
		{
			lookX = 0;
			lookY = -1;
		}
		else if(lookX == -1)
		{
			lookX = 0;
			lookY = 1;
		}
		else if(lookY == 1)
		{
			lookY = 0;
			lookX = 1;
		}
		else if(lookY == -1)
		{
			lookY = 0;
			lookX = -1;
		}
	}
	/*
	if (key == 'a' && maze[playerY][playerX-1] != 1)
		playerX--;
	else if (key == 'd' && maze[playerY][playerX+1] != 1)
		playerX++;
	else if (key == 'w' && maze[playerY+1][playerX] != 1)
		playerY++;
	else if (key == 's' && maze[playerY - 1][playerX] != 1)
		playerY--;
		*/
	else if (key == 'f' || key == 'F')
	{
		if (maze[playerY + 1][playerX] == 2)
			maze[playerY + 1][playerX] = 0;
		else if (maze[playerY][playerX + 1] == 2)
			maze[playerY][playerX + 1] = 0;
		else if (maze[playerY - 1][playerX] == 2)
			maze[playerY - 1][playerX] = 0;
		else if (maze[playerY][playerX - 1] == 2)
			maze[playerY][playerX - 1] = 0;
	}
	else if (key == 'p' || key == 'P')
		exit(0);
	else if ((key == 'e' || key == 'E') && maze[playerY][playerX] == 3)
	{
		bool allTreasures = true;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (maze[i][j] == 2)
					allTreasures = false;
			}
		}

		if (allTreasures == true)
		{
			maze[playerY][playerX] = 0;
			maze[playerY - 1][playerX] = 0;
			maze[playerY + 1][playerX] = 0;
			maze[playerY][playerX + 1] = 0;
		}
	}

	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	LoadTGA(&wallTexture, "bricks2.tga");
	LoadTGA(&floorTexture, "Floor.tga");
	LoadTGA(&startTexture, "Start2.tga");
	LoadTGA(&exitTexture, "Exit.tga");
	//Initialize glut library
	glutInit(&argc, argv);
	//Set initial display mode for new context
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Maze");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}