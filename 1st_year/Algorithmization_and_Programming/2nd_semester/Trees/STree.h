#include <iostream>
#include <gl/GL.h>
#include <glut.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class STree
{
private:
	int data;
	STree* left;
	STree* right;
	STree* parent;
public:
	GLfloat x = 0, y = 4;
	int state, level = 1;

	STree(int);
	STree();
	~STree();

	STree* findElement(int data);
	STree* findMin();
	STree* findMax();

	STree* getLeft();
	STree* getRight();
	int getData();
	int getHeight();

	void setLeft(STree*);
	void setRight(STree*);
	
	STree* balanced(int);
	void inOrder(STree*);
	void insertNode(int);
	STree* next();
	void deleteNode(int);
	void printTree(int);

	friend void LevelCounter(STree* root);
	friend void CountLevels(STree* root, void (*LevelCounter)(STree* root));
	friend void Coords(STree* node);
	friend void CoordsCalculate(STree* node, void (*Coords)(STree* node));
	friend void DrawOneNode(STree* root);
	friend void DrawNodes(STree* root, void (*DrawOneNode)(STree* root));
	friend void DrawOneLine(STree* root);
	friend void DrawLines(STree* root, void (*DrawOneLine)(STree* root));
	void drawTree(int argc, char** argv, int win_height, int win_width);
	void PrintinInfo(int& maxim, vector<int>& arr);
	void DrawCircle(char color, GLfloat x, GLfloat y, float radiusB, int count);
	void DrawOutLine(float tmp_x, float tmp_y, float radiusB);
	void DrawNode(const char* str, GLfloat x, GLfloat y, char color);
	void reshape(int heigth, int wigth);
	void display();
};



