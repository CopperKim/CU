import copy 
import math
import time

class vector :
    def __init__(this, dim, elements) :
        this.dim = dim
        this.elements = copy.deepcopy(elements)

    def __mul__(this, other) :
        assert (this.dim == other.dim), "vector is not able to perform dot product"
        res = 0
        for i in range(this.dim) : res += this.elements[i]*other.elements[i] 
        return res
    
class matrix :
    def __init__(this, row, column, elements) :
        this.row = row
        this.column = column
        this.elements = tuple(tuple(elements[j][i] for i in range(row)) for j in range(column))

    def rowvec(this, idx) :
        elements = tuple(this.elements[idx][i] for i in range(this.column))
        return vector(this.column, elements)
    
    def colvec(this, idx) :
        elements = tuple(this.elements[i][idx] for i in range(this.row))
        return vector(this.row, elements)
    
    def __mul__(this, other) :
        assert (this.row == other.column), "matrix is not multiplcatable"
        elements = tuple(tuple(this.colvec(i)*other.rowvec(j) for j in range(this.column)) for i in range(other.row))
        res = matrix(other.row, this.column, elements)
        return res
    
    def __str__(this) :
        res = ""
        for i in range(this.column) :
            for j in range(this.row) :
                res += str(this.elements[i][j]) + " "
            res += '\n'
        return res

def fibo(n) :   
    A = matrix(2, 2, ((1, 1), (1, 0)))
    def recursiveFibo(n) : 
        if (n == 0 or n == 1) : return A
        R = recursiveFibo(n//2)
        if (n%2 == 0) : return R*R
        return R*R*A
    return recursiveFibo(n).elements[0][0]

start = time.time()
res = fibo(10000000)
print(res)
print(math.log(res))
print(time.time()-start)