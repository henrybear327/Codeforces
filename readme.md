# Codeforces Contest code backup

I started doing Codeforces contest in 2015 summer vacation while participating in **2015CPSTC(competitive programming summer training camp)** @NCTU. Thanks to the teacher and student mentors there. :)

This is a repository that I use for backing up my Codeforces code. I am still new to this competitive programming field, so my code may be really bad. Please don't take it too seriously.

# Compilation parameter

`clang-format-3.7 -style=LLVM -i main.cpp && astyle --style=linux main.cpp && g++ -Wall -Wextra -o main.o main.cpp`

#List format

The following lists will be written as followed.

* (h1 title) Contest name(type)
    * Division(if present)
        1. Round / contest name
            * solved problem

#Contest

* Div 2
    1. Round 312 (The first ever contest that I participated in!)
        * A, B
    2. Round 313
        * A, B, C
    3. Round Pi
        * A, B, C
    4. Round 315
        * A, B, C
    5. Round 316
        * A, B, C
    6. Round 317
        * A, B, C
    7. Round 318
        * A, B, C
    8. Round 319
        * A, B, C
    9. Round 320
        * A, B, D
    10. Round 321
        * A, B, C
    11. Round 322
        * A, B (Test case 53!!), C
    12. Round 323
        * A, B
    13. Round 324
        * A, B
    14. Round 325
        * A, B, C
    15. Round 326
        * A, B, C
    16. Round 327
        * A, B
    17. Round 328
        * A, B
    18. Round 329
        * A, B
    19. Testing Round #12
        * A, B
    20. Educational Round #1
        * A, B, C
    21. Round 332
        * A, B, C
    22. Round 333
        * A, B, C

#Gym

1. Acm Aamman Collegiate Programming Contest (3-star)
    * C, E, J, K
2. 2013-2014 Samara SAU ACM ICPC Quarterfinal Qualification Contest (3-star)
    * A, B, H (F TLE)
3. 2014-2015 Samara SAU ACM ICPC Quarterfinal Qualification Contest
    * A, E, F, G, I, M

# Notes

1. Test for upper/lower bound input that's given by the problem statement.
(Hacks may come from here! Ex: Round 316 Div2 problem B)

2. Does the problem need a linear scan? Or just look at its left and right?
(Round 316 Div2 problem C)

3. Read the problem statements carefully. Use pen and paper to finalize thoughts before actually coding them!

4. Don't rush! Double check the source code and rethink the program flow before submitting the code.

5. If `long long int` is required, declare all of the variables using `long long int` in case you miss any of them. (2013-2014 Samara SAU ACM ICPC Quarterfinal Qualification Contest problem C, forgot to use `long long int` for `sum_so_far`, stupid)

# Command

`find . -type f -name '*.orig' -delete`
