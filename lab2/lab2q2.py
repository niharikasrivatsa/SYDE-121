import sys

line_counter = 0
sum_length = 0 
max_length = 0 
min_length = 0

for current_line in sys.stdin:

    stripped_line = current_line.strip()

    stripped_length = len( stripped_line )

    length_as_string = str( stripped_length )

    line_counter += 1

    sum_length = sum_length + stripped_length

    if stripped_length > max_length:
        max_length = stripped_length 
    elif min_length == 0:
        min_length = stripped_length 
    elif stripped_length < min_length:
        min_length = stripped_length 

    output_string = length_as_string + "\t" + current_line

    # Need to use an explicit end parameter otherwise it will output a \n
    print( output_string, end='' )

avg_length = sum_length / line_counter

avg_length_string = str( avg_length)
line_counter_string = str( line_counter)
sum_length_string = str ( sum_length)
max_length_string = str ( max_length)
min_length_string = str( min_length)

output_string2 = "lines:" + "\t" + line_counter_string + "\t" + " total length:" + "\t" + sum_length_string + "\t" + "average length:" +  "\t" + avg_length_string + "\t" + "max:" + "\t" +  max_length_string  + "\t" + "min: " +  "\t" + min_length_string

print( output_string2)

