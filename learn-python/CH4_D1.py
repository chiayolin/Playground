## CH4_D1.py - Morsecode converter 
# Authors: Nirat Singh, Chiayo Lin  
# License: GPL 3.0

## init 
code = [('A',".-"), ('B',"-..."), ('C',"-.-."), ('D',"-.."), ('E',"."), 
    ('F',"..-."), ('G',"--."),  ('H',"...."), ('I',".."),  ('J',".---"),
    ('K',"-.-"),  ('L',".-.."), ('M',"--"),   ('N',"-."),  ('O',"---"),
    ('P',".--."), ('Q',"--.-"), ('R',".-."),  ('S',"..."), ('T',"-"),
    ('U',"..-"),  ('V',"...-"), ('W',".--"),  ('X',"-..-"),('Y',"-.--"),
    ('Z',"--..")]

## info
print('this is a plaintext to Morsecode converter,\n' + \
    'input may contain letters only.')


## loop
while True:
    ## prompt and get input
    string = input('enter your sentence: ').upper().rstrip()

    ## main and error handling 
    try:
        for ch in string:
            counter = 0
            found_item = False
            while not found_item:
                if ch == code[counter][0]:
                    print(code[counter][1], end='')
                    found_item = True
                counter += 1
    except IndexError:
        print("error: invalid character(s)", end='')
    print(end='\n')

    ## terminate?
    quit() if input('again? (y/n): ').split()[0][0].lower() != 'y' \
        else None
