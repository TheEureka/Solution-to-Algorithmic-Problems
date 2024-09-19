#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "blk" : $space space space space$

Suppose $A$ and $B$ are the two endpoints of a diameter in the tree. For any two points $u, v$ in the tree, denote $"dis"(u, v)$ to be the length of the shortest path from $u$ to $v$.

For any node $x$ in the tree, we claim that the longest path starting from $x$ is equal to $max("dis"(x, A), "dis"(x, B))$.

#proof[
  WLOG, assume that $"dis"(x, A) > "dis"(x, B)$.

  Now assume for the sake of contradiction that one of the farthest point reachable from $x$ is $y$, where $"dis"(x, y) > "dis"(x, A)$. According to the algorithm used to find a diameter of the tree, we know that $y$ is an endpoint of a diameter in the tree. 

  Before we continue, note that any two diameters in a tree must meet at some node. To prove this, we can first assume two diameters don't intersect, and then find a contradiction. But the contradiction is obvious. Suppose the two diameters have a common length $D$ (common because they are diameters). Pick any two nodes on those two diameters, say points $a$ and $b$, and connect them. Suppose $D_a$ is the longer of the distances from $a$ to the two endpoints of the first diameter, and denote $D_b$ for $b$ similarly. Now, we can see that there is a path of length $D_a + D_b + n$, where $n$ is the length of the path connecting the two diameters. But $D_a >= ceil(D / 2), D_b >= ceil(D / 2)$, so $D_a + D_b + n >= ceil(D / 2) + ceil(D / 2) + n >= D + n > D$. Hence, there is a path in the tree longer than the original diameters, and hence a contradiction arises.

  Using this fact about any two diameters must intersect, we know that in the original problem, as we go from $x$ to $y$, we must cross some points that lie on the diamter with endpoints $A$ and $B$. Suppose the first such point is $z$. Then we have that $"dis"(x, y) = "dis"(x, z) + "dis"(z, y) > "dis"(x, A) = "dis"(x, z) + "dis"(z, A)$, which means $"dis"(z, y) > "dis"(z, A)$. Now consider the path from $y$ to $B$, we have that $"dis"(y, B) = "dis"(y, z) + "dis"(z, B) > "dis"(A, z) + "dis"(z, B) = "dis"(A, B)$, contradicting the fact that $A$ and $B$ are the endpoints of a diameter in the tree.

  Thus, such a $y$ doesn't exist for $x$, and the farthest distance reachable from $x$ is $"dis"(x, A)$. 
]

Therefore, we simply have to find a diameter, then run two DFS's from the two endpoints ($A$, $B$) of this diameter, and for each node $x$ in the tree, output $max("dis"(x, A), "dis"(x, B))$.