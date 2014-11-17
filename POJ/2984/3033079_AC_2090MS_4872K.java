/*

poj 2984

*/

import java.util.*;

import java.math.*;

import java.io.*;



public class Main

{

    public static void main(String args[])

    {

        Scanner cin = new Scanner(System.in);

        BigInteger a= cin.nextBigInteger();		System.out.println(BigInteger.ONE.shiftLeft(a.bitCount()).subtract(BigInteger.ONE));

    }

}
