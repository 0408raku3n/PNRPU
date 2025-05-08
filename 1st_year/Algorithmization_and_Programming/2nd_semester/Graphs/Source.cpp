#include <iostream>
#include "./Graph.h"
#include "./LineText.h"
#include "./DataCircle.h"
#include "./Position.h"
#include <glut.h>
using namespace std;

int WinW = 800;
int WinH = 600;
int x = 200;
int y = 200;
string title = "Graph";
Graph<int> graph(10);

double to_rad(const double& d)
{
	return d * 3.1415926535897932 / 180;
}

vector<Position> getPolyCircleVertPos(const Position& pos, const int& radius, const int& n)
{
	vector<Position> result(n);
	for (int i = 0; i < n; i++)
	{
		double angle = to_rad(360 / double(n) * double(i));
		result[i] = Position(pos.x + radius * cos(angle), pos.y + radius * sin(angle));
	}
	return result;
}

template <class T>
void Graph<T>::DrawGraph()
{
	int radiusCircle = min(WinW, WinH) / 2 - 40;
	Position posCircle(WinW / 2, WinH / 2);
	vector<Position> VertexArray = getPolyCircleVertPos(posCircle, radiusCircle, this->vertexList.size());

	vector<DataCircle> circles(VertexArray.size());
	list<LineText> edges;

	for (int i = 0; i < VertexArray.size(); i++)
	{
		circles[i].setData(this->vertexList[i]);
		circles[i].setPosition(VertexArray[i].x, VertexArray[i].y);
	}

	for (int i = 0; i < this->adjMatrix.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (this->adjMatrix[i][j])
			{
				LineText edge(this->adjMatrix[i][j]);
				edge.setStart(VertexArray[i]);
				edge.setEnd(VertexArray[j]);
				edges.push_back(edge);
			}
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}

	for (LineText i : edges)
	{
		i.toBuff();
	}

	for (DataCircle i : circles)
	{
		i.toBuff();
	}
}

void draw()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, WinW, 0, WinH);

	graph.DrawGraph();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	bool* visitedVerts = new bool[20];
	fill(visitedVerts, visitedVerts + 20, false);



	int vertex, amountVerts, amountEdges, sourceVertex, targetVertex, weightEdge;
	cout << "Enter amount of vertexes: "; cin >> amountVerts;
	for (int i = 0; i < amountVerts; i++)
	{
		graph.insertVertex(i);
	}
	graph.PrintMatrix();

	cout << "\nEnter amount of edges: "; cin >> amountEdges;
	for (int i = 0; i < amountEdges; i++)
	{
		cout << "\nEnter source vertex: "; cin >> sourceVertex;
		cout << "Enter target vertex : "; cin >> targetVertex;
		cout << "Enter weight of edge:"; cin >> weightEdge;
		graph.insertEdge(sourceVertex, targetVertex, weightEdge);
	}
	graph.PrintMatrix();

	cout << "\nEnter vertex to delete:"; cin >> vertex;
	graph.deleteVertex(vertex);

	graph.PrintMatrix();

	cout << "\nEnter source vertex of changing edge: "; cin >> sourceVertex;
	cout << "Enter target vertex of changing edge:"; cin >> targetVertex;
	cout << "Enter weight to change weight:"; cin >> weightEdge;
	graph.changeEdge(sourceVertex, targetVertex, weightEdge);
	graph.PrintMatrix();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WinW, WinH);
	glutInitWindowPosition(x, y);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(draw);
	glutMainLoop();
	/*cout << "\nEnter vertex, where to start the crawl:"; cin >> vertex;
	graph.DFS(vertex, visitedVerts);

	cout << "\nEnter vertex, where to start the crawl:"; cin >> vertex;
	graph.BFS(vertex, visitedVerts);*/
}