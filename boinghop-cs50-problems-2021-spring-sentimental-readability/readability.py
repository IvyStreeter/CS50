import cs50

text = cs50.get_string("Text:\n")

# intitializing variables for counting
letter = 0 
word = 1
sentence = 0

# iterate over the text
for character in text:
    # if character is a letter
    if character.isalpha():
        # count +1 value
        letter = letter + 1
    # if character is a space
    if character.isspace():
        # count +1 value
        word = word + 1
    # if character is one of these punctuation
    if character == "." or character == "!" or character == "?":
        # count +1 value
        sentence = sentence + 1
        
# get the average over 100 words for letteres and sentences
L = letter / float(word) * 100
S = sentence / float(word) * 100

# formula + round into index
index = round(0.0588 * L - 0.296 * S - 15.8)
if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")