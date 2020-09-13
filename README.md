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