#include <iostream>
#include <cassert>

#include "../shared/Stack.h"
#include "../shared/Queue.h"

using namespace std;

template<typename T>
class AdjMatGraph // Adjacent Matrix Graph
{
public:
	struct Vertex // Node
	{
		T item = T();
	};

	AdjMatGraph(int max_vertices)
	{
		max_vertices_ = max_vertices; // capacity

		matrix_ = new int* [max_vertices_];
		for (int r = 0; r < max_vertices_; r++) {
			matrix_[r] = new int[max_vertices_];
			for (int c = 0; c < max_vertices_; c++)
				matrix_[r][c] = 0;
		}

		vertices_ = new Vertex[max_vertices_];

		n_ = 0;
	}

	~AdjMatGraph()
	{
		delete[] vertices_;

		for (int i = 0; i < max_vertices_; i++)
			delete[] matrix_[i];
		delete[] matrix_;

		if (visited_)
			delete[] visited_;
	}

	void PrintMatrix()
	{
		using namespace std;
		if (n_)
			for (int r = 0; r < n_; r++) {
				for (int c = 0; c < n_; c++)
					cout << matrix_[r][c] << ", ";
				cout << endl;
			}
		else
			cout << "Empty" << endl;

		cout << endl;
	}

	void InsertVertex(T item)
	{
		vertices_[n_].item = item;
		n_++;
	}

	void InsertEdge(int u, int v) // 여기서 u, v는 인덱스
	{
		assert(u < n_ && v < n_);

		// TODO:
		matrix_[u][v] = 1;
	}

	int Capacity()
	{
		return max_vertices_;
	}

	void DepthFirstTraversal()
	{
		ResetVisited();

		DepthFirstTraversal(0);

		cout << endl;
	}

	void DepthFirstTraversal(int v) // v는 인덱스
    {
        // TODO:
                    
        visited_[v] = true;
        cout << v;
        for(int i = 0; i < n_; i++)
            if(matrix_[v][i] == 1 && visited_[i] == false)
                    DepthFirstTraversal(i);
	}

	void IterDFT()
	{
		// TODO:
        Stack<int> s;
        
        ResetVisited();
        
        visited_[0] = true;
        s.Push(0);
        
        while(!s.IsEmpty())
        {
            int v = s.Top();
            s.Pop();
            cout << vertices_[v].item << " ";
            for(int i = n_ - 1; i >= 0; i--)
                if(matrix_[v][i] == 1 && visited_[i] == false)
                {
                    visited_[i] = true;
                    s.Push(i);
                }
            cout <<  "stack : ";
            s.Print();
            cout << endl;
                        
                        
        }
	}

	void BreadthFirstTraversal()
	{
		int v = 0; // 0번에서 시작

		Queue<int> q;

		ResetVisited();
        
    
		// TODO:
        
        visited_[v] = true;
        q.Enqueue(v);
        
        while(!q.IsEmpty())
        {
            int v = q.Front();
            q.Dequeue();
            cout << vertices_[v].item << " ";
            for(int i = 0 ; i < n_; i++)
                if(matrix_[v][i] == 1 && visited_[i] == false)
                {
                    visited_[i] = true;
                    q.Enqueue(i);
                }
            
            cout <<  "Queue : ";
            q.Print();
            cout << endl;
                        
                        
        }
	}

	void ResetVisited()
	{
		if (!visited_)
			visited_ = new bool[max_vertices_];
		for (int i = 0; i < max_vertices_; i++) visited_[i] = false; // 초기화
	}

private:
	int** matrix_ = nullptr;
	Vertex* vertices_ = nullptr;
	int n_ = 0;					// size
	int max_vertices_ = 0;		// capacity

	bool* visited_ = nullptr;
};

int main()
{
	// 정점(vertex), 간선(edge)

	AdjMatGraph<int> g(7);

	for (int i = 0; i < g.Capacity(); i++)
		g.InsertVertex(i);

	/*
	// 위키피디아 버전
	g.InsertEdge(0, 2);	g.InsertEdge(2, 0);
	g.InsertEdge(0, 1);	g.InsertEdge(1, 0);
	g.InsertEdge(1, 4);	g.InsertEdge(4, 1);
	g.InsertEdge(1, 3);	g.InsertEdge(3, 1);
	g.InsertEdge(2, 4);	g.InsertEdge(4, 2);
	g.InsertEdge(3, 6);	g.InsertEdge(6, 3);
	g.InsertEdge(4, 6);	g.InsertEdge(6, 4);
	g.InsertEdge(5, 6);	g.InsertEdge(6, 5);
	g.InsertEdge(3, 0);	g.InsertEdge(0, 3);
	g.InsertEdge(4, 0);	g.InsertEdge(0, 4);
	*/

	// 강의 영상 버전
	g.InsertEdge(0, 2);	g.InsertEdge(2, 0);
	g.InsertEdge(0, 1);	g.InsertEdge(1, 0);
	g.InsertEdge(1, 4);	g.InsertEdge(4, 1);
	g.InsertEdge(1, 3);	g.InsertEdge(3, 1);
	g.InsertEdge(2, 4);	g.InsertEdge(4, 2);
	g.InsertEdge(3, 6);	g.InsertEdge(6, 3);
	g.InsertEdge(4, 6);	g.InsertEdge(6, 4);
	g.InsertEdge(5, 6);	g.InsertEdge(6, 5);

	g.PrintMatrix();

    g.IterDFT();

	g.BreadthFirstTraversal();

	return 0;
}
