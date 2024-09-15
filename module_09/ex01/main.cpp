#include "RPN.hpp"

int main(void)
{
	// RPN::compute( "8 9 * 9 - 9 - 9 - 4 - 1 +");
	// RPN::compute( "7 7 * 7 -");
	// RPN::compute(  "1 2 * 2 / 2 * 2 4 - +");
	RPN::compute(  "(1 + 1)");
	 
}

/* 

tempOperants
1 2 2 2 2 4 <- top

tempOperations
* / * - + <- top

tempOperants -> operants

tempOperations -> operations

4 2 2 2 2 1 <- top
+ - * / * <- top
[*, 1, 2] 2
[/, 2, 2] 1
[*, 1, 2] 2
[-, 2, 2] 0
[+, 0, 4] 4

 "1 2 * 2 / 2 * 2 4 - +"
 [*, 1, 2] 2
 [/, 2, 2] 1
 [*, 1, 2] 2
 [-, 2, 2, 4] -2
 [+, 2, -2] 0


tempOperants
1 2 3 4 5 6 <- top

tempOperations
* / * - + <- top

tempOperants -> operants
6 5 4 3 2 1 <- top

tempOperations -> operations
+ - * / * <- top

[2, 1, *]
1 * 2 = 2
[2, 3, /]
2 / 3 = (2/3)
[(2/3), 4, *]
(2/3) * 4 = (8/3)
[(8/3), 5, -]
(8/3) - 5 = ((8/3) - 5)
[((8/3) - 5), 6, +]
((8/3) - 5) + 6 = (11/3) = 3.666666667



 */