# Problem Set 2, hangman.py
# Name: kana800 
# Collaborators: non
# Time spent: start 12:00pm end 01:00pm 

# Hangman Game
# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)
import random
import string

WORDLIST_FILENAME = "words.txt"


def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist



def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)
    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code

# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = load_words()


def is_word_guessed(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing; assumes all letters are
      lowercase
    letters_guessed: list (of letters), which letters have been guessed so far;
      assumes that all letters are lowercase
    returns: boolean, True if all the letters of secret_word are in letters_guessed;
      False otherwise
    '''
    for i in secret_word:
        if i not in letters_guessed:
            return False
    return True



def get_guessed_word(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string, comprised of letters, underscores (_), and spaces that represents
      which letters in secret_word have been guessed so far.
    '''
    secretwordwithblanks = secret_word
    for letter in secretwordwithblanks:
        if letter not in letters_guessed:
            # find the index of the letter
            secretwordwithblanks = secretwordwithblanks.replace(letter,"_")
    return secretwordwithblanks

def get_available_letters(letters_guessed):
    '''
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string (of letters), comprised of letters that represents which letters have not
      yet been guessed.
    '''
    lowercaseletters = string.ascii_lowercase
    available = ""
    for i in lowercaseletters:
        if i not in letters_guessed:
            available += i
    return available

def hangman(secret_word):
    '''
    secret_word: string, the secret word to guess.
    Starts up an interactive game of Hangman.
    * At the start of the game, let the user know how many
      letters the secret_word contains and how many guesses s/he starts with.
    * The user should start with 6 guesses
    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    * Ask the user to supply one guess per round. Remember to make
      sure that the user puts in a letter!
    * The user should receive feedback immediately after each guess
      about whether their guess appears in the computer's word.
    * After each guess, you should display to the user the
      partially guessed word so far.
    Follows the other limitations detailed in the problem write-up.
    '''
    # number of guesses
    guesses = 6
    # list of letter
    letter_guessed = []
    # letting the user know the number of letters in the word
    print(f"The number of letters in the word{len(secret_word)}\n")
    while guesses != 0:
        print(f"The number of guesses left {guesses}\n")
        # asking the user to enter the letter
        while True:
            letterGuessed = input("Guess the Letter:\t")
            # checking if the letterGuessed is an string
            if letterGuessed.lower().islower():
                letterGuessed = letterGuessed.lower()
                letter_guessed.append(letterGuessed)
                break
            else:
                print("Make Sure to Input a Letter")
        # giving the feedback to the user about the guessed word
        secretwordwithblanks = get_guessed_word(secret_word, letter_guessed)
        # check if the word is guessed!
        if is_word_guessed(secret_word, letter_guessed):
            print("You Won!\n")
            return
        else:
            secretwordwithblanks = get_guessed_word(secret_word, letter_guessed)
            availableletters = get_available_letters(letter_guessed)
            print(f"{secretwordwithblanks}\tavailable letters: {availableletters}")
        guesses -= 1
    print("You Lost\n")
    return



# When you've completed your hangman function, scroll down to the bottom
# of the file and uncomment the first two lines to test
#(hint: you might want to pick your own
# secret_word while you're doing your own testing)


# -----------------------------------



def match_with_gaps(my_word, other_word):
    '''
    my_word: string with _ characters, current guess of secret word
    other_word: string, regular English word
    returns: boolean, True if all the actual letters of my_word match the
        corresponding letters of other_word, or the letter is the special symbol
        _ , and my_word and other_word are of the same length;
        False otherwise:
    '''
    if my_word.count("_") == 1:
        return False
    elif len(my_word) == len(other_word):
        # finding the posistion of the holes
        holes = [i for i in range(0,len(my_word)) if my_word[i] == "_"]
        other_word =list(other_word)
        for i in holes:
            other_word[i] = "_"
        if my_word == "".join(other_word):
            return True
        else:
            return False
    else:
        return False


def show_possible_matches(my_word):
    '''
    my_word: string with _ characters, current guess of secret word
    returns: nothing, but should print out every word in wordlist that matches my_word
             Keep in mind that in hangman when a letter is guessed, all the positions
             at which that letter occurs in the secret word are revealed.
             Therefore, the hidden letter(_ ) cannot be one of the letters in the word
             that has already been revealed.

    '''
    global wordlist
    if len(my_word) == 1:
        print("No matches found")
        return
    else:
        words = [i for i in wordlist if match_with_gaps(my_word, i)]
        if len(words) == 0:
            print("No matches found")
            return
        else:
            wordstr = ""
            for i in words:
                wordstr += f"{i} "
            print(f"{wordstr}")




def hangman_with_hints(secret_word):
    '''
    secret_word: string, the secret word to guess.
    Starts up an interactive game of Hangman.
    * At the start of the game, let the user know how many
      letters the secret_word contains and how many guesses s/he starts with.
    * The user should start with 6 guesses
    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    * Ask the user to supply one guess per round. Make sure to check that the user guesses a letter
    * The user should receive feedback immediately after each guess
      about whether their guess appears in the computer's word.
    * After each guess, you should display to the user the
      partially guessed word so far.
    * If the guess is the symbol *, print out all words in wordlist that
      matches the current guessed word.
    Follows the other limitations detailed in the problem write-up.
    '''
    # number of guesses
    guesses = 6
    # list of letter
    letter_guessed = []
    # letting the user know the number of letters in the word
    print(f"The number of letters in the word {len(secret_word)}\n")
    while guesses != 0:
        print(f"The number of guesses left {guesses}\n")
        # asking the user to enter the letter
        while True:
            letterGuessed = input("Guess the Letter: ")
            # checking if the letterGuessed is an string
            if letterGuessed.lower().islower() or letterGuessed == "*":
                if letterGuessed != "*":
                    letterGuessed = letterGuessed.lower()
                    letter_guessed.append(letterGuessed)
                break
            else:
                print("Make Sure to Input a Letter")
        # giving the feedback to the user about the guessed word
        secretwordwithblanks = get_guessed_word(secret_word, letter_guessed)
        if letterGuessed == "*":
            show_possible_matches(secretwordwithblanks)
        # check if the word is guessed!
        if is_word_guessed(secret_word, letter_guessed):
            print("You Won!\n")
            return
        else:
            secretwordwithblanks = get_guessed_word(secret_word, letter_guessed)
            availableletters = get_available_letters(letter_guessed)
            print(f"{secretwordwithblanks}\tavailable letters: {availableletters}")
        guesses -= 1
    print("You Lost\n")
    return



# When you've completed your hangman_with_hint function, comment the two similar
# lines above that were used to run the hangman function, and then uncomment
# these two lines and run this file to test!
# Hint: You might want to pick your own secret_word while you're testing.


if __name__ == "__main__":
    # pass

    # To test part 2, comment out the pass line above and
    # uncomment the following two lines.
    #secret_word = choose_word(wordlist)
    #secret_word = "cake"
    #hangman(secret_word)

###############
    # To test part 3 re-comment out the above lines and 
    # uncomment the following two lines. 
    secret_word = "cake"
    hangman_with_hints(secret_word)
