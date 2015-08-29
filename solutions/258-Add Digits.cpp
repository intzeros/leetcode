/* ----------------- Solution 1: Recursion ----------------- */
/*class Solution {
public:
  int getSum(int num){
    int sum = 0;
		while(num){
			sum += num%10;
			num /= 10;
		}
		return sum;
	}

    int addDigits(int num) {
      if(num < 10) return num;
      return addDigits(getSum(num));
    }
};*/

/* ----------------- Solution 2: o(1) ----------------- */
class Solution {
public:
  int addDigits(int num) {
    if(num == 0) return 0;
    int rst = num % 9;
    if(rst == 0) return 9;
    else return rst;
  }
};
