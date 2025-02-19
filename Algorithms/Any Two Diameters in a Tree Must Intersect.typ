#import "@preview/lemmify:0.1.7": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#set page(fill: rgb("#907f5ff4"))
#set text(fill: rgb("#010304"))

#theorem(name: "Intersecting Diameters")[
  Any two diameters in a tree must intersect one another.
]

#proof[
  To prove this, we can first assume two diameters don't intersect, and then find a contradiction. But the contradiction is obvious. Suppose the two diameters have a common length $D$ (common because they are diameters). Pick any two nodes on those two diameters, say points $a$ and $b$, and connect them. Suppose $D_a$ is the longer of the distances from $a$ to the two endpoints of the first diameter, and denote $D_b$ for $b$ similarly. Now, we can see that there is a path of length $D_a + D_b + n$, where $n$ is the length of the path connecting the two diameters. But $D_a >= ceil(D / 2), D_b >= ceil(D / 2)$, so $D_a + D_b + n >= ceil(D / 2) + ceil(D / 2) + n >= D + n > D$. Hence, there is a path in the tree longer than the original diameters, and hence a contradiction arises.
]

