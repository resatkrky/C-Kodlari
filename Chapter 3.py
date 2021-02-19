##def hello():
##  print('Howdy!')
##  print('Howdy!!!')
##  print('Hello there.')
##
##hello()
##hello()
##hello()

##def hello(name):
##  print('Hello ' + name)
##
##hello('Alice')
##hello('Bob')

##import random
##
##def getAnswer(answerNumber):
## if answerNumber == 1:
##  return 'It is certain'
## elif answerNumber == 2:
##  return 'It is decidedly so'
## elif answerNumber == 3:
##  return 'Yes'
## elif answerNumber == 4:
##  return 'Reply hazy try again'
## elif answerNumber == 5:
##  return 'Ask again later'
## elif answerNumber == 6:
##  return 'Concentrate and ask again'
## elif answerNumber == 7:
##  return 'My reply is no'
## elif answerNumber == 8:
##  return 'Outlook not so good'
## elif answerNumber == 9:
##  return 'Very doubtful'
##
##r = random.randint(1, 9)
##fortune = getAnswer(r)
##print(fortune)

##print('Hello', end=' ')
##print('World')

##print('cats', 'dogs', 'mice', sep='-')

##def spam():
##  eggs = 31337 #Local değişken 
##
##spam()
##print(eggs)

##def spam():
##  eggs = 99
##  bacon()
##  print(eggs)
##
##def bacon():
##  ham = 101
##  eggs = 0
##
##spam()

##def spam():
##  print(eggs) #Local değişken
##
##eggs = 42 #Global değişken
##spam()
##print(eggs)

##def spam():
##   eggs = 'spam local'
##   print(eggs) # prints 'spam local'
##
##def bacon():
##   eggs = 'bacon local'
##   print(eggs) # prints 'bacon local'
##   spam()
##   print(eggs) # prints 'bacon local'
##
##eggs = 'global'
##bacon()
##print(eggs) # prints 'global'

##def spam(divideBy):
##    return 42 / divideBy
##
##print(spam(2))
##print(spam(12))
##print(spam(0)) #Sıfırda hata verecek
##print(spam(1))

### This is a guess the number game.
##import random
##
##secretNumber = random.randint(1, 20)
##print('I am thinking of a number between 1 and 20.')
##
### Ask the player to guess 6 times.
##for guessesTaken in range(1, 7):
##   print('Take a guess.')
##   guess = int(input())
##   if guess < secretNumber:
##     print('Your guess is too low.')
##   elif guess > secretNumber:
##     print('Your guess is too high.')
##   else:
##     break # This condition is the correct guess!
##if guess == secretNumber:
##   print('Good job! You guessed my number in ' + str(guessesTaken) + ' guesses!')
##else:
##   print('Nope. The number I was thinking of was ' + str(secretNumber))
