# Push_swap

_This project is about sorting a list composed of integer values while being restricted in the possibles moves._

__Rules:__
* The game is constituted of two piles named `a` and `b`.
* At the beginning, `b` is empty and `a` contains a certain number of integers positives or negatives (without duplicates).
* The goal is to sort `a` in an increasing way.
* To this end we dispose of the following operations:
  * (`sa`) swap `a` - Swap the first two elements of `a`.
  * (`sb`) swap `b` - Swap the first two elements of `b`.
  * (`ss`) `sa` and `sb` at the same time.
  * (`pa`) push `a` - Take the first element from top of `b` and put it on `a`.
  * (`pb`) push `b` - Take the first element from top of `a` and put it on `b`.
  * (`ra`) rotate `a` - Shift of a position all elements of `a` (towards the top, the first element becomes the last).
  * (`rb`) rotate `b` - Shift of a position all elements of `b` (towards the top, the first element becomes the last).
  * (`rr`) `ra` and `rb` at the same time.
  * (`rra`) reverse rotate `a` (towards the bottom, the last element becomes the first).
  * (`rrb`) reverse rotate `b` (towards the bottom, the last element becomes the first).
  * (`rrr`) `rra` and `rrb` at the same time.


__Installation:__
```sh
git clone git@github.com:Aaramis/push_swap.git;
make
```

**Generate integer list using ruby**
```sh
sudo apt-get install ruby;
ARG=$(ruby -e puts "(1..100).to_a.shuffle.join(' '))";
./push_swap $ARG > test;
./checker $ARG < test;
```
