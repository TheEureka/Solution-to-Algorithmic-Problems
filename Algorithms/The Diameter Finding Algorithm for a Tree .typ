#import "@preview/lemmify:0.1.7": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#set page(fill: rgb("#907f5ff4"))
#set text(fill: rgb("#010304"))

To prove the correctness of the Tree Diameter Finding Algorithm, in which we start from a vertex in a tree, first find another vertex farthest from it, and then start from that vertex to find a vertex in the tree farthest from that. The last two vertices, according to the algorithm, should be the two endpoints of a diameter in the tree.

To show this, it is apparently sufficient to prove the following theorem.

#theorem()[  
  For any vertex in the tree, the farthest vertex from it is an endpoint of a diameter.
]

#proof[
  For any two vertices $x, y$ in the tree, denote $"dis"(x, y)$ the length of the shortest path between them.

  Take any vertex $x$ in the tree. Assume on the contrary that the theorem does not hold, then there exists a vertex $y$ such that $y$ is one of the farthest vertices from $x$ in the tree and $y$ is not the end of a diameter.
  
  Suppose that $A$ and $B$ are the two endpoints of a diameter in the tree (by definition they must exist); note that it is immediately clear that $A$ and $B$ are leaf nodes. Imagine reshaping the structure of the tree so that diameter $A B$ becomes horizontal with A on the left, so that the remaining vertices extend upwards or downwards from a vertex on this diameter. There are now two cases to consider.

  In the first case, the path from $x$ to $y$ does not intersect with diameter A-B at all, which means that the path is contained within a subtree that is extended upwards or downwards from the horizontal diameter. Let $z$ be the last vertex that this path shares with the path connecting $x$ and $A$. By the definition of $y$, $"dis"(x, z) + "dis"(z, y) = "dis"(x, y) >= "dis"(x, A) = "dis"(x, z) + "dis"(z, A)$, which means $"dis"(z, y) >= "dis"(z, A)$. Let $w$ be the vertex on path z-A that first lies on diameter AB, we then have 
  $ "dis"(y, B) &= "dis"(y, z) + "dis"(z, B) \
                &>= "dis"(z, A) + "dis"(z, B) \
                &= ("dis"(z, w) + "dis"(w, A)) + ("dis"(z, w) + "dis"(w, B)) \
                &= "dis"(w, A) + "dis"(w, B) + 2"dis"(z, w) \
                &>= "dis"(w, A) + "dis"(w, B) \
                &= "dis"(A, B), $  
  meaning that y-B must be a diameter as well, contradicting the definition of $y$.

  In the second case, the path from $x$ to $y$ intersects diameter A-B. Let $z$ be the first vertex on the path from x to y that lies on diameter A-B, and let w be the last. At vertex $z$, the path either goes left towards $A$, or right towards $B$. W.L.O.G., assume that the path from $z$ to $y$ goes left, then we have $"dis"(x, z) + "dis"(z, w) + "dis"(w, y) = "dis"(x, y) >= "dis"(x, A) = "dis"(x, z) + "dis"(z, w) + "dis"(w, A)$. This means $"dis"(w, y) >= "dis"(w, A)$, after which $"dis"(y, B) = "dis"(y, w) + "dis"(w, B) >= "dis"(w, A) + "dis"(w, B) = "dis"(A, B)$, again bringing a similar contradiction as in the first case.

  Combining the two cases, it is clear that the theorem to be proved must be true.
        
]

