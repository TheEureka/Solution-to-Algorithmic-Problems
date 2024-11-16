#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "sseparator": "--------------------------------------------------------------------------------------------------------------------------"

Problem link: #link("https://atcoder.jp/contests/abc379/tasks/abc379_c")

We start by finding the necessary and sufficient condition for being able to reach the target state, the state where each position from $1$ to $N$ has exactly one stone.

In one direction, if we are able to start with the current state and reach the target state, then it must be the case that $sum_(i = 1) ^ M A_i = N$, and that after sorting the stones in increasing order based on 
their $x$ values, we must have, for each $1 <= i <= M$, $sum_(j = i) ^ M A_j <= N - X_i + 1.$

In the other direction, moving from the target state to any possible starting state means moving some of the stones towards the left. Naturally, the total number of stones over all positions must still be $N$, and note 
that the condition $sum_(j = i) ^ M A_j <= N - X_i + 1$ for each $i$ is preserved by the leftward movements of the stones.

Therefore, the condition is necessary and sufficient.

It is also important to realise if the target state can be reached, the number of operations required to reach it is a constant, given by value $sum_("stone u over all stones") ("dest"(u) - "start"(u)) = sum_(i = 1) ^ N i - sum_(j = 1) ^ M X_j times A_j$.

This finishes the problem.