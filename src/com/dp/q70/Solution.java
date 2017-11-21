package com.dp.q70;

class Solution {

    private int fab(int n){
        double sqrt5 = Math.sqrt(5);
        return (int)((1/sqrt5) *( Math.pow( (1+sqrt5)/2, n ) - Math.pow((1-sqrt5)/2, n)));
    }
    public int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3){
            return n;
        }
        return fab(n)+fab(n-1);
    }
}