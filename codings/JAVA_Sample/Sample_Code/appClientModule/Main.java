public class Main 
{
	public static void main(String[] args) 
	{
		DataBaseManagementSystem	DBMS = new DataBaseManagementSystem();
		
		// Use Interface
		DBMS.SelectSorter(new InsertSort());
		DBMS.Sort();
		
		DBMS.SelectSorter(new BubbleSort());
		DBMS.Sort();		
		
		DBMS.SelectSorter(new QuickSort());
		DBMS.Sort();
	}
}

