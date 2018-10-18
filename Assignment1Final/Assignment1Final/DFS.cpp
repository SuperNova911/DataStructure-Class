#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "GenericStackDL.h"
#include "GenericDoublyListP.h"

#define MAX_GRAPH_SIZE 256
#define BRANCH_NUM 10

using namespace std;

template<typename Out>
void Split(const string &s, char delim, Out result);
vector<string> Split(const string &s, char delim);
void DFS(const int graph[MAX_GRAPH_SIZE][BRANCH_NUM], int row, int column, int start, int end);

int main()
{
	char fileName[] = "sample_graph3.txt";
	FILE *stream;
	if (fopen_s(&stream, fileName, "r") != 0)
	{
		cout << "파일을 열 수 없습니다. FileName: " << fileName << endl;
		return 0;
	}

	int graph[MAX_GRAPH_SIZE][BRANCH_NUM];
	for (int i = 0; i < MAX_GRAPH_SIZE; i++)
		for (int j = 0; j < BRANCH_NUM; j++)
			graph[i][j] = -1;

	int node;
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stream) != NULL)
	{
		vector<string> elements = Split(buffer, ' ');

		node = stoi(elements[0]);
		for (int index = 1; index <= BRANCH_NUM && index < elements.size(); index++)
		{
			graph[node][index - 1] = stoi(elements[index]);
		}
	}
	fclose(stream);

	int start, end;
	while (true)
	{
		cout << "enter staring and ending vertices> ";
		cin >> start >> end;
		DFS(graph, MAX_GRAPH_SIZE, BRANCH_NUM, start, end);
	}

	return 0;
}

template<typename Out>
void Split(const string &s, char delim, Out result)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> Split(const string &s, char delim)
{
	vector<string> elements;
	Split(s, delim, back_inserter(elements));
	return elements;
}

void DFS(const int graph[MAX_GRAPH_SIZE][BRANCH_NUM], int row, int column, int start, int end)
{
	if (start < 0 || MAX_GRAPH_SIZE - 1 < start || end < 0 || MAX_GRAPH_SIZE - 1 < end)
	{
		cout << "out of range" << endl;
		return;
	}

	StackClass<int> stack = StackClass<int>();
	bool visited[MAX_GRAPH_SIZE] = { false };
	visited[start] = true;

	stack.Push(start);
	int target;
	while (stack.IsEmpty() == false)
	{
		stack.GetTop(target);

		if (target == end)
			break;

		bool fallback = true;
		for (int index = 0; index < column; index++)
		{
			if (graph[target][index] != -1 && visited[graph[target][index]] == false)
			{
				stack.Push(graph[target][index]);
				visited[graph[target][index]] = true;
				fallback = false;
				break;
			}
		}

		if (fallback == true)
			stack.Pop();
	}

	if (stack.GetSize() > 0)
	{
		printf("path length: %d\n", stack.GetSize() - 1);

		int path;
		vector<int> pathList;
		while (stack.IsEmpty() == false)
		{
			stack.GetTop(path);
			stack.Pop();
			pathList.insert(pathList.begin(), path);
		}

		for (int index = 0; index < pathList.size(); index++)
		{
			printf("%d ", pathList[index]);
		}
		printf("\n");
	}
	else
	{
		printf("not found\n");
	}
}