# Subject tests
|   | Test | Output
| - | ---- | ------
| 1 | `./a.out ab bac abacabccabcb | cat -e` | `a$`
| 2 | `./a.out bonjour salut bonjour bonjour | cat -e` | `u$`
| 3 | `./a.out xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e` | `$`
| 4 | `./a.out bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg | cat -e` | `os$`
| 5 | `./a.out | cat -e` | `$`

# Trace tests
|   | Test | Output
| - | ---- | ------
| 1 | `./a.out "Bonjour" | cat -e` | `Bonjour$`
| 2 | `./a.out "bonjouran" "bonjouran" "confiseriean" "bonne annee" | cat -e` | `on$`
| 3 | `./a.out "bonjour an" "bonjour an" "confiserie an" "bonne annee" | cat -e` | ` an$`
| 4 | `./a.out "voila" "voila" "ouais ben voila" | cat -e` | `voila$`
| 5 | `./a.out "bosdsdfnjodur" "atehhellosd" "afkuonjosurafg" "headfgllosf" "fghellosag afdfbosnjourafg" | cat -e` | `os$`