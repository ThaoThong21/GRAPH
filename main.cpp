#include<iostream>
using namespace std;
#include<vector>
#include"GRAPH.h"
#include<fstream>
#include<string>
#include<iostream>
ADJACENCY_LIST_ITEM adjacency_list[MAX_N][MAX_N];
int adjacency_list_size[MAX_N], d[MAX_N], visited[MAX_N];
int map_table[MAX_N];// Bang Tra

int main(int argc, const char* argv[])
{
	int n = 0;
	ifstream fin;
	ofstream fout;
	string filein,fileout;
	if (argc == 3)
	{
		filein = argv[1];
		fileout = argv[2];
	}
	if (argc == 2)
	{
		filein = argv[1];
	}
	if (argc < 2)
	{
		cout << "\nNhap file input: ";
		cin >> filein;
	}
	fin.open(filein);
	if (!fin.is_open())
	{
		cout << "Can't not open!" << endl;
		cin.get();
		return 0;
	}
	if (argc < 3)
	{
		cout << "\nNhap file ouput: ";
		cin >> filein;
	}
	fout.open(filein);
	int u, v, c;
	string request;
	string del = "DELETE\0", sp = "SP\0", cr = "CREATE\0";
	
	while (!fin.eof())
	{
		getline(fin, request, ' ');
		if (request == cr)
		{
			fin >> u >> v >> c;
			getline(fin, request, '\n');// xoa ki tu \n
			fout << addEdge(n, u, v, c, adjacency_list, adjacency_list_size) << endl;
		}
		else if (request == del)
		{
			fin >> u >> v;
			getline(fin, request, '\n');// xoa ki tu \n
			fout << deleteEdge(n, u, v, adjacency_list, adjacency_list_size) << endl;
		}
		else if (request == sp)
		{
			fin >> u >> v;
			getline(fin, request, '\n');// xoa ki tu\n
			int result=dijkstra_heap(n, u, v, adjacency_list, adjacency_list_size,d,visited, map_table);
			fout << result << endl;
			if (result != -1) PrintPath(u, v, map_table,fout);
		}
	}
	fin.close();
	fout.close();
	cin.get();
	return 1;
}