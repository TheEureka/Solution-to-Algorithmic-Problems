#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "blk" : $space space space space$

A straightforward observation to make is that in the resultant array, every element is divisible by the greatest common divisor, call it $g$, of all the elements in the original array.

Therefore, to maximise the value of $"mex"_k$, we can make sure that by the end of all operations, we have $0, g, 2g, dots, (n - 1)g$ all in the lists, where $n$ is the length of the array.

A way to prove that this is possible is to refer to the Euclidean Algorithm. Notice how the first operation, $a_i := a_i - a_j$, can be repeatedly used to make both of $a_i, a_j$ equal to $gcd(a_i, a_j)$ in the end, which is the conclusion of the Euclidean Algorithm. If we keep repeating this operation on all pairs in the array, we must eventually arrive at the situation where all elements of the array are $g$. From here onwards, the array $0, g, 2g, dots, (n - 1)g$ is easy to generate.
