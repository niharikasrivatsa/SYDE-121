import sys

for current_line in sys.stdin:
    
    stripped_line = current_line.strip()

    num = int ( stripped_line)

    if num % 3 == 0 and num % 5 == 0:
         output_string = stripped_line + "\t" + "Fizz  Buzz" 
    elif num % 3 == 0:
        output_string = stripped_line + "\t" + "Fizz"
    elif num % 5 == 0:
        output_string = stripped_line + "\t" + "Buzz"
    elif num % 5 != 0 and num%3 !=0:
        output_string = stripped_line 
    
    print( output_string)




