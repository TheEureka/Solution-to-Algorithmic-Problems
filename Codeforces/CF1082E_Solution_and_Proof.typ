#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "sseparator": "--------------------------------------------------------------------------------------------------------------------------"

Suppose we fix the right end of the interval at $r$, where $1 <= r <= n$, so that the mode of the required interval $[l, r]$ is equal to $a[r]$.

Then, it is clear that the contribution of the remaining elements to the right is just equal to the number of values in the interval $[r + 1, n]$ equal to $c$.

But for the prefix $[1, r]$, we clearly need to find a separation at $l$, where $1 <= l <= r$, such that the total contribution from the interval $[1, l - 1]$ and $[l, r]$ is maximised.

For the interval $[l, r]$, its contribution to the answer will be equal to the frequency of the mode for that interval. The contribution of $[1, l - 1]$ is similar to that of $[r + 1, n]$, which is just the number of elements equal to $c$ in that range. From this, it is clear that the best case arises when $a[r] = a[l]$; otherwise, the answer doesn' decrease when we shift $l$ rightwards towards $r$.

Now, we define $"ord"_k [i]$ for each $(1 <= i <= n), 0 <= k <= 5 times 10 ^ 5 $ as follows: the $j$th occurrence of $a[i]$ when going from left to right will be assigned a value of $"ord"_(a[i])[j]$ for each $1 <= i <= n$. Moreover, let $"cnt"_c [i]$ denote the number of elements equal to $c$ in the prefix $[1, i]$. Then, after fixing the value of $r$, the optimal value of $l$ occurs at the place where 
$ "cnt"_c [l - 1] + "ord"_(a[r])[r] - "ord"_(a[l])[l] + 1 $

is maximised. But because $r$ is fixed, and $1$ is constant, we simply need to track down the largest value of $"cnt"_c [l - 1] - "ord"_(a[l])[l]$ that has occurred so far.

The problem is now easy to solve by implementing the idea above.
