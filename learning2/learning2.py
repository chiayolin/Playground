# [file_name].py
# 
# [Program Description]
#
# date:    [Today's Date]
# author:  [Your Name] 
# license: [Your Prefered Open Source License]

from random import randint

students = [
    "Frank Sinatra", "John Lennon", "Bob Dylan", "Ho Chi Minh", 
    "Adolf Hitler", "Sun Yat-Sen", "Fidel Castro", "Alan Turing", 
    "Ada Lovelence", "Nat King Cole" ]

amount = int(raw_input("How many students? "))

while amount != 0:
    index = randint(0, len(students) - 1)
    print(students[index])
    amount = amount - 1
