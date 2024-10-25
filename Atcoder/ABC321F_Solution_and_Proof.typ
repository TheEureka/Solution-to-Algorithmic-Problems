#import "@preview/lemmify:0.1.5": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#show "sseparator": "--------------------------------------------------------------------------------------------------------------------------"

Problem link: #link("https://atcoder.jp/contests/abc321/tasks/abc321_f")

The key here is finding the way to handle the deletion operator.

Define dp as usual, where dp$["partial sum"]$ = count. The addition process is very straightforward. Suppose we've just inserted a new value of $x$, then the only updates are to go through each $i$ from $K$ down to $x$ in that order, and add dp$[i - x]$ to dp$[i]$.

The reverse operation is a little tricky. It took me a little while to understand why it worked, even after reading the solution.

At first, I thought of somehow handling the order in which the values of $x$ are used to calculate the dp values before a deletion occurs. I thought so because if an element to be deleted was the element in the last loop used to calculate the dp values, the deletion operation is very straightforward: we just iterate $i$ from $K$ down to $x$ again, and decrease dp$[i]$ by dp$[i - x]$.

However, the order of the insertions are quite hard to handle, so this method doesn't sound plausible in end.

The correct way to handle deletions efficiently is to do the following: suppose $x$ is to be removed, then iterate $i$ from $x$ to $K$, and subtract dp$[i - x]$ from dp$[i]$.

To prove why this works, we can think in the following way: firstly, the values from dp$[0]$ to dp$[x - 1]$ are certainly unaffected by the insertion or deletion of $x$, so they are fine. Starting at $i = x$, we update the value of dp$[x]$ so that it now counts the number of ways to generate a sum of $x$ without the ball with number $x$. By iterating $i$ from $x$ to $K$ in that order, we make sure that each time we update dp$[i]$, all previous values count the number of ways to achieve the smaller sums without using $x$ (and this is why balls have to be distinguishable in the box). Thus, we can repeat the operation dp$[i]$ -= dp$[i - x]$ to find the updated number of ways to achieve a sum of $i$ without $x$.

