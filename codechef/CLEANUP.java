import java.util.*;
import java.io.*;
import java.math.*;

public class CLEANUP
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
				int m = in.nextInt();
				
				char[] jobs = new char[n+1];
				
				//E-> empty, D-> already done, A->by the assistant, C->by the chef
				for(int i = 0; i <= n; i++)
				{
					jobs[i] = 'E';
				}
				
				boolean noJobByChef = true;
				boolean noJobByAsst = true;
				
				for(int i = 1; i <= m; i++)
				{
					int doneIndex = in.nextInt();
					
					jobs[doneIndex] = 'D';
				}
				
				char turn = 'C';	//C and A
				
				for(int i = 1; i <= n; i++)
				{
					if(jobs[i] != 'N' && jobs[i] == 'E')
					{
						if(turn == 'C')
						{
							jobs[i] = 'C';
							turn = 'A';
							noJobByChef = false;
						}
						else if(turn == 'A')
						{
							jobs[i] = 'A';
							turn = 'C';
							noJobByAsst = false;
						}
					}
				}
				
				//for chef
				if(noJobByChef)
				{
					System.out.println();
				}
				else
				{
					for(int i = 1; i <= n; i++)
					{
						if(jobs[i] == 'C')
							System.out.print(i + " ");
					}
					System.out.println();
				}

				//for assistant
				if(noJobByAsst)
				{
					System.out.println();
				}
				else
				{
					for(int i = 1; i <= n; i++)
					{
						if(jobs[i] == 'A')
							System.out.print(i + " ");
					}
					System.out.println();
				}
			}
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}

}
