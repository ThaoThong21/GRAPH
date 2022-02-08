#include"GRAPH.h"
#include<iostream>
#include<stack>
#include<fstream>
int addEdge(int &n, int u, int v, int w, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size)
{
	int idn = n;
	if (w < 0) return 0;
	int vert = v > u ? v : u;
	if (vert > n)
	{
		n = vert;// update vertice
		for (idn; idn < n; ++idn) {
			adjacency_list_size[idn] = 0;
		}
	}
	--u;
	--v;
	for (int i = 0; i < adjacency_list_size[u]; i++)
	{
		if (adjacency_list[u][i].vertex == v)
		{
			return 0;
		}
	}

	{
		adjacency_list[u][adjacency_list_size[u]].vertex = v;
		adjacency_list[u][adjacency_list_size[u]].weight = w;
		++adjacency_list_size[u];

		adjacency_list[v][adjacency_list_size[v]].vertex = u;
		adjacency_list[v][adjacency_list_size[v]].weight = w;
		++adjacency_list_size[v];
		return 1;
	}
}

int deleteEdge(int n, int u, int v, ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N], int *adjacency_list_size)
{
	if (u > n || v > n) return 0;
	--u; --v;
	int check = 0;
	for (int i = 0; i < adjacency_list_size[u]; i++)
		if (adjacency_list[u][i].vertex == v)
		{
			check = 1;
			while (i < adjacency_list_size[u] - 1)
			{
				adjacency_list[u][i].vertex = adjacency_list[u][i + 1].vertex;
				adjacency_list[u][i].weight = adjacency_list[u][i + 1].weight;
				i++;
			}
			adjacency_list_size[u]--;
		}
	for (int j = 0; j < adjacency_list_size[v]; j++)
		if (adjacency_list[v][j].vertex == u)
		{
			check = 1;
			while (j < adjacency_list_size[v] - 1)
			{
				adjacency_list[v][j].vertex = adjacency_list[v][j + 1].vertex;
				adjacency_list[v][j].weight = adjacency_list[v][j + 1].weight;
				j++;
			}
			adjacency_list_size[v]--;
		}

	if (check) return 1;
	return 0;
}
// dk da kiem tra co lo trinh
void PrintPath(int start, int end,int *map_table,std::ofstream &fout)
{
	start--;
	end--;
	std::stack<int> k;
	int i = end;
	while (i != start)
	{
		k.push(i+1);
		k.push(map_table[i]+1);
		i = map_table[i];
	}
	int x, y;
	while (!k.empty())
	{
		x = k.top(); k.pop();
		y = k.top(); k.pop();
		fout << x << " " << y << std::endl;
	}
}