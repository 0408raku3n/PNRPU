#include "./STree.h"
#include <iostream>
#include <ctime>
using namespace std;

int depth, width, maxim = 0;
float radiusA = 0.5;
STree* tree = new STree(10);

void STree::drawTree(int argc, char** argv, int win_height, int win_width)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(win_height, win_width);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Tree");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
}

void LevelCounter(STree* root)
{
	if (root->parent != NULL)
	{
		root->level = root->parent->level + 1;
	}
	if (depth < root->level)
	{
		depth = root->level;
	}
}

void CountLevels(STree* root, void (*LevelCounter)(STree* root))
{
	if (root == NULL)
	{
		return;
	}
	(*LevelCounter)(root);
	CountLevels(root->left, LevelCounter);
	CountLevels(root->right, LevelCounter);
}

void Coords(STree* node)
{
	if (node->parent != NULL)
	{
		if (node->level == 2)
		{
			node->x = node->parent->x + node->state * (pow(2, depth - 1) / 2);
		}
		else
		{
			node->x = node->parent->x + node->state * (pow(2, depth - 1) / pow(2, node->level - 1));
			node->y = node->parent->y - 1;
		}
	}
}

void CoordsCalculate(STree* node, void (*Coords)(STree* node))
{
	if (node == NULL)
	{
		return;
	}
	(*Coords)(node);
	if (node->left != NULL)
	{
		node->left->state = -1;
		CoordsCalculate(node->left, Coords);
	}
	if (node->right != NULL)
	{
		node->right->state = 1;
		CoordsCalculate(node->right, Coords);
	}
	return;
}

void DrawCircle(char color, GLfloat x, GLfloat y, float radiusB, int count)
{
	if (color == 'g')
	{
		glColor3f(0, 0, 0.0, 0.0);
	}
	else if (color == 'r')
	{
		glColor3f(250.0, 0.0, 0.0);
	}
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (int i = 0; i <= count; i++)
	{
		glVertex2f((x + (radiusA * cos(i * count))), (y + (radiusB * sin(i * count))));
	}
	glEnd();
}

void DrawOutLine(float tmp_x, float tmp_y, float radiusB)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i <= radiusA; i++)
	{
		for (int j = 0; j <= 540; j++)
		{
			tmp_x = radiusA * sin(j) + tmp_x;
			tmp_y = radiusB * cos(j) + tmp_y;
			glVertex2f(tmp_x - 0.35, tmp_y - 0.1);
		}
	}
	glEnd();
}

void drawNode(const char* str, GLfloat x, GLfloat y, char color)
{
	double c = 0;
	c = (4 + depth) / pow(2, depth);
	float radiusB = c * radiusA;
	int count = 50;
	DrawCircle(color, x, y, radiusB, count);
	DrawOutLine(x, y, radiusB);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(x - 0.075, y - 0.075);
	const char* p;
	for (p = str; *p != '\0'; p++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
	}
}

void DrawOneLine(STree* root)
{
	if (root->parent != NULL)
	{
		glBegin();
		glVertex2d(root->parent->x, root->parent->y);
		glVertex2d(root->x, root->y);
		glEnd();
	}
}

void DrawLines(STree* root, void (*DrawOneLine)(STree* root))
{
	if (root == NULL)
	{
		return;
	}
	(*DrawOneLine)(root);
	DrawLines(root->left, DrawOneLine);
	DrawLines(root->right, DrawOneLine);
}

void DrawOneNode(STree* root)
{
	char color;
	if (root->parent != NULL)
	{
		if (root->data == maxim)
			color = 'r';
		else
			color = 'g';
		drawNode(to_string(root->data).c_str(), root->x, root->y, color);
	}
}

void DrawNodes(STree* root, void (*DrawOneNode)(STree* root))
{
	char color;
	if (root == NULL)
	{
		return;
	}
	(*DrawOneNode)(root);
	DrawNodes(root->left, DrawOneNode);
	DrawNodes(root->right, DrawOneNode);
	if (root->data == maxim)
	{
		color = 'r';
	}
	else
	{
		color = 'g';
	}
	drawNode(to_string(tree->data).c_str(), tree->x, tree->y, color);
}

void reshape(int height, int width)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIndentity();
	glViewport(0, 0, height, width);
	gluOrtho2D(-pow(2, depth - 1), pow(2, depth - 1), -depth, 5);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	DrawLines(tree, DrawOneLine);
	DrawNodes(tree, DrawOneNode);
	glutSwapBuffers();
}

void PrintingInfo(int& maxim, vector<int>& arr)
{
	maxim = *max_element(arr.begin(), arr.end());
	cout << "\nMax element in tree:" << maxim;
	depth = tree->getHeight();
	width = pow(2, depth - 1);
	cout << "\nDepth of tree: " << depth << "\nWidth of tree:" << width;
}

int main(int argc, char** argv)
{
	vector<int> arr = { 3,8,6,10,5,2,15,-1,3, 0 };
	for (int i = 0; i < arr.size(); i++)
	{
		tree->insertNode(arr[i]);
	}
	PrintingInfo(maxim, arr);
	CountLevels(tree, LevelCounter);
	CoordsCalculate(tree, Coords);
	tree->drawTree(argc, argv, 960, 720);
}