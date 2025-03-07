# CS333 - Project 2 - README
### Zachary Berg
### 03/02/2024

***Google Sites Report: https://sites.google.com/colby.edu/zaberg26cs333/home?authuser=0 ***

## Directory Layout:
```
.
├── c
│   ├── task1.c
│   ├── task2.c
│   ├── task2text.txt
│   ├── task3.c
│   ├── task3test1.html
│   ├── task3test2.html
│   ├── task3test3.html
│   ├── task4.c
│   └── task4test.c
├── cpp
│   └── helloworld.cpp
├── images
│   ├── cpphelloworld1
│   ├── cpphelloworld2
│   ├── ctask1
│   ├── ctask2
│   ├── ctask2text
│   ├── ctask3
│   ├── ctask4
│   ├── extension3
│   ├── swifthelloword1
│   └── swifthelloword2
├── report.md
└── swift
    └── helloworld.swift
```
## OS and C compiler
OS: Debian 12 Bookworm
C compiler: (Debian 12.2.0-14) 12.2.0

## Part I 
### Task 1
**Compile:** 

flex task1.c

gcc -o encode lex.yy.c -ll

**Run:** 

echo "Zach is SUPER cool" | ./encode

echo "Mnpu vf FHCRE pbby" | ./encode

(Second input is output of first run cmd)

**Output:**
![Screenshot of c task 1](images/ctask1)

**Q.b.** 

First, we check if the ASCII value of the current char is between A-Z or a-z (using single quotes around char to get the ASCII value). If it's between a-z, we subtract a, add 13, using %26 to force it within the 26 char range we want it to be (wrap around of it would exceed 'z' after the addition of 13) then add back a to return us to the correct ASCII value. We can't simply add 13 because the behavior we desire is for the function called on the output of a given string to return the original string, and this would not occur if we didn't use the % operator to cause this wrapping. We do the same thing for the A-Z range with 'A' instead of a. We then set yytext to the ascii var we've been using for all the prior operations and print it, getting the desired result. We see that capital Z goes to capital M, Z is the 26th letter of the alphabet and M is the 13th, 26+13=39, 39%26 = 13, so M is the expect result. Then coming back around: 13+13=26, so we get back to Z.

 
### Task 2
**Compile:**

flex task1.c

gcc -o vowels lex.yy.c -ll

**Run:**

./vowels task2text.txt

**Output:**
![Screenshot of c task 2](images/ctask2)
![Screenshot of text for c task 2](images/ctask2text)

7 rows, matches expectation (rows begin counting at one as it counts each newline character and you start on row 1)

Row by row char counts:

1: 10

2: 8

3: 11

4: 11

5: 2

6: 6

7: 4 (not 5 because no newline char)

10+8+11+11+2+6+4 = 52, which matches our output. In my interpretation newline chars should be counted as they are present in the text file and how the computer reads it but some may not wish to count them. To changes this, remove the count incrementer in line 13.

Vowel counts match with what is present in the text file, both capital and lowercase vowels are tested.

**Q.b.** 

First we initialize rows to 1 (as you will always start on the first row), and initiliaze chars to 0 and the array of vowels (with length 5) to 0. Then in our regex part we increment char if we see anything (vowel, newline, or anything else). We increment the row counter whenever we see a newline, and we increment each index of the vowel array when we see the corresponding vowel. In our main function we read in the file provided in the command line argument, call the regex, and then print the rows, chars, and vowel variables.
Not really sure what is meant by "Include in that explanation an example of how one letter is counted" as it seems rather nonsensical in this situation. If we look at the 'o' character in line 5 we see that it properly increments the o counter (as it ends up at 2 with the one prior 'O' occurance) and it reflects properly in the char counter as described in the math in the output section. 

### Task 3
**Compile:**

flex task3.c

gcc -o html lex.yy.c -ll

**Run:** $ 

./task3 task3test1.html

./task3 task3test2.html

**Output:**
![Screenshot of c task 3](images/ctask3)

**Q.b.** 
In the task3test1.html we see:

Thisisapagetitle

From:

&lt;title&gt;This is a page title&lt;/title&gt;

We can see that the title tag is correctly removed and a newline character is inserted. The regex used for this is:

"<"(h[1-6]|title|ul|ol|li|p)[^>]*">"

The begining "&lt;" catches the opening bracket of an html tag. The ending "&gt;" does the same but with the closing html tag. The [^>]* matches any character that is not a closing bracket, and the * tells the program to do that match 0 to many times. With this fairly simple regex, we are able to match html tags. However, this regex takes it a little further, specifically identifying headers, titles, ordered and unordered lists, list items, and paragraphs, this is handled by the content within the parentheses (h[1-6]|title|ul|ol|li|p), which matches any of those words, making heavy use of the | (or) operator. To note, this is able to catch headers h1, h2, h3, h4, h5, 6 through the bracketed [1-6] which refers to the range of numbers from 1-6. For this specific example, we match the phrase "title". This is necessary because the directions specified that these tags should result in a newline, which is the case here. By omitting the content of parentheses, we get our generic header ommision, which does not result in a newline.

