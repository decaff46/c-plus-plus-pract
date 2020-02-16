public class DataBaseManagementSystem {
	
	Sorter m_Sorter;
	
	// Select Interface
	public void SelectSorter( Sorter _Sorter )
	{
		m_Sorter = _Sorter;
	}
	// Use Interface
	public void Sort()
	{
		m_Sorter.Sort();
	}
}
