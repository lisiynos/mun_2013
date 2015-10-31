
import sys
sys.stdin = open('berg.in', 'r')
sys.stdout = open('berg.out', 'w')

cyphertext = input()

cleartext, key = cyphertext[::2], cyphertext[1::2]

if key != 'a' * len(key):
    print('Suspicious!')
else:
    print(cleartext)