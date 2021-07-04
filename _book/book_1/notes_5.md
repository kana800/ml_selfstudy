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

 

