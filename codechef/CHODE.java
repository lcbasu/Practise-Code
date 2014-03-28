import java.util.*;
import java.io.*;

public class CHODE
{
	public static void main(String[] args)
	{
		try
		{
			Scanner in1 = new Scanner(System.in);
			
			int t;
			
			t = in1.nextInt();
			while(t-- > 0)
			{
				Scanner in2 = new Scanner(System.in);
				
				String freqStr = in2.nextLine();
				String text = in2.nextLine();
				
				Map<Character, Integer> map = new LinkedHashMap<Character, Integer>();
				
				char[] finalStrChar = text.toCharArray();
				
				for(char c : finalStrChar)
				{
					if(Character.isLetter(c))
					{
						if(map.containsKey(c))
						{
							map.put(c, map.get(c)+1);
						}
						else
						{
							map.put(c, 1);
						}
					}
				}
				
				List<TextChar> list = new ArrayList<TextChar>();
				
				for(char c : map.keySet())
				{
					list.add(new TextChar(c, map.get(c)));
				}
				

				Collections.sort(list);

				
				int freqIndex = 26;
				
				boolean[] visited = new boolean[text.length()];
				
				for(int i = list.size()-1; i >=0; i--)
				{
					TextChar tc = list.get(i);
					char oldChar = tc.ch;
					char newChar = freqStr.charAt(--freqIndex);
					
					for(int j = 0; j < text.length(); j++)
					{
						if(text.charAt(j) == oldChar && visited[j] == false)
						{
							visited[j] = true;
							finalStrChar[j] = newChar;
						}
					}
				}
				
				//lower to upper
				
				for(int i = 0 ; i < text.length(); i++)
				{
					if(Character.isUpperCase(text.charAt(i)))
					{
						finalStrChar[i] = Character.toUpperCase(finalStrChar[i]);
					}
				}
				
				String finalStr = new String(finalStrChar);
				System.out.println(finalStr);
			}
		}
		catch(Exception e)
		{
			System.exit(0);
		}
	}
}

class TextChar implements Comparable<TextChar>
{
	Character ch;
	Integer freq;
	
	public TextChar(Character ch, Integer freq)
	{
		this.ch = ch;
		this.freq = freq;
	}
	
	public String toString()
	{
		return ch.toString();
	}
	
	public int compareTo(TextChar o)
	{
		return freq.compareTo(o.freq);
	}
}