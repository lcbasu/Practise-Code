import java.util.*;
import java.io.*;
import java.math.*;

public class FCTRL2
{
	public static void main(String[] args)
	{
		try
		{
			Scanner in = new Scanner(System.in);
			
			int t = in.nextInt();
			
			while(t-- > 0)
			{	
				int n = in.nextInt();
				
				BigInteger fact = BigInteger.ONE;
				
				for(int i = 1; i <= n; i++)
				{
					fact = fact.multiply(BigInteger.valueOf(i));
				}	
				System.out.println(fact);
			}
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}

}
