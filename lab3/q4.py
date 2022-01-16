import random

matrix = []
row_count = 5
col_count = 5

data_list = [ ]

#Creating Random List of Floating Points
for i in range (0,25):
    value =  (round(random.uniform(1.00, 99.90),2))
    data_list.append(value)


#Making a Matrix with the Random List
for i in range(row_count):
    rowList = []
    for j in range (col_count):
        rowList.append(data_list[row_count * i + j])
    matrix.append(rowList)

print("Matrix:")
#Display Matrix by row and coloumn
for i in range (row_count):
    for j in range(col_count):
        print(matrix[i][j], end=" ")
    print("")

