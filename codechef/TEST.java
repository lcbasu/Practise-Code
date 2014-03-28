import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args)
	{
		try
		{
			Scanner in = new Scanner(System.in);
			
			while(true)
			{
				int el = in.nextInt();
				if(el != 42)
				{
					System.out.println(el);
				}
				else
				{
					in.close();
					System.exit(0);
				}
			}
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}
}