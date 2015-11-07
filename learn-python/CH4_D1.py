## CH4_D1.py - Morsecode converter 
# Authors: Nirat Singh, Chiayo Lin  
# License: GPL 3.0

import sys

## morsecode table
code = [('A',".-"), ('B',"-..."), ('C',"-.-."), ('D',"-.."), ('E',"."), 
    ('F',"..-."), ('G',"--."),  ('H',"...."), ('I',".."),  ('J',".---"),
    ('K',"-.-"),  ('L',".-.."), ('M',"--"),   ('N',"-."),  ('O',"---"),
    ('P',".--."), ('Q',"--.-"), ('R',".-."),  ('S',"..."), ('T',"-"),
    ('U',"..-"),  ('V',"...-"), ('W',".--"),  ('X',"-..-"),('Y',"-.--"),
    ('Z',"--.."), (' ', " ")]

## info
print('this is a plaintext to Morsecode converter.')

## loop
while True:
    ## prompt and get input
    string = " ".join( \
        input('enter your sentence: ') \
            .upper().rstrip().split()) 
            # ^ convert string to uppercase, remove 
            #   extra whitespaces, and chop off 
            #   trailing newline
    
    ## init
    morsecode = []

    ## main and error handling 
    try:
        for ch in string:
            counter = 0
            found_item = False
            while not found_item:
                if ch == code[counter][0]:
                    morsecode.append(code[counter][1])
                    found_item = True
                counter += 1
    except IndexError:
        print('error: input may contain letters and spaces only :(',
            file=sys.stderr)
    else:
        print(*morsecode, sep=' ', end='\n')

    ## terminate?
    quit() if input('try again? (y/n): ') \
        .split()[0][0].lower() != 'y' else None
