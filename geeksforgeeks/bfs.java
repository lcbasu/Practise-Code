import java.util.*;

class Graph
{
	private int V;
	private List<Integer> adjList[];

	public Graph(int V)
	{
		this.V = V;
		adjList = (List [])new List[V];
		
		for(int i = 0; i < V; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
	}
	
	public void addEdge(int u, int v)
	{
		adjList[u].add(v);
	}
	
	public void BFS(int src)
	{
		boolean[] visited = new boolean[V];
		for(int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		
		ArrayList<Integer> que = new ArrayList<Integer>();
		que.add(src);
		
		visited[src] = true;
		
		System.out.print("BFS : ");
		
		while(!que.isEmpty())
		{
			int tmpSrc = que.get(0);
			System.out.print(tmpSrc + " ");
			que.remove(0);

			for(int v:adjList[tmpSrc])
			{
				if(!visited[v])
				{
					que.add(v);
					visited[v] = true;
				}
			}
		}
	}
}

public class DebugClass
{
	public static void main(String[] args)
	{
		Graph g = new Graph(4);
	    
	    g.addEdge(0, 1);
	    g.addEdge(0, 2);
	    g.addEdge(1, 2);
	    g.addEdge(2, 0);
	    g.addEdge(2, 3);
	    g.addEdge(3, 3);
	    
	    g.BFS(2);
	}
}