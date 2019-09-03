# Subject tests
## Test 1
```
./a.out ab bac abacabccabcb | cat -e
a$
```
## Test 2
```
./a.out bonjour salut bonjour bonjour | cat -e
u$
```
## Test 3
```
./a.out xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
```
## Test 4
```
./a.out bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg | cat -e
os$
```
## Test 5
```
./a.out | cat -e
$
```

# Trace tests
## Test 1
```
./a.out "Bonjour" | cat -e
Bonjour$
```
## Test 2
```
./a.out "bonjouran" "bonjouran" "confiseriean" "bonne annee" | cat -e
on$
```
## Test 3
```
./a.out "bonjour an" "bonjour an" "confiserie an" "bonne annee" | cat -e
 an$
 ```
## Test 4
```
./a.out "voila" "voila" "ouais ben voila" | cat -e
voila$
```
## Test 5
```
./a.out "bosdsdfnjodur" "atehhellosd" "afkuonjosurafg" "headfgllosf" "fghellosag afdfbosnjourafg" | cat -e
os$
```
