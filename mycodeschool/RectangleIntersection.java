import java.util.Scanner;

class RectangleIntersection
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		while(t>0)
		{
			int first[] = new int[4];
			int second[] = new int[4];
			for (int i = 0; i < 4; ++i)
			{
				first[i] = in.nextInt();
			}
			for (int i = 0; i < 4; ++i)
			{
				second[i] = in.nextInt();
			}
			if(isInterSecting(first, second))
				System.out.println("YES");
			else
				System.out.println("NO");
			t--;
		}
	}
	static boolean isInterSecting(int first[], int second[])
	{
		if(first[2] < second[0] || second[2] < first[0] || first[3] < second[1] || second[3] < first[1])
			return false;
		return true;
	}
}