#import "@preview/lemmify:0.1.7": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#set page(fill: rgb("#907f5ff4"))
#set text(fill: rgb("#010304"))

#show "blk" : $space space space space$

Suppose $A$ and $B$ are the two endpoints of a diameter in the tree. For any two points $u, v$ in the tree, denote $"dis"(u, v)$ to be the length of the shortest path from $u$ to $v$.

For any node $x$ in the tree, we claim that the longest path starting from $x$ is equal to $max("dis"(x, A), "dis"(x, B))$.

#proof[
  
  WLOG, assume that $"dis"(x, A) >= "dis"(x, B)$. Let $z$ be the first point the path from $x$ to $A$ intersects with diameter AB. Note that since $"dis"(x, z) + "dis"(z, A) = "dis"(x, A) >= "dis"(x, B) = "dis"(x, z) + "dis"(z, B)$, we must have $"dis"(z, A) >= "dis"(z, B)$.

  Now assume for the sake of contradiction that one of the farthest points reachable from $x$ is $y$, where $"dis"(x, y) > "dis"(x, A)$. 

  If the path from $x$ to $y$ crosses diameter AB, then it must intersect AB first at vertex $z$ (otherwise there is clearly a cycle on the tree, which is impossible). In this case, there are two sub-cases to consider:

  blk 1. the path from $x$ to $y$ either overlaps with the path from $z$ to A and doesn't overlap with the path from $z$ to B;

  blk 2. it overlaps with the path from $z$ to $B$ and doesn't overlap with the path from $z$ to A. 

  blk 3. it doesn't overlap with any of the two segments that divide diameter AB.
  
  Note that from $"dis"(z, y) + "dis"(x, z) = "dis"(x, y) > "dis"(x, A) = "dis"(z, A) + "dis"(x, z) >= "dis"(x, B) = "dis"(z, B) + "dis"(x, z)$, we get $"dis"(z, y) > "dis"(z, A) > "dis"(z, B)$. If it is sub-case 1. that we're dealing with, then $"dis"(y, B) = "dis"(y, z) + "dis"(z, B) > "dis"(z, A) + "dis"(z, B) = "dis"(A, B)$, contradicting the definition of diameter AB; on the other hand, if it is sub-case 2. or 3. that occurs, then $"dis"(y, A) = "dis"(y, z) + "dis"(z, A) > "dis"(B, z) + "dis"(z, A) = "dis"(B, A)$, again contradicting the definition of diameter AB.

  Hence, if the path from $x$ to $y$ crosses diameter AB, we reach a contradiction. So this cannot be the case.

  We now examine the case where the path from $x$ to $y$ doesn't cross  diameter AB. In this case, let $u$ be the last vertex that the path from $x$ to $y$ and the path from $x$ to A share. Since path $x$—$y$ doesn't intersect with diameter AB, $u$ must be a node in the middle of the path from $x$ to $z$. Now, $"dis"(x, u) + "dis"(u, y) = "dis"(x, y) > "dis"(x, A) >= "dis"(x, B) = "dis"(x, u) + "dis"(u, z) + "dis"(z, B)$ implies that $"dis"(u, y) > "dis"(u, z) + "dis"(z, B)$. Consider then the path from A to $y$, we have that $"dis"(A, y) = "dis"(A, u) + "dis"(u, y) > "dis"(A, u) + "dis"(z, u) + "dis"(z, B) = "dis"(A, z) + 2 times "dis"(z, u) + "dis"(z, B) = "dis"(A, B) + 2times "dis"(z, u) > "dis"(A, B)$, where $"dis"(z, u) > 0$ because path $x$—$y$ doesn't intersect diameter AB. This is apparently another contradiction with the definition of diameter AB.

  Hence, our original assumption that there exists a vertex $y$ with $"dis"(x, y) > "dis"(x, A)$ was false. This means that the length of the longest path starting from vertex $x$ is given by $"dis"(x, A) = max("dis"(x, A), "dis"(x, B))$.


  
]

Therefore, we simply have to find a diameter, then run two DFS's from the two endpoints ($A$, $B$) of this diameter, and for each node $x$ in the tree, output $max("dis"(x, A), "dis"(x, B))$.