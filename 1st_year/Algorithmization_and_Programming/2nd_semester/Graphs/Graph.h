#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

template <class T>
class Graph
{
private:
	vector<T> vertexList;
	vector<vector<int>> adjMatrix;
	int maxSize;
	queue<int> VertsQueue;
public:
	Graph();
	~Graph();
	Graph(const int&);

	bool isFull();
	bool isEmpty();
	void insertVertex(const T&);
	void deleteVertex(const T&);
	int GetVertPos(const T&);
	int GetAmountVerts();
	vector<T> GetNbrs(const T&);
	int GetWeight(const T&, const T&);
	void insertEdge(const T&, const T&, int);
	void changeEdge(const T&, const T&, int);
	void PrintMatrix();
	void DFS(T&, bool*);
	void BFS(T&, bool*);
	void DrawGraph();
};

template <class T>
Graph<T>::Graph()
{
}

template <class T>
Graph<T>::~Graph()
{
}

template <class T>
Graph<T>::Graph(const int& size)
{
	this->maxSize = size;
	this->adjMatrix = vector<vector<T>>(size, vector<T>(size));
	for (int i = 0; i < this->maxSize; i++)
	{
		for (int j = 0; j < this->maxSize; j++)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template <class T>
bool Graph<T>::isFull()
{
	return this->vertexList.size() == this->maxSize;
}

template <class T>
bool Graph<T>::isEmpty()
{
	return this->vertexList.size() == 0;
}

template <class T>
void Graph<T>::insertVertex(const T& vert)
{
	if (this->isFull())
	{
		cout << "\nIt's impossible to add vertex";
		return;
	}
	this->vertexList.push_back(vert);
}

template <class T>
void Graph<T>::deleteVertex(const T& vert)
{
	int VertPos = this->GetVertPos(vert);
	if (VertPos == -1)
	{
		cout << "\nVertex doesn't exist!";
		return;
	}
	this->adjMatrix.erase(adjMatrix.begin() + VertPos);
	for (auto& line : adjMatrix)
	{
		line.erase(line.begin() + VertPos);
	}
	this->vertexList.erase(vertexList.begin() + VertPos);
}

template <class T>
int Graph<T>::GetVertPos(const T& v)
{
	for (int i = 0; i < this->vertexList.size(); i++)
	{
		if (this->vertexList[i] == v)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
int Graph<T>::GetAmountVerts()
{
	return this->vertexList.size();
}

template <class T>
int Graph<T>::GetWeight(const T& v1, const T& v2)
{
	if (this->isEmpty()) return 0;

	int v1_p = this->GetVertPos(v1);
	int v2_p = this->GetVertPos(v2);

	if (v1_p == -1 || v2_p == -1)
	{
		cout << "\nOne of the nodes in the graph does not exist";
		return 0;
	}

	return this->adjMatrix[v1_p][v2_p];
}

template <class T>
vector<T> Graph<T>::GetNbrs(const T& vertex)
{
	vector<T> nbrsList;
	int pos = this->GetVertPos(vertex);
	if (pos != -1)
	{
		for (int i = 0; i < this->vertexList.size(); i++)
		{
			if (this->adjMatrix[pos][i] != 0)
			{
				nbrsList.push_back(this->vertexList[i]);
			}
		}
	}
	return nbrsList;
}

template <class T>
void Graph<T>::insertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != -1 && this->GetVertPos(vertex2) != -1)
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);

		if (this->adjMatrix[vertPos1][vertPos2] != 0)
		{
			cout << "\nThere is already an edge between the vertices";
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
		}
	}
	else if (this->GetVertPos(vertex1) == -1) cout << "\nSource vertex doesn't exist in the graph";
	else cout << "\nTarget vertex doesn't exist in the graph";
}

template <class T>
void Graph<T>::changeEdge(const T& vertex1, const T& vertex2, int weight)
{
	int vertPos1 = GetVertPos(vertex1);
	int vertPos2 = GetVertPos(vertex2);

	if (vertPos1 != -1 && vertPos2 != -1)
	{
		if (this->adjMatrix[vertPos1][vertPos2] == 0)
		{
			cout << "\nThere's not edge between therse vertices!";
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
		}
	}
	else if (vertPos1 == -1) cout << "\nSource vertex doesn't exist in the graph";
	else cout << "\nTarget vertex doesn't exist in the graph";
}

template <class T>
void Graph<T>::PrintMatrix()
{
	if (!this->isEmpty())
	{
		cout << "\nAdjacency matrix:";

		cout << "\n-  ";
		for (int i = 0; i < this->vertexList.size(); i++)
		{
			cout << vertexList[i] << " ";
		}
		cout << "\n";

		for (int i = 0; i < this->vertexList.size(); i++)
		{
			cout << this->vertexList[i] << " ";
			for (int j = 0; j < this->vertexList.size(); j++)
			{
				cout << " " << this->adjMatrix[i][j];
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "\nGraph is empty";
	}
}

template <class T>
void Graph<T>::DFS(T& startVertex, bool* visitedVerts)
{
	cout << "\nVertex " << startVertex << " is visited";
	visitedVerts[this->GetVertPos(startVertex)] = true;
	vector<T> neighbors = this->GetNbrs(startVertex);
	for (int i = 0; i < neighbors.size(); i++)
	{
		if (!visitedVerts[this->GetVertPos(neighbors[i])])
		{
			this->DFS(neighbors[i], visitedVerts);
		}
	}
}

template <class T>
void Graph<T>::BFS(T& startVertex, bool* visitedVerts)
{
	if (!visitedVerts[this->GetVertPos(startVertex)])
	{
		this->VertsQueue.push(startVertex);
		cout << "\nVertex " << startVertex << " is visited";
		visitedVerts[this->GetVertPos(startVertex)] = true;
	}
	vector<T> neighbors = this->GetNbrs(startVertex);
	this->VertsQueue.pop();
	for (int i = 0; i < neighbors.size(); i++)
	{
		if (!visitedVerts[this->GetVertPos(neighbors[i])])
		{
			this->VertsQueue.push(neighbors[i]);

			visitedVerts[this->GetVertPos(neighbors[i])] = true;
			cout << "\nVertex " << neighbors[i] << " is visited";
		}
	}
	if (this->VertsQueue.empty())
	{
		return;
	}
	BFS(VertsQueue.front(), visitedVerts);
}



