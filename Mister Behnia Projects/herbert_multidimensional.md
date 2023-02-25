
# MultiDimensional Arrays in C programming (more than two dimensions) 
# Tarokh Yaghoubi , Jacob


/*

	Multidimensional Arrays in C programming 
	C allows more than two dimensional arrays 

	the general form of a multidimensional array declaration is : 

	type name[size1][size2][size3] ... [sizeN];

	Arrays of more than "THREE" dimensions are not often used because of the amount of memory the require 

	For Example : a four dimensional character array with the dimensions 10,6,9,4 requires : 
	
	'10 * 6 * 9 * 4' or 2160 Bytes	. if the array held 2-byte integer it would be needed 4,320 Bytes ! 
	
	for double , assuming each double 8 bytes , it would need 17280 bytes 
	
	
*/

/*

		In multidimensional arrays, it takes the computer time to compute each index. This means that
		accessing an element in a multidimensional array can be slower than accessing an element in a
		single-dimension array

*/

/*



		When passing multidimensional arrays into functions, you must declare all but the leftmost
		dimension.

		int m[4][3][6][5];

		a function, func1( ), that receives m, would look like

		void func1(int d[][3][6][5])
		{

		}

		note : ! of course you can include the first dimension if you wish to do so . 


*/