import java.util.*;
import java.io.*;
import java.math.*;

public class DOUBLE
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
				System.out.println(doubleString(n));
			}
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}
	
	public static int doubleString(int n)
	{
		if(n%2 == 0)
			return n;
		else
			return n-1;
	}

}