### Task 4
**Compile:**

flex task4.c

gcc -o clite lex.yy.c -ll

**Run:**

./clite task4test.c

![Screenshot of c task 4](images/ctask4)

**Q.b:**
First I define a regex sequence to the name of the type of token I'm trying to parse, I do this because I think it looks better. Then in the regex part, I refence these regex sequences using the name of the token and define the desired behavior. Sometimes, the behavior involves including the yytext, like with identifier and int, and sometimes it does not, like with assigmnet and close-paren. We take special care to tell the program to do nothing for newline chars, and newline chars are not recognized by the . regex.

### Extensions

#### Extension 1:

In task 3:

"&gt;" { printf(">"); }
"&lt;" { printf("<"); }
"&ge;" { printf("≥"); }
"&le;" { printf("≤"); }
"&amp;" { printf("&"); }
Allows parser to accomated greater than, less than, greater than or equal to, less than or equal to, and ampersand characters, which must be written as character entities in HTML as they have other uses within the HTML syntax. It's pretty simple regex, there are plenty of other character entities that could be added but I considered these to be the most impactful.

Website with information on HTML Character entities: https://www.w3schools.com/html/html_entities.asp 

Stackoverflow post that brought to my attention that greater than or equal to and less than or equal to must also be considered: https://stackoverflow.com/questions/5068951/what-do-lt-and-gt-stand-for

#### Extension 2:

In task 3:

Special care was given to formatting. I utilized two internal variables to allow my formatting solution, newline (initialized to 0) and startoffile(initialized to 1). Newline is set to 1 when an html tag of the specified type is detected, and a newline character is then inserted before the next "normal" char, and the variable is set back to 1. The startoffile variable is used only once, to ignore the first instance of this newline generation, so that we don't have an extra blank line at the top of the file. I chose to just remove all tabs, because it looked bad, and I replace all consecutive spaces with a single space. A final note is that we print an addition newline after the yylex() is done, so that our terminal session starts on a new line as it can be pretty gross if it doesn't (causes strange typing behavior on my computer and also just looks bad).

#### Extension 3:

In task 3:

Removal of multiline comments. This one stumped me for a while but I was eventually able to get it to block out multiline comments, but then it broke on line 11 of test 2, failing to recognize the end of the comment and blocking the whole file, which took a while to fix. Initially I had:

"<"!--([^\n]|[\n])+--">"  { /* ignore comments both single and multiline */ }

But I believe it is impossible to get this to work as flex is inherently a greedy regex (will match longest possible string) so this regex will always match everything between the first occurance of &lt;!-- and the last occurance of --&gt; which is not the desired behavior as we want to the regex to end at the first occurance of --&gt;. Current behavior causes it to block out the entirety of task3test2.html.

I then tried to use a regex that detects the start and end of comments and changes a variable dependantly based on whether one is inside a comment or not, but this doesn't work because it won't detect the start of the comment unless I make it super greedy (like first attempt) but then the end is never classified and we have the same issue. This regex is very restrictive.

"<"!-- { insidecomment = 1; printf("AAAAAAAAAAAAAAAAAA %i | ", insidecomment); /* comment start */ }
--">" { insidecomment = 0; printf("%i", insidecomment); /* comment end */ }

Finally, I was rather exasperated and frustrated with the limits of flex and googled it, finding the following answer, quotations added so it wouldn't be commented out:

COMMENT    "<"!--([^-]|-[^-]|--+[^->])*-*--">"

From this stack overflow post:

https://stackoverflow.com/questions/15506240/matching-html-style-comments-with-lex-flex

I modified it to this:

"<"!--([^-]|-[^-]|--+[^->])*--+">" { /* Removes html comments */ }

Because I didn't like how it classified the (1 or more dashes) condition inconsistently. This regex works because it is hyper specific in specifying which characters are allowed, I am ashamed to have not thought of such a solution. First we match the start condition "<"!--, then we match anything other than a dash, anything other than 2 dashes, and 2 or more dashes that aren't followed by ">". We match this 0 or more times, them match the closing condition (which may have any number of dashes that is atleast 2). This was endlessly frustrating and I look forward to the future when I can use a more comprehensive regex system with negative lookahead assertions and non-greedy matching.

Here is a screenshot of with working correctly on task3test3.html (the one with the multi line comment) and it also not deleting everything in task3test2.html (which is the bug I was struggling with):
![Screenshot of extension 3](images/extension3)
