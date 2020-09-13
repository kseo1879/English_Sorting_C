# Sorter

This is a sotring algorithm which sorts the file in alpha numeric or numeric order. 

## How to use

1. First you need to build and link each object file:
HOWEVER you can simply type 'make' on your command line. 

```bash
make
```

2. After you build your program here is the option:

```bash
./sorter words.txt -a -alph
```

This was a quick example of how to use the algorithm. 
- First argument would be your file name (file path)
- Second argument is either -a or -d which each represents sorting in ascending or descending order. 
- Last argument is either -alph or -num which decides the method to sort the algorithm. It is either alpha-numeric or numeric sort. 

3. To clean the directory

```bash
make clean
```

## Testing

In order to test your code I have made a simple testing test under test folder. 

There are total four test (txt) files that you can utilise.

IMPORTANTLY I have also amended make file to test each of the function. 

1. Testing alpha numeric function in ascending order

```bash
make
make test1
```
This will utilise the alph-ascending.txt file under test folder.


2. Testing alpha numeric function in ascending order

```bash
make
make test2
```
This will utilise the alph-descending.txt file under test folder.


3. Testing numeric function in ascending order

```bash
make
make test3
```
This will utilise the num-ascending.txt file under test folder.


4. Testing numeric function in ascending order

```bash
make
make test4
```
This will utilise the num-descending.txt file under test folder.

## Important Note to my Lovely Tutor
I made this section to explain how my code works and which method I have implemented each functionality.
Here are some keypoint. 

1. sorter.c under src directory.
- This is where the main function is and I have written some defensive coding to guard from possible error that user might make while writing a command. 
- Based on the option user picks it will either utilise functions in alpha.h or num.h

2. How I have implemented without using a long fixed size array.
- Basically what I have done is that I was using only 2 byte char array; buf(one for character and one for null terminator) which will save character by character and compare it with other words from the file. In other words since it is compareing character by character and resetting buf after reading it has no limits to reading a big line. 

3. Difference I made to alpha-numeric and numeric 
- First for alpha-numeric I've tried to make it simillar to the sort function in linux terminal. It will first print the numebers, then from the alphabetical order. When asending lower case will have the priority than the capital letters. 
This is the actual result of the ascending alpha numerical sort. 

```bash
make test1
./sorter ./test/alph-ascending.txt -a -alph
101010
1202
13
a
Apple
b
Banana
c
Cake
Crepe
d
e
eg
f
Orange
```

- For the numeric sort I've tried to make it simillar to the sort with '-n' flag which puts non alphabetical words to it's least priority. However one thing that I did not implement was making 10 comes later than 3 in ascending order. This was due to the possible weakness of my code where I have made the funcstion to compare string character by character. 
This is the actual result of the ascending numerical sort

```bash
make test3
./sorter ./test/num-ascending.txt -a -num
a
Apple
b
Banana
c
Cake
Crepe
d
e
eg
f
Orange
101010
1202
13
```

4. How I tested
I have tried to think about most of the edge test cases for each of the functionaliry. I have resolved every error that I had with the edge test case input that I have found. 

Here is the cases where I have tested
- Alpahbet with upper case and lower case. 
- Putting least prior letter to the front or back
- Putting same letter with different character at the end (ex) apple, appla)
- File with no contents
- File with only new line

## To conclude
- I have basically followed the required field of the homeework. But to be honest I think I have a bit of repetition that I could get rid of. I tried hard to get rid of by making the helper.h under src folder to minimize as much as I can.  
- I've heard that it is better to keep the readme simple but I have put in quite a lot of effort in this and there were a lot of things that I have done and wanted to write it down. Sorry about the long readme file. 