#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "blk" : $space space space space$

Suppose that $g = gcd(a_1, a_2, dots, a_n)$, the answer we seek is the minimum value of 
$ g dot (a_1/g + gcd(a_1, a_2) / g) + dots + g dot gcd(a_1, a_2, dots, a_n) / g. $
Suppose we let $a_i ' = a_i / g$ for each $1 <= i <= n$, then this value is equal to 
$ g dot (a_1 ' + gcd(a_1 ', a_2 ') + dots + gcd(a_1 ', a_2 ', dots, a_n ')). $
Note that now we have $gcd(a_1 ', a_2 ', dots, a_n ') = 1$.


Now, consider the following greedy algorithm. We will start with an initially empty array $b$
 and add to the end of array $b$
 the element that minimizes the GCD with the already existing array $b$
. It can be observed that the gcd
 will reach 1 in at most 10 iterations. After that, the remaining elements can be added in any order.


#underline[Claim 1: ] At most 17 rounds are needed.

#proof[
  It actually suffices to show that after appending each element to the back of $b$, the GCD decreases.
  Then, we know that it will decrease at most $floor(log_2(100000)) = 16$ times, which a gives a maximum of $17$ times in total.

  This can be shown using proof by contradiction. Observe that the first element appended into $b$ is the minimum value among all $a_i '$s. Thus, if after a round after the first, the gcd of all values in $b$ doesn't decrease and remains unchanged (note that it is decreasing, though not strictly), then there must be an integer $d > 1$ that divides all values $a_i$. This contradicts with our assumption that $gcd(a_1 ', a_2 ', dots, a_n ') = 1. $

  Hence, the claim is proved.
]


#underline[Claim 2:] The greedy algorithm gives one of the optimal solutions.

#proof[
  Consider a specific permutation $(b_1, b_2, dots, b_n)$ of $(a_1 ', a_2 ', dots, a_n ')$. Suppose this gives an answer of $A$.
  Now, if there is an index $1 <= i < n$ such that $gcd(b_1, b_2, dots, b_(i - 1), b_i) > gcd(b_1, b_2, dots, b_(i - 1), b_(i + 1))$, then observe that if we exchange the positions of $b_i$ and $b_(i + 1)$, only the part $gcd(b_1, b_2, dots, b_(i - 1), b_i)$ that makes up the original answer $A$ changes. In this case, it actually decreases.

  Thus, as long as there is such an index $i$, we can keep performing the swapping operation until no more such $i$ exists. By this time, it is clear that the answer is minimised.

  This means the method adopted in the greedy solution is correct.
]

