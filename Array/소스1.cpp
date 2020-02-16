// Main.java
public class Main
{
	public static void main(String[] args)
	{
		DataBaseManagementSystem	DBMS = new DataBasemanagementSystem();

		//Use Interface
		DMBS.SelectSorter(new InsertSort());
		DMBS.Sort();

		DBMS.SelectSorter(new BubbleSort());
		DBMS.Sort();

		DBMS.SelectSorter(new QuickSort());
		DBMS.Sort();
	}
}


//Sorter.java
public interface Sorter
{
	public void Sort();
}


//InsertSort.java
public class InsertSort implements Sorter
{
	public void Sort()
	{
		System.out.println("InsertSort Process");
	}
}


//BubbleSort.java
public class Bubblesort implements Sorter
{
	public void sort()
	{
		System.out.println("BubbleSort Process");
	}
}


//QuickSort.java
public class QuickSort implements Sorter
{
	public void sort()
	{
		System.out.println("QuickSort Procss");
	}
}


//DataBaseManagementSystem.java
public class DataBaseManagementSystem
{
	sorter m_sorter;

	//Select interface
	public void SelectSorter(Sorter _Sorter)
	{
		m_Sorter = _Sorter;
	}

	//Use Interface
	public void Sort()
	{
		m_Sorter.sort();
	}
}






