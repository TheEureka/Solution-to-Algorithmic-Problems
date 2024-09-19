#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "blk" : $space space space space$

We claim that the optimal choice of connection is to connect the node nearest the midpoint of the diameter in the first tree with the same type of point in the second tree.

#proof[
  Let's focus on the first tree.
  Suppose the point we choose from the first tree is $a$, and the length of the diameter of the first tree is $D$.

  In the final longest path which consists of the connecting edge between the two trees, we apparently wish to minise the the length of the longest path we can get in the first tree starting from $a$. The same thing goes for the other tree. The two choices are actually indepedent and so can be dealt with similarly.
  
  To get to the farthest point from $a$, we apparently have to cross at least one diameter of the tree (recall the process of finding the diameter of a tree). Note also that the farthest point is one endpoint of a diameter.
  
  When $a$ is not on the diameter, we first need to get to a node in the diameter using $d > 0$ steps. Suppose now we're at some node on the diameter, and the shorter distance from this node to any endpoint of the diameter is $x$. Now, the longest path we can form is of length $d + min(x, D - x) >= d + ceil(D / 2) > ceil(D / 2)$, as $d > 0$.

  But if $a$ is on the diameter, the lower bound decreases to $ceil(D / 2)$. Actually, this lower bound is reached exactly when $a$ is nearest to the midpoint of any diameter in the first tree.

  Thus, it is optimal to choose $a$ to be such a point, and do the same for the second tree. In the end, the minimised length of the longest path that crosses both trees is equal to $ceil(D_1 / 2) + ceil(D_2 / 2) + 1$, where $D_1, D_2$ are the respective diameters of the two trees.
]

However, we should note that this might not be the final answer, as the original diameter of one of the two treees might be longer than the longest path that spans over both trees. So a last comparison is needed before outputting the answer.
