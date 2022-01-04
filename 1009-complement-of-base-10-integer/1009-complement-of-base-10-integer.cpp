class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        else
        {
            int c = log2(n)+1; // This will count number of bits in the given number(i.e binary of 7 is 111 so it will return 3)

            int num=pow(2,c)-1; // returns the max binary number on given number of digits
            return num^n; // xor with num will give us desired output(5=101=> 101 ^ 111 = 010 => 2)
        }
        
    }
};