def isSafe(mat, r, c): 
    for i in range(r):         
        if mat[i][c] == 'Q': 
            return False         
        if c - r + i >= 0 and mat[i][c - r + i] == 'Q': 
            return False         
        if c + r - i < len(mat) and mat[i][c + r - i] == 'Q': 
            return False     
        return True 
 
def nQueen(mat, r):     
    if r == len(mat): 
        printSolution(mat)         
        return 
    for i in range(len(mat)):         
        if isSafe(mat, r, i):             
            mat[r][i] = 'Q'             
            nQueen(mat, r + 1)             
            mat[r][i] = '-' 
 
def printSolution(mat): 
    for r in mat: 
        print(''.join(r)) 
    print() 
 
if __name__ == '__main__': 
    print("Enter the number of queens") 
    N = int(input()) 
    mat = [['-' for _ in range(N)] for _ in range(N)] 
    nQueen(mat, 0) 
 
