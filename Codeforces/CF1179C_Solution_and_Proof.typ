#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "blk" : $space space space space$

We start by proving the following lemma:

#lemma()[
  Exchanging the positions of neighbouring pupils doesn't change the final answer.
] <lemma1>

#proof[
  Suppose the two neighbouring pupils in consideration are $b_i$ and $b_(i + 1)$ for some $1 <= i < n$. Assume that now all of the pupils in the queue before them have already chosen their dishes. We consider the following four cases:
  - Case 1: $b_i >= b_(i + 1)$ and there exists an $a_j$ such that $b_i >= a_j > b_(i + 1)$.
    
  blk In this case, it is clear that the choices made by $b_i$ and $b_(i + 1)$ don't interefore with each other at all.

  - Case 2: $b_i >= b_(i + 1)$ and there doesn't exist an $a_j$ such that $b_i >= a_j > b_(i + 1)$.
  
  blk For this case, the two dish values that are chosen will always be the two most expensive dish values (could be repeated) less than or equal to $b_(i + 1)$. 

  - Case 3: $b_i <= b_(i + 1)$ and there exists an $a_j$ such that $b_i < a_j <= b_(i + 1)$.
  
  blk This is similar to Case 1, where the choices don't interfere.

  - Case 4: $b_i <= b_(i + 1)$ and there doesn't exist an $a_j$ such that $b_i < a_j <= b_(i + 1)$.

  blk This is similar to Case 2, where the two dish values to be chosen are always the two most expensive dish values (could be repeated) less than or equal to $b_i$.

  In all of the four cases, exchaing the order of $b_i "and" b_(i + 1)$ doesn't change the final dish values chosen. Thus, it doesn't change the final answer, and the lemma is true.
]

Using @lemma1, we can conclude that the order of the waiting queue of pupils doesn't matter in this problem because we could keep exchanging neighbouring students to arrive at any permutation of students. 

Following this, it's not hard to notice that the answer for the current lists ${a_i}_(i = 1) ^ n, {b_i}_(i = 1) ^ m$ is simply the largest $x$ for which the number of dishes with costs greater than or equal to $x$ is strictly greater than the number of students with money greater than or equal to $x$. This idea can be easily implemented using a segmentree.