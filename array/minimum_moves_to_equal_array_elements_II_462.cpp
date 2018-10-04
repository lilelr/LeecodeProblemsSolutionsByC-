//
// Created by YuXiao on 10/3/18.
//
//  https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
//
//Actually, when n is even, any number between the median two numbers can give a minimum number of moves. Here is a simple example, assume the array is sorted, x is the number chosen:
//
//a0 a1 a2 a3 x a4 a5 a6 a7; // moves needed: (a4 - a3) + (a5 - a2) + (a6 - a1) + (a7 - a0)
//
//a0 a1 a2 (a3 a4 x) a5 a6 a7; // moves needed: (2x - a3 - a4) + (a5 - a2) + (a6 - a1) + (a7 - a0).
//
//a0 a1 (a2 a3 a4 a5 x) a6 a7; // moves needed: (2x - a3 - a4) + (2x - a5 - a2) + (a6 - a1) + (a7 - a0)
//
//As you can see, the number of moves needed for the numbers outside the parentheses remains the same, and inside the parentheses increases. So moving x leftward or rightward will increase the moves needed. This is similar when n is odd, and because there is only one median, so the median should be chosen.
//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/94932/Why-median-is-better-than-average
//public class Solution {
//public int minMoves2(int[] nums) {
//        Arrays.sort(nums);
//        int i = 0, j = nums.length-1;
//        int count = 0;
//        while(i < j){
//            count += nums[j]-nums[i];
//            i++;
//            j--;
//        }
//        return count;
//    }
//}