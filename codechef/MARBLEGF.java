import java.util.*;
import java.io.*;
import java.math.*;

public class MARBLEGF
{
	public static void main(String[] args)
	{
		try
		{
			Scanner in = new Scanner(System.in);
			
			int n = in.nextInt();
			int q = in.nextInt();
			
			int[] marbleArr = new int[n];
			
			for(int i = 0; i < n; i++)
			{
				marbleArr[i] = in.nextInt();
			}
			
			Scanner in1 = new Scanner(System.in);
			while(q-- > 0)
			{
				String[] query = in1.nextLine().split(" ");
				int i = Integer.parseInt(query[1]);;
				
				int j = -1, num_marbles = -1;
				
				if(query[0].equals("S"))
				{
					j = Integer.parseInt(query[2]);
					
					BigInteger sum = BigInteger.valueOf(0);
					for(int index = i; index <= j; index++)
					{
						sum = sum.add(BigInteger.valueOf(marbleArr[index]));
					}
					System.out.println(sum);
				}
				else if(query[0].equals("G"))
				{
					num_marbles = Integer.parseInt(query[2]);
					marbleArr[i] += num_marbles;  
				}
				else if(query[0].equals("T"))
				{
					num_marbles = Integer.parseInt(query[2]);
					marbleArr[i] -= num_marbles;  
				}
			}
			
			in.close();
			in1.close();
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}
}
