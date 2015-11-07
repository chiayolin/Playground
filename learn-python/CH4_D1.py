#This program will allow the user to type a message and have it converted into
#Morse code
code = [('A',".-"),   ('B',"-..."), ('C',"-.-."), ('D',"-.."), ('E',"."),\
           ('F',"..-."), ('G',"--."),  ('H',"...."), ('I',".."),  ('J',".---"),\
           ('K',"-.-"),  ('L',".-.."), ('M',"--"),   ('N',"-."),  ('O',"---"),\
           ('P',".--."), ('Q',"--.-"), ('R',".-."),  ('S',"..."), ('T',"-"),\
           ('U',"..-"),  ('V',"...-"), ('W',".--"),  ('X',"-..-"),('Y',"-.--"),\
           ('Z',"--..")]
print('This program will convert sentences to Morse Code.')
print('Sentences may only contain letters, spaces or periods.')
print()
correct_item = False
terminate = False
while not correct_item:
    item = input('Enter your sentence (words and spaces only. Type in capitals)): ')
    
    string = input().upper()

for ch in item:
    found_ch= False
    while not found_ch:
        counter = 0
        if ch == letter[counter][0]:
            print(letter[counter][1])
            found_ch= True
    for letter in string:
        print("%s " % (code[code.index(letter) + 1] \
        if letter in code else letter), end=' ')
print(end="\n")
while terminate:
    repeat = input('Again? (y or n): ')
    if 'n' or 'N':
        terminate = True




