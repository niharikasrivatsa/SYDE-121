import sys

for current_line in sys.stdin:

    stripped_line = current_line.strip()

    reversed_line = stripped_line[::-1]

    print(reversed_line)