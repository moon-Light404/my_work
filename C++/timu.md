贝茜已经搬到一个小农场，有时喜欢回去看望她最好的朋友之一。 她不想过早地回到老家，因为她喜欢沿途的风景。 她决定采取第二短路径，而不是最短路径。 她知道一定有第二短路径。

​    乡村由R（1≤R≤100,000）条双向道路组成，每条道路连接N（1≤N≤5000）个交叉口中的两个，方便地编号为1..N。 贝西从路口1开始，她的朋友（目的地）在路口N。

​    第二最短路径可以与任何最短路径共享道路，并且可能回溯，即多次使用同一条道路或交叉路口。 第二最短路径是长度比最短路径长的最短路径（即，如果存在两个或更多个最短路径，则第二最短路径是长度比那些最短路径长但不超过任何最短路径的路径 其他路径）。



输入值

​    第1行：两个以空格分隔的整数：N和R

​    第2..R + 1行：每行包含三个以空格分隔的整数：A，B和D，它们描述了一条连接相交点A和B且长度为D（1≤D≤5000）的道路。

输出量

​    第1行：节点1和节点N之间的第二条最短路径的长度

样本输入

​    4 4

​    1 2 100

 

​    2 4 200

 

​    2 3 250

 

​    3 4 100