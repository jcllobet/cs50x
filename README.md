CS50x
=====

Submission for CS50x online course by Harvard University.
[Link to edX](https://www.edx.org/course/introduction-computer-science-harvardx-cs50x#!)

Week 0: Scratch
=================
![alt text](https://github.com/jcllobet/cs50x/blob/master/week1/pset1/4waysoccer.png)

My Project: A randomized 4 way soccer made with scratch: 
[https://scratch.mit.edu/projects/170768406/](https://scratch.mit.edu/projects/170768406/)

Week 1: C
=================
hello.c : prints hello, world
```javascript
~/workspace/pset1/ (master) $ ./hello
hello, world
```

water.c : a program to convert shower's length (in minutes) to equivalent water bottles
```javascript
~/workspace/pset1/ (master) $ ./water
minutes: 10
bottles: 120
```
mario.c : a program that recreates half-pyramid using hashes (#) for blocks.
```javascript
~/workspace/pset1/ (master) $ ./mario
height: 8
       ##
      ###
     ####
    #####
   ######
  #######
 ########
#########
```
greedy.c : a program that converts your money to quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). Rule: Use the least number of coins.
```javascript
~/workspace/pset1/ (master) $ ./greedy
O hai! How much change is owed?
0.41
4 coins
```

Week 2: Crypto
=================
initials.c: a program that given a person’s name, prints a person’s initials.
```javascript
~/workspace/pset2/ (master) $ ./initials
Harry James Potter
HJP
```

caesar.c : a program to [caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) a text
```javascript
~/workspace/pset2/ (master) $ ./caesar 13
Be sure to drink your Ovaltine!
Or fher gb qevax lbhe Binygvar!
```
 

vigenere.c : a program to [vigenere cipher](https://en.wikipedia.org/wiki/Vigenère_cipher) a text
```javascript
~/workspace/pset2/ (master) $ ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

Week 3: Game of Fifteen
=================
1. pset3/find/ - generate.c generates pseudorandom of size of user's choice, then find.c check if a number of user's choice is in those generated pseudorandom number. Usage: ./generate <size> <seed> | ./find <value><br>
2. pset3/fifteen/ - generates a game of fifteen. Usage: ./fifteen <size of board><br>
3. hacker3/find/ - similar as pset3, but this find (sort and search) algorithm is faster. Usage: ./generate <size> <seed> | ./find <value><br>

Week 4: Forensics
=================
Made a game called Breakout with GUI using API from SPL (Stanford Portable Library). Avoid the ball from falling down the bottom edge, when the ball hit the paddle, it will bounce to the top, when it hit the bricks on the top portion of the game, the brick will dissapear, points increased, and ball will bounce back down.<br>

1. pset4 - Standard version of Breakout.<br>
2. hacker4 - Implemented GOD mode, the paddle will move itself according to x-position of the ball, essentially the computer is playing the game for you. Implemented paddle shrinking mechanism, variable scoring mechanism, variable-velocity mechanism, and laser.<br>

## Week 5 and 6: Spellchecker
```javascript
~/workspace/pset5/ (master) $ ./speller dictionaries/large endi.txt


MISSPELLED WORDS

nme
veri
persan
yo
bro
USConstitution
http
usconstitution
const
html

WORDS MISSPELLED:     10
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        722
TIME IN load:         0.10
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.06
TIME IN TOTAL:        0.16
```

## Week 7 and 8: Python
Requirements & Dependencies:
```javascript
cd ~/workspace/pset6/sentiments/
pip3 install --user -r requirements.txt
```

Convert some of week 1 & 2 .c programs to .py
```javascript
~/workspace/pset6/ (master) $ python mario.py
Height: 5
    ##
   ###
  ####
 #####
######
```

```javascript
~/workspace/pset6/ (master) $ python greedy.py
O hai! How much change is owed?
0.41
4
```

```javascript
~/workspace/pset6/ (master) $ python caesar.py 13
HELLO
URYYB
```

```javascript
~/workspace/pset6/ (master) $ python vigenere.py bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
```

Sentiments

smile.py : a program that categorizes a word as positive or negative

[![smile.png](https://s28.postimg.org/jzsjsjkod/smile.png)](https://postimg.org/image/907cgxu95/)

tweets.py categorizes a user’s recent 100 tweets as positive or negative (uses Twitter API)

[![tweets.png](https://s23.postimg.org/xjn5x6qm3/tweets.png)](https://postimg.org/image/4u0a0jmlz/)

Implement a website that generates a pie chart categorizing a user’s tweets
[![sentiments.png](https://s23.postimg.org/ortjkn7vf/sentiments.png)](https://postimg.org/image/o2ar8a7br/)

Usage: 
```javascript
~/workspace/pset6/sentiments/ (master) $ export API_KEY= <insert your API_KEY from Twitter here>
~/workspace/pset6/sentiments/ (master) $ export API_SECRET= <insert your API_SECRET from Twitter here>
~/workspace/pset6/sentiments/ (master) $ export FLASK_APP=application.py
~/workspace/pset6/sentiments/ (master) $ export FLASK_DEBUG=1
~/workspace/pset6/sentiments/ (master) $ flask run
```

## Week 9: Python & SQL

C$50 Finance
Implement a website via which users can "buy" and "sell" stocks, a la the below.

[![login.png](https://s29.postimg.org/9db3is4tz/login.png)](https://postimg.org/image/kpnp0kdir/)

[![history.png](https://s28.postimg.org/8lwbj1hf1/history.png)](https://postimg.org/image/6hbyhyfs9/)

[![register.png](https://s29.postimg.org/y3lizvo7r/register.png)](https://postimg.org/image/9abyz8577/)

Requirements & Dependencies:
```javascript
cd ~/workspace/pset7/finance/
pip3 install --user -r requirements.txt
```
Usage: 
```javascript
~/workspace/pset7/finance/ (master) $ flask run
~/workspace/pset7/finance/ (master) $ phpliteadmin finance.db
```
## Week 10 & 11: Javascript
Implement a website that lets users search for articles atop a map (using Google's API)

[![mashup.png](https://s29.postimg.org/nejvi69pz/mashup.png)](https://postimg.org/image/ewafdu377/)

Requirements & Dependencies:
```javascript
cd ~/workspace/pse8/mashup/
pip3 install --user -r requirements.txt
```
Usage: 
```javascript
~/workspace/pset8/mashup/ (master) $ export API_KEY=<API_KEY from Google Maps API>
~/workspace/pset8/mashup/ (master) $ flask run
~/workspace/pset8/mashup/ (master) $ phpliteadmin mashup.db
```

## Week 12-end: Final Project
In progress
