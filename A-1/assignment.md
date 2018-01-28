# Encrpytion
# Requirements:
	1. Take inputs MESSAGE and KEY from user.
	2. Remove all extra characters from MESSAGE.
	3. Remove all repeated characters from KEY. 
	4. Capitalize MESSAGE and KEY.
	5. Make 5-by-5 matrix which contains alphabets and in this 	   matrix I and J are at same position in it. This matrix 	   will make from KEY and alphabets where KEY lies in start	   of matrix(in rows).
	6. Make paired-alphabet array of MESSAGE.
	7. Now encrpyt the MESSAGE according to matrix in such way;

		-> If first and second alphabet(from paired-alphabet 	   array) are in different rows then change positions	   vertically according to rows' position.
		-> If first and second alphabet are in same row then 	   change alphabet to next one.
		-> If first and second are same alphabets then change	   alphabets to next one(for first) and the other next one	 (for second) in row.
		-> If length of MESSAGE is odd then make it even.
		
	8. Print Cipher text.
