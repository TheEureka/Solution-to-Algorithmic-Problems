#import "@preview/lemmify:0.1.7": *
#let (
  theorem, lemma, corollary,
  remark, proposition, example,
  proof, rules: thm-rules
) = default-theorems("thm-group", lang: "en")
#show: thm-rules

#set page(fill: rgb("#907f5ff4"))
#set text(fill: rgb("#010304"))

#show "sseparator": "--------------------------------------------------------------------------------------------------------------------------"
#show "blk" : $space space space space$

Suppose that there are $a$ blue discs and $b$ discs in total, so that $a, b in ZZ ^ + union {0}$ and $2 <= a <= b$. We wish to find the smallest value of $b$ such that $b > 10 ^ 12$ and $P("BB") = a / b times (a - 1) / (b - 1) = 1 / 2$.  

Rearranging the final equation, we get 

$ &2a(a - 1) = b(b - 1)\
  <=>& 2a ^ 2 - 2a - (b ^ 2 - b) = 0\ 
  <=> a &= (2 plus.minus sqrt(4 + 8(b ^ 2 - b))) / 4 \
        &= (2 plus.minus 2sqrt(2b ^ 2 - 2b + 1)) / 4 \
        &= (1 plus.minus sqrt((b - 1) ^ 2 + b ^ 2)) / 2. $

In the context of the problem, $a$ clearly cannot be negative, so for each value of $b$, we can have at most one corresponding value of $a$ for which $P("BB") = 1 / 2$, namely $a = (1 + sqrt((b - 1) ^ 2 + b ^ 2)) / 2$, when this equals an integer.

Hence, the problem boils down to finding the smallest value of $b$ greater than $10 ^ 12$ for which $a = (1 + sqrt((b - 1) ^ 2 + b ^ 2)) / 2$ is an integer, and this corresponding value of $a$ is the answer we want.

The expression $(1 + sqrt((b - 1) ^ 2 + b ^ 2)) / 2$ is an integer if and only if $(b - 1) ^ 2 + b ^ 2$ is the square of an odd positive integer. According to #link("https://math.stackexchange.com/a/1790786/1198263")[#underline[this post on Maths Stack Exchange]], all such values of $b$ could be found by the stated recursive method. Using this algorithm, we can start from $(r, s) = (1, 1)$ ,recursively find all other possible solutions of $(r, s)$, and for each one find the given values of $(n, k)$ in the post's context. This $n$ value is then equal to $b - 1$, so each time we check when $b = n + 1$ is greater than $10 ^ 12$ and odd, which can be done quite quickly with the help of a program. 

Eventually, one should get an answer of #box(stroke: black,inset:0.3em, baseline: 30%)[756872327473].