file_path = 'trains.txt'
student_id = 'A0271585W'

starting_line = 0
matrix = []
i = 0

letter_to_number = {chr(i): i - 65 for i in range(ord('A'), ord('J') + 1)}

with open(file_path, 'r') as file:
   for line_number, line in enumerate(file, 1):

      # identify which line has my student number
      if student_id in line:
         print(f"Found '{student_id}' on line {line_number}: {line.strip()}")
         
         # shift line to first row of adjacency matrix
         starting_line = line_number + 2

      # strips the relevant lines
      if line_number == (starting_line + i) and i < (10 + 2):
         matrix.append(line.strip().split('\t'))
         i += 1

# post-processing of matrix
for i in range(0, 12):
   
   # we only need the last character for source and destination
   if i >= 10:
      matrix[i][0] = matrix[i][0][-1]
      continue
   
   matrix[i].pop(0)

# print output to paste to unit tests:
print("[OUTPUT]")
print("")
print("int src = " + str(letter_to_number[matrix[10][0]]) + ";")
print("int dest = " + str(letter_to_number[matrix[11][0]]) + ";")
print("")

#EXAMPLE: g.addEdge(7, 2, 7);
for i in range(len(matrix) - 2):
   for j in range(len(matrix[i])):
      if matrix[i][j] != '    ':
         print("g.addEdge(" + str(i) + ", " + str(j) + ", " + str(matrix[i][j]) + ");")

print("")
print("Path p = shortestPath(g, src, dest);")
print("")
