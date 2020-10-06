# fern quest game
# Author: Codie Cottrell
# needs: player class, character class, items class, location class

# this is a template I used as a concept with the client

# going to write this i c++ because it seems that it would be a better way to code this

def walking():
    for i in range(0,3):
        print("...\n")
        time.sleep(1)

import time

print("you have entered the ferny forest of pineland, would you like to continue\n\n")

cont = input()

if (cont.lower() == "yes"):
    walking()
    print ("As you walked down a swampy dirt road you come across a badger. \n\n would you like to address him?\n\n")
elif(cont.lower() == "no"):
    print("You turn away and go on your merry way")
    exit()
else:
    print("sorry, I didnt hear you")
    exit()

cont = input()



if(cont.lower() == "yes"):
    print("\nhow would you like to address him? \n\n 1.\'heres a dollar\'\n\n 2.\'life sucks man\'\n\n 3.\'hello!\'\n\n")
else:
    print("\nyou continue on your merry way")
    walking()
    exit()

begger_remark = input()
if(begger_remark.lower() == "1"):
    print("\n\nthe badger turned out to be a knight in disguise! \n \n He has offered you a chance to join him at the knights table tonight. \n \n Do you accept?")
    exit()
elif(begger_remark.lower() == "2"):
    print("\'\n\n sir, you doth not know...\', the badger says and you continue on your way")
    walking()
else:
    print("\nthe badger throws his dinner at you and runs away\n")
