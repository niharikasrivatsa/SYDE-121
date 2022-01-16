import random
import sys

line_counter = 0
matrix = []
data_list = []
elements = 0
target_rows = []
target_col = []

for current_line in sys.stdin:

    line_counter = line_counter + 1

    if line_counter == 1:
        row_count = int(current_line.strip())

    elif line_counter == 2: 
        col_count = int(current_line.strip())
        
        elements = row_count * col_count

    elif line_counter <= elements + 2:
        value = float(current_line.strip())
        data_list.append(value)

    elif line_counter >  elements + 2 :
        if current_line != "/n":

            if (elements + 2) % 2 == 0:
                if line_counter % 2 != 0:
                    row_target =  int(current_line.strip())
                    if  row_target > row_count or row_target < 0:
                        target_rows.append(-1)
                    else:    
                        target_rows.append(row_target)
                else:
                    col_target =  int(current_line.strip())
                    if  col_target > col_count or col_target < 0:
                        target_col.append(-1)
                    else:   
                        target_col.append(col_target)

            elif (elements + 2) % 2 != 0:
                if line_counter % 2 == 0:
                    row_target =  int(current_line.strip())
                    if  row_target > row_count or row_target < 0:
                        target_rows.append(-1)
                    else:    
                        target_rows.append(row_target)
                else:
                    col_target =  int(current_line.strip())
                    if  col_target > col_count or col_target < 0:
                        target_col.append(-1)
                    else:   
                        target_col.append(col_target)
                

#Making a Matrix with list
if abs(row_count - col_count) == 1:
    for i in range(row_count):
        rowList = []
        for j in range (col_count):
            rowList.append(data_list[((row_count+1) * i) + j])
        matrix.append(rowList)

else:
    for i in range(row_count):
        rowList = []
        for j in range (col_count):
            rowList.append(data_list[((row_count) * i) + j])
        matrix.append(rowList)


print("Matrix:")
#Display Matrix by row and coloumn
for i in range (row_count):
    for j in range(col_count):
        print(matrix[i][j], end=" ")
    print("")


print("\nTargets:")
for i in range (len(target_rows)):
    row = target_rows[i]-1
    col = target_col[i]-1
    if (target_rows[i] == -1) or (target_col[i] == -1):
        print("Target", str(i+1), ": ERROR TARGET NOT IN MATRIX ")
    else:
        print("Target", str(i+1) + ": Matrix[" + str(row+1) + "][" + str(col+1) + "] = " + str(matrix[row][col]))
 