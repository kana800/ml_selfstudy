#### Introduction to Graphs

The below notes are from [mycodeschool](https://www.youtube.com/watch?v=gXgEDyodOJU) youtube channel.

>  Graphs are non-linear data structures 
>  [@3:32](https://youtu.be/gXgEDyodOJU?t=202) A graph `G` is an ordered pair of set `V` if vertices and a set `E` of edges,  `G = (V,E)`. In an ordered pair,
>  ```
>  (a,b) not equal (b,a) if a not equal b
>  ```
>  In an unordered pair,
>  ```
>  {a,b} is equal {b,a}
>  ```
>  There are two types of edges:
>  - directed edges, where the connection is one-way.
>  - undirected edges, where the connection is two-way.
>  [representing edges](https://youtu.be/gXgEDyodOJU?t=283) 
>
>  A graph with all directed edges is called a `directed graph` or `digraph` and graph with all undirected edges is called an `undirected graph`.
>
>  [Examples of Graphs](https://youtu.be/gXgEDyodOJU?t=539)
>
>  Graphs also can [weighted graphs or unweighted graphs](https://youtu.be/gXgEDyodOJU?t=798). 

#### Properties of Graphs

> - If both endpoints of the an edge is the same we call this a [self loop](https://youtu.be/AfYqN3fGapc?t=127), self loop can be both directed and undirected graphs.
>
> - An edge is called an [multi edge](https://youtu.be/AfYqN3fGapc?t=224) if it occurs more than once in a graph.
>
> - The [number of maximum edges](https://youtu.be/AfYqN3fGapc?t=364) of a simple directed graph that doesn't contain a self loop or multi-edge would have `n(n - 1), where n is the number of edges` for undirected graph it will be `n(n - 1) / 2`.
>   - Graph is called dense if the number of edges are close to the maximum number of edges (too many edges)
>   - Graph is called sparse if the number of edges are small (too few edges).
> - A [path in a graph](https://youtu.be/AfYqN3fGapc?t=511) is a sequence of vertices where each adjacent pair is connected by an edge. A path is called a simple path if no vertices are repeated (no edges repeated). If the vertices are repeated in the sequence we call this **path** a [walk](https://youtu.be/AfYqN3fGapc?t=578).
>   - We call a graph [strongly connected](https://youtu.be/AfYqN3fGapc?t=672), if there is a path from any vertex to any other vertex. If its an undirected graph we call its connected if its directed graph we call it strongly connected.
> - A walk is called a [closed walk](https://youtu.be/AfYqN3fGapc?t=786) if the start and end are the same vertex and the length of the walk should be greater than zero.
>   - A simple cycle is closed walk, no repetitions other than start and end.
>   - A graph with no cycle is called [acyclic graph](https://youtu.be/AfYqN3fGapc?t=841).

#### Graph Representation [Edge List](https://www.youtube.com/watch?v=ZdY1Fp9dKzs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=40)

Here will be storing the vertices in an array and edges in an array. For the `edge list` we will need `start vertex` and `end vertex` .

```c
struct edge{
    char * startvertex;
    char * endvertex;
};

struct edge edgelist[size];
```

if the graph is weighted we can add `weight` to the structure.

```c
struct edge{
    char * startvertex;
    char * endvertex;
	int weight;
};
```

space complexity for the vertex list would be `O(|v|)`. For the edge list instead of storing character pointers we can store the index of the [character from the vertex list](https://youtu.be/ZdY1Fp9dKzs?list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&t=547). 

- Finding adjacent node to a given node will take us `O(|E|)` time because we need to iterate through the array 

If graph doesn't contain self-loops, If `|v| = n` then `|E| <= n(n - 1)`, Therefore `O(n(n - 1))` would be `O(n^2)`.

---

The below notes are from [lecture 10](https://www.youtube.com/watch?v=Sjk0xqWWPCc&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=11)

Data Structures for Graphs

- [Adjacency Matrix](https://youtu.be/Sjk0xqWWPCc?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=3539)
- [Adjacency List](https://youtu.be/Sjk0xqWWPCc?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=3590)

---

The below notes are from [lecture 11](https://www.youtube.com/watch?v=ZTwjXj81NVY&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=11)

**Problem of the Day**

Present correct and efficient algorithms to convert between the following graph data structures, for an undirected graph `G` with `n` vertices and `m` edges. You must give the time complexity of each algorithm.

- convert from an adjacency matrix to adjacency lists

we can iterate through the adjacency matrix row `i` and column `j`. 

```pseudocode
for i = 1 to N
	for j = 1 to N
		if M(i,j) == 1:
			addegde(i,j)
```

This will take `O(n^2)` time complexity.

- cost adding an node to the list would be (`O(n)`) constant time because we are adding it the front of the list

- convert from an adjacency lists to adjacency matrix

```pseudocode
for i = 1 to N
	// iterating through the list
	l = edge(i)
	// iterating through the nodes of 
	// the linked list
	while (l != NULL)
		M(i, l->next ) = 1
		// moving to the next node
		l = l->next;
```

Time complexity would be `O(n + 2m)` (*`m`*  is the number of edges), there will be outer loop iterating through the list, if there is no edges it would take `O(n)` time.

**Traversing a Graph**

> - For *efficiency*, we must we visit each edge at most twice. For *correctness*, we must do the traversal in a systematic way so that we don't miss anything.
> - The key idea is that we must mark each vertex when we first visit it, and keep track of what have not yet completely explored. [Each vertex will always be in one of the following three states](https://youtu.be/ZTwjXj81NVY?t=2600)
>   - undiscovered - the vertex in its initial, virgin state
>   - discovered - the vertex after we have encountered it, but before we have check out all its incident edges.
>   - processed - the vertex after we have visited all its incident edges.

> Breadth-first search is appropriate if we are interested in shortest paths on unweighted graphs. For data structures we use two boolean arrays to maintain our knowledge about each vertex in the graph. 
>
> A vertex is *discovered* the first time we visit it. A vertex is considered *processed* after we have traversed all outgoing edges from it. Once a vertex is discovered, it is placed on a `FIFO` queue. Thus the oldest vertices / closest to the roots are expanded first. ([link](https://youtu.be/ZTwjXj81NVY?t=2814))
>
> ```c
> bool processed[MAXV + 1];
> bool discovered[MAXV + 1];
> int parent[MAXV + 1]; // parent is one who discovered edges
> ```
>
> vertex who discovers another vertex is the parent
>
> - Time complexity of the [BFS](https://youtu.be/ZTwjXj81NVY?t=3382) : `O(n + m)`
>
> **Application of BFS**
>
> - [connected components](https://youtu.be/ZTwjXj81NVY?t=4298) of an undirected graph are the separate *pieces* of the graph such that there is no connection between the pieces. BFS can be used to check the number of connected graphs. [algorithm](https://youtu.be/ZTwjXj81NVY?t=4619) | time complexity: `O(n ( n + m))`

---

The below notes are from [lecture 12](https://www.youtube.com/watch?v=KyordYB3BOs&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=13)

> **Two-Coloring Graphs**
>
> A graph is *bipartite* if it can be colored without conflicts while using only two colors. Bipartite graphs are important because they arise naturally in many applications and **two-coloring** is the problem of coloring the vertices so that every edge, two end points are different colors.
>
> > [How can find if a graph is *bipartite* ?](https://youtu.be/KyordYB3BOs?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=198)
>
> - Time complexity of [Two-Coloring graph](https://youtu.be/KyordYB3BOs?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=452) : `O(n + m)`

[**problem of the day**](https://youtu.be/KyordYB3BOs?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=554)

> Prove that in a breadth-first search on a undirected graph *G*, every edge in *G* is either a tree edge or a cross edge, where a cross edge `(x,y)` is an edge where *x* is neither is an ancestor or descendant of *y*.

[**Depth-First Search**](https://youtu.be/KyordYB3BOs?list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&t=1251)

> for DFS, the evolution of the vertices are the same as the BFS it would be
>
> ```
> undiscovered -> discovered -> completely processed
> ```
>
> and we will be using stack (LIFO) as the data structure instead of a queue. To eliminate using stack as a data structure we can use recursion, In a programming language there is stack of records maintained by the runtime system of the programming language.

