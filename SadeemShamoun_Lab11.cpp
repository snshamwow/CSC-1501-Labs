// SADEEM SHAMOUN LAB 11 CSC 1501//
#include <iostream> // For cin, cout, and system
using namespace std; // So "std::cout" may be abbreviated to "cout"

const int dimensions = 7;
void add(int i, int j, int matrix[dimensions][dimensions])
{
	matrix[i][j] = 1;
	matrix[j][i] = 1;
}
void eDelete(int i, int j, int matrix[dimensions][dimensions])
{
	matrix[i][j] = 0;
	matrix[j][i] = 0;
}
void print(int vertices, int matrix[dimensions][dimensions])
{
	int i, j;
	for (i = 0; i < vertices; i++)
	{
		for (j = 0; j < vertices; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void edgeCheck(int i, int j, int matrix[dimensions][dimensions])
{
	if (matrix[i][j] == 1 && matrix[j][i] == 1)
	{
		cout << "Numbers " << i << " and " << j << " are connected" << endl;
	}
	else if (matrix[i][j] == 0 && matrix[j][i] == 0)
	{
		cout << "Numbers " << i << " and " << j << " are not connected" << endl;
	}
}
int main()
{
	int vertex = 6;
	int graph[dimensions][dimensions];
	fill(*graph, *graph + dimensions * dimensions, 0);
	add(1, 5, graph);
	add(1, 4, graph);
	add(4, 3, graph);
	add(4, 2, graph);
	add(2, 3, graph);
	add(5, 0, graph);
	cout << "Adjacency matrix 1:" << endl;
	print(vertex, graph);
	cout << "\nDeleting edge (1, 4)" << endl;
	eDelete(1, 4, graph);
	cout << "\nPrinting new matrix: " << endl;
	print(vertex, graph);
	cout << "\nChecking if 1 and 4 are connected: ";
	edgeCheck(1, 4, graph);
	cout << "\nChecking if 0 and 3 are connected: ";
	edgeCheck(0, 3, graph);
}