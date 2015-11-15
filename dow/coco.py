# This program will display the day of the week that the 
# following holidays fall on for a year entered by the user:
#
# New Year’s eve   -  12/31
# St. Patrick Day  -  03/17
# April Fool’s Day -  04/01
# Fourth of July   -  07/04
# Labor Day        -  First monday of September
# Halloween        -  10/31
# User’s birthday  -  Dynamic 
#

# dow algorithm by Tomohiko Sakamoto 
def dow(m, d, y):
    # constants
    t = (0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4); c = 0	
    y -= m < 3
    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d + c) % 7)

# some common senses that computers don't know
monday = 1; labor_day_day = 1 # initialize it first
holiday = [("New Year's Eve", 12, 31), ("St. Patrick Day", 3, 17),
    ("April Fool’s Day", 4, 1), ("Fourth of July", 7, 4),
        ["Labor Day", 9, 1], ("Halloween", 10, 31)]
month_name = ('January', 'February', 'March', 'April', 'May', 'June', 'July', 
    'August', 'September', 'October', 'November', 'December')
day_name = ('Sunday', 'Monday','Tuesday','Wednesday','Thursday',
    'Friday', 'Saturday')

terminate = 0
while not terminate: 
    # get user's birthday into a list
    user_birthday = \
        input("what's your birthday? (mm/dd/yyyy): ").split("/")

    # convert user's birthday into a list of intergers
    # using list comprehension
    user_birthday = [int(i) for i in user_birthday]

    # get a year number in interger 
    the_year = int(input("which year are you looking for? "))

    # define numeric symbols
    MONTH = 0; DAY = 1; YEAR = 2;

    # find the DoW of user's birthday
    dow_user_birthday = \
        dow(user_birthday[MONTH],
            user_birthday[DAY], user_birthday[YEAR])
    dow_user_birthday_the_year = \
        dow(user_birthday[MONTH],
            user_birthday[DAY], the_year)

    # re-define the numeric symbols
    NAME = 0; MONTH = 1; DAY = 2; YEAR = the_year
    labor_day = 4 # labor day is the forth tuple of the list

    # print a newline so it looks better
    print(end = '\n')

    # print user's birthday
    print("your birthday was on", day_name[int(dow_user_birthday)], 
        "and it's on", day_name[int(dow_user_birthday_the_year)],
        "in", the_year)

    # find every DoWs using a loop 
    counter = 0
    while counter != len(holiday):
        # labor's day special ;)
        if counter == labor_day:
            while int(dow(9, labor_day_day, the_year)) != 1:
                labor_day_day += 1
            holiday[labor_day][DAY] = labor_day_day
            
        # since everything is in a list, just print it 
        # base on the list counter 
        print(holiday[counter][NAME], "is on",
            month_name[holiday[counter][MONTH] - 1],
            str(holiday[counter][DAY]) + ",",
            day_name[int(dow(holiday[counter][MONTH], 
            holiday[counter][DAY], YEAR))])
        counter += 1
    
    terminate = 1 if input("try again? ")[0][0].lower() != 'y' else None 
